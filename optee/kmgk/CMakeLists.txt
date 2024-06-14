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

if(CONFIG_TA_KEYSTORE)

  set(CSRCS
      kmgk/keymaster/ta/keystore_ta.c
      kmgk/keymaster/ta/attestation.c
      kmgk/keymaster/ta/auth.c
      kmgk/keymaster/ta/crypto_aes.c
      kmgk/keymaster/ta/crypto_ec.c
      kmgk/keymaster/ta/crypto_rsa.c
      kmgk/keymaster/ta/generator.c
      kmgk/keymaster/ta/master_crypto.c
      kmgk/keymaster/ta/mbedtls_proxy.c
      kmgk/keymaster/ta/operations.c
      kmgk/keymaster/ta/paddings.c
      kmgk/keymaster/ta/parameters.c
      kmgk/keymaster/ta/parsel.c
      kmgk/keymaster/ta/shift.c
      kmgk/keymaster/ta/tables.c)

  nuttx_add_application(
    MODULE
    ${CONFIG_TA_KEYSTORE}
    NAME
    ta_keystore
    SRCS
    ${CSRCS}
    COMPILE_FLAGS
    -DKM_RECV_BUF_SIZE=${CONFIG_KM_RECV_BUF_SIZE}
    INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/kmgk/keymaster/ta/include)

endif()
