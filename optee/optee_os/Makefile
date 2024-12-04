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

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/crypto/mbedtls/mbedtls/library
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/frameworks/security/optee_vela/include
ifeq ($(CONFIG_OPTEE_COMPAT_MITEE_FS),y)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/frameworks/security/optee_vela/include/mitee_compat
endif
CFLAGS += ${INCDIR_PREFIX}optee_os/core/include
CFLAGS += ${INCDIR_PREFIX}optee_os/core/lib/libtomcrypt/include
CFLAGS += ${INCDIR_PREFIX}optee_os/core/lib/libtomcrypt/src/headers
CFLAGS += ${INCDIR_PREFIX}optee_os/ldelf/include
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libmbedtls/core
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libutee/include
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libutils/ext/include

ifeq ($(CONFIG_ARCH_ARM64),y)
CFLAGS += -DARM64
else ifeq ($(CONFIG_ARCH_ARM),y)
CFLAGS += -DARM32
else ifeq ($(CONFIG_ARCH_SIM),y)
CFLAGS += -DARM32
endif

CFLAGS += -D__text_start=_stext

CFLAGS += -DCFG_COMPAT_GP10_DES
CFLAGS += -DCFG_CORE_BIGNUM_MAX_BITS=4096
CFLAGS += -DCFG_CORE_DYN_SHM
CFLAGS += -DCFG_CORE_MAX_SYSCALL_RECURSION=4
CFLAGS += -DCFG_CRYPTO_AES
CFLAGS += -DCFG_CRYPTO_CBC
CFLAGS += -DCFG_CRYPTO_CBC_MAC
CFLAGS += -DCFG_CRYPTO_CBC_MAC_BUNDLE_BLOCKS=64
CFLAGS += -DCFG_CRYPTO_CMAC
CFLAGS += -DCFG_CRYPTO_CTR
CFLAGS += -DCFG_CRYPTO_DES
CFLAGS += -DCFG_CRYPTO_DH
CFLAGS += -DCFG_CRYPTO_ECB
CFLAGS += -DCFG_CRYPTO_ECC
CFLAGS += -DCFG_CRYPTO_GCM
CFLAGS += -DCFG_CRYPTO_HMAC
CFLAGS += -DCFG_CRYPTO_MD5 -DCFG_CRYPTO_SHA1 -DCFG_CRYPTO_SHA224 -DCFG_CRYPTO_SHA256 -DCFG_CRYPTO_SHA384 -DCFG_CRYPTO_SHA512
CFLAGS += -DCFG_CRYPTO_SM2_KEP
CFLAGS += -DCFG_LPAE_ADDR_SPACE_BITS=32
CFLAGS += -DCFG_MAX_CACHE_LINE_SHIFT=6
CFLAGS += -DCFG_MSG_LONG_PREFIX_MASK=0x1a
CFLAGS += -DCFG_NUM_THREADS=1
CFLAGS += -DCFG_TEE_CORE_NB_CORE=1
CFLAGS += -DCFG_OTP_SUPPORT
CFLAGS += -DCFG_OTP_SUPPORT_NO_PROVISION_TMP
CFLAGS += -DCFG_TA_BIGNUM_MAX_BITS=2048
CFLAGS += -DCFG_WITH_SOFTWARE_PRNG
CFLAGS += -DCFG_WITH_USER_TA
CFLAGS += -DTRACE_PERF
CFLAGS += -D__KERNEL__

ifneq ($(CONFIG_DEBUG_INFO),)
CFLAGS += -DTRACE_LEVEL=3
else ifneq ($(CONFIG_DEBUG_WARN),)
CFLAGS += -DTRACE_LEVEL=2
else ifneq ($(CONFIG_DEBUG_ERROR),)
CFLAGS += -DTRACE_LEVEL=1
else
# the default TRACE_LEVEL are 1(with error level)
CFLAGS += -DTRACE_LEVEL=1
endif

ifeq ($(CONFIG_ENABLE_CRYPTO_SM3),y)
CFLAGS += -DCFG_CRYPTO_SM3
CSRCS += optee_os/core/crypto/sm3.c \
         optee_os/core/crypto/sm3-hash.c \
         optee_os/core/crypto/sm3-hmac.c
endif

ifeq ($(CONFIG_TEE_CORE_DEBUG),y)
CFLAGS += -DCFG_TEE_CORE_DEBUG
endif

ifeq ($(CONFIG_OPTEE_REE_FS),y)
CFLAGS += -DCFG_REE_FS
endif

ifeq ($(CONFIG_OPTEE_RPMB_FS),y)
CFLAGS += -DCFG_RPMB_FS
CFLAGS += -DCFG_RPMB_FS_DEV_ID=0
CFLAGS += -DCFG_RPMB_FS_RD_ENTRIES=1
CFLAGS += -DCFG_RPMB_FS_CACHE_ENTRIES=0
CSRCS += \
        optee_os/core/tee/tee_rpmb_fs.c
ifeq ($(CONFIG_OPTEE_RPMB_WRITE_KEY),y)
CFLAGS += -DCFG_RPMB_WRITE_KEY
endif
ifeq ($(CONFIG_OPTEE_RPMB_TESTKEY),y)
CFLAGS += -DCFG_RPMB_TESTKEY
endif
ifeq ($(CONFIG_OPTEE_HUK_SUBKEY_COMPAT),y)
CFLAGS += -DCFG_CORE_HUK_SUBKEY_COMPAT
CFLAGS += -DCFG_CORE_HUK_SUBKEY_COMPAT_USE_OTP_DIE_ID
endif
endif

CSRCS += \
        optee_os/core/crypto/aes-gcm-sw.c \
        optee_os/core/crypto/aes-gcm.c \
        optee_os/core/crypto/cbc-mac.c \
        optee_os/core/crypto/crypto.c \
        optee_os/core/crypto/rng_hw.c \
        optee_os/core/crypto/sm2-kdf.c \
        optee_os/core/kernel/initcall.c \
        optee_os/core/kernel/mutex.c \
        optee_os/core/kernel/otp_stubs.c \
        optee_os/core/kernel/pseudo_ta.c \
        optee_os/core/kernel/refcount.c \
        optee_os/core/kernel/scattered_array.c \
        optee_os/core/kernel/tee_misc.c \
        optee_os/core/kernel/tee_ta_manager.c \
        optee_os/core/kernel/tee_time.c \
        optee_os/core/kernel/wait_queue.c \
        optee_os/core/lib/libtomcrypt/tomcrypt.c \
        optee_os/core/mm/tee_mm.c \
        optee_os/core/tee/entry_std.c \
        optee_os/core/tee/tee_cryp_utl.c \
        optee_os/core/tee/tee_fs_key_manager.c \
        optee_os/core/tee/tee_pobj.c \
        optee_os/core/tee/tee_svc.c \
        optee_os/core/tee/tee_svc_cryp.c \
        optee_os/core/tee/tee_time_generic.c \
        optee_os/core/tee/uuid.c \
        optee_os/lib/libmbedtls/core/aes.c \
        optee_os/lib/libmbedtls/core/aes_cbc.c \
        optee_os/lib/libmbedtls/core/aes_ctr.c \
        optee_os/lib/libmbedtls/core/aes_ecb.c \
        optee_os/lib/libmbedtls/core/bignum.c \
        optee_os/lib/libmbedtls/core/cmac.c \
        optee_os/lib/libmbedtls/core/des3_cbc.c \
        optee_os/lib/libmbedtls/core/des3_ecb.c \
        optee_os/lib/libmbedtls/core/des_cbc.c \
        optee_os/lib/libmbedtls/core/des_ecb.c \
        optee_os/lib/libmbedtls/core/dh.c \
        optee_os/lib/libmbedtls/core/ecc.c \
        optee_os/lib/libmbedtls/core/hash.c \
        optee_os/lib/libmbedtls/core/hmac.c \
        optee_os/lib/libmbedtls/core/mbed_helpers.c \
        optee_os/lib/libmbedtls/core/rsa.c \
        optee_os/lib/libmbedtls/core/sm2-dsa.c \
        optee_os/lib/libmbedtls/core/sm2-kep.c \
        optee_os/lib/libmbedtls/core/sm2-pke.c \
        optee_os/lib/libmbedtls/core/tomcrypt.c \
        optee_os/lib/libutee/tee_api.c \
        optee_os/lib/libutee/tee_api_arith_mpi.c \
        optee_os/lib/libutee/tee_api_objects.c \
        optee_os/lib/libutee/tee_api_operations.c \
        optee_os/lib/libutee/tee_api_panic.c \
        optee_os/lib/libutee/tee_system_pta.c \
        optee_os/lib/libutee/user_ta_entry.c \
        optee_os/lib/libutils/ext/consttime_memcmp.c \
        optee_os/lib/libutils/ext/memzero_explicit.c \
        optee_os/lib/libutils/ext/snprintk.c \
        optee_os/lib/libutils/ext/trace.c

ifeq ($(CONFIG_OPTEE_COMPAT_MITEE_FS),)
CSRCS += \
        optee_os/core/kernel/huk_subkey.c \
        optee_os/core/tee/fs_dirfile.c \
        optee_os/core/tee/fs_htree.c \
        optee_os/core/tee/tee_fs_rpc.c \
        optee_os/core/tee/tee_obj.c \
        optee_os/core/tee/tee_ree_fs.c \
        optee_os/core/tee/tee_svc_storage.c
endif

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/liboptee$(LIBEXT)
endif

include $(APPDIR)/Application.mk
