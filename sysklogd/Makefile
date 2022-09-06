#
# Copyright (C) 2020 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

PROGNAME  = syslogd
PRIORITY  = $(CONFIG_SYSLOGD_PRIORITY)
STACKSIZE = $(CONFIG_SYSLOGD_STACKSIZE)
MODULE    = $(CONFIG_SYSLOGD)
CFLAGS   += -DSYSCONFDIR=CONFIG_SYSLOGD_CONFDIR \
            -DRUNSTATEDIR=CONFIG_SYSLOGD_STATEDIR \
            -DMAXLINE=CONFIG_SYSLOGD_LINE_MAX
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CSRCS    += sysklogd/src/timer.c     \
            sysklogd/src/socket.c    \
            sysklogd/lib/pidfile.c   \
            sysklogd/lib/strlcat.c   \
            sysklogd/lib/utimensat.c
MAINSRC   = sysklogd/src/syslogd.c

include $(APPDIR)/Application.mk
