#
# Copyright (C) 2022 Xiaomi Corporation
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

CFLAGS += -DG_LOG_DOMAIN=\"GLib\" -DGLIB_COMPILATION
CFLAGS += -Dfork=vfork -Db_coverage=false -DGLIB_CHARSETALIAS_DIR=\"/etc/locale/lib/\"
CFLAGS += -DSIGWINCH=21 -DSIGABRT=22 -DNSIG=_NSIG
CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}glib
CFLAGS += ${INCDIR_PREFIX}glib/glib

GLIB_FILTER_OUT  = $(wildcard glib/glib/*win32*.c) glib/glib/gtester.c
GLIB_FILTER_OUT += glib/glib/gstdio-private.c glib/glib/gjournal-private.c glib/glib/gregex.c
CSRCS += $(filter-out $(GLIB_FILTER_OUT), $(wildcard glib/glib/g*.c))
CSRCS += glib/glib/libcharset/localcharset.c

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libtelephony.a
endif

WASM_BUILD = y

include $(APPDIR)/Application.mk
