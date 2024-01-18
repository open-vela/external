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
CFLAGS   += ${INCDIR_PREFIX}$(APPDIR)/external/unqlite/unqlite
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

ifneq ($(CONFIG_UNQLITE_ENABLE_TESTS),)
PRIORITY  = $(CONFIG_UNQLITE_TESTS_PRIORITY)
STACKSIZE = $(CONFIG_UNQLITE_TESTS_STACKSIZE)

PROGNAME += unqlite_test1
MAINSRC  += unqlite/example/1.c
PROGNAME += unqlite_test2
MAINSRC  += unqlite/example/2.c
PROGNAME += unqlite_test3
MAINSRC  += unqlite/example/3.c
PROGNAME += unqlite_test4
MAINSRC  += unqlite/example/4.c
PROGNAME += unqlite_test5
MAINSRC  += unqlite/example/5.c
PROGNAME += unqlite_test6
MAINSRC  += unqlite/example/6.c
PROGNAME += unqlite_test_huge
MAINSRC  += unqlite/example/unqlite_huge.c
PROGNAME += unqlite_test_mp3
MAINSRC  += unqlite/example/unqlite_mp3.c
PROGNAME += unqlite_test_tar
MAINSRC  += unqlite/example/unqlite_tar.c
PROGNAME += unqlite_test_demovfs
MAINSRC  += unqlite/example/demovfs/unqlite_demovfs.c
endif

CFLAGS += -Wno-unused-function -Wno-misleading-indentation
CFLAGS += -Wno-shadow -Wstringop-overflow=0

include $(APPDIR)/Application.mk
