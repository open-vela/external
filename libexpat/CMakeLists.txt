#
# Copyright (C) 2021 Xiaomi Corporation
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
if(CONFIG_LIB_EXPAT)

  nuttx_add_library(libexpat STATIC)

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}
             ${CMAKE_CURRENT_LIST_DIR}/libexpat/expat/lib)

  file(GLOB CSRCS libexpat/expat/lib/*.c)

  target_sources(libexpat PRIVATE ${CSRCS})
  target_include_directories(libexpat PRIVATE ${INCDIR})

  if(CONFIG_LIBEXPAT_TEST)
    list(APPEND INCDIR {CMAKE_CURRENT_LIST_DIR}/libexpat/libexpat/expat/tests)
    set(TEST_SRCS
        libexpat/expat/tests/runtests.c libexpat/expat/tests/chardata.c
        libexpat/expat/tests/memcheck.c libexpat/expat/tests/minicheck.c
        libexpat/expat/tests/structdata.c)
    nuttx_add_application(
      NAME
      libexpat_runtests
      STACKSIZE
      ${CONFIG_LIBEXPAT_TEST_STACKSIZE}
      PRIORITY
      ${CONFIG_LIBEXPAT_TEST_PRIORITY}
      SRCS
      ${TEST_SRCS}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      DEPENDS
      libexpat)
  endif()

endif()
