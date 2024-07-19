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
  nuttx_add_library(png_static)

  if(CONFIG_ARM_NEON OR CONFIG_ARM64_NEON)
    file(GLOB CSRCS libpng/arm/*.c libpng/arm/*.S)
    set_source_files_properties(
      ${CMAKE_CURRENT_LIST_DIR}/libpng/arm/palette_neon_intrinsics.c
      PROPERTIES COMPILE_FLAGS -Os)

    target_sources(png_static PRIVATE ${CSRCS})

  else()
    target_compile_options(png_static PRIVATE -DPNG_ARM_NEON_IMPLEMENTATION=0)
  endif()

  target_include_directories(png_static
                             PRIVATE ${NUTTX_APPS_DIR}/system/zlib/zlib)
  file(GLOB CSRCS libpng/*.c)
  list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/libpng/pngtest.c)

  target_sources(png_static PRIVATE ${CSRCS})
  nuttx_export_header(TARGET png_static INCLUDE_DIRECTORIES
                      ${CMAKE_CURRENT_SOURCE_DIR}/libpng)
  # ############################################################################
  # Applications Configuration
  # ############################################################################

  if(CONFIG_LIB_PNG_TEST)
    nuttx_add_application(
      NAME
      test_libpng
      STACKSIZE
      ${CONFIG_LIB_PNG_TEST_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_PNG_TEST_PRIORITY}
      SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/libpng/pngtest.c
      MODULE
      ${CONFIG_LIB_PNG_TEST}
      DEPENDS
      png_static)
  endif()

endif()
