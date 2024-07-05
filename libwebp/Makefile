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

CFLAGS += -Wno-maybe-uninitialized

CFLAGS += ${INCDIR_PREFIX}libwebp/
CFLAGS += ${INCDIR_PREFIX}libwebp/src/

CSRCS += $(wildcard libwebp/src/dec/*.c)
CSRCS += $(wildcard libwebp/src/dsp/*.c)
CSRCS += $(wildcard libwebp/src/utils/*.c)

include $(APPDIR)/Application.mk
