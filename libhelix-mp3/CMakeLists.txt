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

if(CONFIG_LIB_HELIX_MP3)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB HELIX_SRCS "libhelix-mp3/*.c")
  file(GLOB HELIX_REAL_SRCS "libhelix-mp3/real/*.c")
  set(CSRCS ${HELIX_SRCS} ${HELIX_REAL_SRCS})

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(HELIX_INC "${CMAKE_CURRENT_LIST_DIR}/libhelix-mp3/pub/")
  set(INCDIR ${HELIX_INC})

  # ############################################################################
  # Compiler Flags
  # ############################################################################

  if(CONFIG_ARCH_ARM)
    set(CFLAGS -DARM)
  endif()

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(libhelix-mp3 STATIC)
  target_compile_options(libhelix-mp3 PRIVATE ${CFLAGS})
  target_sources(libhelix-mp3 PRIVATE ${CSRCS})
  target_include_directories(libhelix-mp3 PUBLIC ${INCDIR})

endif()
