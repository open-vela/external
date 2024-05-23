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
if(CONFIG_LIB_PCRE2)
  set(LIBPCRE2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pcre2)

  nuttx_add_library(libpcre2 STATIC)

  set(CFLAGS -DPCRE2_CODE_UNIT_WIDTH=8 -DHAVE_CONFIG_H
             -Wno-implicit-function-declaration)
  set(INCDIR ${LIBPCRE2_DIR}/src ${LIBPCRE2_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
  file(GLOB CSRCS ${LIBPCRE2_DIR}/src/*.c
       ${CMAKE_CURRENT_SOURCE_DIR}/pcre2_chartables.c)
  list(
    REMOVE_ITEM
    CSRCS
    ${LIBPCRE2_DIR}/src/pcre2_jit_match.c
    ${LIBPCRE2_DIR}/src/pcre2_jit_misc.c
    ${LIBPCRE2_DIR}/src/pcre2_printint.c
    ${LIBPCRE2_DIR}/src/pcre2test.c
    ${LIBPCRE2_DIR}/src/pcre2_jit_test.c)

  target_sources(libpcre2 PRIVATE ${CSRCS})
  target_compile_options(libpcre2 PRIVATE ${CFLAGS})
  target_include_directories(libpcre2 PRIVATE ${INCDIR})
endif()
