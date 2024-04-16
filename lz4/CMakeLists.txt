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

if(CONFIG_LIB_LZ4)

  # ############################################################################
  # Sources
  # ############################################################################
  file(GLOB CSRCS lz4/lib/*.c)
  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/lz4/lib)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(lz4 STATIC)
  target_sources(lz4 PRIVATE ${CSRCS})
  target_include_directories(lz4 PRIVATE ${INCDIR})

  # ############################################################################
  # Applications Configuration
  # ############################################################################

  if(CONFIG_UTILS_LZ4)
    set(UTILS_LZ4_SRCS lz4/programs/lz4cli.c lz4/programs/lz4io.c
                       lz4/programs/bench.c lz4/programs/datagen.c)
    nuttx_add_application(
      NAME
      ${CONFIG_UTILS_LZ4_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_LZ4_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_LZ4_PRIORITY}
      SRCS
      ${UTILS_LZ4_SRCS}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      DEPENDS
      lz4)
  endif()
endif()
