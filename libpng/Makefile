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

ifneq ($(CONFIG_ARM_NEON),)
CSRCS += $(wildcard libpng/arm/*.c)
ASRCS += $(wildcard libpng/arm/*.S)
else
CFLAGS += -DPNG_ARM_NEON_IMPLEMENTATION=0
endif

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/zlib/zlib
CSRCS += $(filter-out libpng/pngtest.c, $(wildcard libpng/*.c))

ifneq ($(CONFIG_LIB_PNG_TEST),)
${shell mkdir -p $(BOARD_DIR)/resource/libpng}
${shell cp libpng/pngtest.png $(BOARD_DIR)/resource/libpng}
CFLAGS += -DPNG_TEST_DIR=\"/resource/libpng\"
MODULE     = $(CONFIG_LIB_PNG_TEST)
PRIORITY   = $(CONFIG_LIB_PNG_TEST_PRIORITY)
STACKSIZE  = $(CONFIG_LIB_PNG_TEST_STACKSIZE)
PROGNAME  += test_libpng
MAINSRC    = libpng/pngtest.c
endif

include $(APPDIR)/Application.mk
