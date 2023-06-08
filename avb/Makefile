#
# Copyright (C) 2023 Xiaomi Corporation
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

CFLAGS += -DAVB_COMPILATION
CFLAGS += -I$(APPDIR)/external/avb/avb
CFLAGS += -I$(APPDIR)/external/avb/avb/libavb/sha

CSRCS += \
        avb/libavb/avb_chain_partition_descriptor.c \
        avb/libavb/avb_cmdline.c \
        avb/libavb/avb_crypto.c \
        avb/libavb/avb_descriptor.c \
        avb/libavb/avb_footer.c \
        avb/libavb/avb_hash_descriptor.c \
        avb/libavb/avb_hashtree_descriptor.c \
        avb/libavb/avb_kernel_cmdline_descriptor.c \
        avb/libavb/avb_property_descriptor.c \
        avb/libavb/avb_rsa.c \
        avb/libavb/avb_slot_verify.c \
        avb/libavb/avb_sysdeps_posix.c \
        avb/libavb/avb_util.c \
        avb/libavb/avb_vbmeta_image.c \
        avb/libavb/avb_version.c
ifneq ($(CONFIG_LIB_AVB_CRC32),)
CSRCS += avb/libavb/avb_crc32.c
endif
ifneq ($(CONFIG_LIB_AVB_SHA256),)
CSRCS += avb/libavb/sha/sha256_impl.c
endif
ifneq ($(CONFIG_LIB_AVB_SHA512),)
CSRCS += avb/libavb/sha/sha512_impl.c
endif
CSRCS := $(wildcard $(CSRCS))

NOEXPORTSRCS=$(CSRCS)
ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libexternal.a
endif

EXPORT_FILES:= \
        avb/libavb/avb_chain_partition_descriptor.h \
        avb/libavb/avb_cmdline.h \
        avb/libavb/avb_crypto.h \
        avb/libavb/avb_descriptor.h \
        avb/libavb/avb_footer.h \
        avb/libavb/avb_hash_descriptor.h \
        avb/libavb/avb_hashtree_descriptor.h \
        avb/libavb/avb_kernel_cmdline_descriptor.h \
        avb/libavb/avb_ops.h \
        avb/libavb/avb_property_descriptor.h \
        avb/libavb/avb_rsa.h \
        avb/libavb/avb_sha.h \
        avb/libavb/avb_slot_verify.h \
        avb/libavb/avb_sysdeps.h \
        avb/libavb/avb_util.h \
        avb/libavb/avb_vbmeta_image.h \
        avb/libavb/avb_version.h \
        avb/libavb/libavb.h \
        avb/libavb/sha/avb_crypto_ops_impl.h

include $(APPDIR)/Application.mk
