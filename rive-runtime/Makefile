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

MODULE = $(CONFIG_LIB_RIVE_RUNTIME)

CXXEXT     := .cpp

RIVE_RUNTIME_DIR = ${INCDIR_PREFIX}$(APPDIR)/external/rive-runtime

CFLAGS += -Wno-shadow -Wno-undef
CXXFLAGS += -Wno-shadow -Wno-unused-but-set-variable

CXXSRCS += $(shell find -L $(RIVE_RUNTIME_DIR)/rive-runtime/src -name *.cpp)

include $(APPDIR)/Application.mk
