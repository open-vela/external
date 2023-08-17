/*
 * Copyright (C) 2023 Xiaomi Corperation
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

#include <cutils/properties.h>
#include <fcntl.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <kvdb.h>
#include <stdlib.h>
#include <storage.h>
#include <sys/statvfs.h>
#include <system_info.h>
#include <systemd/sd-login.h>
#include <unistd.h>

#include "mtp_util.h"
#include "mtp_util_fs.h"
#include "mtp_util_media_info.h"
#include "mtp_util_support.h"
#include "vconf.h"

/**
 * This function get the integer value of given key.
 *
 * @param[in] in_key key
 * @param[out] intval output buffer
 * @return 0 on success, -1 on error
 * @pre None
 * @post None
 * @remkar None
 * @see vconf_get_bool, vconf_get_dbl, vconf_get_str
 * @par example
 * @code

#include <stdio.h>
#include <vconf.h>

const char *key1_name="db/test/key1";
int main(int argc, char **argv)
{
   int key1_value;

   if(vconf_set_int(key1_name,1))
      fprintf(stderr, "vconf_set_int FAIL\n");
   else
      printf("vconf_set_int OK\n");

   if(vconf_get_int(key1_name, &key1_value))
      fprintf(stderr, "vconf_get_int FAIL\n");
   else
      printf("vconf_get_int OK(key1 value is %d)\n", key1_value);

   return 0;
}
 * @endcode
 */

int vconf_get_int(const char* key, int* intval)
{
    if (strcmp(key, VCONFKEY_IDLE_LOCK_STATE_READ_ONLY) == 0) {
        *intval = MTP_PHONE_LOCK_OFF;
    } else if (strcmp(key, VCONFKEY_SYSMAN_MMC_STATUS) == 0) {
        *intval = VCONFKEY_SYSMAN_MMC_MOUNTED;
    } else if (strcmp(key, VCONFKEY_SYSMAN_USB_STATUS) == 0) {
        *intval = MTP_PHONE_USB_CONNECTED;
    } else {
        *intval = property_get_int32(key, INT32_MAX);
    }

    if (INT32_MAX == *intval) {
        return -1;
    }

    return 0;
}

/**
 * This function sets the integer value of given key.
 * @param[in]  in_key  key
 * @param[in]  intval integer value to set (0 is also allowed as a value.)
 * @return 0 on success, -1 on error
 * @pre None
 * @post None
 * @remarks None
 * @see vconf_set_bool(), vconf_set_dbl(), vconf_set_str()
 */

int vconf_set_int(const char* key, int intval)
{
    if (property_set_int32(key, intval) < 0) {
        return -1;
    }

    return 0;
}

/**
 * This function gets the string value of given key.
 * \n You have to free this returned value.
 * @param[in]  in_key  key
 * @return allocated pointer of key value on success, NULL on error
 * @pre None
 * @post None
 * @remarks None
 * @see vconf_get_int(), vconf_get_dbl(), vconf_get_bool()
 * @par example
 * @code
   #include <stdio.h>
   #include <vconf.h>

   char *get_str=vconf_get_str("db/test/test1");
   if(get_str) {
      printf("vconf_get_str OK(value = %s)", get_str);
      free(get_str);
   }else
      fprintf(stderr, "vconf_get_str FAIL");
 * @endcode
 */

char* vconf_get_str(const char* key)
{
    char* pstr = malloc(PROP_VALUE_MAX);

    if (strcmp(key, VCONFKEY_SETAPPL_DEVICE_NAME_STR) == 0) {
        strlcpy(pstr, "NuttX", PROP_VALUE_MAX);
    } else if (strcmp(key, VCONFKEY_MTP_SYNC_PARTNER_STR) == 0) {
        strlcpy(pstr, MTP_DEV_PROPERTY_SYNCPARTNER, PROP_VALUE_MAX);
    } else {
        property_get_buffer(key, pstr, PROP_VALUE_MAX);
    }

    return pstr;
}

/**
 * This function sets the string value of given key.
 * @param[in]  in_key  key
 * @param[in]  strval string value to set
 * @return 0 on success, -1 on error
 * @pre None
 * @post None
 * @remarks None
 * @see vconf_set_bool(), vconf_set_dbl(), vconf_set_int()
 */

int vconf_set_str(const char* key, const char* strval)
{
    if (property_set_buffer(key, strval, sizeof(strval)) < 0) {
        return -1;
    }

    return 0;
}

/**
 * This function gets Integer value of the keynode.
 * @param[in] keynode The Key
 * @return Integer value, or 0 if no value is obtained
 ** @pre Nome
 * @post None
 * @remarks None
 * @see vconf_notify_key_changed(), vconf_keynode_get_name, vconf_keynode_get_bool, vconf_keynode_get_type,
        vconf_keynode_get_str, vconf_keynode_get_dbl, keynode_t, vconf_t
 */

int vconf_keynode_get_int(keynode_t* keynode)
{
    return 0;
}

/**
 * This function adds a change callback for given key,
 * which is called when the key is set or unset.
 * \n Information(#keynode_t) of the key that changed is delivered to #vconf_callback_fn,
 * or if the key is deleted, the @link #keynode_t keynode @endlink has #VCONF_TYPE_NONE as type.
 * \n Multiple vconf_callback_fn functions may exist for one key.
 * \n The callback is issued in the context of the glib main loop.
 * \n WARNING: This callback mechanism DOES NOT GUARANTEE consistency of data chage. For example,
 * When you have a callback for a certain key, assume that two or more processes are trying to
 * change the value of the key competitively. In this case, your callback function will always
 * get 'CURRENT' value, not the value raised the notify that caused run of the callback.  So,
 * do not use vconf callback when competitive write for a key is happening. In such case, use
 * socket-based IPC(dbus or something else) instead.
 *
 * @param[in]   in_key  key
 * @param[in]   cb      callback function
 * @param[in]   user_data    callback data
 * @return 0 on success, -1 on error
 * @pre Nome
 * @post None
 * @remarks None
 * @see vconf_ignore_key_changed
 * @par example
 * @code
 void test_cb(keynode_t *key, void* data)
 {
    switch(vconf_keynode_get_type(key))
    {
       case VCONF_TYPE_INT:
        printf("key = %s, value = %d(int)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_int(key));
        break;
       case VCONF_TYPE_BOOL:
        printf("key = %s, value = %d(bool)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_bool(key));
        break;
       case VCONF_TYPE_DOUBLE:
        printf("key = %s, value = %f(double)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_dbl(key));
        break;
       case VCONF_TYPE_STRING:
        printf("key = %s, value = %s(string)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_str(key));
        break;
       default:
        fprintf(stderr, "Unknown Type(%d)\n", vconf_keynode_get_type(key));
        break;
    }
    return;
 }

 int main()
 {
    int i;
    GMainLoop *event_loop;

    g_type_init();

    vconf_notify_key_changed("db/test/test1", test_cb, NULL);

    event_loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(event_loop);

    vconf_ignore_key_changed("db/test/test1", test_cb);
    return 0;
 }
 * @endcode
 */
int vconf_notify_key_changed(const char* in_key, vconf_callback_fn cb, void* user_data)
{
    return 0;
}

/**
 * @brief Removes a change callback for the given key,
 *        which was added by vconf_notify_key_changed().
 *
 * @since_tizen 2.3
 *
 * @param[in]   in_key  The key
 * @param[in]   cb      The callback function
 *
 * @return @c 0 on success,
 *         otherwise @c -1 on error
 *
 * @see vconf_notify_key_changed()
 */
int vconf_ignore_key_changed(const char* in_key, vconf_callback_fn cb)
{
    return 0;
}

mtp_bool _util_get_audio_metadata(const mtp_char* filepath,
    comp_audio_meta_t* audio_data)
{
    return FALSE;
}

mtp_bool _util_get_video_metadata(mtp_char* filepath,
    comp_video_meta_t* video_data)
{
    return FALSE;
}

mtp_bool _util_get_image_ht_wt(const mtp_char* filepath,
    image_meta_t* image_data)
{
    return FALSE;
}

mtp_bool _util_get_audio_meta_from_extractor(const mtp_char* filepath,
    comp_audio_meta_t* audio_data)
{
    return FALSE;
}

mtp_bool _util_get_video_meta_from_extractor(const mtp_char* filepath,
    comp_video_meta_t* video_data)
{
    return FALSE;
}

void _util_flush_db(void)
{
}

void _util_delete_file_from_db(const mtp_char* filepath)
{
}

void _util_add_file_to_db(const mtp_char* filepath)
{
}

void _util_scan_folder_contents_in_db(const mtp_char* filepath)
{
}

void _util_free_common_meta(common_meta_t* metadata)
{
}

void _util_free_video_meta(video_meta_t* video)
{
}

int storage_foreach_device_supported(storage_device_supported_cb callback, void* user_data)
{
    strlcpy((char*)user_data, MTP_EXTERNAL_PATH_CHAR, MTP_MAX_PATHNAME_SIZE);
    return STORAGE_ERROR_NONE;
}

int storage_get_internal_memory_size(struct statvfs* buf)
{
    return 0;
}

int media_content_disconnect(void)
{
    return 0;
}

int media_content_connect_with_uid(uid_t uid)
{
    return 0;
}

/* sd_listen_fds() may be invoked by a daemon to check for file descriptors
 * passed by the service manager as part of the socket-based activation logic.
 * It returns the number of received file descriptors. If no file descriptors
 * have been received, zero is returned. The first file descriptor may be
 * found at file descriptor number 3 (i.e. SD_LISTEN_FDS_START), the remaining
 * descriptors follow at 4, 5, 6, …, if any.
 */

int sd_listen_fds(int unset_environment)
{
    return 0;
}

int sd_get_uids(uid_t** users)
{
    *users = calloc(sizeof(uid_t), 1);
    return 1;
}

int sd_login_monitor_new(const char* category, sd_login_monitor** m)
{
    return 0;
}

int sd_login_monitor_get_fd(sd_login_monitor* m)
{
    return open("/dev/null", O_RDONLY);
}

int sd_login_monitor_get_events(sd_login_monitor* m)
{
    return POLLIN;
}

void sd_login_monitor_unrefp(sd_login_monitor** m)
{
}

int system_info_get_platform_string(const char* key, char** value)
{
    return SYSTEM_INFO_ERROR_NOT_SUPPORTED;
}
