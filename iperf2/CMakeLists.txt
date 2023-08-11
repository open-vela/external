# ##############################################################################
# external/iperf2/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_UTILS_IPERF2)

  set(IPERF2_FLAGS
      -DHAVE_CONFIG_H
      -Wno-undef
      -Wno-shadow
      -Wno-unused-function
      -Dwarn=iperf2_warn
      -Dwarn_errno=iperf2_warn_errno
      -Dversion=iperf2_version
      $<$<COMPILE_LANGUAGE:C>:-Wno-strict-prototypes>)

  set(IPERF2_INCDIR . iperf2/include ${CMAKE_BINARY_DIR}/include)

  nuttx_add_application(
    NAME
    iperf2
    SRCS
    iperf2/src/main.cpp
    INCLUDE_DIRECTORIES
    ${IPERF2_INCDIR}
    COMPILE_FLAGS
    ${IPERF2_FLAGS}
    STACKSIZE
    ${CONFIG_UTILS_IPERF2_STACKSIZE}
    PRIORITY
    ${CONFIG_UTILS_IPERF2_PRIORITY})

  nuttx_add_library(iperf2)

  target_sources(
    iperf2
    PRIVATE iperf2/src/checksums.c
            iperf2/src/dscp.c
            iperf2/src/Extractor.c
            iperf2/src/gnu_getopt.c
            iperf2/src/gnu_getopt_long.c
            iperf2/src/histogram.c
            iperf2/src/Locale.c
            iperf2/src/packet_ring.c
            iperf2/src/pdfs.c
            iperf2/src/Reporter.c
            iperf2/src/ReportOutputs.c
            iperf2/src/Reports.c
            iperf2/src/service.c
            iperf2/src/SocketAddr.c
            iperf2/src/socket_io.c
            iperf2/src/stdio.c
            iperf2/src/tcp_window_size.c
            iperf2/compat/delay.c
            iperf2/compat/error.c
            iperf2/compat/gettcpinfo.c
            iperf2/compat/inet_ntop.c
            iperf2/compat/signal.c
            iperf2/compat/string.c
            iperf2/compat/Thread.c
            iperf2/src/active_hosts.cpp
            iperf2/src/Client.cpp
            iperf2/src/isochronous.cpp
            iperf2/src/Launch.cpp
            iperf2/src/Listener.cpp
            iperf2/src/PerfSocket.cpp
            iperf2/src/Server.cpp
            iperf2/src/Settings.cpp)

  target_include_directories(iperf2 PRIVATE ${IPERF2_INCDIR})
  target_compile_options(iperf2 PRIVATE ${IPERF2_FLAGS})

endif()
