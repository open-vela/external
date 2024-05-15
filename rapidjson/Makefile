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

PRIORITY  += SCHED_PRIORITY_DEFAULT
STACKSIZE += $(CONFIG_DEFAULT_TASK_STACKSIZE)

CXXFLAGS += ${INCDIR_PREFIX}rapidjson/test/unittest

CXXFLAGS += -fexceptions -Wno-shadow -Wno-sign-compare -Wno-infinite-recursion
CXXFLAGS += -Wno-class-memaccess -Wno-deprecated-declarations

MAINSRC += unittest.cpp
PROGNAME += unittest

include $(APPDIR)/Application.mk
