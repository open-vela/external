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

CXXSRCS += $(wildcard yaml-cpp/src/*.cpp)
CXXSRCS += $(wildcard yaml-cpp/src/contrib/*.cpp)

CXXFLAGS += ${INCDIR_PREFIX}yaml-cpp/test
CXXFLAGS += ${INCDIR_PREFIX}yaml-cpp/src
CXXFLAGS += -Wno-unused-variable -Wno-sign-compare -Wno-shadow \
            -Wno-range-loop-construct

ifneq ($(CONFIG_LIB_YAMLCPP_TESTCASE),)
PROGNAME += yaml_cpp_test
MAINSRC += yaml_cpp_test.cpp
PRIORITY += SCHED_PRIORITY_DEFAULT
STACKSIZE += $(CONFIG_DEFAULT_TASK_STACKSIZE)
endif

include $(APPDIR)/Application.mk
