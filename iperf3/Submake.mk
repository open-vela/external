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
MAINSRC   = src/main.c

CSRCS     = src/iperf_api.c src/iperf_error.c src/iperf_auth.c
CSRCS    += src/iperf_client_api.c src/iperf_locale.c src/iperf_server_api.c
CSRCS    += src/iperf_tcp.c src/iperf_udp.c src/iperf_sctp.c src/iperf_util.c
CSRCS    += src/iperf_time.c src/dscp.c src/net.c src/tcp_info.c src/timer.c
CSRCS    += src/units.c

ifeq ($(CONFIG_NETUTILS_CJSON),)
CSRCS    += src/cjson.c
endif

CFLAGS   += -Dlinux

include $(APPDIR)/Application.mk
