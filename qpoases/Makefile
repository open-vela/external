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

CXXSRCS += $(wildcard qpoases/src/*.cpp)
CXXSRCS += $(wildcard qpoases/interfaces/c/*.cpp)

CFLAGS += ${INCDIR_PREFIX}qpoases/interfaces/c
CFLAGS += -Wno-strict-prototypes
CXXFLAGS += -Wno-format-truncation -Wno-overloaded-virtual -Wno-unused-variable -Wno-undef \
            -Wno-misleading-indentation -Wno-shadow

define qpoases_add_benchmark
  PROGNAME += qpoases_$1
  MAINSRC += qpoases/$2/$1.$3
  PRIORITY += SCHED_PRIORITY_DEFAULT
  STACKSIZE += $(CONFIG_DEFAULT_TASK_STACKSIZE)
endef

ifneq ($(CONFIG_LIB_QPOASES_TESTCASE),)

QPOASES_EXCLUDE_CASE := example4CP

define add_benchmarks
  $(foreach benchmark, \
    $(filter-out $(QPOASES_EXCLUDE_CASE), $(patsubst %.$2,%,$(notdir $(wildcard qpoases/$1/*.$2)))), \
    $(eval $(call qpoases_add_benchmark,$(benchmark),$1,$2)))
endef

$(call add_benchmarks,testing/cpp,cpp)
$(call add_benchmarks,testing/c,c)
$(call add_benchmarks,examples,cpp)
$(call add_benchmarks,interfaces/c,c)
endif

include $(APPDIR)/Application.mk
