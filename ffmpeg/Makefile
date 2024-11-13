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
ifeq ($(DST_PATH),)
  include $(APPDIR)/Make.defs
  BIN := $(APPDIR)/staging/libffmpeg.a
  # configure in place
  DST_PATH := ffmpeg
else
  # configure out of tree
  DST_PATH = $(realpath $(DST_PATH))
  include $(DST_PATH)/Make.defs
  BIN := $(DST_PATH)/libffmpeg.a
  # enable Application.mk PREFIX
  PREFIX := $(DST_PATH)$(DELIM)
endif

FFMPEG_CONFIG_SCRIPT := $(CURDIR)$(DELIM)ffmpeg$(DELIM)configure
FFMPEG_VERSION_SCRIPT := $(CURDIR)$(DELIM)ffmpeg$(DELIM)ffbuild$(DELIM)version.sh

SBINDIR   := $(BINDIR)
SINCDIR   := $(INCDIR)
SAR       := $(AR)
-include $(DST_PATH)/ffbuild/config.mak
BINDIR    := $(SBINDIR)
INCDIR    := $(SINCDIR)
AR        := $(SAR)

CSRCS     :=
ASRCS     :=
NASRCS    :=
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

ifeq ($(CONFIG_ARM_NEON)$(CONFIG_ARM64_NEON),)
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
  OBJS            :=
  OBJS-yes        :=
  X86ASM-OBJS-yes :=
  include $(SRC_PATH)/$(1)/Makefile
  -include $(SRC_PATH)/$(1)/$$(ARCH)/Makefile
  ifeq ($(CONFIG_ARM_HAVE_NEON),y)
    -include $(SRC_PATH)/$(1)/neon/Makefile
  endif
  ifeq ($(CONFIG_ARM64_HAVE_NEON),y)
    -include $(SRC_PATH)/$(1)/neon/Makefile
  endif
  include $(SRC_PATH)/ffbuild/arch.mak
  SOBJS := $$(filter-out $$(SHLIBOBJS), $$(OBJS) $$(OBJS-yes) $$(X86ASM-OBJS-yes))
  SOBJS := $$(sort $$(addprefix $(SRC_PATH)/$(1)/, $$(SOBJS)))
  CSRCS += $$(wildcard $$(patsubst %.o,%.c, $$(SOBJS)))
  ASRCS += $$(wildcard $$(patsubst %.o,%.S, $$(SOBJS)))
  NASRCS += $$(wildcard $$(patsubst %.o,%.asm, $$(SOBJS)))
endef

$(foreach D,$(FFLIBS-yes),$(eval $(call DOSUBDIR,lib$(D))))

ifneq ($(NASRCS),)
NAFLAGS = -g -F dwarf -P$(DST_PATH)/config.asm
NAFLAGS += ${INCDIR_PREFIX}$(SRC_PATH)/
ifneq ($(wildcard $(SRC_PATH)/libavcodec/$(ARCH)),)
  NAFLAGS += ${INCDIR_PREFIX}$(SRC_PATH)/libavcodec/$(ARCH)
endif

ifeq ($(CONFIG_SIM_M32),y)
  NAFLAGS += -f elf32
else
  NAFLAGS += -f elf64
endif

NASUFFIX = $(subst $(DELIM),.,$(CURDIR))
EXTOBJS  = $(NASRCS:%=$(PREFIX)%$(NASUFFIX)$(OBJEXT))

$(EXTOBJS): $(PREFIX)%.asm$(NASUFFIX)$(OBJEXT): %.asm
	$(Q) nasm $(NAFLAGS) $< -o $@
	$(Q) strip -x $@
endif

PRIORITY  = $(CONFIG_UTILS_FFMPEG_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_FFMPEG_STACKSIZE)
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

ifneq ($(CONFIG_FFMPEG_UTILS_GRAPH2DOT),)
  PROGNAME += graph2dot
  MAINSRC  += $(SRC_PATH)/tools/graph2dot.c
endif

ifneq ($(CONFIG_LIB_FFMPEG_TEST),)
PROGNAME += ffmpeg_api_band
MAINSRC  += $(SRC_PATH)/tests/api/api-band-test.c
PROGNAME += ffmpeg_api_flac
MAINSRC  += $(SRC_PATH)/tests/api/api-flac-test.c
PROGNAME += ffmpeg_api_h264_slice
MAINSRC  += $(SRC_PATH)/tests/api/api-h264-slice-test.c
PROGNAME += ffmpeg_api_h264
MAINSRC  += $(SRC_PATH)/tests/api/api-h264-test.c
PROGNAME += ffmpeg_api_seek
MAINSRC  += $(SRC_PATH)/tests/api/api-seek-test.c
PROGNAME += ffmpeg_api_threadmessage
MAINSRC  += $(SRC_PATH)/tests/api/api-threadmessage-test.c
PROGNAME += ffmpeg_fft
MAINSRC  += $(SRC_PATH)/libavcodec/tests/fft.c
endif

CFLAGS += ${INCDIR_PREFIX}$(SRC_PATH)
AFLAGS += ${INCDIR_PREFIX}$(SRC_PATH)

ifneq ($(DST_PATH),)
  CFLAGS += ${INCDIR_PREFIX}$(DST_PATH)
  AFLAGS += ${INCDIR_PREFIX}$(DST_PATH)
endif

ifeq ($(CONFIG_CODEC_FDKAAC), y)
CFLAGS += -DAACENCODER_LIB_VL0=4 -DAACENCODER_LIB_VL1=0
endif

ifeq ($(CONFIG_LIB_HELIX_AAC),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/libhelix-aac/libhelix-aac
endif

ifeq ($(CONFIG_LIB_HELIX_MP3),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/libhelix-mp3/libhelix-mp3/pub
endif

ifeq ($(CONFIG_LIB_LHDC),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/liblhdc/liblhdc/include
endif

ifeq ($(CONFIG_LIB_OPENCORE_AMR),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/libopencore-amr/libopencore-amr/include
endif

ifeq ($(CONFIG_LIB_ZLIB),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/system/zlib/zlib
endif

ifneq ($(CONFIG_H264_MCVDEC_DECODER)$(CONFIG_VP8_MCVDEC_DECODER),)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/vendor/xring/platform/media/vdec/include
endif

ifneq ($(CONFIG_H264_MCVENC_ENCODER)$(CONFIG_JPEG_MCVENC_ENCODER),)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/vendor/xring/platform/media/venc/include
endif

ifneq ($(CONFIG_V4L2_M2M), )
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/ffmpeg/include
endif

ifeq ($(CONFIG_VIDEOUTILS_LIBX264),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/videoutils/x264/x264
endif

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/vendor/bes/framework/services_hifi4/services/multimedia/audio/smf/core/inc
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/vendor/xiaomi/miwear/xiaomi_enc
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/vendor/xiaomi/miwear/bes_aec
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/vendor/allwinnertech/chips/r528/components/multimedia/src/libcedarx/external/include/libcedarc

ifeq ($(MAKECMDGOALS), context)
CFLAGS += -Wno-error
endif

CFLAGS += -Wno-shift-count-overflow -Wno-implicit-int-float-conversion -Wno-shadow
CFLAGS += -Wno-missing-braces
CFLAGS += $(CFLAGS_HEADERS) -DHAVE_AV_CONFIG_H -DZLIB_CONST

ifneq ($(CONFIG_LIB_FFMPEG_DISABLE_KASAN),)
CFLAGS += -fno-sanitize=all
endif

FFEXTRA := $(CFLAGS)

ifeq ($(CONFIG_DEBUG_CUSTOMOPT),y)
  CFG_CMDS += --optflags=$(strip $(CONFIG_DEBUG_OPTLEVEL))
endif

$(DST_PATH)/libavutil/ffversion.h:
	$(Q)cd $(DST_PATH) && $(FFMPEG_VERSION_SCRIPT) . libavutil/ffversion.h $(EXTRA_VERSION)

$(DST_PATH)/ffbuild/config.mak:
	$(Q) echo "FFMPEG configure... $(CONFIG_ARCH)"
	$(Q)cd $(DST_PATH) &&                              \
		$(FFMPEG_CONFIG_SCRIPT) --disable-all                    \
		--disable-everything    --disable-autodetect             \
		--disable-amf           --disable-audiotoolbox           \
		--disable-cuda-llvm     --disable-cuvid                  \
		--disable-d3d11va       --disable-doc                    \
		--disable-dwt           --disable-dxva2                  \
		--disable-dxva2         --disable-error-resilience       \
		--disable-faan          --disable-ffnvcodec              \
		--disable-htmlpages     --disable-iconv                  \
		--disable-lsp           --disable-threads                \
		--disable-manpages      --disable-pic                    \
		--disable-pixelutils    --disable-podpages               \
		--disable-nvdec         --disable-nvenc                  \
		--disable-txtpages      --disable-v4l2-m2m               \
		--disable-vaapi         --disable-vdpau                  \
		--disable-videotoolbox  --disable-xop                    \
		--enable-version3       --enable-small                   \
		--extra-cflags="$(FFEXTRA)" --extra-ldflags="$(FFEXTRA)" \
		--ld=echo --pkg-config=false assert_level=3 $(CFG_CMDS)  \
		"$(CONFIG_LIB_FFMPEG_CONFIGURATION)"

context:: $(DST_PATH)/ffbuild/config.mak $(DST_PATH)/libavutil/ffversion.h
ifneq ($(DST_PATH),)
	@$(eval ALL_SRCS = $(ASRCS) $(CSRCS) $(MAINSRC) $(NASRCS))
	@$(foreach src,$(ALL_SRCS),$(shell mkdir -p $(DST_PATH)$(DELIM)$(dir $(src))))
endif

depend:: $(NASRCS)

clean_context::
	$(call DELFILE, $(SRC_PATH)/Makefile)
	$(call DELFILE, $(SRC_PATH)/doc/config.texi)

distclean:: clean_context
	rm -f $(SRC_PATH)/config.asm
	rm -f $(SRC_PATH)/config.h $(SRC_PATH)/config_components.h $(SRC_PATH)/.version
	rm -f $(SRC_PATH)/ffbuild/.config $(SRC_PATH)/ffbuild/config*
	rm -f $(SRC_PATH)/libavutil/avconfig.h  $(SRC_PATH)/libavutil/ffversion.h
	find ./ -name "*_list.c" | xargs rm -f

include $(APPDIR)/Application.mk
