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

CXXEXT = .cpp
CXXSRCS = $(wildcard aac/*/src/*$(CXXEXT))

CXXFLAGS += -Wno-undef

CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libArithCoding/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libDRCdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libFDK/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libMpegTPDec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libMpegTPEnc/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libPCMutils/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libSACdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libSACenc/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libSBRdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" aac/libSBRenc/include}

include $(APPDIR)/Application.mk
