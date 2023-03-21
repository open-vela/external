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

CSRCS = $(wildcard nghttp2/lib/*.c)

CFLAGS += -DHAVE_CONFIG_H
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}

ifneq ($(CONFIG_NGHTTP2_TEST),)
CSRCS += $(wildcard nghttp2/tests/nghttp2_*.c)
CSRCS += $(wildcard nghttp2/tests/failmalloc*.c)
CSRCS += $(wildcard nghttp2/tests/malloc*.c)
PROGNAME = $(CONFIG_NGHTTP2_TEST_PROGNAME)
MODULE = $(CONFIG_NGHTTP2_TEST)
PRIORITY = $(CONFIG_NGHTTP2_TEST_PRIORITY)
STACKSIZE = $(CONFIG_NGHTTP2_TEST_STACKSIZE)
MAINSRC = $(APPDIR)/external/nghttp2/nghttp2/tests/main.c
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" nghttp2/tests}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" nghttp2/lib}
endif

include $(APPDIR)/Application.mk
