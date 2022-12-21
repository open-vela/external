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

BIN := $(APPDIR)/staging/libexternal.a

SBINDIR   := $(BINDIR)
SINCDIR   := $(INCDIR)
SAR       := $(AR)
-include ffmpeg/ffbuild/config.mak
BINDIR    := $(SBINDIR)
INCDIR    := $(SINCDIR)
AR        := $(SAR)

CSRCS     :=
ASRCS     :=
SRC_PATH  := ffmpeg

CFG_ARCH  := $(CONFIG_ARCH)
ifeq ($(CONFIG_ARCH),avr)
  CFG_ARCH = avr32
endif

ifneq ($(CONFIG_ARCH),sim)
  CFG_CMDS += --arch=$(CFG_ARCH) --target-os=none
  CFG_CMDS += --enable-cross-compile --cross-prefix=$(CROSSDEV)
  CFG_CMDS += --cc=$(CC)
endif

ifneq ($(CONFIG_CRYPTO_MBEDTLS),)
  CFG_CMDS += --enable-mbedtls
endif

ifeq ($(CONFIG_ARM_NEON),)
  CFG_CMDS += --disable-neon
endif

FFLIBS-yes                  += avutil
FFLIBS-$(CONFIG_AVCODEC)    += avcodec
FFLIBS-$(CONFIG_AVDEVICE)   += avdevice
FFLIBS-$(CONFIG_AVFILTER)   += avfilter
FFLIBS-$(CONFIG_AVFORMAT)   += avformat
FFLIBS-$(CONFIG_AVRESAMPLE) += avresample
FFLIBS-$(CONFIG_POSTPROC)   += postproc
FFLIBS-$(CONFIG_SWRESAMPLE) += swresample
FFLIBS-$(CONFIG_SWSCALE)    += swscale

# ignore share objects in gathering phase to avoid link error
SHLIBOBJS := ac3_channel_layout_tab.o to_upper4.o

define DOSUBDIR
  OBJS     :=
  OBJS-yes :=
  include $(SRC_PATH)/$(1)/Makefile
  -include $(SRC_PATH)/$(1)/$$(ARCH)/Makefile
  include $(SRC_PATH)/ffbuild/arch.mak
  SOBJS := $$(filter-out $$(SHLIBOBJS), $$(OBJS) $$(OBJS-yes))
  SOBJS := $$(sort $$(addprefix $(SRC_PATH)/$(1)/, $$(SOBJS)))
  CSRCS += $$(wildcard $$(patsubst %.o,%.c, $$(SOBJS)))
  ASRCS += $$(wildcard $$(patsubst %.o,%.S, $$(SOBJS)))
endef

$(foreach D,$(FFLIBS-yes),$(eval $(call DOSUBDIR,lib$(D))))

PRIORITY  = $(CONFIG_LIB_FFMPEG_TOOLS_PRIORITY)
STACKSIZE = $(CONFIG_LIB_FFMPEG_TOOLS_STACKSIZE)
MODULE    = $(CONFIG_LIB_FFMPEG)
CSRCS    += $(SRC_PATH)/fftools/cmdutils.c
CSRCS    += $(SRC_PATH)/fftools/opt_common.c
CSRCS    += $(SRC_PATH)/libavformat/ac3_channel_layout_tab.c
CSRCS    += $(SRC_PATH)/libavformat/to_upper4.c

ifeq ($(CONFIG_FFMPEG),yes)
  PROGNAME += ffmpeg
  MAINSRC  += $(SRC_PATH)/fftools/ffmpeg.c
  CSRCS    += $(SRC_PATH)/fftools/ffmpeg_opt.c
  CSRCS    += $(SRC_PATH)/fftools/ffmpeg_filter.c
  CSRCS    += $(SRC_PATH)/fftools/ffmpeg_hw.c
  CSRCS    += $(SRC_PATH)/fftools/ffmpeg_mux.c
endif

ifeq ($(CONFIG_FFPROBE),yes)
  PROGNAME += ffprobe
  MAINSRC  += $(SRC_PATH)/fftools/ffprobe.c
endif

ifneq ($(CONFIG_FFMPEG_TOOLS_GRAPH2DOT),)
  PROGNAME += graph2dot
  MAINSRC  += $(SRC_PATH)/tools/graph2dot.c
endif

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(SRC_PATH)}

ifeq ($(CONFIG_CODEC_FDKAAC), y)
CFLAGS += -DAACENCODER_LIB_VL0=4 -DAACENCODER_LIB_VL1=0
endif

ifeq ($(CONFIG_LIB_FLUORIDE_SBC), y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libfluoride-sbc/libfluoride-sbc/decoder/include}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libfluoride-sbc/libfluoride-sbc/encoder/include}
endif

ifeq ($(CONFIG_LIB_HELIX_AAC),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libhelix-aac/libhelix-aac}
endif
ifeq ($(CONFIG_LIB_HELIX_MP3),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libhelix-mp3/libhelix-mp3/pub}
endif

ifeq ($(CONFIG_LIB_SILK),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/silk-v3-decoder/silk-v3-decoder/silk/interface}
endif

ifeq ($(CONFIG_LIB_ZLIB),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/zlib/zlib}
endif

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/vendor/bes/framework/services_hifi4/services/multimedia/audio/smf/core/inc}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/vendor/xiaomi/miwear/xiaomi_enc}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/vendor/xiaomi/miwear/bes_aec}

ifeq ($(MAKECMDGOALS), context)
CFLAGS += -Wno-error
endif

CFLAGS += -Wno-shift-count-overflow -Wno-implicit-int-float-conversion -Wno-shadow
CFLAGS += -Wno-missing-braces
CFLAGS += $(CFLAGS_HEADERS) -DHAVE_AV_CONFIG_H -DZLIB_CONST

EXTRA := $(CFLAGS)

$(SRC_PATH)/libavutil/ffversion.h:
	$(Q)cd $(SRC_PATH) && ./ffbuild/version.sh . libavutil/ffversion.h $(EXTRA_VERSION)

$(SRC_PATH)/ffbuild/config.mak:
	$(Q) echo "FFMPEG configure... $(CONFIG_ARCH)"
	$(Q)cd $(SRC_PATH) && ./configure --disable-all             \
		--disable-everything    --disable-autodetect            \
		--disable-amf           --disable-audiotoolbox          \
		--disable-cuda-llvm     --disable-cuvid                 \
		--disable-d3d11va       --disable-doc                   \
		--disable-dwt           --disable-dxva2                 \
		--disable-dxva2         --disable-error-resilience      \
		--disable-faan          --disable-ffnvcodec             \
		--disable-htmlpages     --disable-iconv                 \
		--disable-lsp           --disable-threads               \
		--disable-manpages      --disable-pic                   \
		--disable-pixelutils    --disable-podpages              \
		--disable-nvdec         --disable-nvenc                 \
		--disable-txtpages      --disable-v4l2-m2m              \
		--disable-vaapi         --disable-vdpau                 \
		--disable-videotoolbox  --disable-x86asm                \
		--disable-xop                                           \
		--enable-version3       --enable-small                  \
		--extra-cflags="$(EXTRA)" --extra-ldflags="$(EXTRA)"    \
		--ld=echo --pkg-config=false assert_level=3 $(CFG_CMDS) \
		"$(CONFIG_LIB_FFMPEG_CONFIGURATION)"

context:: $(SRC_PATH)/ffbuild/config.mak $(SRC_PATH)/libavutil/ffversion.h

distclean::
	rm -f $(SRC_PATH)/config.h $(SRC_PATH)/config_components.h $(SRC_PATH)/.version
	rm -f $(SRC_PATH)/ffbuild/.config $(SRC_PATH)/ffbuild/config*
	rm -f $(SRC_PATH)/libavutil/avconfig.h  $(SRC_PATH)/libavutil/ffversion.h
	find ./ -name "*_list.c" | xargs rm -f

include $(APPDIR)/Application.mk
