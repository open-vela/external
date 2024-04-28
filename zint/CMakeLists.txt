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
if(CONFIG_LIB_ZINT)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  set(ZINT_USE_PNG
      OFF
      CACHE BOOL "Build with PNG support" FORCE)
  set(ZINT_STATIC
      ON
      CACHE BOOL "Build zint static" FORCE)
  set(ZINT_VERSION_MAJOR 2)
  set(ZINT_VERSION_MINOR 11)
  set(ZINT_VERSION_RELEASE 1)
  set(ZINT_VERSION_BUILD 9)
  set(ZINT_VERSION
      "${ZINT_VERSION_MAJOR}.${ZINT_VERSION_MINOR}.${ZINT_VERSION_RELEASE}.${ZINT_VERSION_BUILD}"
  )
  set(INCLUDE_INSTALL_DIR {CMAKE_CURRENT_BINARY_DIR}/zint)
  add_definitions(-DZINT_VERSION=\"${ZINT_VERSION}\")
  get_property(TARGET_SUPPORTS_SHARED_ORIG GLOBAL
               PROPERTY TARGET_SUPPORTS_SHARED_LIBS)
  set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/zint/backend
                   ${CMAKE_CURRENT_BINARY_DIR}/zint/backend EXCLUDE_FROM_ALL)
  nuttx_add_external_library(zint-static)
  nuttx_export_header(TARGET zint-static INCLUDE_DIRECTORIES
                      ${CMAKE_CURRENT_SOURCE_DIR}/zint/backend)
  set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS
                               ${TARGET_SUPPORTS_SHARED_ORIG})

  # ############################################################################
  # Applications Configuration
  # ############################################################################

  if(CONFIG_UTILS_ZINT)
    nuttx_add_application(
      NAME
      ${CONFIG_UTILS_ZINT_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_ZINT_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_ZINT_PRIORITY}
      SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/zint/frontend/main.c
      MODULE
      ${CONFIG_UTILS_ZINT}
      DEPENDS
      zint-static)
  endif()

endif()
