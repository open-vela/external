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

CFLAGS += -DHAVE_CONFIG_H
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/zlib/zlib}

CSRCS = $(wildcard curl/lib/*.c)
CSRCS += $(wildcard curl/lib/vauth/*.c)
CSRCS += $(wildcard curl/lib/vtls/*.c)

ifneq ($(CONFIG_TOOLS_CURL),)
PROGNAME  = $(CONFIG_TOOLS_CURL_PROGNAME)
PRIORITY  = $(CONFIG_TOOLS_CURL_PRIORITY)
STACKSIZE = $(CONFIG_TOOLS_CURL_STACKSIZE)
MODULE    = $(CONFIG_TOOLS_CURL)

CFLAGS += -Dconfig_init=curl_config_init
CFLAGS += -Dstr2num=curl_str2num
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" curl/lib}

MAINSRC = curl/src/tool_main.c
CSRCS  += $(filter-out $(MAINSRC),$(wildcard curl/src/*.c))
endif

include $(APPDIR)/Application.mk
