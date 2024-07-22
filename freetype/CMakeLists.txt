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

if(CONFIG_LIB_FREETYPE)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  # Disable host package finders

  set(CMAKE_DISABLE_FIND_PACKAGE_ZLIB TRUE)
  set(CMAKE_DISABLE_FIND_PACKAGE_BZip2 TRUE)
  set(CMAKE_DISABLE_FIND_PACKAGE_PNG TRUE)
  set(CMAKE_DISABLE_FIND_PACKAGE_HarfBuzz TRUE)
  set(CMAKE_DISABLE_FIND_PACKAGE_BrotliDec TRUE)
  set(FTSYSTEM_SRC
      "builds/nuttx/ftsystem.c"
      CACHE STRING "Path to ftsystem.c source file" FORCE)

  set(INCDIR ${CMAKE_CURRENT_SOURCE_DIR}/freetype/include)

  add_definitions(-DFT_CONFIG_MODULES_H="../builds/nuttx/ftmodule.h"
                  -DFT_CONFIG_OPTIONS_H="../builds/nuttx/ftoption.h")

  add_compile_options(-Wno-dangling-pointer)

  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/freetype
                   ${CMAKE_CURRENT_BINARY_DIR}/freetype EXCLUDE_FROM_ALL)
  nuttx_add_external_library(freetype)

  # Export headers to global
  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${INCDIR})

endif()
