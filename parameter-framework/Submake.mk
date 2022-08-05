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

CXXEXT   := .cpp
CXXSRCS  += bindings/c/ParameterFramework.cpp
CXXSRCS  += $(wildcard parameter/*.cpp)
CXXSRCS  += $(wildcard remote-processor/*.cpp)
CXXSRCS  += $(wildcard xmlserializer/*.cpp)
CXXSRCS  += $(wildcard utility/*.cpp)
CXXSRCS  += $(wildcard utility/nuttx/*.cpp)

CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" parameter/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" parameter/log/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" remote-processor}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" xmlserializer}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" utility}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" asio/stub}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/libxml2/libxml2/include}

ifeq ($(NETWORKING),)
CXXSRCS  := $(filter-out remote-processor/BackgroundRemoteProcessorServer.cpp, $(CXXSRCS))
endif

include $(APPDIR)/Application.mk
