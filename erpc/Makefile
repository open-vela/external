#
# Copyright (C) 2024 Xiaomi Corporation
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

CXXEXT = .cpp

CXXSRCS += erpc/erpc_c/infra/erpc_arbitrated_client_manager.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_basic_codec.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_client_manager.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_crc16.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_framed_transport.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_message_buffer.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_message_loggers.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_server.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_simple_server.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_transport_arbitrator.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_utils.cpp
CXXSRCS += erpc/erpc_c/infra/erpc_pre_post_action.cpp
CXXSRCS += erpc/erpc_c/port/erpc_port_stdlib.cpp
CXXSRCS += erpc/erpc_c/port/erpc_threading_pthreads.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_arbitrated_client_setup.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_client_setup.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_setup_mbf_dynamic.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_setup_mbf_static.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_server_setup.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_setup_serial.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_setup_tcp.cpp
CXXSRCS += erpc/erpc_c/setup/erpc_setup_rpmsg_sock.cpp
CXXSRCS += erpc/erpc_c/transports/erpc_inter_thread_buffer_transport.cpp
CXXSRCS += erpc/erpc_c/transports/erpc_rpmsg_sock_transport.cpp
CXXSRCS += erpc/erpc_c/transports/erpc_sock_transport.cpp

ifeq ($(CONFIG_ERPC_PRE_POST_ACTION),)
  CXXFLAGS += -DERPC_PRE_POST_ACTION=0
else
  CXXFLAGS += -DERPC_PRE_POST_ACTION=1
endif

CXXFLAGS += -DERPC_HAS_POSIX=1
CXXFLAGS += -DERPC_DEFAULT_BUFFER_SIZE=CONFIG_ERPC_DEFAULT_BUFFER_SIZE

CXXFLAGS += ${INCDIR_PREFIX}erpc/erpc_c/config
CXXFLAGS += ${INCDIR_PREFIX}erpc/erpc_c/infra
CXXFLAGS += ${INCDIR_PREFIX}erpc/erpc_c/port
CXXFLAGS += ${INCDIR_PREFIX}erpc/erpc_c/setup
CXXFLAGS += ${INCDIR_PREFIX}erpc/erpc_c/transports

CXXFLAGS += -Wunused-variable -Wno-deprecated-register -Wno-narrowing
CXXFLAGS += -Wno-narrowing -Wno-free-nonheap-object -Wno-maybe-uninitialized

ifneq ($(CONFIG_ERPC_TEST_SERVER)$(CONFIG_ERPC_TEST_CLIENT),)
CXXSRCS += test_interface.cpp
endif

include $(APPDIR)/Application.mk
