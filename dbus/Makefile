#
# Copyright (C) 2021 Xiaomi Corporation
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

ifeq ($(CONFIG_DBUS_DAEMON),)
ifneq ($(CONFIG_LIB_DBUS_RPMSG_SERVER_CPUNAME),"")
  CFLAGS += -DDBUS_RPMSG_SERVER_CPUNAME=CONFIG_LIB_DBUS_RPMSG_SERVER_CPUNAME
endif
endif

CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" dbus}
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" dbus/dbus}
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" dbus/tools}
CFLAGS   += -Dfork=vfork -DDBUS_COMPILATION -D__linux__
CFLAGS   += -DLOG_DAEMON=0 -DLOG_AUTH=0
CFLAGS   += -Dprint_message=dbus_print_message

PRIORITY  = $(CONFIG_DBUS_PRIORITY)
STACKSIZE = $(CONFIG_DBUS_STACKSIZE)
MODULE    = $(CONFIG_LIB_DBUS)

# libdbus source files

CSRCS    += dbus/dbus/dbus-address.c dbus/dbus/dbus-auth.c dbus/dbus/dbus-bus.c \
	dbus/dbus/dbus-connection.c dbus/dbus/dbus-credentials.c dbus/dbus/dbus-errors.c \
	dbus/dbus/dbus-keyring.c dbus/dbus/dbus-marshal-header.c dbus/dbus/dbus-marshal-byteswap.c \
	dbus/dbus/dbus-marshal-recursive.c dbus/dbus/dbus-marshal-validate.c dbus/dbus/dbus-message.c \
	dbus/dbus/dbus-misc.c dbus/dbus/dbus-nonce.c dbus/dbus/dbus-object-tree.c \
	dbus/dbus/dbus-pending-call.c dbus/dbus/dbus-resources.c dbus/dbus/dbus-server.c \
	dbus/dbus/dbus-server-socket.c dbus/dbus/dbus-server-debug-pipe.c dbus/dbus/dbus-sha.c \
	dbus/dbus/dbus-signature.c dbus/dbus/dbus-syntax.c dbus/dbus/dbus-timeout.c \
	dbus/dbus/dbus-threads.c dbus/dbus/dbus-transport.c dbus/dbus/dbus-transport-socket.c \
	dbus/dbus/dbus-watch.c dbus/dbus/dbus-uuidgen.c dbus/dbus/dbus-transport-unix.c \
	dbus/dbus/dbus-server-unix.c dbus/dbus/dbus-dataslot.c dbus/dbus/dbus-file.c \
	dbus/dbus/dbus-hash.c dbus/dbus/dbus-internals.c dbus/dbus/dbus-list.c \
	dbus/dbus/dbus-marshal-basic.c dbus/dbus/dbus-memory.c dbus/dbus/dbus-mempool.c \
	dbus/dbus/dbus-string.c dbus/dbus/dbus-sysdeps.c dbus/dbus/dbus-pipe.c \
	dbus/dbus/dbus-file-unix.c dbus/dbus/dbus-pipe-unix.c dbus/dbus/dbus-sysdeps-unix.c \
	dbus/dbus/dbus-sysdeps-pthread.c dbus/dbus/dbus-userdb.c \
	dbus/tools/dbus-print-message.c dbus/tools/tool-common.c

ifneq ($(CONFIG_DBUS_DAEMON),)

CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libexpat/libexpat/expat/lib}

# dbus utils source files

CSRCS    += dbus/dbus/dbus-asv-util.c dbus/dbus/dbus-mainloop.c dbus/dbus/dbus-message-util.c \
	dbus/dbus/dbus-shell.c dbus/dbus/dbus-pollable-set.c dbus/dbus/dbus-pollable-set-poll.c \
	dbus/dbus/dbus-string-util.c dbus/dbus/dbus-sysdeps-util.c dbus/dbus/dbus-userdb-util.c \
	dbus/dbus/dbus-sysdeps-util-unix.c dbus/dbus/dbus-spawn-unix.c \
	dbus/dbus/dbus-pollable-set-epoll.c

# dbus daemon source files

CSRCS    += dbus/bus/activation.c dbus/bus/apparmor.c dbus/bus/audit.c \
	dbus/bus/bus.c dbus/bus/config-loader-expat.c dbus/bus/config-parser.c \
	dbus/bus/config-parser-common.c dbus/bus/connection.c dbus/bus/containers.c \
	dbus/bus/desktop-file.c dbus/bus/dispatch.c dbus/bus/driver.c \
	dbus/bus/expirelist.c dbus/bus/policy.c dbus/bus/selinux.c \
	dbus/bus/services.c dbus/bus/signals.c dbus/bus/test.c \
	dbus/bus/utils.c dbus/bus/dir-watch-default.c dbus/bus/stats.c
MAINSRC  += dbus/bus/main.c
PROGNAME += dbusdaemon
endif

ifneq ($(CONFIG_DBUS_SEND),)
MAINSRC  += dbus/tools/dbus-send.c
PROGNAME += dbussend
endif

ifneq ($(CONFIG_DBUS_MONITOR),)
MAINSRC  += dbus/tools/dbus-monitor.c
PROGNAME += dbusmonitor
endif

ifneq ($(CONFIG_DBUS_TEST_TOOL),)
CSRCS    += dbus/tools/dbus-echo.c dbus/tools/dbus-spam.c
MAINSRC  += dbus/tools/test-tool.c
PROGNAME += dbustesttool
endif

ifneq ($(CONFIG_DBUS_UPDATE_ACTIVATION_ENVIRONMENT),)
MAINSRC  += dbus/tools/dbus-update-activation-environment.c
PROGNAME += dbus_update_activation_environment
endif

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libtelephony.a
endif

WASM_INITIAL_MEMORY = 131072
WASM_BUILD = y

include $(APPDIR)/Application.mk
