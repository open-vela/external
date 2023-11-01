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

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_nuttx/optee_nuttx/include
CFLAGS += ${INCDIR_PREFIX}optee_os/core/include
CFLAGS += ${INCDIR_PREFIX}optee_os/core/lib/libtomcrypt/include
CFLAGS += ${INCDIR_PREFIX}optee_os/core/lib/libtomcrypt/src/headers
CFLAGS += ${INCDIR_PREFIX}optee_os/ldelf/include
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libmbedtls/core
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libmbedtls/include
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libmbedtls/mbedtls/include
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libutee/include
CFLAGS += ${INCDIR_PREFIX}optee_os/lib/libutils/ext/include

CFLAGS += -DARM32
CFLAGS += -DCFG_COMPAT_GP10_DES
CFLAGS += -DCFG_CONCURRENT_SINGLE_INSTANCE_TA
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
CFLAGS += -DCFG_OTP_SUPPORT
CFLAGS += -DCFG_OTP_SUPPORT_NO_PROVISION_TMP
CFLAGS += -DCFG_REE_FS
CFLAGS += -DCFG_TA_BIGNUM_MAX_BITS=2048
CFLAGS += -DCFG_WITH_SOFTWARE_PRNG
CFLAGS += -DCFG_WITH_USER_TA
CFLAGS += -DMBEDTLS_AES_C
CFLAGS += -DMBEDTLS_CIPHER_C
CFLAGS += -DMBEDTLS_CIPHER_MODE_CBC
CFLAGS += -DMBEDTLS_CIPHER_MODE_CTR
CFLAGS += -DMBEDTLS_CMAC_C
CFLAGS += -DMBEDTLS_DES_C
CFLAGS += -DMBEDTLS_DES_C -DMBEDTLS_ECP_C -DMBEDTLS_BIGNUM_C -DMBEDTLS_ECP_DP_SECP192R1_ENABLED -DMBEDTLS_ASN1_PARSE_C -DMBEDTLS_ASN1_WRITE_C
CFLAGS += -DMBEDTLS_DHM_C
CFLAGS += -DMBEDTLS_ECDH_C
CFLAGS += -DMBEDTLS_ECDH_LEGACY_CONTEXT
CFLAGS += -DMBEDTLS_ECDSA_C
CFLAGS += -DMBEDTLS_HMAC_DRBG_C
CFLAGS += -DMBEDTLS_MD2_C -DMBEDTLS_MD4_C -DMBEDTLS_MD5_C -DMBEDTLS_RIPEMD160_C -DMBEDTLS_SHA1_C -DMBEDTLS_SHA256_C -DMBEDTLS_SHA512_C
CFLAGS += -DMBEDTLS_MD_C
CFLAGS += -DMBEDTLS_PK_C
CFLAGS += -DMBEDTLS_RSA_C -DMBEDTLS_OID_C -DMBEDTLS_PKCS1_V15 -DMBEDTLS_PKCS1_V21
CFLAGS += -DTRACE_LEVEL=3
CFLAGS += -DTRACE_PERF
CFLAGS += -D__KERNEL__

ifeq ($(CONFIG_ENABLE_CRYPTO_SM3),y)
CFLAGS += -DCFG_CRYPTO_SM3
CSRCS += optee_os/core/crypto/sm3.c \
         optee_os/core/crypto/sm3-hash.c \
         optee_os/core/crypto/sm3-hmac.c
endif

CSRCS += \
        optee_os/core/crypto/aes-gcm-sw.c \
        optee_os/core/crypto/aes-gcm.c \
        optee_os/core/crypto/cbc-mac.c \
        optee_os/core/crypto/crypto.c \
        optee_os/core/crypto/rng_hw.c \
        optee_os/core/crypto/sm2-kdf.c \
        optee_os/core/kernel/huk_subkey.c \
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
        optee_os/core/tee/entry_std.c \
        optee_os/core/tee/fs_dirfile.c \
        optee_os/core/tee/fs_htree.c \
        optee_os/core/tee/tee_cryp_utl.c \
        optee_os/core/tee/tee_fs_key_manager.c \
        optee_os/core/tee/tee_fs_rpc.c \
        optee_os/core/tee/tee_obj.c \
        optee_os/core/tee/tee_pobj.c \
        optee_os/core/tee/tee_ree_fs.c \
        optee_os/core/tee/tee_svc.c \
        optee_os/core/tee/tee_svc_cryp.c \
        optee_os/core/tee/tee_svc_storage.c \
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
        optee_os/lib/libmbedtls/mbedtls/library/aes.c \
        optee_os/lib/libmbedtls/mbedtls/library/aesni.c \
        optee_os/lib/libmbedtls/mbedtls/library/arc4.c \
        optee_os/lib/libmbedtls/mbedtls/library/aria.c \
        optee_os/lib/libmbedtls/mbedtls/library/asn1parse.c \
        optee_os/lib/libmbedtls/mbedtls/library/asn1write.c \
        optee_os/lib/libmbedtls/mbedtls/library/base64.c \
        optee_os/lib/libmbedtls/mbedtls/library/bignum.c \
        optee_os/lib/libmbedtls/mbedtls/library/blowfish.c \
        optee_os/lib/libmbedtls/mbedtls/library/camellia.c \
        optee_os/lib/libmbedtls/mbedtls/library/ccm.c \
        optee_os/lib/libmbedtls/mbedtls/library/certs.c \
        optee_os/lib/libmbedtls/mbedtls/library/chacha20.c \
        optee_os/lib/libmbedtls/mbedtls/library/chachapoly.c \
        optee_os/lib/libmbedtls/mbedtls/library/cipher.c \
        optee_os/lib/libmbedtls/mbedtls/library/cipher_wrap.c \
        optee_os/lib/libmbedtls/mbedtls/library/cmac.c \
        optee_os/lib/libmbedtls/mbedtls/library/constant_time.c \
        optee_os/lib/libmbedtls/mbedtls/library/ctr_drbg.c \
        optee_os/lib/libmbedtls/mbedtls/library/debug.c \
        optee_os/lib/libmbedtls/mbedtls/library/des.c \
        optee_os/lib/libmbedtls/mbedtls/library/dhm.c \
        optee_os/lib/libmbedtls/mbedtls/library/ecdh.c \
        optee_os/lib/libmbedtls/mbedtls/library/ecdsa.c \
        optee_os/lib/libmbedtls/mbedtls/library/ecjpake.c \
        optee_os/lib/libmbedtls/mbedtls/library/ecp.c \
        optee_os/lib/libmbedtls/mbedtls/library/ecp_curves.c \
        optee_os/lib/libmbedtls/mbedtls/library/entropy.c \
        optee_os/lib/libmbedtls/mbedtls/library/entropy_poll.c \
        optee_os/lib/libmbedtls/mbedtls/library/error.c \
        optee_os/lib/libmbedtls/mbedtls/library/gcm.c \
        optee_os/lib/libmbedtls/mbedtls/library/havege.c \
        optee_os/lib/libmbedtls/mbedtls/library/hkdf.c \
        optee_os/lib/libmbedtls/mbedtls/library/hmac_drbg.c \
        optee_os/lib/libmbedtls/mbedtls/library/md.c \
        optee_os/lib/libmbedtls/mbedtls/library/md2.c \
        optee_os/lib/libmbedtls/mbedtls/library/md4.c \
        optee_os/lib/libmbedtls/mbedtls/library/md5.c \
        optee_os/lib/libmbedtls/mbedtls/library/memory_buffer_alloc.c \
        optee_os/lib/libmbedtls/mbedtls/library/net_sockets.c \
        optee_os/lib/libmbedtls/mbedtls/library/nist_kw.c \
        optee_os/lib/libmbedtls/mbedtls/library/oid.c \
        optee_os/lib/libmbedtls/mbedtls/library/padlock.c \
        optee_os/lib/libmbedtls/mbedtls/library/pem.c \
        optee_os/lib/libmbedtls/mbedtls/library/pk.c \
        optee_os/lib/libmbedtls/mbedtls/library/pk_wrap.c \
        optee_os/lib/libmbedtls/mbedtls/library/pkcs11.c \
        optee_os/lib/libmbedtls/mbedtls/library/pkcs12.c \
        optee_os/lib/libmbedtls/mbedtls/library/pkcs5.c \
        optee_os/lib/libmbedtls/mbedtls/library/pkparse.c \
        optee_os/lib/libmbedtls/mbedtls/library/pkwrite.c \
        optee_os/lib/libmbedtls/mbedtls/library/platform.c \
        optee_os/lib/libmbedtls/mbedtls/library/platform_util.c \
        optee_os/lib/libmbedtls/mbedtls/library/poly1305.c \
        optee_os/lib/libmbedtls/mbedtls/library/ripemd160.c \
        optee_os/lib/libmbedtls/mbedtls/library/rsa.c \
        optee_os/lib/libmbedtls/mbedtls/library/rsa_internal.c \
        optee_os/lib/libmbedtls/mbedtls/library/sha1.c \
        optee_os/lib/libmbedtls/mbedtls/library/sha256.c \
        optee_os/lib/libmbedtls/mbedtls/library/sha512.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_cache.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_ciphersuites.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_cli.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_cookie.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_msg.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_srv.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_ticket.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_tls.c \
        optee_os/lib/libmbedtls/mbedtls/library/ssl_tls13_keys.c \
        optee_os/lib/libmbedtls/mbedtls/library/threading.c \
        optee_os/lib/libmbedtls/mbedtls/library/timing.c \
        optee_os/lib/libmbedtls/mbedtls/library/version.c \
        optee_os/lib/libmbedtls/mbedtls/library/version_features.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509_create.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509_crl.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509_crt.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509_csr.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509write_crt.c \
        optee_os/lib/libmbedtls/mbedtls/library/x509write_csr.c \
        optee_os/lib/libmbedtls/mbedtls/library/xtea.c \
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

include $(APPDIR)/Application.mk
