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
if(CONFIG_UTILS_DIVIDE)

  set(MAIN_SRC_LIST benchmark.cpp benchmark_branchfree.cpp test_c99.c
                    tester.cpp)

  set(PROGNAME_LIST divide_benchmark divide_benchmark_branchfree
                    divide_test_c99 divide_tester)

  list(LENGTH MAIN_SRC_LIST list_len)
  math(EXPR list_len "${list_len} - 1")

  foreach(idx RANGE ${list_len})
    list(GET MAIN_SRC_LIST ${idx} source_file)
    list(GET PROGNAME_LIST ${idx} prog_name)
    nuttx_add_application(
      MODULE
      ${CONFIG_UTILS_DIVIDE}
      NAME
      ${prog_name}
      STACKSIZE
      ${CONFIG_UTILS_DIVIDE_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_DIVIDE_PRIORITY}
      SRCS
      libdivide/test/${source_file}
      INCLUDE_DIRECTORIES
      ${CMAKE_CURRENT_LIST_DIR}/libdivide)
  endforeach()

endif()
