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

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_client/optee_client/libteec/include
CFLAGS += -DBINARY_PREFIX=\"TEEC\"

ifneq ($(CONFIG_DEBUG_INFO),)
CFLAGS += -DDEBUGLEVEL=3
else ifneq ($(CONFIG_DEBUG_WARN),)
CFLAGS += -DDEBUGLEVEL=2
else ifneq ($(CONFIG_DEBUG_ERROR),)
CFLAGS += -DDEBUGLEVEL=1
else
# the default DEBUGLEVEL are 1(with error level)
CFLAGS += -DDEBUGLEVEL=1
endif

CSRCS += optee_client/libteec/src/tee_client_api.c
CSRCS += optee_client/libteec/src/teec_trace.c

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libopteec$(LIBEXT)
endif

include $(APPDIR)/Application.mk
