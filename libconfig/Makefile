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

include $(APPDIR)/Application.mk
