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

PROGNAME  = iperf3
PRIORITY  = CONFIG_TOOLS_IPERF3_PRIORITY
STACKSIZE = CONFIG_TOOLS_IPERF3_STACKSIZE
MODULE    = $(CONFIG_TOOLS_IPERF3)
MAINSRC   = iperf3/src/main.c

CSRCS     = iperf3/src/iperf_api.c iperf3/src/iperf_error.c iperf3/src/iperf_auth.c
CSRCS    += iperf3/src/iperf_client_api.c iperf3/src/iperf_locale.c iperf3/src/iperf_server_api.c
CSRCS    += iperf3/src/iperf_tcp.c iperf3/src/iperf_udp.c iperf3/src/iperf_sctp.c
CSRCS    += iperf3/src/iperf_util.c iperf3/src/iperf_time.c iperf3/src/dscp.c iperf3/src/net.c
CSRCS    += iperf3/src/tcp_info.c iperf3/src/timer.c iperf3/src/units.c

ifeq ($(CONFIG_NETUTILS_CJSON),)
CSRCS    += iperf3/src/cjson.c
endif

CFLAGS   += -Dlinux
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}

include $(APPDIR)/Application.mk
