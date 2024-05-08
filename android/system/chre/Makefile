############################################################################
# external/android/system/chre/Makefile
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

include $(APPDIR)/Make.defs

CXXEXT = .cc
ANDROID_BUILD_TOP = $(APPDIR)/external/android
CHRE_PREFIX = $(ANDROID_BUILD_TOP)/system/chre/chre
CHRE_TOKENIZED_LOGGING_ENABLED = false
COMMON_CFLAGS += -I$(CHRE_PREFIX)/platform/shared/sensor_pal/include

ifneq ($(V), 0)
CHRE_BUILD_VERBOSE = true
endif

CHRE_VARIANT_MK_INCLUDES=$(CHRE_PREFIX)/variant/nuttx/variant.mk

include $(CHRE_VARIANT_MK_INCLUDES)
OUTPUT_NAME = libchre

COMMON_CFLAGS += -DCHRE_MINIMUM_LOG_LEVEL=CHRE_LOG_LEVEL_DEBUG
COMMON_CFLAGS += -DNANOAPP_MINIMUM_LOG_LEVEL=CHRE_LOG_LEVEL_DEBUG
COMMON_CFLAGS += -DCHRE_INCLUDE_DEFAULT_STATIC_NANOAPPS

ifneq ($(CONFIG_DEBUG_ASSERTIONS), false)
COMMON_CFLAGS += -DCHRE_ASSERTIONS_ENABLED
else
COMMON_CFLAGS += -DCHRE_ASSERTIONS_DISABLED
endif

# Place nanoapps in a namespace.
COMMON_CFLAGS += -DCHRE_NANOAPP_INTERNAL

# Optional audio support.
ifeq ($(CHRE_AUDIO_SUPPORT_ENABLED), true)
COMMON_CFLAGS += -DCHRE_AUDIO_SUPPORT_ENABLED
endif

# Optional BLE support
ifeq ($(CHRE_BLE_SUPPORT_ENABLED), true)
COMMON_CFLAGS += -DCHRE_BLE_SUPPORT_ENABLED
endif

# Optional GNSS support.
ifeq ($(CHRE_GNSS_SUPPORT_ENABLED), true)
COMMON_CFLAGS += -DCHRE_GNSS_SUPPORT_ENABLED
endif

# Optional sensors support.
ifeq ($(CHRE_SENSORS_SUPPORT_ENABLED), true)
COMMON_CFLAGS += -DCHRE_SENSORS_SUPPORT_ENABLED
endif

# Optional Wi-Fi support.
ifeq ($(CHRE_WIFI_SUPPORT_ENABLED), true)
COMMON_CFLAGS += -DCHRE_WIFI_SUPPORT_ENABLED
endif

# Optional WWAN support.
ifeq ($(CHRE_WWAN_SUPPORT_ENABLED), true)
COMMON_CFLAGS += -DCHRE_WWAN_SUPPORT_ENABLED
endif

# Determine the CHRE_HOST_OS to resolve build discrepancies across Darwin and
# Linux.
CHRE_HOST_OS := $(shell uname)

ifeq ($(CHRE_PATCH_VERSION),)
ifeq ($(CHRE_HOST_OS),Darwin)
DATE_CMD=gdate
else
DATE_CMD=date
endif

# Compute the patch version as the number of hours since the start of some
# arbitrary epoch. This will roll over 16 bits after ~7 years, but patch version
# is scoped to the API version, so we can adjust the offset when a new API
# version is released.
EPOCH=$(shell $(DATE_CMD) --date='2017-01-01' +%s)
CHRE_PATCH_VERSION = $(shell echo $$(((`$(DATE_CMD) +%s` - $(EPOCH)) / (60 * 60))))
endif

COMMON_CFLAGS += -DCHRE_PATCH_VERSION=$(CHRE_PATCH_VERSION)

# Makefile Includes ############################################################

# Common includes.
include $(CHRE_PREFIX)/build/defs.mk
include $(CHRE_PREFIX)/platform/nuttx/nuttx.mk

# CHRE Implementation includes.
include $(CHRE_PREFIX)/apps/apps.mk
include $(CHRE_PREFIX)/chre_api/chre_api.mk
include $(CHRE_PREFIX)/core/core.mk
include $(CHRE_PREFIX)/pal/pal.mk
include $(CHRE_PREFIX)/platform/platform.mk
include $(CHRE_PREFIX)/util/util.mk

# Supported variants includes.
ifneq ($(CHRE_TARGET_EXTENSION),)
include $(CHRE_TARGET_EXTENSION)
endif

include $(CHRE_PREFIX)/build/variant/nuttx.mk

CXXSRCS += $(COMMON_SRCS)
CXXSRCS += $(TARGET_VARIANT_SRCS)
CXXFLAGS += $(COMMON_CFLAGS)
CXXFLAGS += $(TARGET_CFLAGS)
CXXFLAGS += -DCHRE_FILENAME=__FILE__
CXXFLAGS += -DCHRE_PLATFORM_ID=$(TARGET_PLATFORM_ID)

# Unit Test
ifneq ($(CONFIG_CHRE_UNIT_TEST),)
CXXFLAGS += -Wno-error=shadow
CXXFLAGS += -Wno-error=deprecated-copy
CXXFLAGS += -Wno-error=double-promotion
CXXFLAGS += -I$(CHRE_PREFIX)
CXXFLAGS += -I$(CHRE_PREFIX)/test/common/include
CXXFLAGS += -I$(CHRE_PREFIX)/test/simulation/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/chre_cross_validator_wifi/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/chre_cross_validator_sensor/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/chre_settings_test/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/chre_api_test/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/chre_stress_test/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/rpc_service_test/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/chre_audio_concurrency_test/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/common/shared/inc
CXXFLAGS += -I$(CHRE_PREFIX)/apps/test/chqts/src
CXXFLAGS += -I$(CHRE_PREFIX)/platform/shared
endif

# DSO(dynamic shared object)

OUT_APP = $(CHRE_PREFIX)/platform/nuttx/out/apps

ifneq ($(CONFIG_CHRE_EXAMPLES),)

ifneq ($(CONFIG_CHRE_EXAMPLES_HELLO_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/hello_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_TIMER_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/timer_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_HOST_ASAKE_WORKD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/host_awake_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_BLE_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/ble_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_GNSS_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/gnss_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_MESSAGE_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/message_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_RPC_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/rpc_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_SENSOR_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/sensor_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_DEBUG_DUMP_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/debug_dump_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_AUDIO_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/audio_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_TFLM_DEMO),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/tflm_demo
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_WWAN_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/wwan_world
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_AUDIO_STRESS_TEST),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/audio_stress_test
endif
ifneq ($(CONFIG_CHRE_EXAMPLES_WIFI_WORLD),)
  NUTTX_DSO_DIRS += $(CHRE_PREFIX)/apps/wifi_world
endif

SYMTAB_SRC=$(CHRE_PREFIX)/platform/nuttx/symtab.c
CSRCS += $(SYMTAB_SRC)
CFLAGS += -Wno-builtin-declaration-mismatch

depend::
	$(APPDIR)/tools/mksymtab.sh $(OUT_APP) g_chre $(CHRE_PREFIX)/platform/nuttx/exports_chre_api.txt > $(SYMTAB_SRC)

context:: build_dso_all
install:: build_dso_all

.PHONY: build_dso_all
build_dso_all:
	$(foreach var,$(NUTTX_DSO_DIRS), \
		$(MAKE) -B -C $(var) install \
		OUT_APP="$(OUT_APP)" \
		NUTTX_DSO_PROGNAME="" \
		OPT_LEVEL="$(OPT_LEVEL)" \
		TOPDIR="$(TOPDIR)" \
		APPDIR="$(APPDIR)" \
		CROSSDEV=$(CROSSDEV) \
		CXXFLAGS="$(CXXFLAGS)" \
		CHRE_PREFIX="$(CHRE_PREFIX)" \
		NANOAPP_IS_SYSTEM_NANOAPP=0 \
		CHRE_TARGET_EXTENSION="$(CHRE_PREFIX)/platform/nuttx/dso.mk" \
		NANOAPP_VENDOR_STRING="\\\"Xiaomi\\\"" \
		CHRE_STD_OVERRIDES_ALLOWED=false || exit; \
	)
endif # CONFIG_CHRE_EXAMPLES

MAINSRC = $(CHRE_PREFIX)/platform/nuttx/init.cc
PROGNAME = $(CONFIG_CHRE_PROGNAME)
PRIORITY = $(CONFIG_CHRE_PRIORITY)
STACKSIZE = $(CONFIG_CHRE_STACKSIZE)
MODULE = $(CONFIG_CHRE)

ifneq ($(CONFIG_CHRE_UNIT_TEST),)
MAINSRC += $(CHRE_PREFIX)/platform/nuttx/test.cc
PROGNAME += $(CONFIG_CHRE_UNIT_TEST_PROGNAME)
PRIORITY += $(CONFIG_CHRE_UNIT_TEST_PRIORITY)
STACKSIZE += $(CONFIG_CHRE_UNIT_TEST_STACKSIZE)
endif

include $(APPDIR)/Application.mk
