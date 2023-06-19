#
# Copyright (C) 2022 Xiaomi Corporation
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
CFLAGS += ${INCDIR_PREFIX}libexpat/expat/lib
CSRCS  += $(wildcard libexpat/expat/lib/*.c)

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libtelephony.a
endif

ifeq ($(CONFIG_LIBEXPAT_TEST),y)
PRIORITY  = $(CONFIG_LIBEXPAT_TEST_PRIORITY)
STACKSIZE = $(CONFIG_LIBEXPAT_TEST_STACKSIZE)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/libexpat/libexpat/expat/tests
CSRCS  += libexpat/expat/tests/chardata.c \
	libexpat/expat/tests/memcheck.c \
	libexpat/expat/tests/minicheck.c \
	libexpat/expat/tests/structdata.c
PROGNAME += libexpat_runtests
MAINSRC += libexpat/expat/tests/runtests.c
endif

include $(APPDIR)/Application.mk
