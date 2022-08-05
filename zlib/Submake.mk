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

CSRCS += $(wildcard *.c)
CSRCS += contrib/minizip/ioapi.c
CSRCS += contrib/minizip/mztools.c
CSRCS += contrib/minizip/unzip.c
CSRCS += contrib/minizip/zip.c

ifneq ($(CONFIG_LIB_BZIP2),)
CFLAGS += -DHAVE_BZIP2
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/bzip2/bzip2}
endif

CFLAGS += -Dcrc32=zlib_crc32 -Dunix -Wno-shadow -Wno-strict-prototypes -Wno-undef
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/zlib/zlib}

MODULE = $(CONFIG_LIB_ZLIB)

ifneq ($(CONFIG_UTILS_GZIP),)
PROGNAME += $(CONFIG_UTILS_GZIP_PROGNAME)
PRIORITY += $(CONFIG_UTILS_GZIP_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_GZIP_STACKSIZE)
MAINSRC += test/minigzip.c
endif

ifneq ($(CONFIG_UTILS_ZIP),)
PROGNAME += $(CONFIG_UTILS_ZIP_PROGNAME)
PRIORITY += $(CONFIG_UTILS_ZIP_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_ZIP_STACKSIZE)
MAINSRC += contrib/minizip/minizip.c
endif

ifneq ($(CONFIG_UTILS_UNZIP),)
PROGNAME += $(CONFIG_UTILS_UNZIP_PROGNAME)
PRIORITY += $(CONFIG_UTILS_UNZIP_PRIORITY)
STACKSIZE += $(CONFIG_UTILS_UNZIP_STACKSIZE)
MAINSRC += contrib/minizip/miniunz.c
endif

include $(APPDIR)/Application.mk
