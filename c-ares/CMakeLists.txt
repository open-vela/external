#
# Copyright (C) 2024 Xiaomi Corporation
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

if(CONFIG_LIB_CARES)

  set(CARES_FLAGS -DHAVE_CONFIG_H)

  set(CARES_INCDIR ${CMAKE_CURRENT_LIST_DIR}
                   ${CMAKE_CURRENT_LIST_DIR}/c-ares/src/lib)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}
             ${CMAKE_CURRENT_LIST_DIR}/c-ares/include)

  nuttx_add_library(cares)

  file(GLOB CARES_SRCS c-ares/src/lib/*.c c-ares/src/lib/*/*.c)

  if(CONFIG_UTILS_CARES)
    list(APPEND CARES_SRCS c-ares/src/tools/ares_getopt.c)

    nuttx_add_application(
      NAME
      ahost
      SRCS
      c-ares/src/tools/ahost.c
      INCLUDE_DIRECTORIES
      ${CARES_INCDIR}
      COMPILE_FLAGS
      ${CARES_FLAGS}
      PRIORITY
      ${CONFIG_UTILS_CARES_PRIORITY}
      STACKSIZE
      ${CONFIG_UTILS_CARES_STACKSIZE}
      DEPENDS
      cares)

    nuttx_add_application(
      NAME
      adig
      SRCS
      c-ares/src/tools/adig.c
      INCLUDE_DIRECTORIES
      ${CARES_INCDIR}
      COMPILE_FLAGS
      ${CARES_FLAGS}
      PRIORITY
      ${CONFIG_UTILS_CARES_PRIORITY}
      STACKSIZE
      ${CONFIG_UTILS_CARES_STACKSIZE}
      DEPENDS
      cares)
  endif()

  target_include_directories(cares PRIVATE ${CARES_INCDIR})
  target_compile_options(cares PRIVATE ${CARES_FLAGS})
  target_sources(cares PRIVATE ${CARES_SRCS})

endif()
