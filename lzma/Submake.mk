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

CSRCS = \
  7zAlloc.c \
  7zArcIn.c \
  7zBuf.c \
  7zBuf2.c \
  7zCrc.c \
  7zCrcOpt.c \
  7zDec.c \
  7zFile.c \
  7zStream.c \
  Aes.c \
  AesOpt.c \
  Alloc.c \
  Bcj2.c \
  Bcj2Enc.c \
  Bra.c \
  Bra86.c \
  BraIA64.c \
  CpuArch.c \
  Delta.c \
  LzFind.c \
  Lzma2Dec.c \
  Lzma2Enc.c \
  Lzma86Dec.c \
  Lzma86Enc.c \
  LzmaDec.c \
  LzmaEnc.c \
  LzmaLib.c \
  Ppmd7.c \
  Ppmd7Dec.c \
  Ppmd7Enc.c \
  Sha256.c \
  Sort.c \
  Xz.c \
  XzCrc64.c \
  XzCrc64Opt.c \
  XzDec.c \
  XzEnc.c \
  XzIn.c

CFLAGS += -D_7ZIP_ST
MODULE = $(CONFIG_LIB_LZMA)

VPATH += C
ROOTDEPPATH += --dep-path C

ifneq ($(CONFIG_UTILS_7Z),)
PROGNAME  += $(CONFIG_UTILS_7Z_PROGNAME)
PRIORITY  += $(CONFIG_UTILS_7Z_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_7Z_STACKSIZE)

MAINSRC += 7zMain.c
VPATH += C/Util/7z
ROOTDEPPATH += --dep-path C/Util/7z
endif

ifneq ($(CONFIG_UTILS_LZMA),)
PROGNAME  += $(CONFIG_UTILS_LZMA_PROGNAME)
PRIORITY  += $(CONFIG_UTILS_LZMA_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_LZMA_STACKSIZE)

MAINSRC += LzmaUtil.c
VPATH += C/Util/Lzma
ROOTDEPPATH += --dep-path C/Util/Lzma
endif

include $(APPDIR)/Application.mk
