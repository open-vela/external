#
# Copyright (C) 2023 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

CXXEXT = .cc

CXXFLAGS += ${INCDIR_PREFIX}googlebenchmark/src

CXXSRCS += googlebenchmark/src/benchmark_api_internal.cc
CXXSRCS += googlebenchmark/src/benchmark_name.cc
CXXSRCS += googlebenchmark/src/benchmark_register.cc
CXXSRCS += googlebenchmark/src/benchmark_runner.cc
CXXSRCS += googlebenchmark/src/benchmark.cc
CXXSRCS += googlebenchmark/src/check.cc
CXXSRCS += googlebenchmark/src/colorprint.cc
CXXSRCS += googlebenchmark/src/commandlineflags.cc
CXXSRCS += googlebenchmark/src/complexity.cc
CXXSRCS += googlebenchmark/src/console_reporter.cc
CXXSRCS += googlebenchmark/src/counter.cc
CXXSRCS += googlebenchmark/src/csv_reporter.cc
CXXSRCS += googlebenchmark/src/json_reporter.cc
CXXSRCS += googlebenchmark/src/perf_counters.cc
CXXSRCS += googlebenchmark/src/reporter.cc
CXXSRCS += googlebenchmark/src/statistics.cc
CXXSRCS += googlebenchmark/src/string_util.cc
CXXSRCS += googlebenchmark/src/sysinfo.cc
CXXSRCS += googlebenchmark/src/timers.cc
CXXSRCS += googlebenchmark/src/sleep.cc

PRIORITY  = $(CONFIG_LIB_GOOGLEBENCHMARK_PRIORITY)
STACKSIZE = $(CONFIG_LIB_GOOGLEBENCHMARK_STACKSIZE)
MODULE    = $(CONFIG_LIB_GOOGLEBENCHMARK)

MAINSRC  += googlebenchmark/src/benchmark_main.cc
PROGNAME += benchmark

include $(APPDIR)/Application.mk
