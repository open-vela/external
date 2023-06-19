#
# Copyright (C) 2020 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.crg/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

CSRCSRM += libxml2/rngparser.c
CSRCSRM += libxml2/trio.c
CSRCSRM += libxml2/trionan.c
CSRCSRM += libxml2/triostr.c
CSRCSRM += libxml2/xmlcatalog.c
CSRCSRM += libxml2/xmllint.c

CSRCSRM += $(wildcard libxml2/run*.c)
CSRCSRM += $(wildcard libxml2/test*.c)

CSRCSALL = $(wildcard libxml2/*.c)
CSRCS    = $(filter-out $(CSRCSRM), $(CSRCSALL))

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += -Wno-format-extra-args -Wno-undef

include $(APPDIR)/Application.mk
