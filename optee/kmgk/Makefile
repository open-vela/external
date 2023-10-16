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

include ./defconfig

BIN := libkeystore$(LIBEXT)

CSRCS = $(wildcard kmgk/keymaster/ta/*.c)

CFLAGS += -Ikmgk/keymaster/ta/include

OPTEE_IOT_DIR = $(APPDIR)/external/optee
CFLAGS += -I$(OPTEE_IOT_DIR)/optee_client/optee_client/public
CFLAGS += -I$(OPTEE_IOT_DIR)/optee_os/optee_os/lib/libutee/include

CFLAGS += -I$(OPTEE_IOT_DIR)/optee_os/optee_os/lib/libutils/ext/include
CFLAGS += -I$(OPTEE_IOT_DIR)/optee_os/optee_os/core/include

CFLAGS += -DTRACE_LEVEL=$(CONFIG_TRACE_LEVEL)
CFLAGS += -DKM_RECV_BUF_SIZE=$(CONFIF_KM_RECV_BUF_SIZE)
CFLAGS += -DTRACE_TAG='"ta_keystore"'

include $(APPDIR)/Application.mk
