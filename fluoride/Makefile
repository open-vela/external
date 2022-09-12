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

CXXSRCS += fluoride/audio_a2dp_hw/src/audio_a2dp_hw_utils.cc
CXXSRCS += $(wildcard fluoride/bta/ag/*.cc)
CXXSRCS += $(wildcard fluoride/bta/ar/*.cc)
CXXSRCS += $(wildcard fluoride/bta/av/*.cc)
CXXSRCS += $(wildcard fluoride/bta/dm/*.cc)
CXXSRCS += $(wildcard fluoride/bta/gatt/*.cc)
ifeq ($(CONFIG_BTA_HD_INCLUDED),y)
  CXXSRCS += $(wildcard fluoride/bta/hd/*.cc)
endif
CXXSRCS += $(wildcard fluoride/bta/hf_client/*.cc)
ifeq ($(CONFIG_BTA_HH_INCLUDED),y)
  CXXSRCS += $(wildcard fluoride/bta/hh/*.cc)
endif
CXXSRCS += $(wildcard fluoride/bta/jv/*.cc)
ifeq ($(CONFIG_PAN_INCLUDED),y)
CXXSRCS += $(wildcard fluoride/bta/pan/*.cc)
endif
CXXSRCS += $(wildcard fluoride/bta/sdp/*.cc)
CXXSRCS += $(wildcard fluoride/bta/sys/*.cc)
CXXSRCS += $(wildcard fluoride/btcore/src/*.cc)
ifeq ($(CONFIG_AVRCP_SERVICE),y)
  CXXSRCS += $(wildcard fluoride/btif/avrcp/*.cc)
endif
CXXSRCS += $(wildcard fluoride/btif/co/*.cc)
CXXSRCS += $(wildcard fluoride/btif/src/*.cc)
CXXSRCS += fluoride/common/address_obfuscator.cc
CXXSRCS += fluoride/common/message_loop_thread.cc
CXXSRCS += fluoride/common/metric_id_allocator.cc
CXXSRCS += fluoride/common/metrics_linux.cc
CXXSRCS += fluoride/common/once_timer.cc
CXXSRCS += fluoride/common/repeating_timer.cc
CXXSRCS += fluoride/common/time_util.cc
CXXSRCS += $(wildcard fluoride/device/src/*.cc)
CXXSRCS += $(wildcard fluoride/embdrv/g722/*.cc)
CXXSRCS += $(wildcard fluoride/hci/src/*.cc)
CXXSRCS += $(wildcard fluoride/main/*.cc)
CXXSRCS += fluoride/osi/src/alarm.cc
CXXSRCS += fluoride/osi/src/allocation_tracker.cc
CXXSRCS += fluoride/osi/src/config.cc
CXXSRCS += fluoride/osi/src/fixed_queue.cc
CXXSRCS += fluoride/osi/src/future.cc
CXXSRCS += fluoride/osi/src/list.cc
CXXSRCS += fluoride/osi/src/mutex.cc
CXXSRCS += fluoride/osi/src/osi.cc
CXXSRCS += fluoride/osi/src/properties.cc
CXXSRCS += fluoride/osi/src/reactor.cc
CXXSRCS += fluoride/osi/src/ringbuffer.cc
CXXSRCS += fluoride/osi/src/semaphore.cc
CXXSRCS += fluoride/osi/src/socket_utils/socket_local_client.cc
CXXSRCS += fluoride/osi/src/socket_utils/socket_local_server.cc
CXXSRCS += fluoride/osi/src/socket.cc
CXXSRCS += fluoride/osi/src/thread.cc
CXXSRCS += fluoride/osi/src/wakelock.cc
ifeq ($(CONFIG_AVRCP_SERVICE),y)
  CXXSRCS += $(wildcard fluoride/packet/avrcp/*.cc)
  CXXSRCS += $(wildcard fluoride/profile/avrcp/*.cc)
endif
CXXSRCS += $(wildcard fluoride/packet/base/*.cc)
CXXSRCS += fluoride/stack/a2dp/a2dp_api.cc
CXXSRCS += fluoride/stack/a2dp/a2dp_codec_config.cc
CXXSRCS += fluoride/stack/a2dp/a2dp_sbc.cc
CXXSRCS += fluoride/stack/a2dp/a2dp_sbc_decoder.cc
CXXSRCS += fluoride/stack/a2dp/a2dp_sbc_encoder.cc
CXXSRCS += fluoride/stack/a2dp/a2dp_sbc_up_sample.cc
CXXSRCS += fluoride/stack/a2dp/a2dp_vendor.cc
CXXSRCS += $(wildcard fluoride/stack/acl/*.cc)
CXXSRCS += $(wildcard fluoride/stack/avct/*.cc)
CXXSRCS += $(wildcard fluoride/stack/avdt/*.cc)
CXXSRCS += $(wildcard fluoride/stack/avrc/*.cc)
ifeq ($(CONFIG_BNEP_INCLUDED),y)
CXXSRCS += $(wildcard fluoride/stack/bnep/*.cc)
endif
CXXSRCS += $(wildcard fluoride/stack/btm/*.cc)
CXXSRCS += $(wildcard fluoride/stack/btu/*.cc)
CXXSRCS += $(wildcard fluoride/stack/crypto_toolbox/*.cc)
CXXSRCS += $(wildcard fluoride/stack/eatt/*.cc)
CXXSRCS += $(wildcard fluoride/stack/gap/*.cc)
CXXSRCS += $(wildcard fluoride/stack/gatt/*.cc)
CXXSRCS += $(wildcard fluoride/stack/hcic/*.cc)
CXXSRCS += $(wildcard fluoride/stack/hid/*.cc)
CXXSRCS += $(wildcard fluoride/stack/l2cap/*.cc)
CXXSRCS += $(wildcard fluoride/stack/pan/*.cc)
CXXSRCS += $(wildcard fluoride/stack/rfcomm/*.cc)
CXXSRCS += $(wildcard fluoride/stack/sdp/*.cc)
CXXSRCS += $(wildcard fluoride/stack/smp/*.cc)
CXXSRCS += $(wildcard fluoride/stack/srvc/*.cc)
CXXSRCS += fluoride/types/bluetooth/uuid.cc
CXXSRCS += fluoride/types/raw_address.cc
CXXSRCS += fluoride/udrv/ulinux/uipc.cc
CXXSRCS += fluoride/utils/src/bt_utils.cc

ifeq ($(CONFIG_BTA_HEARING_AID_INCLUDED),y)
  CXXSRCS += fluoride/bta/hearing_aid/hearing_aid.cc
  CXXSRCS += fluoride/audio_hearing_aid_hw/src/audio_hearing_aid_hw_utils.cc
endif

PORTCXXSRCS += fluoride/port/stack/bt_types.cc
PORTCXXSRCS += fluoride/port/audio_hal_interface/a2dp_encoding.cc
PORTCXXSRCS += fluoride/port/bta/hearing_aid/hearing_aid_audio_source.cc
PORTCXXSRCS += fluoride/port/btcore/src/module.cc
PORTCXXSRCS += fluoride/port/common/metrics.cc
PORTCXXSRCS += fluoride/port/gd/common/init_flags.cc
PORTCXXSRCS += fluoride/port/hci/src/btsnoop_net.cc
PORTCXXSRCS += fluoride/port/osi/src/allocator.cc
PORTCXXSRCS += fluoride/port/btif/co/bta_hh_co.cc
PORTCXXSRCS += fluoride/port/btif/src/btif_bqr.cc
PORTCXXSRCS += fluoride/port/btif/src/btif_debug_btsnoop.cc
PORTCXXSRCS += fluoride/port/btif/src/btif_debug_conn.cc
PORTCXXSRCS += fluoride/port/btif/src/btif_keystore.cc
PORTCXXSRCS += fluoride/port/btif/src/btif_pan.cc
PORTCXXSRCS += fluoride/port/btif/src/btif_uid.cc
PORTCXXSRCS += $(wildcard fluoride/port/main/shim/*.cc)

ifeq ($(CONFIG_FLUORIDE_HCI_H4),y)
  PORTCXXSRCS += fluoride/port/hci/src/hci_layer_h4.cc
endif

ifeq ($(CONFIG_FLUORIDE_HCI_USB),y)
  PORTCXXSRCS += fluoride/port/hci/src/hci_layer_libusb.cc
endif

ifeq ($(CONFIG_FLUORIDE_A2DP_SINK_NUTTX),y)
   PORTCXXSRCS += fluoride/port/btif/src/btif_avrcp_audio_track_nuttx.cc
endif

CXXSRCS += $(PORTCXXSRCS)

ifeq ($(CONFIG_AUDIO),y)
  PORTCXXSRCS += fluoride/btif/src/btif_avrcp_audio_track_linux.cc
endif
ifeq ($(CONFIG_BTA_AV_SINK_INCLUDED),)
  PORTCXXSRCS += fluoride/btif/src/btif_a2dp_sink.cc
endif
PORTCXXSRCS += fluoride/btif/src/btif_avrcp_audio_track.cc
PORTCXXSRCS += fluoride/btif/src/btif_a2dp_audio_interface.cc
PORTCXXSRCS += fluoride/hci/src/hci_layer_android.cc
PORTCXXSRCS += fluoride/hci/src/hci_layer_linux.cc

CXXSRCS := $(filter-out $(subst port/,,$(PORTCXXSRCS)), $(CXXSRCS))

FLRDFLAGS += "-DEXPORT_SYMBOL=__attribute__((visibility(\"default\")))" -DOS_POSIX -D_POSIX_MONOTONIC_CLOCK=1 -DNDEBUG
FLRDFLAGS += -Wno-undef -Wno-shadow -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-value
FLRDFLAGS += -D_GNU_SOURCE -DFALLTHROUGH_INTENDED -DOS_GENERIC -fno-exceptions -DHAS_BDROID_BUILDCFG

ifeq ($(CONFIG_ARCH_SIM),y)
  FLRDFLAGS += -O2 -fno-strict-aliasing
  FLRDFLAGS += -ffunction-sections -fdata-sections
endif

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/port}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/port/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/.}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/bta/sys}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/utils/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/internal_include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/types}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/service}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/service/common}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/btif/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/bta/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/hci/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/linux_include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/btcore/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/btif/avrcp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/btm}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/bta}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/bta/gatt}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/bta/hh}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/bta/dm}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/udrv/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/device/include}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/avct}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/eatt}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/l2cap}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/gatt}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/stack/sdp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/vnd/ble}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/gd}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/gd/dumpsys}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/audio_a2dp_hw/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/audio_hearing_aid_hw/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/profile/avrcp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/packet/avrcp}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/vnd/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/audio_hal_interface}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/android}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/embdrv/sbc/decoder/include}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/embdrv/sbc/encoder/include}

FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libchrome/libchrome}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libchrome/libchrome/nuttx}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/tinyxml2/tinyxml2}
FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/modp_b64/modp_b64}

ifneq ($(CONFIG_KVDB),)
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/frameworks/kvdb}
endif

ifeq ($(CONFIG_ARCH_SIM),)
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" fluoride/port/deprecated}
endif

ifneq ($(CONFIG_CODEC_SBC),)
CSRCS += $(wildcard fluoride/embdrv/sbc/*/srce/*.c)
endif

  CXXSRCS += fluoride/stack/a2dp/a2dp_aac.cc
  CXXSRCS += fluoride/stack/a2dp/a2dp_aac_decoder.cc
  CXXSRCS += fluoride/stack/a2dp/a2dp_aac_encoder.cc
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
  CXXSRCS += fluoride/stack/a2dp/a2dp_vendor_ldac.cc

  CXXSRCS += fluoride/port/stack/a2dp/a2dp_vendor_ldac_decoder.cc
  CXXSRCS += fluoride/port/stack/a2dp/a2dp_vendor_ldac_encoder.cc
  CXXSRCS += fluoride/port/stack/a2dp/a2dp_vendor_ldac_abr.cc

  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libldac/libldac/inc}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libldac/libldac/src}
  FLRDFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libldac/libldac/abr/inc}
endif

ifneq ($(CONFIG_CODEC_APTX),)
  CXXSRCS += fluoride/stack/a2dp/a2dp_vendor_aptx.cc
  CXXSRCS += fluoride/stack/a2dp/a2dp_vendor_aptx_encoder.cc
  CXXSRCS += fluoride/stack/a2dp/a2dp_vendor_aptx_hd.cc
  CXXSRCS += fluoride/stack/a2dp/a2dp_vendor_aptx_hd_encoder.cc
endif

CXXFLAGS += $(FLRDFLAGS) -fpermissive -std=c++17
CFLAGS   += $(FLRDFLAGS)

ifneq ($(CONFIG_FLUORIDE_EXAMPLES),)

  PRIORITY  = SCHED_PRIORITY_DEFAULT
  STACKSIZE = $(CONFIG_FLUORIDE_EXAMPLES_STACKSIZE)
  MODULE    = $(CONFIG_FLUORIDE_EXAMPLES)

  CXXSRCS  += fluoride/port/examples/a2dp.cc
  CXXSRCS  += fluoride/port/examples/avrcp.cc
  CXXSRCS  += fluoride/port/examples/avrcpc.cc
ifeq ($(CONFIG_AVRCP_SERVICE),y)
  CXXSRCS  += fluoride/port/examples/avrcs.cc
endif
  CXXSRCS  += fluoride/port/examples/hfp.cc
  CXXSRCS  += fluoride/port/examples/interface.cc
  CXXSRCS  += fluoride/port/examples/sdp.cc
ifeq ($(CONFIG_FLUORIDE_EXAMPLES_RFCOMM),y)
  CXXSRCS  += fluoride/port/examples/socket.cc
endif
  CXXSRCS  += fluoride/port/examples/shell.cc
ifeq ($(CONFIG_BTA_HD_INCLUDED),y)
  CXXSRCS  += fluoride/port/examples/hidd.cc
endif
ifneq ($(CONFIG_FLUORIDE_BLE_ENABLED),)
  CXXSRCS  += fluoride/port/examples/gatt.cc
  CXXSRCS  += fluoride/port/examples/gap.cc
  CSRCS    += fluoride/port/examples/uuid.c
endif

  PROGNAME += fluorided
  MAINSRC  += fluoride/port/examples/fluoride.cc

  PROGNAME += bta
  MAINSRC  += fluoride/port/examples/bta.cc

ifneq ($(CONFIG_FLUORIDE_BLE_ENABLED),)
  PROGNAME += ble
  MAINSRC  += fluoride/port/examples/ble.cc
endif

endif

depend::
	$(Q) ln -sf fluoride.cc fluoride/port/examples/bta.cc
	$(Q) ln -sf fluoride.cc fluoride/port/examples/ble.cc

include $(APPDIR)/Application.mk
