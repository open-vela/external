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

if(CONFIG_LIB_NGHTTP2)

  set(NGHTTP2_FLAGS -DHAVE_CONFIG_H)

  set(NGHTTP2_INCDIR ${CMAKE_CURRENT_LIST_DIR})
  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/nghttp2/lib
             ${CMAKE_CURRENT_LIST_DIR}/nghttp2/lib/includes)

  nuttx_add_library(nghttp2)

  file(GLOB CSRCS nghttp2/lib/*.c)
  target_sources(nghttp2 PRIVATE ${CSRCS})

  target_include_directories(nghttp2 PUBLIC ${NGHTTP2_INCDIR})
  target_compile_options(nghttp2 PRIVATE ${NGHTTP2_FLAGS})
  if(CONFIG_NGHTTP2_TEST)
    file(GLOB CSRCS nghttp2/tests/nghttp2_*.c nghttp2/tests/malloc*.c)

    nuttx_add_application(
      NAME
      ${CONFIG_NGHTTP2_TEST_PROGNAME}
      SRCS
      nghttp2/tests/main.c
      ${CSRCS}
      INCLUDE_DIRECTORIES
      ${NGHTTP2_INCDIR}
      COMPILE_FLAGS
      ${NGHTTP2_FLAGS}
      STACKSIZE
      ${CONFIG_NGHTTP2_TEST_STACKSIZE}
      PRIORITY
      ${CONFIG_NGHTTP2_TEST_PRIORITY})

  endif()

endif()
