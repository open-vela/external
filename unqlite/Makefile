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

CSRCS   = unqlite/unqlite.c
CFLAGS += -DSXMEM_POOL_NBUCKETS=$(CONFIG_SXMEM_POOL_NBUCKETS)
CFLAGS += -DSXMEM_POOL_INCR=$(CONFIG_SXMEM_POOL_INCR)

ifneq ($(CONFIG_UNQLITE_LOCK_BY_SEM),)
CFLAGS += -DUNQLITE_LOCK_BY_SEM
endif
ifneq ($(CONFIG_UNQLITE_ENABLE_DIRSYNC),y)
CFLAGS += -DUNQLITE_DISABLE_DIRSYNC
endif
ifneq ($(CONFIG_DISABLE_PTHREAD),y)
CFLAGS += -DUNQLITE_ENABLE_THREADS
endif
ifneq ($(CONFIG_UNQLITE_ENABLE_JX9_HASH_IO),)
CFLAGS += -DUNQLITE_ENABLE_JX9_HASH_IO
endif
ifneq ($(CONFIG_JX9_ENABLE_DISK_IO),y)
CFLAGS += -DJX9_DISABLE_DISK_IO
endif
ifneq ($(CONFIG_JX9_ENABLE_BUILTIN_FUNC),y)
CFLAGS += -DJX9_DISABLE_BUILTIN_FUNC
endif
ifneq ($(CONFIG_JX9_ENABLE_MATH_FUNC),)
CFLAGS += -DJX9_ENABLE_MATH_FUNC
endif

CFLAGS += -Wno-unused-function -Wno-misleading-indentation
CFLAGS += -Wno-shadow

include $(APPDIR)/Application.mk
