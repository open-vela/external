#
# Copyright (C) 2022 Xiaomi Corporation
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

INITIAL_MEMORY ?= 65536

# Toolchain setting

WCC = $(WASI_SDK_ROOT)/bin/clang
MITEE_IOT_DIR = ../../vendor/xiaomi/mitee_iot/

WCFLAGS = $(filter-out $(ARCHCPUFLAGS) $(ARCHCFLAGS) $(ARCHINCLUDES) $(ARCHDEFINES) $(ARCHOPTIMIZATION) $(EXTRAFLAGS),$(CFLAGS))
WCFLAGS += --sysroot=$(WASI_SDK_ROOT)/share/wasi-sysroot -nostdlib $(MAXOPTIMIZATION)
WCFLAGS += -I$(MITEE_IOT_DIR)/tee/lib/libutee/include

WCFLAGS += -I$(MITEE_IOT_DIR)/tee/lib/libutils/ext/include
WCFLAGS += -I$(MITEE_IOT_DIR)/tee/lib/libutils/isoc/include
WCFLAGS += -I$(MITEE_IOT_DIR)/tee/include
WCFLAGS += -I$(MITEE_IOT_DIR)/crypto/libtomcrypt/include
WCFLAGS += -I../../apps/interpreters/wamr/wamr/core/iwasm/include
WCFLAGS += -DUSER_TA_WASM
WCFLAGS += -DTRACE_TAG='"ta_keystore"'
WCFLAGS += -DTRACE_LEVEL=$(CONFIG_TRACE_LEVEL)

WLDFLAGS = -z stack-size=$(STACKSIZE) -Wl,--initial-memory=$(INITIAL_MEMORY) -Wl,--export=main -Wl,--export=__main_argc_argv
WLDFLAGS += -Wl,--export=__heap_base -Wl,--export=__data_end
WLDFLAGS += -Wl,--no-entry -Wl,--strip-all -Wl,--allow-undefined
WLDFLAGS += -Wl,--export=wasm_TA_CreateEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_DestroyEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_OpenSessionEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_CloseSessionEntryPoint
WLDFLAGS += -Wl,--export=wasm_TA_InvokeCommandEntryPoint
# Targets follow


WBIN = $(PROGNAME)

WSRCS = $(MAINSRC) $(CSRCS)
WOBJS = $(WSRCS:%.c=%.wo)

ifeq ($(V),0)
  Q ?= @
endif

all:: $(WOBJS) $(WBIN)

$(WOBJS): %.wo : %.c
	@ echo "WCC: $^"
	$(Q) $(WCC) $(WCFLAGS) -c $^ -o $@

install:: $(WBIN)
	$(Q) install $(WBIN) $(BINDIR)

$(WBIN): $(WOBJS)
	$(Q) $(WCC) $(WOBJS) $(WCFLAGS) $(WLDFLAGS) -o $(WBIN)

clean::
	$(Q) rm -f $(WOBJS)
	$(Q) rm -f $(WBIN)