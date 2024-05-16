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
if(CONFIG_BENCHMARK_LMBENCH)

  set(CSRCS
      lmbench/src/getopt.c
      lmbench/src/lib_debug.c
      lmbench/src/lib_mem.c
      lmbench/src/lib_sched.c
      lmbench/src/lib_stats.c
      lmbench/src/lib_tcp.c
      lmbench/src/lib_timing.c
      lmbench/src/lib_udp.c
      lmbench/src/lib_unix.c)
  set(CFLAGS
      -Wno-all
      -Wno-strict-prototypes
      -Wno-shadow
      -Wno-format
      -Wno-pointer-to-int-cast
      -Wno-implicit-function-declaration
      -DHAVE_uint=1
      -DHAVE_int64_t=1
      -DHAVE_pmap_clnt_h
      -DHAVE_socklen_t
      -DHAVE_DRAND48
      -DHAVE_SCHED_SETAFFINITY=1
      -Wno-int-to-pointer-cast
      -Dtcp_connect=lmbench_tcp_connect
      -Dudp_connect=lmbench_udp_connect
      -Ulinux)

  target_sources(apps PRIVATE ${CSRCS})
  target_compile_options(apps PRIVATE ${CFLAGS})

  set(PROG_LIST
      busy
      bw_file_rd
      bw_mem
      bw_mmap_rd
      bw_pipe
      bw_tcp
      bw_udp
      bw_unix
      disk
      hello
      lat_cmd
      lat_connect
      lat_ctx
      lat_dram_page
      lat_fcntl
      lat_fifo
      lat_fs
      lat_mem_rd
      lat_mmap
      lat_ops
      lat_pagefault
      lat_pipe
      lat_pmake
      lat_proc
      lat_rand
      lat_select
      lat_sig
      lat_syscall
      lat_tcp
      lat_udp
      lat_unix
      lat_unix_connect
      lat_usleep
      line
      lmdd
      loop_o
      memsize
      msleep
      par_mem
      par_ops
      stream
      timing_o
      tlb)

  list(LENGTH PROG_LIST list_len)
  math(EXPR list_len "${list_len} - 1")

  foreach(idx RANGE ${list_len})
    list(GET PROG_LIST ${idx} prog_name)
    nuttx_add_application(
      NAME
      ${prog_name}
      STACKSIZE
      ${CONFIG_BENCHMARK_LMBENCH_STACKSIZE}
      PRIORITY
      ${CONFIG_BENCHMARK_LMBENCH_PRIORITY}
      SRCS
      lmbench/src/${prog_name}.c
      COMPILE_FLAGS
      ${CFLAGS})
  endforeach()

endif()
