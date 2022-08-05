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

-include $(APPDIR)/Make.defs

CXXEXT := .cpp

CSRCS := src/ReportCSV.c
CSRCS += src/ReportDefault.c
CSRCS += src/tcp_window_size.c
CSRCS += src/gnu_getopt.c
CSRCS += src/gnu_getopt_long.c
CSRCS += src/stdio.c
CSRCS += src/sockets.c
CSRCS += src/SocketAddr.c
CSRCS += src/Locale.c
CSRCS += src/service.c
CSRCS += src/Reporter.c
CSRCS += src/Extractor.c
CSRCS += src/checksums.c
CSRCS += src/histogram.c
CSRCS += src/pdfs.c

CSRCS += compat/delay.c
CSRCS += compat/error.c
CSRCS += compat/signal.c
CSRCS += compat/string.c
CSRCS += compat/Thread.c

CXXSRCS := src/Listener.cpp
CXXSRCS += src/Client.cpp
CXXSRCS += src/Server.cpp
CXXSRCS += src/List.cpp
CXXSRCS += src/Launch.cpp
CXXSRCS += src/Settings.cpp
CXXSRCS += src/PerfSocket.cpp
CXXSRCS += src/isochronous.cpp

IPERF2_FLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
IPERF2_FLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" include}
IPERF2_FLAGS += ${shell $(TOPDIR)/tools/define.sh "$(CC)" HAVE_CONFIG_H}
IPERF2_FLAGS += -Wno-undef -Wno-shadow
IPERF2_FLAGS += -Dwarn=iperf2_warn
IPERF2_FLAGS += -Dwarn_errno=iperf2_warn_errno
IPERF2_FLAGS += -Dversion=iperf2_version

CFLAGS += $(IPERF2_FLAGS) -Wno-strict-prototypes
CXXFLAGS += $(IPERF2_FLAGS)

CONFIG_TOOLS_IPERF2_PRIORITY ?= SCHED_PRIORITY_DEFAULT
CONFIG_TOOLS_IPERF2_STACKSIZE ?= 2048

MAINSRC = src/main.cpp
PROGNAME = iperf2
APPNAME = iperf2
PRIORITY = $(CONFIG_TOOLS_IPERF2_PRIORITY)
STACKSIZE = $(CONFIG_TOOLS_IPERF2_STACKSIZE)

MODULE = CONFIG_TOOLS_IPERF2

include $(APPDIR)/Application.mk
