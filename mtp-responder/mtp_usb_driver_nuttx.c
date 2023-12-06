/*
 * Copyright (C) 2023 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define _GNU_SOURCE
#include "mtp_entity_device.h"
#include "mtp_event_handler.h"
#include "mtp_init.h"
#include "mtp_transport.h"
#include "mtp_usb_driver.h"
#include "mtp_util_msgq.h"
#include "mtp_util_support.h"
#include "mtp_util_thread.h"
#include "ptp_container.h"
#include "ptp_datacodes.h"
#include <fcntl.h>
#include <glib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/prctl.h>
#include <systemd/sd-daemon.h>
#include <unistd.h>
/*
 * GLOBAL AND EXTERN VARIABLES
 */
extern mtp_config_t g_conf;
/*
 * STATIC VARIABLES AND FUNCTIONS
 */
/*PIMA15740-2000 spec*/
#define USB_PTPREQUEST_CANCELIO 0x64 /* Cancel request */
#define USB_PTPREQUEST_GETEVENT 0x65 /* Get extened event data */
#define USB_PTPREQUEST_RESET 0x66 /* Reset Device */
#define USB_PTPREQUEST_GETSTATUS 0x67 /* Get Device Status */
#define USB_PTPREQUEST_CANCELIO_SIZE 6
#define USB_PTPREQUEST_GETSTATUS_SIZE 12
static mtp_int32 g_usb_ep_in = -1; /* write (g_usb_ep_in, ...) */
static mtp_int32 g_usb_ep_out = -1; /* read (g_usb_ep_out, ...) */
static mtp_int32 g_usb_ep_status = -1; /* write (g_usb_ep_status, ...) */
static mtp_max_pkt_size_t pkt_size;
static mtp_uint32 rx_mq_sz;
static mtp_uint32 tx_mq_sz;
static mtp_int32 __handle_usb_read_err(mtp_int32 err,
    mtp_uchar* buf, mtp_int32 buf_len);
static void __clean_up_msg_queue(void* param);
/*
 * FUNCTIONS
 */
/* LCOV_EXCL_START */
static mtp_bool __io_init(void)
{
    if (sd_listen_fds(0) >= 4) {
        DBG("socket-activated");
        g_usb_ep_in = SD_LISTEN_FDS_START + 1;
        g_usb_ep_out = SD_LISTEN_FDS_START + 2;
        g_usb_ep_status = SD_LISTEN_FDS_START + 3;
        return TRUE;
    }
    g_usb_ep_in = open(MTP_EP_IN_PATH, O_RDWR);
    if (g_usb_ep_in < 0) {
        ERR("Error opening bulk-in");
        goto cleanup;
    }
    g_usb_ep_out = open(MTP_EP_OUT_PATH, O_RDWR);
    if (g_usb_ep_out < 0) {
        ERR("Error opening bulk-out");
        goto cleanup_in;
    }
    g_usb_ep_status = open(MTP_EP_STATUS_PATH, O_RDWR);
    if (g_usb_ep_status < 0) {
        ERR("Error opening status");
        goto cleanup_out;
    }
    return TRUE;
cleanup_out:
    close(g_usb_ep_out);
cleanup_in:
    close(g_usb_ep_in);
cleanup:
    return FALSE;
}
static mtp_bool ffs_transport_init_usb_device(void)
{
    mtp_int32 status = 0;
    int msg_size;
    if (g_usb_ep_in > 0) {
        DBG("Device Already open\n");
        return TRUE;
    }
    status = __io_init();
    if (!status) {
        char error[256];
        strerror_r(errno, error, sizeof(error));
        ERR("Device node [%s] open failed, errno [%s]\n",
            MTP_EP_IN_PATH, error);
        return FALSE;
    }
    pkt_size.rx = g_conf.read_usb_size;
    pkt_size.tx = g_conf.write_usb_size;
    DBG("Final : Tx pkt size:[%u], Rx pkt size:[%u]\n", pkt_size.tx, pkt_size.rx);
    msg_size = sizeof(msgq_ptr_t) - sizeof(long);
    rx_mq_sz = (g_conf.max_io_buf_size / g_conf.max_rx_ipc_size) * msg_size;
    tx_mq_sz = (g_conf.max_io_buf_size / g_conf.max_tx_ipc_size) * msg_size;
    DBG("RX MQ size :[%u], TX MQ size:[%u]\n", rx_mq_sz, tx_mq_sz);
    return TRUE;
}
static void ffs_transport_deinit_usb_device(void)
{
    if (g_usb_ep_in >= 0)
        close(g_usb_ep_in);
    g_usb_ep_in = -1;
    if (g_usb_ep_out >= 0)
        close(g_usb_ep_out);
    g_usb_ep_out = -1;
    if (g_usb_ep_status >= 0)
        close(g_usb_ep_status);
    g_usb_ep_status = -1;
    return;
}
static mtp_uint32 ffs_get_tx_pkt_size(void)
{
    return pkt_size.tx;
}
static mtp_uint32 ffs_get_rx_pkt_size(void)
{
    return pkt_size.rx;
}
/*
 * static mtp_int32 ffs_transport_mq_init()
 * This function create a message queue for MTP,
 * A created message queue will be used to help data transfer between
 * MTP module and usb buffer.
 * @return  This function returns TRUE on success or
 *	returns FALSE on failure.
 */
static mtp_int32 ffs_transport_mq_init(msgq_id_t* rx_mqid, msgq_id_t* tx_mqid)
{
    if (_util_msgq_init(rx_mqid, 0) == FALSE) {
        ERR("RX MQ init Fail [%d]\n", errno);
        return FALSE;
    }
    if (_util_msgq_set_size(*rx_mqid, rx_mq_sz) == FALSE)
        ERR("RX MQ setting size Fail [%d]\n", errno);
    if (_util_msgq_init(tx_mqid, 0) == FALSE) {
        ERR("TX MQ init Fail [%d]\n", errno);
        _util_msgq_deinit(rx_mqid);
        *rx_mqid = -1;
        return FALSE;
    }
    if (_util_msgq_set_size(*tx_mqid, tx_mq_sz) == FALSE)
        ERR("TX MQ setting size Fail [%d]\n", errno);
    return TRUE;
}
static void* ffs_transport_thread_usb_write(void* arg)
{
    mtp_int32 status = 0;
    mtp_uint32 len = 0;
    unsigned char* mtp_buf = NULL;
    msg_type_t mtype = MTP_UNDEFINED_PACKET;
    msgq_id_t* mqid = (msgq_id_t*)arg;
    pthread_cleanup_push(__clean_up_msg_queue, mqid);
    do {
        /* original LinuxThreads cancelation didn't work right
	 * so test for it explicitly.
	 */
        pthread_testcancel();
        _util_rcv_msg_from_mq(*mqid, &mtp_buf, &len, &mtype);
        if (mtype == MTP_BULK_PACKET || mtype == MTP_DATA_PACKET) {
            status = write(g_usb_ep_in, mtp_buf, len);
            if (status < 0) {
                ERR("USB write fail : %d\n", errno);
                if (errno == ENOMEM || errno == ECANCELED) {
                    status = 0;
                    __clean_up_msg_queue(mqid);
                }
            }
            g_free(mtp_buf);
            mtp_buf = NULL;
        } else if (MTP_EVENT_PACKET == mtype) {
            /* Handling the MTP Asynchronous Events */
            DBG("Send Interrupt data to kernel via g_usb_ep_status\n");
            status = write(g_usb_ep_status, mtp_buf, len);
            g_free(mtp_buf);
            mtp_buf = NULL;
        } else if (MTP_ZLP_PACKET == mtype) {
            DBG("Send ZLP data to kerne via g_usb_ep_in\n");
            status = write(g_usb_ep_in, (void*)0xFEE1DEAD, 0);
        } else {
            DBG("mtype = %d is not valid\n", mtype);
            status = -1;
        }
        if (status < 0) {
            ERR("write data to the device node Fail:\
		    status = %d\n",
                status);
            break;
        }
    } while (status >= 0);
    DBG("exited Source thread with status %d\n", status);
    pthread_cleanup_pop(1);
    g_free(mtp_buf);
    return NULL;
}
static void* ffs_transport_thread_usb_read(void* arg)
{
    mtp_int32 status = 0;
    msgq_ptr_t pkt = { MTP_DATA_PACKET, 0, 0, NULL };
    msgq_id_t* mqid = (msgq_id_t*)arg;
    mtp_uint32 rx_size = _get_rx_pkt_size();
    pthread_cleanup_push(__clean_up_msg_queue, mqid);
    do {
        pthread_testcancel();
        pkt.buffer = (mtp_uchar*)g_malloc(rx_size);
        if (NULL == pkt.buffer) {
            ERR("Sink thread: memalloc failed.\n");
            break;
        }
        status = read(g_usb_ep_out, pkt.buffer, rx_size);
        if (status <= 0) {
            status = __handle_usb_read_err(status, pkt.buffer, rx_size);
            if (status <= 0) {
                ERR("__handle_usb_read_err is failed\n");
                g_free(pkt.buffer);
                break;
            }
        }
        pkt.length = status;
        if (FALSE == _util_msgq_send(*mqid, (void*)&pkt, sizeof(msgq_ptr_t) - sizeof(long), 0)) {
            ERR("msgsnd Fail");
            g_free(pkt.buffer);
        }
    } while (status > 0);
    DBG("status[%d] errno[%d]\n", status, errno);
    pthread_cleanup_pop(1);
    return NULL;
}
static void* ffs_transport_thread_usb_control(void* arg)
{
    return NULL;
}
static mtp_int32 __handle_usb_read_err(mtp_int32 err,
    mtp_uchar* buf, mtp_int32 buf_len)
{
    mtp_int32 retry = 0;
    mtp_bool ret;
    while (retry++ < MTP_USB_ERROR_MAX_RETRY) {
        if (err == 0) {
            DBG("ZLP(Zero Length Packet). Skip");
        } else if (err < 0 && errno == EINTR) {
            DBG("read () is interrupted. Skip");
        } else if (err < 0 && errno == EIO) {
            DBG("EIO");
            if (MTP_PHONE_USB_CONNECTED != _util_get_local_usb_status()) {
                ERR("USB is disconnected");
                break;
            }
            _transport_deinit_usb_device();
            ret = _transport_init_usb_device();
            if (ret == FALSE) {
                ERR("_transport_init_usb_device Fail");
                continue;
            }
        } else if (err < 0 && errno == ESHUTDOWN) {
            DBG("ESHUTDOWN");
        } else {
            ERR("Unknown error : %d, errno [%d] \n", err, errno);
            break;
        }
        err = read(g_usb_ep_out, buf, buf_len);
        if (err > 0)
            break;
    }
    if (err <= 0)
        ERR("USB error handling Fail");
    return err;
}
static void __clean_up_msg_queue(void* mq_id)
{
    mtp_int32 len = 0;
    msgq_ptr_t pkt = { 0 };
    msgq_id_t l_mqid;
    ret_if(mq_id == NULL);
    l_mqid = *(msgq_id_t*)mq_id;
    _transport_set_control_event(PTP_EVENTCODE_CANCELTRANSACTION);
    while (TRUE == _util_msgq_receive(l_mqid, (void*)&pkt, sizeof(msgq_ptr_t) - sizeof(long), 1, &len)) {
        g_free(pkt.buffer);
        memset(&pkt, 0, sizeof(msgq_ptr_t));
    }
    return;
}
/*
 * mtp_bool ffs_transport_mq_deinit()
 * This function destroy a message queue for MTP,
 * @return  This function returns TRUE on success or
 *	returns FALSE on failure.
 */
static mtp_bool ffs_transport_mq_deinit(msgq_id_t* rx_mqid, msgq_id_t* tx_mqid)
{
    mtp_int32 res = TRUE;
    if (*rx_mqid) {
        res = _util_msgq_deinit(rx_mqid);
        if (res == FALSE) {
            ERR("rx_mqid deinit Fail [%d]\n", errno);
        } else {
            *rx_mqid = 0;
        }
    }
    if (*tx_mqid) {
        res = _util_msgq_deinit(tx_mqid);
        if (res == FALSE) {
            ERR("tx_mqid deinit fail [%d]\n", errno);
        } else {
            *tx_mqid = 0;
        }
    }
    return res;
}
static mtp_uint32 ffs_transport_get_usb_packet_len(void)
{
#ifdef CONFIG_USBDEV_DUALSPEED
    return MTP_MAX_PACKET_SIZE_SEND_HS;
#else
    return MTP_MAX_PACKET_SIZE_SEND_FS;
#endif
}
/* LCOV_EXCL_STOP */
const mtp_usb_driver_t mtp_usb_driver_ffs = {
    .transport_init_usb_device = ffs_transport_init_usb_device,
    .transport_deinit_usb_device = ffs_transport_deinit_usb_device,
    .transport_thread_usb_write = ffs_transport_thread_usb_write,
    .transport_thread_usb_read = ffs_transport_thread_usb_read,
    .transport_thread_usb_control = ffs_transport_thread_usb_control,
    .transport_mq_init = ffs_transport_mq_init,
    .transport_mq_deinit = ffs_transport_mq_deinit,
    .transport_get_usb_packet_len = ffs_transport_get_usb_packet_len,
    .get_tx_pkt_size = ffs_get_tx_pkt_size,
    .get_rx_pkt_size = ffs_get_rx_pkt_size,
};
