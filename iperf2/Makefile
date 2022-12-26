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

CXXEXT := .cpp

CSRCS += iperf2/src/checksums.c
CSRCS += iperf2/src/dscp.c
CSRCS += iperf2/src/Extractor.c
CSRCS += iperf2/src/gnu_getopt.c
CSRCS += iperf2/src/gnu_getopt_long.c
CSRCS += iperf2/src/histogram.c
CSRCS += iperf2/src/Locale.c
CSRCS += iperf2/src/packet_ring.c
CSRCS += iperf2/src/pdfs.c
CSRCS += iperf2/src/Reporter.c
CSRCS += iperf2/src/ReportOutputs.c
CSRCS += iperf2/src/Reports.c
CSRCS += iperf2/src/service.c
CSRCS += iperf2/src/SocketAddr.c
CSRCS += iperf2/src/socket_io.c
CSRCS += iperf2/src/stdio.c
CSRCS += iperf2/src/tcp_window_size.c

CSRCS += iperf2/compat/delay.c
CSRCS += iperf2/compat/error.c
CSRCS += iperf2/compat/gettcpinfo.c
CSRCS += iperf2/compat/inet_ntop.c
CSRCS += iperf2/compat/signal.c
CSRCS += iperf2/compat/string.c
CSRCS += iperf2/compat/Thread.c

CXXSRCS += iperf2/src/active_hosts.cpp
CXXSRCS += iperf2/src/Client.cpp
CXXSRCS += iperf2/src/isochronous.cpp
CXXSRCS += iperf2/src/Launch.cpp
CXXSRCS += iperf2/src/Listener.cpp
CXXSRCS += iperf2/src/PerfSocket.cpp
CXXSRCS += iperf2/src/Server.cpp
CXXSRCS += iperf2/src/Settings.cpp

IPERF2_FLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
IPERF2_FLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" iperf2/include}
IPERF2_FLAGS += ${shell $(DEFINE) "$(CC)" HAVE_CONFIG_H}
IPERF2_FLAGS += -Wno-undef -Wno-shadow
IPERF2_FLAGS += -Dwarn=iperf2_warn
IPERF2_FLAGS += -Dwarn_errno=iperf2_warn_errno
IPERF2_FLAGS += -Dversion=iperf2_version

CFLAGS += $(IPERF2_FLAGS) -Wno-strict-prototypes
CXXFLAGS += $(IPERF2_FLAGS)

MAINSRC = iperf2/src/main.cpp
PROGNAME = iperf2
APPNAME = iperf2
PRIORITY = $(CONFIG_TOOLS_IPERF2_PRIORITY)
STACKSIZE = $(CONFIG_TOOLS_IPERF2_STACKSIZE)

MODULE = CONFIG_TOOLS_IPERF2

include $(APPDIR)/Application.mk
