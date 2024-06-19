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
else ifeq ($(CONFIG_ARCH),arm64)
TARGETDIR := aarch64
else ifeq ($(CONFIG_ARCH),xtensa)
TARGETDIR := xtensa
else ifeq ($(CONFIG_ARCH),sim)
TARGETDIR := x86
endif

# When libffi builds the stack frame, it will modify the contents of the
# asan red zone, causing runtime errors.
#
# For details, refer to the following issues:
# https://github.com/libffi/libffi/issues/255

CFLAGS += -fno-sanitize=all -fno-stack-protector

FLAGS += ${INCDIR_PREFIX}.
FLAGS += ${INCDIR_PREFIX}libffi
FLAGS += ${INCDIR_PREFIX}libffi/src
FLAGS += ${INCDIR_PREFIX}libffi/${TARGETDIR}

CFLAGS += $(FLAGS)
CFLAGS += -Wno-deprecated-declarations
CFLAGS_FILTER_OUT = -Wundef
CFLAGS := $(filter-out $(CFLAGS_FILTER_OUT), $(CFLAGS))

CSRCS += libffi/src/prep_cif.c libffi/src/types.c libffi/src/raw_api.c \
         libffi/src/java_raw_api.c libffi/src/closures.c libffi/src/debug.c

ifeq ($(CONFIG_ARCH_SIM),)
  CSRCS += libffi/src/$(TARGETDIR)/ffi.c
else ifeq ($(CONFIG_SIM_M32),)
  CFLAGS += -D__ILP32__
  CSRCS += libffi/src/$(TARGETDIR)/ffi64.c
  ASRCS += libffi/src/$(TARGETDIR)/unix64.S
else
  CSRCS += libffi/src/$(TARGETDIR)/ffi.c
endif
ASRCS += libffi/src/$(TARGETDIR)/sysv.S

AFLAGS += $(FLAGS)
AFLAGS_FILTER_OUT = -Wundef
AFLAGS := $(filter-out $(AFLAGS_FILTER_OUT), $(AFLAGS))

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

TARGET_H  = libffi/include/ffitarget.h

$(TARGET_H):
	$(Q) cp -f libffi/src/$(TARGETDIR)/ffitarget.h $@

context:: $(TARGET_H)

distclean::
	$(call DELFILE, $(TARGET_H))

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libffi.a
endif

include $(APPDIR)/Application.mk

