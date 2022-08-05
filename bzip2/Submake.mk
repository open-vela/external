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

CFLAGS += -Wno-undef

CSRCS = \
  blocksort.c \
  bzlib.c \
  compress.c \
  crctable.c \
  decompress.c \
  huffman.c \
  randtable.c

ifneq ($(CONFIG_UTILS_BZIP2),)
MODULE += $(CONFIG_UTILS_BZIP2)
PROGNAME += $(CONFIG_UTILS_BZIP2_PROGNAME)
PRIORITY += $(CONFIG_UTILS_BZIP2_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_BZIP2_STACKSIZE)
MAINSRC += bzip2.c
endif

include $(APPDIR)/Application.mk
