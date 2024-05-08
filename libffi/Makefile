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

ifeq ($(CONFIG_ARCH),arm)
TARGETDIR := arm
LIBFFI_TARGET=ARM
else ifeq ($(CONFIG_ARCH),arm64)
TARGETDIR := aarch64
LIBFFI_TARGET=AARCH64
else ifeq ($(CONFIG_ARCH),xtensa)
TARGETDIR := xtensa
LIBFFI_TARGET=XTENSA
else ifeq ($(CONFIG_ARCH),sim)
CFLAGS += -fno-sanitize=kernel-address
TARGETDIR := x86
LIBFFI_TARGET=X86_64
endif

FLAGS += ${INCDIR_PREFIX}.
FLAGS += ${INCDIR_PREFIX}libffi
FLAGS += ${INCDIR_PREFIX}libffi/src
FLAGS += ${INCDIR_PREFIX}libffi/src/$(TARGETDIR)

CFLAGS += $(FLAGS)
CFLAGS += -Wno-deprecated-declarations
CFLAGS_FILTER_OUT = -Wundef
CFLAGS := $(filter-out $(CFLAGS_FILTER_OUT), $(CFLAGS))

CSRCS += libffi/src/prep_cif.c libffi/src/types.c libffi/src/raw_api.c \
         libffi/src/java_raw_api.c libffi/src/closures.c libffi/src/debug.c

CSRCS += libffi/src/$(TARGETDIR)/ffi.c
ASRCS += libffi/src/$(TARGETDIR)/sysv.S

AFLAGS += $(FLAGS)
AFLAGS_FILTER_OUT = -Wundef
AFLAGS := $(filter-out $(AFLAGS_FILTER_OUT), $(AFLAGS))

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libffi.a
endif

include $(APPDIR)/Application.mk

