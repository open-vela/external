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

  set(WEBP_BUILD_ANIM_UTILS
      OFF
      CACHE BOOL "Disable animation utilities." FORCE)
  set(WEBP_BUILD_CWEBP
      OFF
      CACHE BOOL "Disable the cwebp command line tool." FORCE)
  set(WEBP_BUILD_DWEBP
      OFF
      CACHE BOOL "Disable the dwebp command line tool." FORCE)
  set(WEBP_BUILD_GIF2WEBP
      OFF
      CACHE BOOL "Disable the gif2webp conversion tool." FORCE)
  set(WEBP_BUILD_IMG2WEBP
      OFF
      CACHE BOOL "Disable the img2webp animation tool." FORCE)
  set(WEBP_BUILD_VWEBP
      OFF
      CACHE BOOL "Disable the vwebp viewer tool." FORCE)
  set(WEBP_BUILD_WEBPINFO
      OFF
      CACHE BOOL "Disable the webpinfo command line tool." FORCE)
  set(WEBP_BUILD_LIBWEBPMUX
      OFF
      CACHE BOOL "Disable the libwebpmux library." FORCE)
  set(WEBP_BUILD_WEBPMUX
      OFF
      CACHE BOOL "Disable the webpmux command line tool." FORCE)
  set(WEBP_BUILD_EXTRAS
      OFF
      CACHE BOOL "Disable extras." FORCE)
  set(WEBP_BUILD_WEBP_JS
      OFF
      CACHE BOOL "Disable Emscripten build of webp.js." FORCE)
  set(WEBP_USE_THREAD
      OFF
      CACHE BOOL "Disable threading support" FORCE)
  set(WEBP_NEAR_LOSSLESS
      OFF
      CACHE BOOL "Disable near-lossless encoding" FORCE)

  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libwebp
                   ${CMAKE_CURRENT_BINARY_DIR}/libwebp EXCLUDE_FROM_ALL)
  nuttx_add_external_library(webpdecoder)
  nuttx_export_header(TARGET webpdecoder INCLUDE_DIRECTORIES
                      ${CMAKE_CURRENT_SOURCE_DIR}/libwebp/src)
endif()
