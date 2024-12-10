#
# Copyright (C) 2023 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#

if(CONFIG_OPTEE_OS)

  # ############################################################################
  # Flags
  # ############################################################################

  set(CFLAGS
      -D__text_start=_stext
      -DCFG_COMPAT_GP10_DES
      -DCFG_CORE_BIGNUM_MAX_BITS=4096
      -DCFG_CORE_DYN_SHM
      -DCFG_CORE_MAX_SYSCALL_RECURSION=4
      -DCFG_CRYPTO_AES
      -DCFG_CRYPTO_CBC
      -DCFG_CRYPTO_CBC_MAC
      -DCFG_CRYPTO_CBC_MAC_BUNDLE_BLOCKS=64
      -DCFG_CRYPTO_CMAC
      -DCFG_CRYPTO_CTR
      -DCFG_CRYPTO_DES
      -DCFG_CRYPTO_DH
      -DCFG_CRYPTO_ECB
      -DCFG_CRYPTO_ECC
      -DCFG_CRYPTO_GCM
      -DCFG_CRYPTO_HMAC
      -DCFG_CRYPTO_MD5
      -DCFG_CRYPTO_SHA1
      -DCFG_CRYPTO_SHA224
      -DCFG_CRYPTO_SHA256
      -DCFG_CRYPTO_SHA384
      -DCFG_CRYPTO_SHA512
      -DCFG_CRYPTO_SM2_KEP
      -DCFG_LPAE_ADDR_SPACE_BITS=32
      -DCFG_MAX_CACHE_LINE_SHIFT=6
      -DCFG_MSG_LONG_PREFIX_MASK=0x1a
      -DCFG_NUM_THREADS=1
      -DCFG_TEE_CORE_NB_CORE=1
      -DCFG_OTP_SUPPORT
      -DCFG_OTP_SUPPORT_NO_PROVISION_TMP
      -DCFG_TA_BIGNUM_MAX_BITS=2048
      -DCFG_WITH_SOFTWARE_PRNG
      -DCFG_WITH_USER_TA
      -DTRACE_LEVEL=3
      -DTRACE_PERF
      -D__KERNEL__)

  if(CONFIG_ARCH_ARM64)
    list(APPEND CFLAGS -DARM64)
  elseif(CONFIG_ARCH_ARM)
    list(APPEND CFLAGS -DARM32)
  elseif(CONFIG_ARCH_SIM)
    list(APPEND CFLAGS -DARM32)
  endif()

  if(CONFIG_TEE_CORE_DEBUG)
    list(APPEND CFLAGS -DCFG_TEE_CORE_DEBUG)
  endif()

  if(CONFIG_OPTEE_REE_FS)
    list(APPEND CFLAGS -DCFG_REE_FS)
  endif()
  # ############################################################################
  # Sources
  # ############################################################################

  set(CSRCS
      optee_os/core/crypto/aes-gcm-sw.c
      optee_os/core/crypto/aes-gcm.c
      optee_os/core/crypto/cbc-mac.c
      optee_os/core/crypto/crypto.c
      optee_os/core/crypto/rng_hw.c
      optee_os/core/crypto/sm2-kdf.c
      optee_os/core/kernel/initcall.c
      optee_os/core/kernel/mutex.c
      optee_os/core/kernel/otp_stubs.c
      optee_os/core/kernel/pseudo_ta.c
      optee_os/core/kernel/refcount.c
      optee_os/core/kernel/scattered_array.c
      optee_os/core/kernel/tee_misc.c
      optee_os/core/kernel/tee_ta_manager.c
      optee_os/core/kernel/tee_time.c
      optee_os/core/kernel/wait_queue.c
      optee_os/core/lib/libtomcrypt/tomcrypt.c
      optee_os/core/mm/tee_mm.c
      optee_os/core/tee/entry_std.c
      optee_os/core/tee/tee_cryp_utl.c
      optee_os/core/tee/tee_fs_key_manager.c
      optee_os/core/tee/tee_pobj.c
      optee_os/core/tee/tee_svc.c
      optee_os/core/tee/tee_svc_cryp.c
      optee_os/core/tee/tee_time_generic.c
      optee_os/core/tee/uuid.c
      optee_os/lib/libmbedtls/core/aes.c
      optee_os/lib/libmbedtls/core/aes_cbc.c
      optee_os/lib/libmbedtls/core/aes_ctr.c
      optee_os/lib/libmbedtls/core/aes_ecb.c
      optee_os/lib/libmbedtls/core/bignum.c
      optee_os/lib/libmbedtls/core/cmac.c
      optee_os/lib/libmbedtls/core/des3_cbc.c
      optee_os/lib/libmbedtls/core/des3_ecb.c
      optee_os/lib/libmbedtls/core/des_cbc.c
      optee_os/lib/libmbedtls/core/des_ecb.c
      optee_os/lib/libmbedtls/core/dh.c
      optee_os/lib/libmbedtls/core/ecc.c
      optee_os/lib/libmbedtls/core/hash.c
      optee_os/lib/libmbedtls/core/hmac.c
      optee_os/lib/libmbedtls/core/mbed_helpers.c
      optee_os/lib/libmbedtls/core/rsa.c
      optee_os/lib/libmbedtls/core/sm2-dsa.c
      optee_os/lib/libmbedtls/core/sm2-kep.c
      optee_os/lib/libmbedtls/core/sm2-pke.c
      optee_os/lib/libmbedtls/core/tomcrypt.c
      optee_os/lib/libutee/tee_api.c
      optee_os/lib/libutee/tee_api_arith_mpi.c
      optee_os/lib/libutee/tee_api_objects.c
      optee_os/lib/libutee/tee_api_operations.c
      optee_os/lib/libutee/tee_api_panic.c
      optee_os/lib/libutee/tee_system_pta.c
      optee_os/lib/libutee/user_ta_entry.c
      optee_os/lib/libutils/ext/consttime_memcmp.c
      optee_os/lib/libutils/ext/memzero_explicit.c
      optee_os/lib/libutils/ext/snprintk.c
      optee_os/lib/libutils/ext/trace.c)

  if(NOT CONFIG_OPTEE_COMPAT_MITEE_FS)
    list(
      APPEND
      CSRCS
      optee_os/core/kernel/huk_subkey.c
      optee_os/core/tee/fs_dirfile.c
      optee_os/core/tee/fs_htree.c
      optee_os/core/tee/tee_fs_rpc.c
      optee_os/core/tee/tee_obj.c
      optee_os/core/tee/tee_ree_fs.c
      optee_os/core/tee/tee_svc_storage.c)
  endif()

  if(CONFIG_ENABLE_CRYPTO_SM3)
    list(APPEND CFLAGS -DCFG_CRYPTO_SM3)
    list(APPEND CSRCS optee_os/core/crypto/sm3.c
         optee_os/core/crypto/sm3-hash.c optee_os/core/crypto/sm3-hmac.c)
  endif()

  if(CONFIG_OPTEE_RPMB_FS)
    list(APPEND CFLAGS -DCFG_RPMB_FS -DCFG_RPMB_FS_DEV_ID=0
         -DCFG_RPMB_FS_RD_ENTRIES=1 -DCFG_RPMB_FS_CACHE_ENTRIES=0)

    list(APPEND CSRCS optee_os/core/tee/tee_rpmb_fs.c)

    if(CONFIG_OPTEE_RPMB_WRITE_KEY)
      list(APPEND CFLAGS -DCFG_RPMB_WRITE_KEY)
    endif()

    if(CONFIG_OPTEE_RPMB_TESTKEY)
      list(APPEND CFLAGS -DCFG_RPMB_TESTKEY)
    endif()

    if(CONFIG_OPTEE_HUK_SUBKEY_COMPAT)
      list(APPEND CFLAGS -DCFG_CORE_HUK_SUBKEY_COMPAT
           -DCFG_CORE_HUK_SUBKEY_COMPAT_USE_OTP_DIE_ID)
    endif()

  endif()

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${NUTTX_APPS_DIR}/crypto/mbedtls/mbedtls/library
             ${NUTTX_APPS_DIR}/frameworks/security/optee_vela/include)
  if(CONFIG_OPTEE_COMPAT_MITEE_FS)
    list(APPEND INCDIR ${CMAKE_CURRENT_LIST_DIR}/optee_os/include/mitee_compat)
  endif()

  list(
    APPEND
    INCDIR
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/core/include
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/core/lib/libtomcrypt/include
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/core/lib/libtomcrypt/src/headers
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/ldelf/include
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/lib/libmbedtls/core
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/lib/libutee/include
    ${CMAKE_CURRENT_LIST_DIR}/optee_os/lib/libutils/ext/include)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(optee_os STATIC)
  target_sources(optee_os PRIVATE ${CSRCS})
  target_include_directories(optee_os PRIVATE ${INCDIR})
  target_compile_options(optee_os PRIVATE ${CFLAGS})

endif()
