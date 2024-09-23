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

CXXEXT := .cpp

RIVE_RUNTIME_DIR = ${INCDIR_PREFIX}$(APPDIR)/external/rive-runtime/rive-runtime

CXXFLAGS += -Wno-shadow -Wno-sign-compare -Wno-class-memaccess -Wno-alloc-size-larger-than
CXXFLAGS += -Wno-format-security -Wno-format -Wno-nonnull -Wno-maybe-uninitialized -Wno-stringop-overflow -Wno-array-bounds

CXXSRCS += $(shell find -L rive-runtime/src -name *.cpp)

ifeq ($(and $(CONFIG_LIB_HARFBUZZ),$(CONFIG_LIB_SHEENBIDI)),y)
CXXFLAGS += -DWITH_RIVE_TEXT=1
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/SheenBidi/SheenBidi/Headers
CXXFLAGS +=  ${INCDIR_PREFIX}$(APPDIR)/external/harfbuzz/harfbuzz/src
endif

include $(APPDIR)/Application.mk
