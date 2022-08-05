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
CXXSRCS = $(wildcard */src/*$(CXXEXT))

CXXFLAGS += -Wno-undef

CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libAACdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libAACenc/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libFDK/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libSYS/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libSBRdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libSBRenc/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libMpegTPDec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libMpegTPEnc/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libPCMutils/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libArithCoding/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libDRCdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libSACdec/include}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" libSACenc/include}

include $(APPDIR)/Application.mk
