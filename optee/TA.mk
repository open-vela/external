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

ifeq ($(CONFIG_USER_TA_WASM),y)
WLDFLAGS += -Wl,--export=wasm_TA_CreateEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_DestroyEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_OpenSessionEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_CloseSessionEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_InvokeCommandEntryPoint
endif

CFLAGS += -DCFG_NUM_THREADS=1

ifeq ($(CONFIG_USER_TA_WASM),y)
CFLAGS += -DUSER_TA_WASM
endif

ifneq ($(CONFIG_DEBUG_INFO),)
CFLAGS += -DTRACE_LEVEL=3
else ifneq ($(CONFIG_DEBUG_WARN),)
CFLAGS += -DTRACE_LEVEL=2
else ifneq ($(CONFIG_DEBUG_ERROR),)
CFLAGS += -DTRACE_LEVEL=1
else
# the default TRACE_LEVEL are 1(with error level)
CFLAGS += -DTRACE_LEVEL=1
endif

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/frameworks/security/optee_vela/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/core/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutee/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutils/ext/include

ifeq ($(CONFIG_USER_TA_WASM),y)
CSRCS += $(APPDIR)/frameworks/security/optee_vela/wasm/wasm_ta_framework.c
endif

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifeq ($(CONFIG_USER_TA_WASM),y)
ifneq ($(NOEXPORTSRCS),)
BIN := lib$(PROGNAME)$(LIBEXT)
endif
endif

STACKSIZE ?= 4096
PRIORITY  ?= SCHED_PRIORITY_DEFAULT

ifeq ($(CONFIG_USER_TA_WASM),y)
ifeq ($(MODULE),y)
WASM_INITIAL_MEMORY = 65536
WASM_BUILD = y
WAMR_MODE = XIP
endif
endif

ifeq ($(CONFIG_USER_TA_ELF),y)
DYNLIB = y
CFLAGS += -fno-lto
LDMODULEFLAGS += -flinker-output=nolto-rel
LDMODULEFLAGS += -fno-lto
endif

include $(APPDIR)/Application.mk
