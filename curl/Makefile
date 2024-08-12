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
CFLAGS += -DMAXINFO=256
CFLAGS += -DBUFFSIZE=64
CFLAGS += -DMAX_PARAMETERS=16

ifneq ($(CONFIG_LIB_CARES),)
CFLAGS += -DUSE_ARES
endif

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/system/zlib/zlib
CFLAGS += ${INCDIR_PREFIX}curl/lib

CSRCS = $(wildcard curl/lib/*.c)
CSRCS += $(wildcard curl/lib/vauth/*.c)
CSRCS += $(wildcard curl/lib/vquic/*.c)
CSRCS += $(wildcard curl/lib/vtls/*.c)

ifneq ($(CONFIG_UTILS_CURL),)
PROGNAME  = $(CONFIG_UTILS_CURL_PROGNAME)
PRIORITY  = $(CONFIG_UTILS_CURL_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_CURL_STACKSIZE)
MODULE    = $(CONFIG_UTILS_CURL)

CFLAGS += -Dconfig_init=curl_config_init
CFLAGS += -Dconfig_free=curl_config_free
CFLAGS += -Dstr2num=curl_str2num

MAINSRC = curl/src/tool_main.c
HELP_C  = tool_listhelp.c
CSRCS  += $(HELP_C)
CSRCS  += $(filter-out $(MAINSRC) curl/src/$(HELP_C),$(wildcard curl/src/*.c))

# Get .d files with Category=important
CMD_GEN_HELP  = grep Category curl/docs/cmdline-opts/*.d | grep important | cut -d ":" -f 1
# Generate the listhelp.c with these .d files
CMD_GEN_HELP += | xargs curl/docs/cmdline-opts/gen.pl listhelp
# Add curl/src prefix to headers
CMD_GEN_HELP += | sed 's@\#include "@\#include "curl/src/@'

$(HELP_C):
	$(Q) $(CMD_GEN_HELP) > $@

context:: $(HELP_C)

distclean::
	$(call DELFILE, $(HELP_C))

endif

include $(APPDIR)/Application.mk
