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

CFLAGS += -DHAVE_EXPLICIT_BZERO -DHAVE_RAWMEMCHR
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" ell}

CSRCS = ell/ell/util.c ell/ell/test.c ell/ell/strv.c ell/ell/utf8.c      \
	ell/ell/queue.c ell/ell/timeout.c ell/ell/main.c ell/ell/idle.c  \
	ell/ell/signal.c ell/ell/io.c ell/ell/checksum.c ell/ell/log.c   \
	ell/ell/uuid.c ell/ell/file.c ell/ell/uintset.c \
	ell/ell/string.c

include $(APPDIR)/Application.mk
