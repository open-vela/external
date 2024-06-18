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

# Filter out directly included files.

LIBJPEG_FILTER_OUT := libjpeg-turbo/jccolext.c
LIBJPEG_FILTER_OUT += libjpeg-turbo/jcstest.c
LIBJPEG_FILTER_OUT += libjpeg-turbo/jdcol565.c
LIBJPEG_FILTER_OUT += libjpeg-turbo/jdcolext.c
LIBJPEG_FILTER_OUT += libjpeg-turbo/jdmrg565.c
LIBJPEG_FILTER_OUT += libjpeg-turbo/jdmrgext.c
LIBJPEG_FILTER_OUT += libjpeg-turbo/jstdhuff.c

CFLAGS += -Dread_stdin=libjpeg_read_stdin

CSRCS += $(filter-out $(LIBJPEG_FILTER_OUT), $(wildcard libjpeg-turbo/j*.c))

include $(APPDIR)/Application.mk
