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

PROGNAME  = socat
PRIORITY  = CONFIG_UTILS_SOCAT_PRIORITY
STACKSIZE = CONFIG_UTILS_SOCAT_STACKSIZE
MODULE    = $(CONFIG_UTILS_SOCAT)
MAINSRC   = socat/socat.c

CSRCS     = $(filter-out socat/socat.c \
                         socat/filan_main.c \
                         socat/procan-cdefs.c \
                         socat/procan_main.c \
                         socat/procan.c \
                         socat/hostan.c \
            , $(wildcard socat/*.c))

CFLAGS   += ${INCDIR_PREFIX}.
CFLAGS   += -Wno-undef -Wno-shadow -Wno-builtin-declaration-mismatch
CFLAGS   += -Wno-format -Wno-unused-variable -Wno-parentheses
CFLAGS   += -Wno-implicit-function-declaration -Wno-unused-function

include $(APPDIR)/Application.mk
