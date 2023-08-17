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

#ifndef __SD_LOGIN_H__
#define __SD_LOGIN_H__

#include <sys/types.h>

typedef void sd_login_monitor;

int sd_get_uids(uid_t** users);
void sd_login_monitor_unrefp(sd_login_monitor** m);
int sd_login_monitor_new(const char* category, sd_login_monitor** m);
int sd_login_monitor_get_fd(sd_login_monitor* m);
int sd_login_monitor_get_events(sd_login_monitor* m);

#endif /* __SD_LOGIN_H__ */
