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

CSRCS += \
lmbench/src/getopt.c \
lmbench/src/lib_debug.c \
lmbench/src/lib_mem.c \
lmbench/src/lib_sched.c \
lmbench/src/lib_stats.c \
lmbench/src/lib_tcp.c \
lmbench/src/lib_timing.c \
lmbench/src/lib_udp.c \
lmbench/src/lib_unix.c

PROGNAME += bw_mem
MAINSRC += lmbench/src/bw_mem.c
PRIORITY  += $(CONFIG_BENCHMARK_LMBENCH_PRIORITY)
STACKSIZE += $(CONFIG_BENCHMARK_LMBENCH_STACKSIZE)

PROGNAME += lat_syscall
MAINSRC += lmbench/src/lat_syscall.c
PRIORITY  += $(CONFIG_BENCHMARK_LMBENCH_PRIORITY)
STACKSIZE += $(CONFIG_BENCHMARK_LMBENCH_STACKSIZE)

PROGNAME += lat_mem_rd
MAINSRC += lmbench/src/lat_mem_rd.c
PRIORITY  += $(CONFIG_BENCHMARK_LMBENCH_PRIORITY)
STACKSIZE += $(CONFIG_BENCHMARK_LMBENCH_STACKSIZE)

CFLAGS += -Wno-all -Wno-strict-prototypes -Wno-shadow \
-Wno-format -Wno-pointer-to-int-cast -Wno-implicit-function-declaration

CFLAGS += -DHAVE_uint=1 -DHAVE_int64_t=1 -DHAVE_pmap_clnt_h \
-DHAVE_socklen_t -DHAVE_DRAND48 -DHAVE_SCHED_SETAFFINITY=1

include $(APPDIR)/Application.mk
