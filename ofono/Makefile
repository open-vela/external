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

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" ofono}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" ofono/src}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" ofono/gatchat}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" ofono/gril}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" ofono/gdbus}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/glib/glib/glib}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/glib/glib}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/dbus/dbus}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/ell/ell}
CFLAGS += -DHAVE_CONFIG_H -DPLUGINDIR=CONFIG_LIB_OFONO_PLUGIN_DIR -DOFONO_PLUGIN_BUILTIN

# OFONO Modem

ifneq ($(CONFIG_LIB_OFONO_RILMODEM),)
CSRCS += $(filter-out ofono/drivers/rilmodem/phonebook.c, \
           $(wildcard ofono/drivers/rilmodem/*.c))
CSRCS += ofono/plugins/rildev.c ofono/plugins/ril.c
BUILTIN_PLUGIN += rilmodem ril rildev
endif

ifneq ($(CONFIG_LIB_OFONO_ATMODEM),)
ATCSRCS += $(filter-out ofono/gatchat/test-server.c, \
           $(wildcard ofono/drivers/atmodem/*.c ofono/gatchat/*.c))
BUILTIN_PLUGIN += atmodem
ifneq ($(CONFIG_LIB_OFONO_PHONESIM),)
CSRCS += $(wildcard ofono/drivers/hfpmodem/*.c) ofono/plugins/phonesim.c
BUILTIN_PLUGIN += hfpmodem phonesim
endif
ifneq ($(CONFIG_LIB_OFONO_HUAWEIMODEM),)
CSRCS += $(wildcard ofono/drivers/huaweimodem/*.c)
BUILTIN_PLUGIN += huaweimodem
CSRCS += ofono/plugins/huawei.c
BUILTIN_PLUGIN += huawei
endif
endif

PRIORITY  = $(CONFIG_LIB_OFONO_PRIORITY)
STACKSIZE = $(CONFIG_LIB_OFONO_STACKSIZE)
MODULE    = $(CONFIG_LIB_OFONO)

# ofono unit test

ifneq ($(CONFIG_LIB_OFONO_UNITTEST),)
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

include $(APPDIR)/Application.mk
