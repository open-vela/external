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

subdir := $(notdir $(CURDIR))
ifneq ($(wildcard $(CURDIR)/$(subdir)),)
STACKDIR 	 := $(subdir)/src/stack
ADAPTERDIR := $(subdir)/src/samples/stack_adapter

CSRCS += $(wildcard $(STACKDIR)/btcommon/*.c)
CSRCS += $(wildcard $(STACKDIR)/bluelet/*.c)

CSRCS += $(wildcard $(STACKDIR)/hci/*.c)
CSRCS += $(wildcard $(STACKDIR)/l2cap/*.c)

CSRCS += $(wildcard $(STACKDIR)/avdtp/*.c)
CSRCS += $(wildcard $(STACKDIR)/avctp/*.c)
CSRCS += $(wildcard $(STACKDIR)/avrcp/*.c)

CSRCS += $(wildcard $(STACKDIR)/a2dp/*.c)
CSRCS += $(wildcard $(STACKDIR)/a2dputil/*.c)
CSRCS += $(wildcard $(STACKDIR)/sbc/*.c)

CSRCS += $(wildcard $(STACKDIR)/sco/*.c)

CSRCS += $(wildcard $(STACKDIR)/sdp/*.c)
CSRCS += $(wildcard $(STACKDIR)/sdap/*.c)

CSRCS += $(wildcard $(STACKDIR)/gap/*.c)

CSRCS += $(wildcard $(STACKDIR)/ots/*.c)
CSRCS += $(wildcard $(ADAPTERDIR)/src/*.c)

ifeq ($(CONFIG_LE),y)
  CSRCS += $(wildcard $(STACKDIR)/att/*.c)
  CSRCS += $(wildcard $(STACKDIR)/smp/*.c)

  ifeq ($(CONFIG_LE_AUDIO),y)
    CSRCS += $(wildcard $(STACKDIR)/le_audio/*.c)
  endif
endif

ifeq ($(CONFIG_HID),y)
  CSRCS  += $(wildcard $(STACKDIR)/hid/*.c)
  CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/hid
endif

ifeq ($(CONFIG_RFCOMM),y)
  CSRCS  += $(wildcard $(STACKDIR)/rfcomm/*.c)
  CSRCS  += $(wildcard $(STACKDIR)/spp/*.c)
  CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/rfcomm
endif

ifeq ($(CONFIG_OBEX),y)
  CSRCS += $(wildcard $(STACKDIR)/obex/*.c)

  ifeq ($(CONFIG_MAP),y)
    CSRCS += $(wildcard $(STACKDIR)/map/*.c)
  endif
  ifeq ($(CONFIG_BIP),y)
    CSRCS += $(wildcard $(STACKDIR)/bip/*.c)
  endif
  ifeq ($(CONFIG_PBAP),y)
    CSRCS += $(wildcard $(STACKDIR)/pbap/*.c)
  endif
endif

ifeq ($(CONFIG_HFP),y)
  CSRCS += $(wildcard $(STACKDIR)/hfp/*.c)
endif

ifeq ($(CONFIG_BNEP), y)
  CSRCS += $(wildcard $(STACKDIR)/bnep/*.c)
endif

ifeq ($(CONFIG_PAN), y)
  CSRCS += $(wildcard $(STACKDIR)/pan/*.c)
endif

ifeq ($(CONFIG_BLUELET_HCI_H4),y)
  CSRCS += $(STACKDIR)/portings/btunix/h4tl.c
endif

ifeq ($(CONFIG_BLUELET_A2DP_SINK_NUTTX),y)
  CSRCS += $(STACKDIR)/portings/btunix/samples/a2dp_sink_nuttx.c
endif

CSRCS += $(STACKDIR)/portings/btunix/unixdep.c

CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/avctp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/sco
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/map
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/rfcomm
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/smp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/sdap
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/include
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/gap
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/hid
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/xmlparse
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/avdtp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/ots
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/sdp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/pan
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/pbap
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/sbc
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/obex
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/l2cap
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/spp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/le_audio
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/avrcp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/bip
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/a2dp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/hfp
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/hci
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/bnep
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/portings/btunix
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/btsoc/include
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/btsoc/include/avnet
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/btsoc/include/alcatel
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/btsoc/include/nsc
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/btsoc/include/stm
CFLAGS += ${INCDIR_PREFIX}$(STACKDIR)/btsoc/include/siw
CFLAGS += ${INCDIR_PREFIX}$(ADAPTERDIR)/inc

CFLAGS += -Wno-pointer-sign -Wno-format -Wno-unused-variable -Wno-return-type
CFLAGS += -Wno-unused-value -Wno-unused-but-set-variable -Wno-strict-prototypes
CFLAGS += -Wno-int-to-pointer-cast -Wno-comment -Wno-parentheses -Wno-unused-function
CFLAGS += -Wno-incompatible-pointer-types -Wno-trigraphs -Wno-undef -Wno-implicit-int
CFLAGS += -Wno-shadow -Wno-sequence-point -Wno-stringop-overflow

ifeq ($(CONFIG_BLUELET_EXAMPLES),y)

  CSRCS     += $(STACKDIR)/portings/btunix/a2dputil_dep.c

  PRIORITY   = $(CONFIG_BLUELET_EXAMPLES_PRIORITY)
  STACKSIZE  = $(CONFIG_BLUELET_EXAMPLES_STACKSIZE)
  MODULE     = $(CONFIG_LIB_BLUELET)

  PROGNAME  += leaudio_broadcast_src
  MAINSRC   += $(STACKDIR)/portings/btunix/samples/leaudio_broadcast_src.c

  PROGNAME  += leaudio_broadcast_snk
  MAINSRC   += $(STACKDIR)/portings/btunix/samples/leaudio_broadcast_snk.c

depend::
	$(Q) touch $(MAINSRC)
else
  CSRCS     += $(STACKDIR)/portings/btunix/a2dputil_dep.c
endif

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libbluelet.a
endif

EXPORT_FILES := bluelet/src/samples/stack_adapter/inc
endif
include $(APPDIR)/Application.mk
