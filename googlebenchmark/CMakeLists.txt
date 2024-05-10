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
if(CONFIG_LIB_GOOGLEBENCHMARK)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_CXX_INCLUDE_DIRECTORIES
             ${CMAKE_CURRENT_LIST_DIR}/googlebenchmark/include)

  set(CXXSRC_DIR ${CMAKE_CURRENT_LIST_DIR}/googlebenchmark/src)
  set(CXXSRCS ${CXXSRC_DIR}/benchmark_main.cc)
  list(
    APPEND
    CXXSRCS
    ${CXXSRC_DIR}/benchmark_api_internal.cc
    ${CXXSRC_DIR}/benchmark_name.cc
    ${CXXSRC_DIR}/benchmark_register.cc
    ${CXXSRC_DIR}/benchmark_runner.cc
    ${CXXSRC_DIR}/benchmark.cc
    ${CXXSRC_DIR}/check.cc
    ${CXXSRC_DIR}/colorprint.cc
    ${CXXSRC_DIR}/commandlineflags.cc
    ${CXXSRC_DIR}/complexity.cc
    ${CXXSRC_DIR}/console_reporter.cc
    ${CXXSRC_DIR}/counter.cc
    ${CXXSRC_DIR}/csv_reporter.cc
    ${CXXSRC_DIR}/json_reporter.cc
    ${CXXSRC_DIR}/perf_counters.cc
    ${CXXSRC_DIR}/reporter.cc
    ${CXXSRC_DIR}/statistics.cc
    ${CXXSRC_DIR}/string_util.cc
    ${CXXSRC_DIR}/sysinfo.cc
    ${CXXSRC_DIR}/timers.cc
    ${CXXSRC_DIR}/sleep.cc)

  nuttx_add_application(
    MODULE
    ${CONFIG_LIB_GOOGLEBENCHMARK}
    NAME
    benchmark
    STACKSIZE
    ${CONFIG_LIB_GOOGLEBENCHMARK_STACKSIZE}
    PRIORITY
    ${CONFIG_LIB_GOOGLEBENCHMARK_PRIORITY}
    SRCS
    ${CXXSRCS}
    INCLUDE_DIRECTORIES
    ${CXXSRC_DIR})

endif()
