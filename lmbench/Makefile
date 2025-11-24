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
  PROGNAME +=  ${CONFIG_BENCHMARK_LMBENCH_CMD_PREFIX}$1
  ifeq (,$(wildcard lmbench/src/$1.cpp))
    MAINSRC += lmbench/src/$1.c
  else
    MAINSRC += lmbench/src/$1.cpp
  endif
  PRIORITY += $(CONFIG_BENCHMARK_LMBENCH_PRIORITY)
  STACKSIZE += $(CONFIG_BENCHMARK_LMBENCH_STACKSIZE)
endef

BENCHMARKS = busy bw_file_rd bw_mem bw_mmap_rd bw_pipe bw_tcp bw_udp bw_unix bw_vsock
BENCHMARKS += disk
BENCHMARKS += lat_cmd lat_connect lat_ctx lat_dram_page lat_fcntl lat_fifo \
lat_fs lat_mem_rd lat_mmap lat_ops lat_pagefault lat_pipe lat_pmake lat_proc \
lat_rand lat_sig lat_syscall lat_unix \
lat_unix_connect lat_usleep lat_vsock lat_rpmsg
BENCHMARKS += line lmdd loop_o memsize msleep par_mem par_ops stream timing_o tlb
BENCHMARKS += lat_binder bw_binder

CSRCS += \
lmbench/src/getopt.c \
lmbench/src/lib_debug.c \
lmbench/src/lib_mem.c \
lmbench/src/lib_sched.c \
lmbench/src/lib_stats.c \
lmbench/src/lib_timing.c \
lmbench/src/lib_unix.c \
lmbench/src/lib_vsock.c \
lmbench/src/lib_rpmsg.c

ifeq ($(CONFIG_BENCHMARK_LMBENCH_NET),y)
  BENCHMARKS += lat_select lat_tcp lat_udp

  CSRCS += \
  lmbench/src/lib_tcp.c \
  lmbench/src/lib_udp.c
endif

$(foreach benchmark,$(BENCHMARKS),$(eval $(call add_benchmark,$(benchmark))))

BENCH_FLAGS += -Wno-all -Wno-shadow -Wno-format
CFLAGS += -Dtcp_connect=lmbench_tcp_connect
CFLAGS += -Dudp_connect=lmbench_udp_connect -Ulinux
CFLAGS += -Wno-strict-prototypes -Wno-pointer-to-int-cast -Wno-implicit-function-declaration

BENCH_FLAGS += -DHAVE_uint=1 -DHAVE_int64_t=1 -DHAVE_pmap_clnt_h \
-DHAVE_socklen_t -DHAVE_DRAND48 -DHAVE_SCHED_SETAFFINITY=1 -Wno-int-to-pointer-cast
CFLAGS += -DMAX_MSIZE=2048

CFLAGS += $(BENCH_FLAGS)
CXXFLAGS += $(BENCH_FLAGS) -Wno-write-strings

include $(APPDIR)/Application.mk
