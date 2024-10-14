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

HARFBUZZ_DIR = ${INCDIR_PREFIX}$(APPDIR)/external/harfbuzz/harfbuzz

CFLAGS += -Wno-shadow -Wno-undef
CXXFLAGS += -Wno-shadow -Wno-unused-but-set-variable -Wno-class-memaccess -Wsign-compare -Wunused-variable

ifeq ($(CONFIG_LIB_FREETYPE),y)
CXXFLAGS += "-DHAVE_FREETYPE=1"
endif

CXXSRCS += $(wildcard $(HARFBUZZ_DIR)/src/harfbuzz.cc)

include $(APPDIR)/Application.mk
