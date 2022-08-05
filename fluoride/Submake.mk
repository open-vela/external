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

CXXEXT = .cc

CXXSRCS += audio_a2dp_hw/src/audio_a2dp_hw_utils.cc
CXXSRCS += $(wildcard bta/ag/*.cc)
CXXSRCS += $(wildcard bta/ar/*.cc)
CXXSRCS += $(wildcard bta/av/*.cc)
CXXSRCS += $(wildcard bta/dm/*.cc)
CXXSRCS += $(wildcard bta/gatt/*.cc)
ifeq ($(CONFIG_BTA_HD_INCLUDED),y)
  CXXSRCS += $(wildcard bta/hd/*.cc)
endif
CXXSRCS += $(wildcard bta/hf_client/*.cc)
ifeq ($(CONFIG_BTA_HH_INCLUDED),y)
  CXXSRCS += $(wildcard bta/hh/*.cc)
endif
CXXSRCS += $(wildcard bta/jv/*.cc)
ifeq ($(CONFIG_PAN_INCLUDED),y)
CXXSRCS += $(wildcard bta/pan/*.cc)
endif
CXXSRCS += $(wildcard bta/sdp/*.cc)
CXXSRCS += $(wildcard bta/sys/*.cc)
CXXSRCS += $(wildcard btcore/src/*.cc)
ifeq ($(CONFIG_AVRCP_SERVICE),y)
  CXXSRCS += $(wildcard btif/avrcp/*.cc)
endif
CXXSRCS += $(wildcard btif/co/*.cc)
CXXSRCS += $(wildcard btif/src/*.cc)
CXXSRCS += common/address_obfuscator.cc
CXXSRCS += common/message_loop_thread.cc
CXXSRCS += common/metric_id_allocator.cc
CXXSRCS += common/metrics_linux.cc
CXXSRCS += common/once_timer.cc
CXXSRCS += common/repeating_timer.cc
CXXSRCS += common/time_util.cc
CXXSRCS += $(wildcard device/src/*.cc)
CXXSRCS += $(wildcard embdrv/g722/*.cc)
CXXSRCS += $(wildcard hci/src/*.cc)
CXXSRCS += $(wildcard main/*.cc)
CXXSRCS += osi/src/alarm.cc
CXXSRCS += osi/src/allocation_tracker.cc
CXXSRCS += osi/src/config.cc
CXXSRCS += osi/src/fixed_queue.cc
CXXSRCS += osi/src/future.cc
CXXSRCS += osi/src/list.cc
CXXSRCS += osi/src/mutex.cc
CXXSRCS += osi/src/osi.cc
CXXSRCS += osi/src/properties.cc
CXXSRCS += osi/src/reactor.cc
CXXSRCS += osi/src/ringbuffer.cc
CXXSRCS += osi/src/semaphore.cc
CXXSRCS += osi/src/socket_utils/socket_local_client.cc
CXXSRCS += osi/src/socket_utils/socket_local_server.cc
CXXSRCS += osi/src/socket.cc
CXXSRCS += osi/src/thread.cc
CXXSRCS += osi/src/wakelock.cc
ifeq ($(CONFIG_AVRCP_SERVICE),y)
  CXXSRCS += $(wildcard packet/avrcp/*.cc)
  CXXSRCS += $(wildcard profile/avrcp/*.cc)
endif
CXXSRCS += $(wildcard packet/base/*.cc)
CXXSRCS += stack/a2dp/a2dp_api.cc
CXXSRCS += stack/a2dp/a2dp_codec_config.cc
CXXSRCS += stack/a2dp/a2dp_sbc.cc
CXXSRCS += stack/a2dp/a2dp_sbc_decoder.cc
CXXSRCS += stack/a2dp/a2dp_sbc_encoder.cc
CXXSRCS += stack/a2dp/a2dp_sbc_up_sample.cc
CXXSRCS += stack/a2dp/a2dp_vendor.cc
CXXSRCS += $(wildcard stack/acl/*.cc)
CXXSRCS += $(wildcard stack/avct/*.cc)
CXXSRCS += $(wildcard stack/avdt/*.cc)
CXXSRCS += $(wildcard stack/avrc/*.cc)
ifeq ($(CONFIG_BNEP_INCLUDED),y)
CXXSRCS += $(wildcard stack/bnep/*.cc)
endif
CXXSRCS += $(wildcard stack/btm/*.cc)
CXXSRCS += $(wildcard stack/btu/*.cc)
CXXSRCS += $(wildcard stack/crypto_toolbox/*.cc)
CXXSRCS += $(wildcard stack/eatt/*.cc)
CXXSRCS += $(wildcard stack/gap/*.cc)
CXXSRCS += $(wildcard stack/gatt/*.cc)
CXXSRCS += $(wildcard stack/hcic/*.cc)
CXXSRCS += $(wildcard stack/hid/*.cc)
CXXSRCS += $(wildcard stack/l2cap/*.cc)
CXXSRCS += $(wildcard stack/pan/*.cc)
CXXSRCS += $(wildcard stack/rfcomm/*.cc)
CXXSRCS += $(wildcard stack/sdp/*.cc)
CXXSRCS += $(wildcard stack/smp/*.cc)
CXXSRCS += $(wildcard stack/srvc/*.cc)
CXXSRCS += types/bluetooth/uuid.cc
CXXSRCS += types/raw_address.cc
CXXSRCS += udrv/ulinux/uipc.cc
CXXSRCS += utils/src/bt_utils.cc

ifeq ($(CONFIG_BTA_HEARING_AID_INCLUDED),y)
  CXXSRCS += bta/hearing_aid/hearing_aid.cc
  CXXSRCS += audio_hearing_aid_hw/src/audio_hearing_aid_hw_utils.cc
endif

PORTCXXSRCS += port/stack/bt_types.cc
PORTCXXSRCS += port/audio_hal_interface/a2dp_encoding.cc
PORTCXXSRCS += port/bta/hearing_aid/hearing_aid_audio_source.cc
PORTCXXSRCS += port/btcore/src/module.cc
PORTCXXSRCS += port/common/metrics.cc
PORTCXXSRCS += port/gd/common/init_flags.cc
PORTCXXSRCS += port/hci/src/btsnoop_net.cc
PORTCXXSRCS += port/osi/src/allocator.cc
PORTCXXSRCS += port/btif/co/bta_hh_co.cc
PORTCXXSRCS += port/btif/src/btif_bqr.cc
PORTCXXSRCS += port/btif/src/btif_debug_btsnoop.cc
PORTCXXSRCS += port/btif/src/btif_debug_conn.cc
PORTCXXSRCS += port/btif/src/btif_keystore.cc
PORTCXXSRCS += port/btif/src/btif_pan.cc
PORTCXXSRCS += port/btif/src/btif_uid.cc
PORTCXXSRCS += $(wildcard port/main/shim/*.cc)

ifeq ($(CONFIG_FLUORIDE_HCI_H4),y)
  PORTCXXSRCS += port/hci/src/hci_layer_h4.cc
endif

ifeq ($(CONFIG_FLUORIDE_HCI_USB),y)
  PORTCXXSRCS += port/hci/src/hci_layer_libusb.cc
endif

ifeq ($(CONFIG_FLUORIDE_A2DP_SINK_NUTTX),y)
   PORTCXXSRCS += port/btif/src/btif_avrcp_audio_track_nuttx.cc
endif

CXXSRCS += $(PORTCXXSRCS)

ifeq ($(CONFIG_AUDIO),y)
  PORTCXXSRCS += btif/src/btif_avrcp_audio_track_linux.cc
endif
ifeq ($(CONFIG_BTA_AV_SINK_INCLUDED),)
  PORTCXXSRCS += btif/src/btif_a2dp_sink.cc
endif
PORTCXXSRCS += btif/src/btif_avrcp_audio_track.cc
PORTCXXSRCS += btif/src/btif_a2dp_audio_interface.cc
PORTCXXSRCS += hci/src/hci_layer_android.cc
PORTCXXSRCS += hci/src/hci_layer_linux.cc

CXXSRCS := $(filter-out $(subst port/,,$(PORTCXXSRCS)), $(CXXSRCS))

FLRDFLAGS += "-DEXPORT_SYMBOL=__attribute__((visibility(\"default\")))" -DOS_POSIX -D_POSIX_MONOTONIC_CLOCK=1 -DNDEBUG
FLRDFLAGS += -Wno-undef -Wno-shadow -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-value
FLRDFLAGS += -D_GNU_SOURCE -DFALLTHROUGH_INTENDED -DOS_GENERIC -fno-exceptions -DHAS_BDROID_BUILDCFG

ifeq ($(CONFIG_ARCH_SIM),y)
  FLRDFLAGS += -O2 -fno-strict-aliasing
  FLRDFLAGS += -ffunction-sections -fdata-sections
endif

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" port}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" port/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" bta/sys}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" utils/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" internal_include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" types}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" service}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" service/common}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" btif/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" bta/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" hci/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" linux_include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" btcore/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" btif/avrcp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/btm}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" bta}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" bta/gatt}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" bta/hh}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" bta/dm}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" udrv/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" device/include}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/avct}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/eatt}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/l2cap}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/gatt}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" stack/sdp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" vnd/ble}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" gd}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" gd/dumpsys}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" audio_a2dp_hw/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" audio_hearing_aid_hw/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" profile/avrcp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" packet/avrcp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" vnd/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" audio_hal_interface}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" android}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" embdrv/sbc/decoder/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" embdrv/sbc/encoder/include}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libchrome/libchrome}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libchrome/libchrome/nuttx}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/tinyxml2/tinyxml2}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/modp_b64/modp_b64}

ifneq ($(CONFIG_KVDB),)
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/frameworks/kvdb}
endif

ifeq ($(CONFIG_ARCH_SIM),)
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" port/deprecated}
endif

ifneq ($(CONFIG_CODEC_SBC),)
CSRCS += $(wildcard embdrv/sbc/*/srce/*.c)
endif

  CXXSRCS += stack/a2dp/a2dp_aac.cc
  CXXSRCS += stack/a2dp/a2dp_aac_decoder.cc
  CXXSRCS += stack/a2dp/a2dp_aac_encoder.cc
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libAACdec/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libAACenc/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libFDK/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libSYS/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libSBRdec/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libMpegTPDec/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libPCMutils/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libArithCoding/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libDRCdec/include}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libSACdec/include}

ifneq ($(CONFIG_CODEC_LDAC),)
  CXXSRCS += stack/a2dp/a2dp_vendor_ldac.cc

  CXXSRCS += port/stack/a2dp/a2dp_vendor_ldac_decoder.cc
  CXXSRCS += port/stack/a2dp/a2dp_vendor_ldac_encoder.cc
  CXXSRCS += port/stack/a2dp/a2dp_vendor_ldac_abr.cc

  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libldac/libldac/inc}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libldac/libldac/src}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libldac/libldac/abr/inc}
endif

ifneq ($(CONFIG_CODEC_APTX),)
  CXXSRCS += stack/a2dp/a2dp_vendor_aptx.cc
  CXXSRCS += stack/a2dp/a2dp_vendor_aptx_encoder.cc
  CXXSRCS += stack/a2dp/a2dp_vendor_aptx_hd.cc
  CXXSRCS += stack/a2dp/a2dp_vendor_aptx_hd_encoder.cc
endif

CXXFLAGS += $(FLRDFLAGS) -fpermissive -std=c++17
CFLAGS   += $(FLRDFLAGS)

ifneq ($(CONFIG_FLUORIDE_EXAMPLES),)

  PRIORITY  = SCHED_PRIORITY_DEFAULT
  STACKSIZE = $(CONFIG_FLUORIDE_EXAMPLES_STACKSIZE)
  MODULE    = $(CONFIG_FLUORIDE_EXAMPLES)

  CXXSRCS  += port/examples/a2dp.cc
  CXXSRCS  += port/examples/avrcp.cc
  CXXSRCS  += port/examples/avrcpc.cc
ifeq ($(CONFIG_AVRCP_SERVICE),y)
  CXXSRCS  += port/examples/avrcs.cc
endif
  CXXSRCS  += port/examples/hfp.cc
  CXXSRCS  += port/examples/interface.cc
  CXXSRCS  += port/examples/sdp.cc
ifeq ($(CONFIG_FLUORIDE_EXAMPLES_RFCOMM),y)
  CXXSRCS  += port/examples/socket.cc
endif
  CXXSRCS  += port/examples/shell.cc
ifeq ($(CONFIG_BTA_HD_INCLUDED),y)
  CXXSRCS  += port/examples/hidd.cc
endif
ifneq ($(CONFIG_FLUORIDE_BLE_ENABLED),)
  CXXSRCS  += port/examples/gatt.cc
  CXXSRCS  += port/examples/gap.cc
  CSRCS    += port/examples/uuid.c
endif

  PROGNAME += fluorided
  MAINSRC  += port/examples/fluoride.cc

  PROGNAME += bta
  MAINSRC  += port/examples/bta.cc

ifneq ($(CONFIG_FLUORIDE_BLE_ENABLED),)
  PROGNAME += ble
  MAINSRC  += port/examples/ble.cc
endif

endif

depend::
	$(Q) ln -sf fluoride.cc port/examples/bta.cc
	$(Q) ln -sf fluoride.cc port/examples/ble.cc

include $(APPDIR)/Application.mk
