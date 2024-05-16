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
if(CONFIG_LIBCONFIG)

  set(CSRCS
      libconfig/lib/grammar.c
      libconfig/lib/libconfig.c
      libconfig/lib/scanctx.c
      libconfig/lib/scanner.c
      libconfig/lib/strbuf.c
      libconfig/lib/util.c
      libconfig/lib/wincompat.c
      libconfig/lib/strvec.c)
  set(CFLAGS -DYYINITDEPTH=${CONFIG_LIBCONFIG_YYINITDEPTH}
             -DYYMAXDEPTH=${CONFIG_LIBCONFIG_YYMAXDEPTH} -Wno-strict-prototypes)
  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/libconfig/lib
             ${CMAKE_CURRENT_LIST_DIR}/libconfig/tinytest)

  target_sources(apps PRIVATE ${CSRCS})
  target_include_directories(apps PRIVATE ${INCDIR})
  target_compile_options(apps PRIVATE ${CFLAGS})

  if(CONFIG_LIBCONFIG_TEST)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIBCONFIG_TEST}
      NAME
      test_libconfig
      STACKSIZE
      ${CONFIG_LIBCONFIG_TEST_STACKSIZE}
      PRIORITY
      ${CONFIG_LIBCONFIG_TEST_PRIORITY}
      SRCS
      libconfig/tests/tests.c
      libconfig/tinytest/tinytest.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS})
  endif()

endif()
