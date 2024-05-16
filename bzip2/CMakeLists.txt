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
if(CONFIG_LIB_BZIP2)

  nuttx_add_library(bzip2 STATIC)

  set(CSRCS
      bzip2/blocksort.c
      bzip2/bzlib.c
      bzip2/compress.c
      bzip2/crctable.c
      bzip2/decompress.c
      bzip2/huffman.c
      bzip2/randtable.c)
  target_sources(bzip2 PRIVATE ${CSRCS})
  target_compile_options(bzip2 PRIVATE -Wno-undef)

  if(CONFIG_UTILS_BZIP2)
    nuttx_add_application(
      MODULE
      ${CONFIG_UTILS_BZIP2}
      NAME
      ${CONFIG_UTILS_BZIP2_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_BZIP2_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_BZIP2_PRIORITY}
      SRCS
      bzip2/bzip2.c
      DEPENDS
      bzip2)
  endif()

endif()
