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

CSRCS += libconfig/lib/grammar.c
CSRCS += libconfig/lib/libconfig.c
CSRCS += libconfig/lib/scanctx.c
CSRCS += libconfig/lib/scanner.c
CSRCS += libconfig/lib/strbuf.c
CSRCS += libconfig/lib/util.c
CSRCS += libconfig/lib/wincompat.c
CSRCS += libconfig/lib/strvec.c

CFLAGS += -DYYINITDEPTH=$(CONFIG_LIBCONFIG_YYINITDEPTH)
CFLAGS +=  -DYYMAXDEPTH=$(CONFIG_LIBCONFIG_YYMAXDEPTH)
CFLAGS += -Wno-strict-prototypes

ifneq ($(CONFIG_LIBCONFIG_TEST),)
${shell mkdir -p $(BOARD_DIR)/resource/libconfig}
${shell cp -r libconfig/tests/testdata $(BOARD_DIR)/resource/libconfig}
CFLAGS += -DCONFIG_TEST_DIR=\"/resource/libconfig/testdata\"
PRIORITY = $(CONFIG_LIBCONFIG_TEST_PRIORITY)
STACKSIZE = $(CONFIG_LIBCONFIG_TEST_STACKSIZE)
CFLAGS += ${INCDIR_PREFIX}libconfig/lib
CFLAGS += ${INCDIR_PREFIX}libconfig/tinytest
MODULE = $(CONFIG_LIBCONFIG_TEST)
CSRCS += libconfig/tinytest/tinytest.c
PROGNAME += test_libconfig
MAINSRC = libconfig/tests/tests.c
endif

include $(APPDIR)/Application.mk
