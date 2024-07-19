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

if(CONFIG_LIB_JPEG_TURBO)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(turbojpeg-static)
  file(GLOB CSRCS libjpeg-turbo/j*.c)
  list(
    REMOVE_ITEM
    CSRCS
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jccolext.c
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jcstest.c
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jdcol565.c
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jdcolext.c
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jdmrg565.c
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jdmrgext.c
    ${CMAKE_CURRENT_LIST_DIR}/libjpeg-turbo/jstdhuff.c)
  target_sources(turbojpeg-static PRIVATE ${CSRCS})
  target_compile_options(turbojpeg-static
                         PRIVATE -Dread_stdin=libjpeg_read_stdin)

  nuttx_export_header(TARGET turbojpeg-static INCLUDE_DIRECTORIES
                      ${CMAKE_CURRENT_SOURCE_DIR}/libjpeg-turbo)

endif()
