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

if(CONFIG_LIB_FLUORIDE_SBC)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB DECODER_SRCS libfluoride-sbc/decoder/srce/*.c)
  file(GLOB ENCODER_SRCS libfluoride-sbc/encoder/srce/*.c)
  set(CSRCS ${DECODER_SRCS} ${ENCODER_SRCS})

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(DECODER_INC ${CMAKE_CURRENT_LIST_DIR}/libfluoride-sbc/decoder/include)
  set(ENCODER_INC ${CMAKE_CURRENT_LIST_DIR}/libfluoride-sbc/encoder/include)
  set(INCDIR ${DECODER_INC} ${ENCODER_INC})

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(libfluoride-sbc STATIC)
  target_sources(libfluoride-sbc PRIVATE ${CSRCS})
  target_include_directories(libfluoride-sbc PUBLIC ${INCDIR})

endif()
