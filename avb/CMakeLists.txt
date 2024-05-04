#
# Copyright (C) 2021 Xiaomi Corporation
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
if(CONFIG_LIB_AVB)

  nuttx_add_library(avb STATIC)

  set(CFLAGS -DAVB_COMPILATION)
  set(INCDIR ${NUTTX_APPS_DIR}/external/avb/avb)

  if(CONFIG_LIB_AVB_SHA256_CRYPTODEV OR CONFIG_LIB_AVB_SHA512_CRYPTODEV)
    list(APPEND INCDIR ${NUTTX_APPS_DIR}/external/avb/avb/libavb/cryptodev)
  else()
    list(APPEND INCDIR ${NUTTX_APPS_DIR}/external/avb/avb/libavb/sha)
  endif()

  set(CSRCS
      avb/libavb/avb_chain_partition_descriptor.c
      avb/libavb/avb_cmdline.c
      avb/libavb/avb_crypto.c
      avb/libavb/avb_descriptor.c
      avb/libavb/avb_footer.c
      avb/libavb/avb_hash_descriptor.c
      avb/libavb/avb_hashtree_descriptor.c
      avb/libavb/avb_kernel_cmdline_descriptor.c
      avb/libavb/avb_property_descriptor.c
      avb/libavb/avb_slot_verify.c
      avb/libavb/avb_sysdeps_posix.c
      avb/libavb/avb_util.c
      avb/libavb/avb_vbmeta_image.c
      avb/libavb/avb_version.c)

  if(CONFIG_LIB_AVB_CRC32)
    list(APPEND CSRCS avb/libavb/avb_crc32.c)
  endif()

  if(CONFIG_LIB_AVB_SHA256)
    if(CONFIG_LIB_AVB_SHA256_CRYPTODEV)
      list(APPEND CSRCS avb/libavb/cryptodev/sha256_cryptodev.c)
    else()
      list(APPEND CSRCS avb/libavb/sha/sha256_impl.c)
    endif()
  endif()

  if(CONFIG_LIB_AVB_SHA512)
    if(CONFIG_LIB_AVB_SHA512_CRYPTODEV)
      list(APPEND CSRCS avb/libavb/cryptodev/sha512_cryptodev.c)
    else()
      list(APPEND CSRCS avb/libavb/sha/sha512_impl.c)
    endif()
  endif()

  if(CONFIG_LIB_AVB_SCONFIG_LIB_AVB_RSA_VERIFY_CRYPTODEVHA512_CRYPTODEV)
    list(APPEND CSRCS avb/libavb/cryptodev/rsa_cryptodev.c)
  else()
    list(APPEND CSRCS avb/libavb/avb_rsa.c)
  endif()

  target_sources(avb PRIVATE ${CSRCS})
  target_include_directories(avb PRIVATE ${INCDIR})
  target_compile_options(avb PRIVATE ${CFLAGS})

endif()
