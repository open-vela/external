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

CSRCS += tinycrypt/lib/source/utils.c
CSRCS += tinycrypt/lib/source/ecc.c

ifeq ($(CONFIG_TINYCRYPT_ECC_DH),y)
  CSRCS += tinycrypt/lib/source/ecc_dh.c
endif

ifeq ($(CONFIG_TINYCRYPT_ECC_DSA),y)
  CSRCS += tinycrypt/lib/source/ecc_dsa.c
endif

ifeq ($(CONFIG_TINYCRYPT_AES),y)
  CSRCS += tinycrypt/lib/source/aes_decrypt.c
endif

ifeq ($(CONFIG_TINYCRYPT_AES),y)
  CSRCS += tinycrypt/lib/source/aes_encrypt.c
endif

ifeq ($(CONFIG_TINYCRYPT_AES_CBC),y)
  CSRCS += tinycrypt/lib/source/cbc_mode.c
endif

ifeq ($(CONFIG_TINYCRYPT_AES_CTR),y)
  CSRCS += tinycrypt/lib/source/ctr_mode.c
endif

ifeq ($(CONFIG_TINYCRYPT_AES_CCM),y)
  CSRCS += tinycrypt/lib/source/ccm_mode.c
endif

ifeq ($(CONFIG_TINYCRYPT_AES_CMAC),y)
  CSRCS += tinycrypt/lib/source/cmac_mode.c
endif

ifeq ($(CONFIG_TINYCRYPT_SHA256),y)
  CSRCS += tinycrypt/lib/source/sha256.c
endif

ifeq ($(CONFIG_TINYCRYPT_SHA256_HMAC),y)
  CSRCS += tinycrypt/lib/source/hmac.c
endif

ifeq ($(CONFIG_TINYCRYPT_SHA256_HMAC_PRNG),y)
  CSRCS += tinycrypt/lib/source/hmac_prng.c
endif

ifeq ($(CONFIG_TINYCRYPT_CTR_PRNG),y)
  CSRCS += tinycrypt/lib/source/ctr_prng.c
endif

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/tinycrypt/tinycrypt/lib/include}

include $(APPDIR)/Application.mk
