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

CSRCS     = exfatprogs/lib/libexfat.c
CFLAGS   += -D__le16=uint16_t
CFLAGS   += -D__le32='unsigned int'
CFLAGS   += -D__le64=uint64_t
CFLAGS   += -D__u8=uint8_t
CFLAGS   += -D__u16=uint16_t
CFLAGS   += -D__u32='unsigned int'
CFLAGS   += -D__u64=uint64_t
CFLAGS   += ${INCDIR_PREFIX}.
CFLAGS   += ${INCDIR_PREFIX}exfatprogs/include
PRIORITY  = $(CONFIG_LIB_EXFATPROGS_PRIORITY)
STACKSIZE = $(CONFIG_LIB_EXFATPROGS_STACKSIZE)
MODULE    = $(CONFIG_LIB_EXFATPROGS)

ifneq ($(CONFIG_LIB_EXFATPROGS_DUMP),)
MAINSRC  += exfatprogs/dump/dump.c
PROGNAME += dumpexfat
endif

ifneq ($(CONFIG_LIB_EXFATPROGS_LABEL),)
MAINSRC  += exfatprogs/label/label.c
PROGNAME += labelexfat
endif

ifneq ($(CONFIG_LIB_EXFATPROGS_TUNE),)
MAINSRC  += exfatprogs/tune/tune.c
PROGNAME += tuneexfat
endif

ifneq ($(CONFIG_LIB_EXFATPROGS_FSCK),)
CFLAGS   += ${INCDIR_PREFIX}exfatprogs/fsck
CSRCS    += exfatprogs/fsck/repair.c
CSRCS    += exfatprogs/fsck/de_iter.c
MAINSRC  += exfatprogs/fsck/fsck.c
PROGNAME += fsckexfat
endif

ifneq ($(CONFIG_LIB_EXFATPROGS_MKFS),)
CFLAGS   += ${INCDIR_PREFIX}exfatprogs/mkfs
CSRCS    += exfatprogs/mkfs/upcase.c
MAINSRC  += exfatprogs/mkfs/mkfs.c
PROGNAME += mkfsexfat
endif

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libexternal.a
endif

include $(APPDIR)/Application.mk
