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

SPEEXDIR=$(APPDIR)/external/speex/speex

CSRCS  += $(filter-out speex/libspeex/testenc.c     \
                       speex/libspeex/testenc_wb.c  \
                       speex/libspeex/testenc_uwb.c \
          , $(wildcard speex/libspeex/*.c))
CFLAGS += ${INCDIR_PREFIX}speex
CFLAGS += ${INCDIR_PREFIX}speex/include

MODULE    = $(CONFIG_LIB_SPEEX)
PRIORITY  = $(CONFIG_LIB_SPEEX_PRIORITY)
STACKSIZE = $(CONFIG_LIB_SPEEX_STACKSIZE)

ifneq ($(CONFIG_LIB_SPEEX_NB_TEST),)
  PROGNAME += speex_nbtest
  MAINSRC  += speex/libspeex/testenc.c
endif

ifneq ($(CONFIG_LIB_SPEEX_WB_TEST),)
  PROGNAME += speex_wbtest
  MAINSRC  += speex/libspeex/testenc_wb.c
endif

ifneq ($(CONFIG_LIB_SPEEX_UWB_TEST),)
  PROGNAME += speex_uwbtest
  MAINSRC  += speex/libspeex/testenc_uwb.c
endif

CFLAGS += -DHAVE_CONFIG_H
CFLAGS += -Wno-shadow -Wno-unused-function -Wno-incompatible-pointer-types  -Wno-literal-conversion -Wno-incompatible-pointer-types
CFLAGS += -Dkiss_fft_alloc=spx_kiss_fft_alloc -Dkiss_fftr_alloc=spx_kiss_fftr_alloc \
          -Dkiss_fft_stride=spx_kiss_fft_stride -Dkiss_fft=spx_kiss_fft -Dkiss_fftr=spx_kiss_fftr \
          -Dkiss_fftri=spx_kiss_fftri

context::
	cd ${SPEEXDIR} && \
	${SPEEXDIR}/autogen.sh 1> /dev/null && \
	${SPEEXDIR}/configure --disable-sse --enable-fixed-point 1> /dev/null

include $(APPDIR)/Application.mk
