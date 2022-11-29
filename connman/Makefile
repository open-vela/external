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

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}include
CFLAGS += ${INCDIR_PREFIX}connman
CFLAGS += ${INCDIR_PREFIX}connman/gdbus

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/dbus/dbus

CFLAGS += -DCONNMAN_PLUGIN_BUILTIN
CFLAGS += -DHAVE_CONFIG_H
CFLAGS += -DSTORAGEDIR=\"$(CONFIG_CONNMAN_STORAGEDIR)\"
CFLAGS += -DPLUGINDIR=\"$(CONFIG_CONNMAN_STORAGEDIR)\"
CFLAGS += -DVPN_STORAGEDIR=\"$(CONFIG_CONNMAN_VPN_STORAGEDIR)\"
CFLAGS += -DCONFIGDIR=\"$(CONFIG_CONNMAN_CONFIGDIR)\"
CFLAGS += -DSTATEDIR=\"$(CONFIG_CONNMAN_STATEDIR)\"

CFLAGS += -Wno-shadow -Wno-strict-prototypes

ifneq ($(CONFIG_LIB_OFONO),)
PLUGIN_SRCS += connman/plugins/ofono.c
PLUGIN_MODULES += ofono
endif

ifneq ($(CONFIG_WIRELESS_WAPI),)
PLUGIN_SRCS += connman/plugins/wifi_wapi.c
PLUGIN_MODULES += wifi
endif

CSRCS  = $(filter-out connman/src/main.c \
                      connman/src/connmand-wait-online.c \
                      connman/src/firewall-nftables.c \
                      connman/src/inotify.c \
                      connman/src/clock.c \
                      connman/src/timezone.c \
                      connman/src/ntp.c \
                      connman/src/6to4.c \
                      connman/src/dnsproxy.c \
                      connman/src/wispr.c \
                      connman/src/timeserver.c \
                      connman/src/stats.c \
                      connman/src/wpad.c \
         , $(wildcard connman/src/*.c))

CSRCS += $(filter-out connman/src/shared/mnlg.c \
         , $(wildcard connman/src/shared/*.c))

CSRCS += $(filter-out connman/gdhcp/ipv4ll.c \
         , $(wildcard connman/gdhcp/*.c))

CSRCS += $(wildcard connman/gdbus/*.c)

CSRCS += $(PLUGIN_SRCS)

MAINSRC   += connman/src/main.c
PROGNAME  += connmand
PRIORITY  += $(CONFIG_CONNMAN_PRIORITY)
STACKSIZE += $(CONFIG_CONNMAN_STACKSIZE)
MODULE    += $(CONFIG_CONNMAN)

ifneq ($(CONFIG_CONNMAN_CTL),)
CSRCS += $(filter-out connman/client/main.c \
                      connman/client/main_nuttx.c \
                      connman/client/input.c \
         , $(wildcard connman/client/*.c))

MAINSRC  += connman/client/main_nuttx.c
PROGNAME += connmanctl
endif

builtin.h:
	$(Q) connman/src/genbuiltin $(PLUGIN_MODULES) > $@

include/connman:
	$(Q) mkdir -p include; cd include; ln -sf ../connman/include connman

connman/include/version.h:
	$(Q) touch connman/include/version.h

context:: builtin.h include/connman connman/include/version.h

clean::
	$(call DELFILE, builtin.h)
	$(call DELFILE, connman/connman)
	$(call CLEAN)

distclean:: clean
	$(call DELFILE, Make.dep)
	$(call DELFILE, .depend)

include $(APPDIR)/Application.mk
