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
if(CONFIG_LIB_LCM)
  set(LIBLCM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lcm)

  nuttx_add_library(liblcm STATIC)

  set(CFLAGS
      -Wno-stringop-overflow
      -Wno-array-bounds
      -Wno-restrict
      -Wno-shadow
      -Wno-sign-compare
      -fexceptions
      $<$<COMPILE_LANGUAGE:C>:-Wno-strict-prototypes>)

  set(INCDIR
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${LIBLCM_DIR}
      ${LIBLCM_DIR}/lcm
      ${CMAKE_CURRENT_SOURCE_DIR}/test/types
      ${NUTTX_APPS_DIR}/external/glib/glib
      ${NUTTX_APPS_DIR}/external/glib/glib/glib)

  file(GLOB CSRCS ${LIBLCM_DIR}/lcm/*.c ${LIBLCM_DIR}/lcm/lcmtypes/*.c)

  if(CONFIG_LIB_LCM_TESTCASE)
    file(GLOB TEST_CSRCS ${CMAKE_CURRENT_SOURCE_DIR}/test/types/*.c
         ${LIBLCM_DIR}/test/c/*.c)
    list(REMOVE_ITEM TEST_CSRCS ${LIBLCM_DIR}/test/c/server.c)
    list(APPEND CSRCS ${TEST_CSRCS})

    nuttx_add_application(
      NAME
      lcm_server
      SRCS
      ${LIBLCM_DIR}/test/c/server.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      liblcm)

    nuttx_add_application(
      NAME
      lcm_test
      SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/test/lcm_test.cpp
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      liblcm)
  endif()

  target_sources(liblcm PRIVATE ${CSRCS})
  target_compile_options(liblcm PRIVATE ${CFLAGS})
  target_include_directories(liblcm PRIVATE ${INCDIR})
endif()
