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

LIBJPEG_FILTER_OUT := jccolext.c
LIBJPEG_FILTER_OUT += jcstest.c
LIBJPEG_FILTER_OUT += jdcol565.c
LIBJPEG_FILTER_OUT += jdcolext.c
LIBJPEG_FILTER_OUT += jdmrg565.c
LIBJPEG_FILTER_OUT += jdmrgext.c
LIBJPEG_FILTER_OUT += jstdhuff.c

CSRCS += $(filter-out $(LIBJPEG_FILTER_OUT), $(wildcard j*.c))

include $(APPDIR)/Application.mk
