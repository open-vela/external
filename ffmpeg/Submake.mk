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

SBINDIR   := $(BINDIR)
SINCDIR   := $(INCDIR)
SAR       := $(AR)
-include ffbuild/config.mak
BINDIR    := $(SBINDIR)
INCDIR    := $(SINCDIR)
AR        := $(SAR)

CSRCS     :=
ASRCS     :=
SRC_PATH  := .

CFG_ARCH  := $(CONFIG_ARCH)
ifeq ($(CONFIG_ARCH),avr)
  CFG_ARCH = avr32
endif

ifneq ($(CONFIG_ARCH),sim)
  CFG_CMDS += --arch=$(CFG_ARCH) --target-os=none
  CFG_CMDS += --enable-cross-compile --cross-prefix=$(CROSSDEV)
  CFG_CMDS += --cc=$(CC)
endif

ifneq ($(CONFIG_LIB_MBEDTLS),)
  CFG_CMDS += --enable-mbedtls
endif

ifeq ($(CONFIG_ARM_NEON),)
  CFG_CMDS += --disable-neon
endif

FFLIBS-$(CONFIG_AVCODEC)    += avcodec
FFLIBS-$(CONFIG_AVDEVICE)   += avdevice
FFLIBS-$(CONFIG_AVFILTER)   += avfilter
FFLIBS-$(CONFIG_AVFORMAT)   += avformat
FFLIBS-$(CONFIG_AVRESAMPLE) += avresample
FFLIBS-yes                  += avutil
FFLIBS-$(CONFIG_POSTPROC)   += postproc
FFLIBS-$(CONFIG_SWRESAMPLE) += swresample
FFLIBS-$(CONFIG_SWSCALE)    += swscale

SUBDIR_VARS := CLEANFILES FFLIBS HOSTPROGS TESTPROGS TOOLS               \
               HEADERS ARCH_HEADERS BUILT_HEADERS SKIPHEADERS            \
               ARMV5TE-OBJS ARMV6-OBJS ARMV8-OBJS VFP-OBJS NEON-OBJS     \
               ALTIVEC-OBJS VSX-OBJS MMX-OBJS X86ASM-OBJS                \
               MIPSFPU-OBJS MIPSDSPR2-OBJS MIPSDSP-OBJS MSA-OBJS         \
               MMI-OBJS OBJS SLIBOBJS HOSTOBJS TESTOBJS

define DOSUBDIR
  $(foreach V,$(SUBDIR_VARS), $(V) := $(V)-yes :=)
  include $(1)/Makefile
  -include $(1)/$$(ARCH)/Makefile
  include ffbuild/arch.mak
  SOBJS := $$(sort $$(addprefix $(1)/, $$(OBJS) $$(OBJS-yes)))
  CSRCS += $$(wildcard $$(patsubst %.o,%.c, $$(SOBJS)))
  ASRCS += $$(wildcard $$(patsubst %.o,%.S, $$(SOBJS)))
endef

$(foreach D,$(FFLIBS-yes),$(eval $(call DOSUBDIR,lib$(D))))

PRIORITY  = $(CONFIG_LIB_FFMPEG_TOOLS_PRIORITY)
STACKSIZE = $(CONFIG_LIB_FFMPEG_TOOLS_STACKSIZE)
MODULE    = $(CONFIG_LIB_FFMPEG)
CSRCS    += fftools/cmdutils.c

ifeq ($(CONFIG_FFMPEG),yes)
  PROGNAME += ffmpeg
  MAINSRC  += fftools/ffmpeg.c
  CSRCS    += fftools/ffmpeg_opt.c fftools/ffmpeg_filter.c fftools/ffmpeg_hw.c
endif

ifeq ($(CONFIG_FFPROBE),yes)
  PROGNAME += ffprobe
  MAINSRC  += fftools/ffprobe.c
endif

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}

ifeq ($(CONFIG_CODEC_FDKAAC), y)
CFLAGS += -DAACENCODER_LIB_VL0=4 -DAACENCODER_LIB_VL1=0
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libSYS/include}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libAACenc/include}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/aac/aac/libAACdec/include}
endif

ifeq ($(CONFIG_LIB_FLUORIDE_SBC_DECODER),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libfluoride-sbc/libfluoride-sbc/decoder/include}
endif
ifeq ($(CONFIG_LIB_FLUORIDE_SBC_ENCODER),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libfluoride-sbc/libfluoride-sbc/encoder/include}
endif

ifeq ($(CONFIG_LIB_HELIX_AAC),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libhelix-aac/libhelix-aac}
endif
ifeq ($(CONFIG_LIB_HELIX_MP3),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libhelix-mp3/libhelix-mp3/pub}
endif

ifeq ($(CONFIG_UORB),y)
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/uORB}
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
CFLAGS += $(CFLAGS_HEADERS) -DHAVE_AV_CONFIG_H -DZLIB_CONST

EXTRA := $(CFLAGS)

libavutil/ffversion.h .version:
	$(Q)ffbuild/version.sh . libavutil/ffversion.h $(EXTRA_VERSION)

config.h:
	$(Q) echo "FFMPEG configure... $(CONFIG_ARCH)"
	$(Q)./configure             --disable-all                   \
		--disable-everything    --disable-autodetect            \
		--disable-amf           --disable-audiotoolbox          \
		--disable-cuda-llvm     --disable-cuvid                 \
		--disable-d3d11va       --disable-doc                   \
		--disable-dwt           --disable-dxva2                 \
		--disable-dxva2         --disable-error-resilience      \
		--disable-faan          --disable-ffnvcodec             \
		--disable-htmlpages     --disable-iconv                 \
		--disable-lsp           --disable-lzo                   \
		--disable-manpages      --disable-pic                   \
		--disable-pixelutils    --disable-podpages              \
		--disable-nvdec         --disable-nvenc                 \
		--disable-txtpages      --disable-v4l2-m2m              \
		--disable-vaapi         --disable-vdpau                 \
		--disable-videotoolbox  --disable-x86asm                \
		--disable-xop           --disable-threads               \
		--enable-version3       --enable-small                  \
		--extra-cflags="$(EXTRA)" --extra-ldflags="$(EXTRA)"   \
		--ld=echo --pkg-config=false assert_level=3 $(CFG_CMDS) \
		"$(CONFIG_LIB_FFMPEG_CONFIGURATION)"

context:: config.h libavutil/ffversion.h

distclean::
	rm -f .version config.h ffbuild/.config ffbuild/config*
	rm -f libavutil/avconfig.h libavutil/ffversion.h
	find ./ -name "*_list.c" | xargs rm -f

include $(APPDIR)/Application.mk
