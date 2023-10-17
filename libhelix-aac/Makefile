#
# Copyright (C) 2021 Xiaomi Corporation
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

CSRCS += libhelix-aac/aacdec.c
CSRCS += libhelix-aac/bitstream.c
CSRCS += libhelix-aac/buffers.c
CSRCS += libhelix-aac/dct4.c
CSRCS += libhelix-aac/decelmnt.c
CSRCS += libhelix-aac/dequant.c
CSRCS += libhelix-aac/fft.c
CSRCS += libhelix-aac/filefmt.c
CSRCS += libhelix-aac/huffman.c
CSRCS += libhelix-aac/hufftabs.c
CSRCS += libhelix-aac/imdct.c
CSRCS += libhelix-aac/noiseless.c
CSRCS += libhelix-aac/pns.c
CSRCS += libhelix-aac/stproc.c
CSRCS += libhelix-aac/tns.c
CSRCS += libhelix-aac/trigtabs.c
CSRCS += libhelix-aac/aactabs.c

ifneq ($(CONFIG_LIB_HELIX_AAC_SBR),)
CSRCS += libhelix-aac/sbr.c
CSRCS += libhelix-aac/sbrfft.c
CSRCS += libhelix-aac/sbrfreq.c
CSRCS += libhelix-aac/sbrhfadj.c
CSRCS += libhelix-aac/sbrhfgen.c
CSRCS += libhelix-aac/sbrhuff.c
CSRCS += libhelix-aac/sbrimdct.c
CSRCS += libhelix-aac/sbrmath.c
CSRCS += libhelix-aac/sbrqmf.c
CSRCS += libhelix-aac/sbrside.c
CSRCS += libhelix-aac/sbrtabs.c
endif

ifeq ($(CONFIG_ARCH_ARM),y)
ASRCS += libhelix-aac/sbrcov.s
ASRCS += libhelix-aac/sbrqmfak.s
ASRCS += libhelix-aac/sbrqmfsk.s
AFLAGS += -Wa,-mimplicit-it=thumb
endif

CFLAGS += -DUSE_DEFAULT_STDLIB -fno-sanitize=undefined

include $(APPDIR)/Application.mk
