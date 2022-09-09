#
# Copyright (C) 2021 Xiaomi Corporation #
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

CSRCS += $(wildcard src/stack/btcommon/*.c)
CSRCS += $(wildcard src/stack/bluelet/*.c)

CSRCS += $(wildcard src/stack/hci/*.c)
CSRCS += $(wildcard src/stack/l2cap/*.c)

CSRCS += $(wildcard src/stack/avdtp/*.c)
CSRCS += $(wildcard src/stack/avctp/*.c)
CSRCS += $(wildcard src/stack/avrcp/*.c)

CSRCS += $(wildcard src/stack/a2dp/*.c)
CSRCS += $(wildcard src/stack/a2dputil/*.c)
CSRCS += $(wildcard src/stack/sbc/*.c)

CSRCS += $(wildcard src/stack/sco/*.c)

CSRCS += $(wildcard src/stack/sdp/*.c)
CSRCS += $(wildcard src/stack/sdap/*.c)

CSRCS += $(wildcard src/stack/gap/*.c)

CSRCS += $(wildcard src/stack/ots/*.c)
CSRCS += $(wildcard src/samples/stack_adapter/src/*.c)

ifeq ($(CONFIG_LE),y)
  CSRCS += $(wildcard src/stack/att/*.c)
  CSRCS += $(wildcard src/stack/smp/*.c)

  ifeq ($(CONFIG_LE_AUDIO),y)
    CSRCS += $(wildcard src/stack/le_audio/*.c)
  endif
endif

ifeq ($(CONFIG_HID),y)
  CSRCS  += $(wildcard src/stack/hid/*.c)
  CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/hid}
endif

ifeq ($(CONFIG_RFCOMM),y)
  CSRCS  += $(wildcard src/stack/rfcomm/*.c)
  CSRCS  += $(wildcard src/stack/spp/*.c)
  CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/rfcomm}
endif

ifeq ($(CONFIG_OBEX),y)
  CSRCS += $(wildcard src/stack/obex/*.c)

  ifeq ($(CONFIG_MAP),y)
    CSRCS += $(wildcard src/stack/map/*.c)
  endif
  ifeq ($(CONFIG_BIP),y)
    CSRCS += $(wildcard src/stack/bip/*.c)
  endif
  ifeq ($(CONFIG_PBAP),y)
    CSRCS += $(wildcard src/stack/pbap/*.c)
  endif
endif

ifeq ($(CONFIG_HFP),y)
  CSRCS += $(wildcard src/stack/hfp/*.c)
endif

ifeq ($(CONFIG_BNEP), y)
  CSRCS += $(wildcard src/stack/bnep/*.c)
endif

ifeq ($(CONFIG_PAN), y)
  CSRCS += $(wildcard src/stack/pan/*.c)
endif

CSRCS += $(wildcard src/stack/xmlparse/*.c)

ifeq ($(CONFIG_BLUELET_HCI_H4),y)
  CSRCS += src/stack/portings/btunix/h4tl.c
endif

ifeq ($(CONFIG_BLUELET_A2DP_SINK_NUTTX),y)
  CSRCS += src/stack/portings/btunix/samples/a2dp_sink_nuttx.c
endif

CSRCS += src/stack/portings/btunix/unixdep.c

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/portings/btunix}

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/*/}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/btsoc/include}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/btsoc/include/avnet}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/btsoc/include/alcatel}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/btsoc/include/nsc}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/btsoc/include/stm}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/stack/btsoc/include/siw}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/samples/stack_adapter/inc}

CFLAGS += -Wno-pointer-sign -Wno-format -Wno-unused-variable -Wno-return-type
CFLAGS += -Wno-unused-value -Wno-unused-but-set-variable -Wno-strict-prototypes
CFLAGS += -Wno-int-to-pointer-cast -Wno-comment -Wno-parentheses -Wno-unused-function
CFLAGS += -Wno-incompatible-pointer-types -Wno-trigraphs -Wno-undef -Wno-implicit-int
CFLAGS += -Wno-shadow -Wno-sequence-point -Wno-stringop-overflow

TARGET_PATH = $(APPDIR)/vendor/xiaomi/vela/bluelet
$(shell cd $(APPDIR)/vendor/xiaomi/vela/ && mkdir -p bluelet &&  \
                         cd bluelet  && mkdir -p boards )
$(shell cp -rf src/samples/stack_adapter/inc  $(TARGET_PATH))

ifeq ($(CONFIG_ARCH_SIM),y)
  $(shell cd $(TARGET_PATH)/boards && mkdir -p sim)
  BUILD_PATH =  $(TARGET_PATH)/boards/sim
else
  $(shell cd $(TARGET_PATH)/boards && mkdir -p $(CONFIG_ARCH_CHIP_CUSTOM_NAME))
  BUILD_PATH =  $(TARGET_PATH)/boards/$(CONFIG_ARCH_CHIP_CUSTOM_NAME)
endif

ifeq ($(CONFIG_SIM_ASAN),y)
  BIN   = $(BUILD_PATH)/libbluelet_asan$(LIBEXT)
else
  BIN   = $(BUILD_PATH)/libbluelet$(LIBEXT)
endif

ifeq ($(CONFIG_BLUELET_EXAMPLES),y)

  CSRCS     += src/stack/portings/btunix/a2dputil_dep.c

  PROGNAME  += bluelet
  PRIORITY   = $(CONFIG_BLUELET_EXAMPLES_PRIORITY)
  STACKSIZE  = $(CONFIG_BLUELET_EXAMPLES_STACKSIZE)
  MODULE     = $(CONFIG_LIB_BLUELET)
  MAINSRC   += src/stack/portings/btunix/samples/bluelet.c

  PROGNAME  += bl_sink
  MAINSRC   += src/stack/portings/btunix/samples/a2dp_sink.c

depend::
	$(Q) touch $(MAINSRC)
else
  CSRCS     += src/stack/portings/btunix/a2dputil_dep.c
endif

include $(APPDIR)/Application.mk
