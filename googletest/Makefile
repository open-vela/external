#
# Copyright (C) 2021 Xiaomi Corporation
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

MODULE = $(CONFIG_LIB_GOOGLETEST)
CXXEXT = .cc

CXXFLAGS += ${INCDIR_PREFIX}googletest/googletest
CXXFLAGS += ${INCDIR_PREFIX}googletest/googlemock

CXXFLAGS += -DGTEST_HAS_POSIX_RE=0

CXXSRCS += googletest/googletest/src/gtest-all.cc
CXXSRCS += googletest/googlemock/src/gmock-all.cc

ifneq ($(CONFIG_UTILS_GTEST),)
PROGNAME += $(CONFIG_UTILS_GTEST_PROGNAME)
PRIORITY += $(CONFIG_UTILS_GTEST_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_GTEST_STACKSIZE)
MAINCXXSRCS += googletest/googletest/src/gtest_main.cc
endif

ifneq ($(CONFIG_UTILS_GMOCK),)
PROGNAME += $(CONFIG_UTILS_GMOCK_PROGNAME)
PRIORITY += $(CONFIG_UTILS_GMOCK_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_GMOCK_STACKSIZE)
MAINCXXSRCS += googletest/googlemock/src/gmock_main.cc
endif

include $(APPDIR)/Application.mk
