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

CXXEXT := .cc

SHEENBIDI_DIR = ${INCDIR_PREFIX}$(APPDIR)/external/SheenBidi/SheenBidi

CFLAGS += -Wno-shadow -Wno-maybe-uninitialized -Wstringop-overflow=0 -Wno-unused-variable -Wno-unused-function

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/SheenBidi/SheenBidi/Headers
CSRCS += $(wildcard $(SHEENBIDI_DIR)/Source/SheenBidi.c)

CFLAGS += -Os
CFLAGS += "-DSB_CONFIG_UNITY=1"
CFLAGS += "-DNDEBUG=1"
CFLAGS += "-DRELEASE=1"

include $(APPDIR)/Application.mk
