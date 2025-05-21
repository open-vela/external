#
# Copyright (C) 2024 Xiaomi Corporation
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

if(CONFIG_LIB_ERPC)
  set(ERPC_DIR ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${ERPC_DIR}/config ${ERPC_DIR}/infra
             ${ERPC_DIR}/port ${ERPC_DIR}/setup ${ERPC_DIR}/transports)

  nuttx_add_library(erpc STATIC)

  set(ERPC_FLAGS
      -DERPC_HAS_POSIX=1
      -DERPC_DEFAULT_BUFFER_SIZE=CONFIG_ERPC_DEFAULT_BUFFER_SIZE
      -Wunused-variable
      -Wno-deprecated-register
      -Wno-narrowing
      -Wno-free-nonheap-object
      -Wno-maybe-uninitialized)

  if(CONFIG_ERPC_PRE_POST_ACTION)
    list(APPEND ERPC_FLAGS -DERPC_PRE_POST_ACTION=1)
  else()
    list(APPEND ERPC_FLAGS -DERPC_PRE_POST_ACTION=0)
  endif()

  set(ERPC_SRCS
      ${ERPC_DIR}/infra/erpc_arbitrated_client_manager.cpp
      ${ERPC_DIR}/infra/erpc_basic_codec.cpp
      ${ERPC_DIR}/infra/erpc_client_manager.cpp
      ${ERPC_DIR}/infra/erpc_crc16.cpp
      ${ERPC_DIR}/infra/erpc_framed_transport.cpp
      ${ERPC_DIR}/infra/erpc_message_buffer.cpp
      ${ERPC_DIR}/infra/erpc_message_loggers.cpp
      ${ERPC_DIR}/infra/erpc_server.cpp
      ${ERPC_DIR}/infra/erpc_simple_server.cpp
      ${ERPC_DIR}/infra/erpc_transport_arbitrator.cpp
      ${ERPC_DIR}/infra/erpc_utils.cpp
      ${ERPC_DIR}/infra/erpc_pre_post_action.cpp
      ${ERPC_DIR}/port/erpc_port_stdlib.cpp
      ${ERPC_DIR}/port/erpc_threading_pthreads.cpp
      ${ERPC_DIR}/setup/erpc_arbitrated_client_setup.cpp
      ${ERPC_DIR}/setup/erpc_client_setup.cpp
      ${ERPC_DIR}/setup/erpc_setup_mbf_dynamic.cpp
      ${ERPC_DIR}/setup/erpc_setup_mbf_static.cpp
      ${ERPC_DIR}/setup/erpc_server_setup.cpp
      ${ERPC_DIR}/setup/erpc_setup_serial.cpp
      ${ERPC_DIR}/setup/erpc_setup_tcp.cpp
      ${ERPC_DIR}/setup/erpc_setup_rpmsg_sock.cpp
      ${ERPC_DIR}/transports/erpc_inter_thread_buffer_transport.cpp
      ${ERPC_DIR}/transports/erpc_rpmsg_sock_transport.cpp
      ${ERPC_DIR}/transports/erpc_sock_transport.cpp)

  target_sources(erpc PRIVATE ${ERPC_SRCS})
  target_compile_options(erpc PRIVATE ${ERPC_FLAGS})
endif()
