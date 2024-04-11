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

if(CONFIG_LIB_TAR)

  # ############################################################################
  # Flags
  # ############################################################################

  set(CFLAGS -DMAXPATHLEN=PATH_MAX)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB LIB_CSRCS ${CMAKE_CURRENT_LIST_DIR}/libtar/lib/*.c)
  file(GLOB LISTHASH_CSRCS ${CMAKE_CURRENT_LIST_DIR}/libtar/listhash/*.c)
  set(CSRCS ${CMAKE_CURRENT_LIST_DIR}/libtar/compat/strmode.c ${LIB_CSRCS}
            ${LISTHASH_CSRCS})

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR
      ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/libtar/compat
      ${CMAKE_CURRENT_LIST_DIR}/libtar/listhash
      ${CMAKE_CURRENT_LIST_DIR}/libtar/lib ${NUTTX_APPS_DIR}/system/zlib/zlib)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(libtar)
  target_sources(libtar PRIVATE ${CSRCS})
  target_include_directories(libtar PRIVATE ${INCDIR})
  target_compile_options(libtar PRIVATE ${CFLAGS})

  # ############################################################################
  # Applications Configuration
  # ############################################################################

  if(CONFIG_UTILS_TAR)
    nuttx_add_application(
      MODULE
      ${CONFIG_UTILS_TAR}
      NAME
      ${CONFIG_UTILS_TAR_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_TAR_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_TAR_PRIORITY}
      SRCS
      ${CMAKE_CURRENT_LIST_DIR}/libtar/libtar/libtar.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      libtar)
  endif()

endif()
