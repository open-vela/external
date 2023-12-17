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

# ofono compile flags

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}ell
CFLAGS += ${INCDIR_PREFIX}ofono
CFLAGS += ${INCDIR_PREFIX}ofono/src
CFLAGS += ${INCDIR_PREFIX}ofono/gatchat
CFLAGS += ${INCDIR_PREFIX}ofono/gril
CFLAGS += ${INCDIR_PREFIX}ofono/gdbus
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/dbus/dbus
CFLAGS += -DHAVE_CONFIG_H -DPLUGINDIR=CONFIG_OFONO_PLUGIN_DIR -DOFONO_PLUGIN_BUILTIN
CFLAGS += -Dprint_buf=ofono_gril_print_buf
CFLAGS += -DHAVE_EXPLICIT_BZERO -DHAVE_RAWMEMCHR

# ELL (Embedded Linux library)

CSRCS = ell/ell/util.c ell/ell/test.c ell/ell/strv.c ell/ell/utf8.c      \
        ell/ell/queue.c ell/ell/timeout.c ell/ell/main.c ell/ell/idle.c  \
        ell/ell/signal.c ell/ell/io.c ell/ell/checksum.c ell/ell/log.c   \
        ell/ell/uuid.c ell/ell/file.c ell/ell/uintset.c ell/ell/string.c

# OFONO Modem

ifneq ($(CONFIG_OFONO_RILMODEM),)
CSRCS += $(wildcard ofono/drivers/rilmodem/*.c)
CSRCS += ofono/plugins/rildev.c ofono/plugins/ril.c
BUILTIN_PLUGIN += rildev ril rilmodem provision
endif

ifneq ($(CONFIG_OFONO_ATMODEM),)
ATCSRCSRM += ofono/gatchat/test-server.c ofono/gatchat/gsmdial.c ofono/gatchat/test-qcdm.c
ATCSRCS += $(filter-out $(ATCSRCSRM), \
           $(wildcard ofono/drivers/atmodem/*.c ofono/gatchat/*.c))
BUILTIN_PLUGIN += atmodem
ifneq ($(CONFIG_OFONO_PHONESIM),)
CSRCS += $(wildcard ofono/drivers/hfpmodem/*.c) ofono/plugins/phonesim.c
BUILTIN_PLUGIN += hfpmodem phonesim
endif
ifneq ($(CONFIG_OFONO_HUAWEIMODEM),)
CSRCS += $(wildcard ofono/drivers/huaweimodem/*.c)
BUILTIN_PLUGIN += huaweimodem
CSRCS += ofono/plugins/huawei.c
BUILTIN_PLUGIN += huawei
endif
endif

PRIORITY  = $(CONFIG_OFONO_PRIORITY)
STACKSIZE = $(CONFIG_OFONO_STACKSIZE)
MODULE    = $(CONFIG_OFONO)

# ofono unit test

ifneq ($(CONFIG_OFONO_UNITTEST),)
CSRCS    += ofono/gatchat/ringbuffer.c $(wildcard ofono/gril/*.c) ofono/src/common.c \
            ofono/src/log.c ofono/src/simutil.c ofono/src/smsutil.c ofono/src/storage.c \
            ofono/src/stkutil.c ofono/src/util.c ofono/unit/rilmodem-test-engine.c \
            ofono/unit/rilmodem-test-server.c
MAINSRC  += ofono/unit/test-rilmodem-cb.c
PROGNAME += test_rilmodem_cb
MAINSRC  += ofono/unit/test-rilmodem-cs.c
PROGNAME += test_rilmodem_cs
MAINSRC  += ofono/unit/test-rilmodem-gprs.c
PROGNAME += test_rilmodem_gprs
MAINSRC  += ofono/unit/test-rilmodem-sms.c
PROGNAME += test_rilmodem_sms
MAINSRC  += ofono/unit/test-util.c
PROGNAME += test_util
MAINSRC  += ofono/unit/test-simutil.c
PROGNAME += test_simutil
MAINSRC  += ofono/unit/test-sms.c
PROGNAME += test_sms
MAINSRC  += ofono/unit/test-stkutil.c
PROGNAME += test_stkutil
else

# ofono gatchat file(needby ofono emulator)

CSRCS    += $(sort $(ATCSRCS) ofono/gatchat/gatchat.c ofono/gatchat/gatio.c \
              ofono/gatchat/gatresult.c ofono/gatchat/gatserver.c \
              ofono/gatchat/gatutil.c ofono/gatchat/ringbuffer.c)

# ofono gprs provision file

CSRCS    += ofono/plugins/mbpi.c ofono/plugins/provision.c

# ofono core source file and compile flags

CSRCS    += $(filter-out ofono/src/main.c, \
              $(wildcard ofono/gdbus/*.c ofono/gril/*.c ofono/src/*.c))
MAINSRC  += ofono/src/main.c
PROGNAME += ofonod
endif

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libtelephony.a

# auto generate file for header file, version.h, builtin.h

builtin.h:
	$(Q) ./ofono/src/genbuiltin $(BUILTIN_PLUGIN) > $@

context:: builtin.h

clean::
	$(call DELFILE, builtin.h)

endif

WASM_INITIAL_MEMORY = 327680
WASM_BUILD          = n

include $(APPDIR)/Application.mk
