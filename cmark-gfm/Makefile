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

# Filter out directly included files.

CMARK_FILTER_OUT := cmark-gfm/src/main.c

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}cmark-gfm/src
CFLAGS += ${INCDIR_PREFIX}cmark-gfm/extensions

CFLAGS += -DCMARK_DEBUG_NODES=0

CSRCS += $(filter-out $(CMARK_FILTER_OUT), $(wildcard cmark-gfm/src/*.c))
CSRCS += $(filter-out $(CMARK_FILTER_OUT), $(wildcard cmark-gfm/extensions/*.c))

include $(APPDIR)/Application.mk
