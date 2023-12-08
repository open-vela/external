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

define add_benchmark
  PROGNAME += $1
  MAINSRC += lmbench/src/$1.c
  PRIORITY += $(CONFIG_BENCHMARK_LMBENCH_PRIORITY)
  STACKSIZE += $(CONFIG_BENCHMARK_LMBENCH_STACKSIZE)
endef

BENCHMARKS = busy bw_file_rd bw_mem bw_mmap_rd bw_pipe bw_tcp bw_udp bw_unix
BENCHMARKS += disk hello
BENCHMARKS += lat_cmd lat_connect lat_ctx lat_dram_page lat_fcntl lat_fifo \
lat_fs lat_mem_rd lat_mmap lat_ops lat_pagefault lat_pipe lat_pmake lat_proc \
lat_rand lat_select lat_sig lat_syscall lat_tcp lat_udp lat_unix \
lat_unix_connect lat_usleep
BENCHMARKS += line lmdd loop_o memsize msleep par_mem par_ops stream timing_o tlb

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

$(foreach benchmark,$(BENCHMARKS),$(eval $(call add_benchmark,$(benchmark))))

CFLAGS += -Dtcp_connect=lmbench_tcp_connect
CFLAGS += -Dudp_connect=lmbench_udp_connect -Ulinux
CFLAGS += -Wno-all -Wno-strict-prototypes -Wno-shadow \
-Wno-format -Wno-pointer-to-int-cast -Wno-implicit-function-declaration

CFLAGS += -DHAVE_uint=1 -DHAVE_int64_t=1 -DHAVE_pmap_clnt_h \
-DHAVE_socklen_t -DHAVE_DRAND48 -DHAVE_SCHED_SETAFFINITY=1 -Wno-int-to-pointer-cast

include $(APPDIR)/Application.mk
