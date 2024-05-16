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
if(CONFIG_UTILS_MMC)

  set(CSRCS
      mmc-utils/mmc.c mmc-utils/mmc_cmds.c mmc-utils/lsmmc.c
      mmc-utils/3rdparty/hmac_sha/hmac_sha2.c
      mmc-utils/3rdparty/hmac_sha/sha2.c)

  set(DEFINITIONS
      __u32=uint32_t
      __u64=uint64_t
      __u8=uint8_t
      __u16=uint16_t
      sha224=mmc_sha224
      hmac_sha224=mmc_hmac_sha224
      sha224_init=mmc_sha224_init
      sha224_update=mmc_sha224_update
      sha224_final=mmc_sha224_final
      hmac_sha224_init=mmc_hmac_sha224_init
      hmac_sha224_update=mmc_hmac_sha224_update
      hmac_sha224_final=mmc_hmac_sha224_final
      sha256=mmc_sha256
      hmac_sha256=mmc_hmac_sha256
      sha256_init=mmc_sha256_init
      sha256_update=mmc_sha256_update
      sha256_final=mmc_sha256_final
      hmac_sha256_init=mmc_hmac_sha256_init
      hmac_sha256_update=mmc_hmac_sha256_update
      hmac_sha256_final=mmc_hmac_sha256_final
      sha384=mmc_sha384
      hmac_sha384=mmc_hmac_sha384
      sha384_init=mmc_sha384_init
      sha384_update=mmc_sha384_update
      sha384_final=mmc_sha384_final
      hmac_sha384_init=mmc_hmac_sha384_init
      hmac_sha384_update=mmc_hmac_sha384_update
      hmac_sha384_final=mmc_hmac_sha384_final
      sha512=mmc_sha512
      hmac_sha512=mmc_hmac_sha512
      sha512_init=mmc_sha512_init
      sha512_update=mmc_sha512_update
      sha512_final=mmc_sha512_final
      hmac_sha512_init=mmc_hmac_sha512_init
      hmac_sha512_update=mmc_hmac_sha512_update
      hmac_sha512_final=mmc_hmac_sha512_final
      VERSION=\"1.0\")

  nuttx_add_application(
    MODULE
    ${CONFIG_UTILS_MMC}
    NAME
    mmc
    STACKSIZE
    8192
    PRIORITY
    100
    SRCS
    ${CSRCS}
    COMPILE_FLAGS
    -Wno-shadow
    DEFINITIONS
    ${DEFINITIONS})

endif()
