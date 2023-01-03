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

MAINSRC = coremark/core_main.c

CSRCS = coremark/core_list_join.c \
        coremark/core_matrix.c    \
        coremark/core_state.c     \
        coremark/core_util.c      \
        coremark/posix/core_portme.c

CFLAGS += -DCALLGRIND_RUN=0
CFLAGS += -DCOMPILER_REQUIRES_SORT_RETURN=0
CFLAGS += -DCORE_DEBUG=$(CONFIG_UTILS_COREMARK_DEBUG)
CFLAGS += -DITERATIONS=$(CONFIG_UTILS_COREMARK_ITERATIONS)
CFLAGS += -DMEM_METHOD=$(CONFIG_UTILS_COREMARK_MEM_METHOD)
CFLAGS += -DMICA=0
CFLAGS += -DMULTITHREAD=$(CONFIG_UTILS_COREMARK_MULTITHREAD)
CFLAGS += -DPRINT_ARGS=0
CFLAGS += -DSEED_METHOD=$(CONFIG_UTILS_COREMARK_SEED_METHOD)
CFLAGS += -DUSE_CLOCK=1
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" coremark}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" coremark/posix}

CFLAGS += -DCOMPILER_FLAGS="\"$(CFLAGS)\""

include $(APPDIR)/Application.mk
include $(APPDIR)/Wasm.mk
