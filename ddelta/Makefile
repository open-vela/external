#
# Copyright (C) 2023 Xiaomi Corporation
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

ifneq ($(CONFIG_UTILS_DDELTA),)
PROGNAME  = ddelta_apply
PRIORITY  = $(CONFIG_UTILS_DDELTA_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_DDELTA_STACKSIZE)
MODULE    = $(CONFIG_UTILS_DDELTA)
CFLAGS   += -DDDELTA_BLOCK_SIZE=$(STACKSIZE)/3
CFLAGS   += ${INCDIR_PREFIX}$(APPDIR)/external/zlib/zlib
MAINSRC   = ddelta/ddelta_apply.c
endif

include $(APPDIR)/Application.mk
