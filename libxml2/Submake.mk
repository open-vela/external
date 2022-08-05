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

CSRCS   = buf.c
CSRCS  += chvalid.c
CSRCS  += dict.c
CSRCS  += encoding.c
CSRCS  += entities.c
CSRCS  += error.c
CSRCS  += globals.c
CSRCS  += hash.c
CSRCS  += list.c
CSRCS  += parser.c
CSRCS  += parserInternals.c
CSRCS  += SAX2.c
CSRCS  += threads.c
CSRCS  += tree.c
CSRCS  += uri.c
CSRCS  += valid.c
CSRCS  += xmlIO.c
CSRCS  += xmlmemory.c
CSRCS  += xmlstring.c
CSRCS  += xpath.c
CFLAGS += ${shell  $(INCDIR) $(INCDIROPT) "$(CC)" include}
CFLAGS += ${shell  $(INCDIR) $(INCDIROPT) "$(CC)" .}

include $(APPDIR)/Application.mk
