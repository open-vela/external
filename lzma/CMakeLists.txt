#
# Copyright (C) 2021 Xiaomi Corporation
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
if(CONFIG_LIB_LZMA)

  nuttx_add_library(liblzma STATIC)

  set(CSRCS
      lzma/C/7zAlloc.c
      lzma/C/7zArcIn.c
      lzma/C/7zBuf.c
      lzma/C/7zBuf2.c
      lzma/C/7zCrc.c
      lzma/C/7zCrcOpt.c
      lzma/C/7zDec.c
      lzma/C/7zFile.c
      lzma/C/7zStream.c
      lzma/C/Aes.c
      lzma/C/AesOpt.c
      lzma/C/Alloc.c
      lzma/C/Bcj2.c
      lzma/C/Bcj2Enc.c
      lzma/C/Bra.c
      lzma/C/Bra86.c
      lzma/C/BraIA64.c
      lzma/C/CpuArch.c
      lzma/C/Delta.c
      lzma/C/LzFind.c
      lzma/C/LzFindMt.c
      lzma/C/LzFindOpt.c
      lzma/C/Lzma2Dec.c
      lzma/C/Lzma2DecMt.c
      lzma/C/Lzma2Enc.c
      lzma/C/Lzma86Dec.c
      lzma/C/Lzma86Enc.c
      lzma/C/LzmaDec.c
      lzma/C/LzmaEnc.c
      lzma/C/LzmaLib.c
      lzma/C/MtCoder.c
      lzma/C/MtDec.c
      lzma/C/Ppmd7.c
      lzma/C/Ppmd7Dec.c
      lzma/C/Ppmd7Enc.c
      lzma/C/Sha256.c
      lzma/C/Sha256Opt.c
      lzma/C/Sort.c
      lzma/C/Threads.c
      lzma/C/Xz.c
      lzma/C/XzCrc64.c
      lzma/C/XzCrc64Opt.c
      lzma/C/XzDec.c
      lzma/C/XzEnc.c
      lzma/C/XzIn.c)

  target_sources(liblzma PRIVATE ${CSRCS})

  if(CONFIG_UTILS_7Z)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_LZMA}
      NAME
      ${CONFIG_UTILS_7Z_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_7Z_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_7Z_PRIORITY}
      SRCS
      lzma/C/Util/7z/7zMain.c
      DEPENDS
      liblzma)
  endif()

  if(CONFIG_UTILS_LZMA)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_LZMA}
      NAME
      ${CONFIG_UTILS_LZMA_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_LZMA_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_LZMA_PRIORITY}
      SRCS
      lzma/C/Util/Lzma/LzmaUtil.c
      DEPENDS
      liblzma)
  endif()

endif()
