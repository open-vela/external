############################################################################
# external/nng/Makefile
#
#   Copyright (C) 2020 Xiaomi Inc. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name NuttX nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

include $(APPDIR)/Make.defs

SOURCE_MAIN_PATH = src

CFLAGS +=  -I include -I src \
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


ALL_SUBDIR = src \
		   src/core \
		   src/supplemental/util \
		   src/supplemental/tls \
		   src/platform/posix

cflags.NNG_PROTOCOL_PAIR := src/protocol/pair0 src/protocol/pair1
cflags.NNG_PROTOCOL_SURVEY := src/protocol/survey0
cflags.NNG_PROTOCOL_REQREP := src/protocol/reqrep0
cflags.NNG_PROTOCOL_PUBSUB := src/protocol/pubsub0
cflags.NNG_PROTOCOL_PIPELINE := src/protocol/pipeline0
cflags.NNG_PROTOCOL_BUS := src/protocol/bus0
cflags.NNG_TRANSPORT_INPROC := src/transport/inproc
cflags.NNG_TRANSPORT_IPC := src/transport/ipc
cflags.NNG_TRANSPORT_TCP := src/transport/tcp src/supplemental/tcp
cflags.NNG_TRANSPORT_WS := src/transport/ws src/supplemental/websocket src/supplemental/http
cflags.NNG_TRANSPORT_TLS := src/transport/tls src/supplemental/tls \
		   src/supplemental/tls/mbedtls src/supplemental/tls/wolfssl
cflags.NNG_TRANSPORT_ZEROTIER := src/transport/zerotier

#CONFIG_NNG_DEFINES := NNG_PLATFORM_POSIX NNG_PROTOCOL_PAIR NNG_PROTOCOL_SURVEY \
	NNG_PROTOCOL_REQREP NNG_PROTOCOL_PUBSUB NNG_PROTOCOL_PIPELINE NNG_PROTOCOL_BUS \
	NNG_TRANSPORT_INPROC NNG_TRANSPORT_IPC NNG_TRANSPORT_TCP \
	NNG_TRANSPORT_WSS NNG_TRANSPORT_TLS NNG_TRANSPORT_ZEROTIER

CFLAGS += $(foreach flag, $(shell echo $(CONFIG_NNG_DEFINES)), -D${flag})
ALL_SUBDIR += $(foreach flag, $(shell echo $(CONFIG_NNG_DEFINES)), ${cflags.${flag}})

CSRCS = $(shell find $(ALL_SUBDIR) -maxdepth 1 -name "*.c" -a ! -name "*_test.c")

include $(APPDIR)/Application.mk
