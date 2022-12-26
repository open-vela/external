#
# Copyright (C) 2020 Xiaomi Corporation
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

#RTOS-Benchmark

PROGNAME  = $(CONFIG_RTOS_BENCHMARK_PROGNAME)
PRIORITY  = $(CONFIG_RTOS_BENCHMARK_PRIORITY)
STACKSIZE = $(CONFIG_RTOS_BENCHMARK_STACKSIZE)
MODULE    = $(CONFIG_RTOS_BENCHMARK)

CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" rtos-benchmark/h}

CSRCS    += rtos-benchmark/src/common/bench_interrupt_latency_test.c    \
            rtos-benchmark/src/common/bench_mutex_lock_unlock_test.c    \
            rtos-benchmark/src/common/bench_sem_context_switch_test.c   \
            rtos-benchmark/src/common/bench_sem_signal_release_test.c   \
            rtos-benchmark/src/common/bench_thread_switch_yield_test.c  \
            rtos-benchmark/src/common/bench_thread_test.c               \
            rtos-benchmark/src/common/bench_malloc_free_test.c      \
            rtos-benchmark/src/common/bench_utils.c                     \
            rtos-benchmark/src/nuttx/bench_porting_layer_nuttx.c        \
            rtos-benchmark/src/nuttx/timer/timer.c

MAINSRC   = rtos-benchmark/src/common/bench_all.c

include $(APPDIR)/Application.mk
