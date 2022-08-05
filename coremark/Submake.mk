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

PROGNAME  = coremark
PRIORITY  = $(CONFIG_UTILS_COREMARK_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_COREMARK_STACKSIZE)
MODULE    = $(CONFIG_UTILS_COREMARK)

MAINSRC = core_main.c

CSRCS = core_list_join.c     \
        core_matrix.c        \
        core_state.c         \
        core_util.c          \
        posix/core_portme.c

CFLAGS += -DUSE_CLOCK
CFLAGS += -DCORE_DEBUG=$(CONFIG_UTILS_COREMARK_DEBUG)
CFLAGS += -DSEED_METHOD=$(CONFIG_UTILS_COREMARK_SEED_METHOD)
CFLAGS += -DMEM_METHOD=$(CONFIG_UTILS_COREMARK_MEM_METHOD)
CFLAGS += -DMULTITHREAD=$(CONFIG_UTILS_COREMARK_MULTITHREAD)
CFLAGS += -DITERATIONS=$(CONFIG_UTILS_COREMARK_ITERATIONS)
# Rename util function to avoid redefined with system's
CFLAGS += -Dcrcu8=coremark_crcu8
CFLAGS += -Dcrc16=coremark_crc16
CFLAGS += -Dcrcu16=coremark_crcu16
CFLAGS += -Dcrcu32=coremark_crcu32
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/coremark/coremark}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/coremark/coremark/posix}

CFLAGS += -DCOMPILER_FLAGS="\"$(CFLAGS)\""

include $(APPDIR)/Application.mk
include $(APPDIR)/Wasm.mk
