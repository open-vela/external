# ##############################################################################
# external/iperf3/CMakeLists.txt
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

if(CONFIG_UTILS_IPERF3)

  set(IPERF3_FLAGS -Dlinux -Dversion=iperf3_version)

  set(IPERF3_INCDIR .)

  nuttx_add_application(
    NAME
    iperf3
    SRCS
    iperf3/src/main.c
    INCLUDE_DIRECTORIES
    ${IPERF3_INCDIR}
    COMPILE_FLAGS
    ${IPERF3_FLAGS}
    STACKSIZE
    ${CONFIG_UTILS_IPERF3_STACKSIZE}
    PRIORITY
    ${CONFIG_UTILS_IPERF3_PRIORITY})

  nuttx_add_library(iperf3)

  set(CSRCS
      iperf3/src/iperf_api.c
      iperf3/src/iperf_error.c
      iperf3/src/iperf_auth.c
      iperf3/src/iperf_client_api.c
      iperf3/src/iperf_locale.c
      iperf3/src/iperf_server_api.c
      iperf3/src/iperf_tcp.c
      iperf3/src/iperf_udp.c
      iperf3/src/iperf_sctp.c
      iperf3/src/iperf_util.c
      iperf3/src/iperf_time.c
      iperf3/src/dscp.c
      iperf3/src/net.c
      iperf3/src/tcp_info.c
      iperf3/src/timer.c
      iperf3/src/units.c)

  if(NOT $(CONFIG_NETUTILS_CJSON))
    list(APPEND CSRCS iperf3/src/cjson.c)
  endif()

  target_sources(iperf3 PRIVATE ${CSRCS})

  target_include_directories(iperf3 PRIVATE ${IPERF3_INCDIR})
  target_compile_options(iperf3 PRIVATE ${IPERF3_FLAGS})

endif()
