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

LIB_DST_PATH = $(APPDIR)/staging
LIB_SRC_PATH = $(APPDIR)/external/liblhdc/liblhdc/libs

ifeq ($(CONFIG_ARCH),sim)
    $(shell cp $(LIB_SRC_PATH)/x86/lhdcv4_dec/liblhdcDec_x86.a $(LIB_DST_PATH))
    $(shell cp $(LIB_SRC_PATH)/x86/lhdcv5_dec/liblhdcv5dec_x86.a $(LIB_DST_PATH))
else ifeq ($(CONFIG_ARCH),arm)
    $(shell cp $(LIB_SRC_PATH)/arm32/lhdcv4_dec/liblhdc-dec_arm.a $(LIB_DST_PATH))
    $(shell cp $(LIB_SRC_PATH)/arm32/lhdcv5_dec/liblhdcv5dec_arm.a $(LIB_DST_PATH))
endif

distclean::
	$(call DELFILE, $(LIB_DST_PATH)/liblhdc*.a)
	$(call DELFILE, Make.dep)
	$(call DELFILE, .depend)
	$(call DELFILE, .built)

include $(APPDIR)/Application.mk
