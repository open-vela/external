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

CFLAGS +=  -I nng/include -I nng/src \
		   -DNNG_PLATFORM_POSIX \
		   -DNNG_SETSTACKSIZE \
		   -DNNG_HAVE_EVENTFD \
		   -DNNG_HAVE_EPOLL \
		   -DNNG_HAVE_EPOLL_CREATE1 \
		   -DNNG_HAVE_MSG_CONTROL \
		   -DNNG_RESOLV_CONCURRENCY=1 \
		   -DCLOCK_REALTIME

# string
CFLAGS +=  -DNNG_HAVE_STRLCPY \
		   -DNNG_HAVE_STRNLEN \
		   -DNNG_HAVE_STRCASESTR \
		   -DNNG_HAVE_STRCASECMP \


ALL_SUBDIR = nng/src \
		   nng/src/core \
		   nng/src/supplemental/util \
		   nng/src/supplemental/tls \
		   nng/src/platform/posix

cflags.NNG_PROTOCOL_PAIR := nng/src/protocol/pair0 nng/src/protocol/pair1
cflags.NNG_PROTOCOL_SURVEY := nng/src/protocol/survey0
cflags.NNG_PROTOCOL_REQREP := nng/src/protocol/reqrep0
cflags.NNG_PROTOCOL_PUBSUB := nng/src/protocol/pubsub0
cflags.NNG_PROTOCOL_PIPELINE := nng/src/protocol/pipeline0
cflags.NNG_PROTOCOL_BUS := nng/src/protocol/bus0
cflags.NNG_TRANSPORT_INPROC := nng/src/transport/inproc
cflags.NNG_TRANSPORT_IPC := nng/src/transport/ipc
cflags.NNG_TRANSPORT_TCP := nng/src/transport/tcp nng/src/supplemental/tcp
cflags.NNG_TRANSPORT_WS := nng/src/transport/ws nng/src/supplemental/websocket nng/src/supplemental/http \
                           nng/src/supplemental/sha1 nng/src/supplemental/base64
cflags.NNG_TRANSPORT_TLS := nng/src/transport/tls nng/src/supplemental/tls \
		   nng/src/supplemental/tls/mbedtls nng/src/supplemental/tls/wolfssl
cflags.NNG_TRANSPORT_ZEROTIER := nng/src/transport/zerotier

CFLAGS += $(foreach flag, $(shell echo $(CONFIG_NNG_DEFINES)), -D${flag})
ALL_SUBDIR += $(foreach flag, $(shell echo $(CONFIG_NNG_DEFINES)), ${cflags.${flag}})

CSRCS = $(shell find $(ALL_SUBDIR) -maxdepth 1 -name "*.c" -a ! -name "*_test.c" -a ! -name "stub.c")

include $(APPDIR)/Application.mk
