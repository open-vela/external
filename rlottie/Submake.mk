#
# Copyright (C) 2020 Xiaomi Corporation
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
# CXXFLAGS += -fpermissive
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" inc}

CXXSRCS  += $(wildcard src/binding/c/*.cpp)
CXXSRCS  += $(wildcard src/lottie/*.cpp)
CXXSRCS  += $(wildcard src/vector/*.cpp)
CXXSRCS  += $(wildcard src/vector/freetype/*.cpp)
CXXSRCS  += $(wildcard src/vector/stb/*.cpp)

CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/binding/c}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/lottie}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/vector}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/vector/freetype}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/vector/stb}

ifeq ($(ARCH),arm)
ASRCS += $(wildcard src/vector/pixman/*.S)
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/vector/pixman}
endif

include $(APPDIR)/Application.mk
