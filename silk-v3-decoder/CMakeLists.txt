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

if(CONFIG_LIB_SILK)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB CSRCS silk-v3-decoder/silk/src/*.c)

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/silk-v3-decoder/silk/interface)

  # ############################################################################
  # Flags
  # ############################################################################

  if(NOT ${CONFIG_ARCH_TOOLCHAIN_CLANG})
    set(CFLAGS "-Wno-stringop-overread")
  endif()

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(silk-v3-decoder STATIC)
  target_sources(silk-v3-decoder PRIVATE ${CSRCS})
  target_include_directories(silk-v3-decoder PUBLIC ${INCDIR})

endif()
