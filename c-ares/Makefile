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

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}c-ares/src/lib
CFLAGS += -DHAVE_CONFIG_H

CSRCS  = $(wildcard c-ares/src/lib/*.c)
CSRCS += $(wildcard c-ares/src/lib/*/*.c)

ifneq ($(CONFIG_UTILS_CARES),)

CSRCS += c-ares/src/tools/ares_getopt.c

MAINSRC = c-ares/src/tools/adig.c c-ares/src/tools/ahost.c
PROGNAME = adig ahost
APPNAME = adig ahost
PRIORITY = $(CONFIG_UTILS_CARES_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_CARES_STACKSIZE)

MODULE = CONFIG_UTILS_CARES

endif

include $(APPDIR)/Application.mk
