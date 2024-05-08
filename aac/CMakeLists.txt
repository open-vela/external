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

if(CONFIG_CODEC_FDKAAC)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB CXXSRCS aac/*/src/*.cpp)

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIRS
      ${CMAKE_CURRENT_LIST_DIR}/aac/libAACdec/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libAACenc/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libSYS/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libArithCoding/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libDRCdec/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libFDK/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libMpegTPDec/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libMpegTPEnc/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libPCMutils/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libSACdec/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libSACenc/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libSBRdec/include
      ${CMAKE_CURRENT_LIST_DIR}/aac/libSBRenc/include)

  # ############################################################################
  # Compile Flags
  # ############################################################################

  set(CXXFLAGS -Wno-undef)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(fdkaac STATIC)
  target_compile_options(fdkaac PRIVATE ${CXXFLAGS})
  target_sources(fdkaac PRIVATE ${CXXSRCS})
  target_include_directories(fdkaac PUBLIC ${INCDIRS})

endif()
