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

CFLAGS += ${INCDIR_PREFIX}.
CXXFLAGS += ${INCDIR_PREFIX}.

CSRCS += $(wildcard lcm/lcm/*.c)
CSRCS += $(wildcard lcm/lcm/lcmtypes/*.c)

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib/glib
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib/glib

ifneq ($(CONFIG_LIB_LCM_TESTCASE),)

CFLAGS += ${INCDIR_PREFIX}lcm
CFLAGS += ${INCDIR_PREFIX}test/types

CXXFLAGS += ${INCDIR_PREFIX}lcm
CXXFLAGS += ${INCDIR_PREFIX}test/types

CXXFLAGS += -Wno-shadow -Wno-sign-compare -fexceptions
CFLAGS += -Wno-strict-prototypes -Wno-stringop-overflow
CFLAGS += -Wno-array-bounds -Wno-restrict

CSRCS += $(filter-out lcm/test/c/server.c, $(wildcard lcm/test/c/*.c))
CSRCS += $(wildcard test/types/*.c)

MAINSRC += lcm/test/c/server.c
PROGNAME += lcm_server

MAINSRC += test/lcm_test.cpp
PROGNAME += lcm_test

PRIORITY += SCHED_PRIORITY_DEFAULT
STACKSIZE += $(CONFIG_DEFAULT_TASK_STACKSIZE)

endif

include $(APPDIR)/Application.mk
