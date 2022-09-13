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

CSRCS   = libxml2/buf.c
CSRCS  += libxml2/chvalid.c
CSRCS  += libxml2/dict.c
CSRCS  += libxml2/encoding.c
CSRCS  += libxml2/entities.c
CSRCS  += libxml2/error.c
CSRCS  += libxml2/globals.c
CSRCS  += libxml2/hash.c
CSRCS  += libxml2/list.c
CSRCS  += libxml2/parser.c
CSRCS  += libxml2/parserInternals.c
CSRCS  += libxml2/SAX2.c
CSRCS  += libxml2/threads.c
CSRCS  += libxml2/tree.c
CSRCS  += libxml2/uri.c
CSRCS  += libxml2/valid.c
CSRCS  += libxml2/xmlIO.c
CSRCS  += libxml2/xmlmemory.c
CSRCS  += libxml2/xmlstring.c
CSRCS  += libxml2/xpath.c

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}

include $(APPDIR)/Application.mk
