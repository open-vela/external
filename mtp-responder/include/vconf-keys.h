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

#ifndef __VCONF_KEY_H__
#define __VCONF_KEY_H__

#define VCONFKEY_MTP_SYNC_TIME_INT "db/setting/mtp_sync_time_int"
#define VCONFKEY_MTP_SYNC_PARTNER_STR "db/setting/mtp_sync_partner_str"
#define VCONFKEY_SETAPPL_DEVICE_NAME_STR "db/setappl/device_name_str"
#define VCONFKEY_MTP_SERIAL_NUMBER_STR "db/setting/mtp_serial_number_str"
#define VCONFKEY_USB_CUR_MODE "db/usb/cur_mode"

#define VCONFKEY_IDLE_LOCK_STATE_READ_ONLY "memory/idle_lock_state_read_only"
#define VCONFKEY_SYSMAN_BATTERY_CAPACITY "memory/sysman/battery_capacity"
#define VCONFKEY_SYSMAN_MMC_STATUS "memory/sysman/mmc_status"
#define VCONFKEY_SYSMAN_USB_STATUS "memory/sysman/usb_status"

#define VCONFKEY_SYSMAN_USB_DISCONNECTED 0
#define VCONFKEY_SYSMAN_MMC_MOUNTED 0

#endif /* __VCONF_KEY_H__ */
