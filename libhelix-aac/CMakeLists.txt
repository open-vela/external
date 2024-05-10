#
# Copyright (C) 2020 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#

if(CONFIG_LIB_HELIX_AAC)

  # ############################################################################
  # Sources
  # ############################################################################

  set(CSRCS
      libhelix-aac/aacdec.c
      libhelix-aac/bitstream.c
      libhelix-aac/buffers.c
      libhelix-aac/dct4.c
      libhelix-aac/decelmnt.c
      libhelix-aac/dequant.c
      libhelix-aac/fft.c
      libhelix-aac/filefmt.c
      libhelix-aac/huffman.c
      libhelix-aac/hufftabs.c
      libhelix-aac/imdct.c
      libhelix-aac/noiseless.c
      libhelix-aac/pns.c
      libhelix-aac/stproc.c
      libhelix-aac/tns.c
      libhelix-aac/trigtabs.c
      libhelix-aac/aactabs.c)

  if(CONFIG_LIB_HELIX_AAC_SBR)
    set(SBR_CSRCS
        libhelix-aac/sbr.c
        libhelix-aac/sbrfft.c
        libhelix-aac/sbrfreq.c
        libhelix-aac/sbrhfadj.c
        libhelix-aac/sbrhfgen.c
        libhelix-aac/sbrhuff.c
        libhelix-aac/sbrimdct.c
        libhelix-aac/sbrmath.c
        libhelix-aac/sbrqmf.c
        libhelix-aac/sbrside.c
        libhelix-aac/sbrtabs.c)

    list(APPEND CSRCS ${SBR_CSRCS})
  endif()

  if(CONFIG_ARCH_ARM)
    set(SBR_SRCS
        libhelix-aac/sbrcov.s
        libhelix-aac/sbrqmfak.s
        libhelix-aac/sbrqmfsk.s)

    list(APPEND CSRCS ${SBR_SRCS})
  endif()

  # ############################################################################
  # Compile Flags
  # ############################################################################

  set(CFLAGS -DUSE_DEFAULT_STDLIB -fno-sanitize=undefined)

  if(CONFIG_ARCH_ARM)
    set(AFLAGS -Wa,-mimplicit-it=thumb)
    list(APPEND CFLAGS ${AFLAGS})
  endif()

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(libhelix-aac STATIC)
  target_compile_options(libhelix-aac PRIVATE ${CFLAGS})
  target_sources(libhelix-aac PRIVATE ${CSRCS})

endif()
