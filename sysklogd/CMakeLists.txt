#
# Copyright (C) 2021 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#
if(CONFIG_SYSLOGD)

  set(CSRCS sysklogd/src/syslogd.c sysklogd/src/timer.c sysklogd/src/socket.c
            sysklogd/lib/pidfile.c sysklogd/lib/utimensat.c)

  set(CFLAGS
      -DSYSCONFDIR=CONFIG_SYSLOGD_CONFDIR -DRUNSTATEDIR=CONFIG_SYSLOGD_STATEDIR
      -DMAXLINE=CONFIG_SYSLOGD_LINE_MAX)

  nuttx_add_application(
    MODULE
    ${CONFIG_SYSLOGD}
    NAME
    syslogd
    STACKSIZE
    ${CONFIG_SYSLOGD_STACKSIZE}
    PRIORITY
    ${CONFIG_SYSLOGD_PRIORITY}
    SRCS
    ${CSRCS}
    COMPILE_FLAGS
    ${CFLAGS}
    INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_LIST_DIR})

endif()
