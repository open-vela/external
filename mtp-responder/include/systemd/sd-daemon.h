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

#ifndef __SD_DAEMON_H__
#define __SD_DAEMON_H__

/* sd_listen_fds() may be invoked by a daemon to check for file descriptors
 * passed by the service manager as part of the socket-based activation logic.
 * It returns the number of received file descriptors. If no file descriptors
 * have been received, zero is returned. The first file descriptor may be
 * found at file descriptor number 3 (i.e. SD_LISTEN_FDS_START), the remaining
 * descriptors follow at 4, 5, 6, …, if any.
 */

#define SD_LISTEN_FDS_START 3

int sd_listen_fds(int unset_environment);

#endif /* __SD_DAEMON_H__ */
