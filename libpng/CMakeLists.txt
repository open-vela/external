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

if(CONFIG_LIB_PNG)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  set(PNG_SHARED
      OFF
      CACHE BOOL "Disable libpng shared library" FORCE)
  set(PNG_EXECUTABLES
      OFF
      CACHE BOOL "Disable libpng executable" FORCE)
  set(PNG_TESTS
      OFF
      CACHE BOOL "Disable libpng tests program" FORCE)
  set(M_LIBRARY
      ""
      CACHE STRING "Disable libm" FORCE)
  set(ZLIB_INCLUDE_DIRS
      "${NUTTX_APPS_DIR}/system/zlib/zlib"
      CACHE STRING "Disable zlib include files" FORCE)
  set(ZLIB_INCLUDE_DIR
      "${NUTTX_APPS_DIR}/system/zlib/zlib"
      CACHE STRING "Disable zlib include files for generate files" FORCE)
  set(PNG_BUILD_ZLIB
      ON
      CACHE BOOL "Disable zlib compile" FORCE)
  if(CONFIG_ARM_NEON OR CONFIG_ARM64_NEON)
    set(CMAKE_SYSTEM_PROCESSOR "arm64")
  endif()

  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libpng
                   ${CMAKE_CURRENT_BINARY_DIR}/libpng EXCLUDE_FROM_ALL)
  nuttx_add_external_library(png_static)
  nuttx_export_header(TARGET png_static INCLUDE_DIRECTORIES
                      ${CMAKE_CURRENT_SOURCE_DIR}/libpng)
  nuttx_add_dependencies(TARGET png_static DEPENDS zlib)
endif()
