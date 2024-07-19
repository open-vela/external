#
# Copyright (C) 2022 Xiaomi Corporation
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

if(CONFIG_LIB_WEBP)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(webpdecoder)
  file(GLOB CSRCS libwebp/src/dec/*.c libwebp/src/dsp/*.c libwebp/src/utils/*.c)
  target_sources(webpdecoder PRIVATE ${CSRCS})
  target_include_directories(
    webpdecoder PRIVATE ${CMAKE_CURRENT_LIST_DIR}/libwebp
                        ${CMAKE_CURRENT_LIST_DIR}/libwebp/src)
  target_compile_options(webpdecoder PRIVATE -Wno-maybe-uninitialized)

  nuttx_export_header(TARGET webpdecoder INCLUDE_DIRECTORIES
                      ${CMAKE_CURRENT_SOURCE_DIR}/libwebp/src)

endif()
