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

if(CONFIG_OPTEE_TEST_CA)
  set(INCDIR
      ${NUTTX_APPS_DIR}//external/optee/optee_os/optee_os/lib/libutee/include
      ${NUTTX_APPS_DIR}//external/optee/optee_os/optee_os/lib/libutils/ext/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/host/supp_plugin/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/host/xtest
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/host/xtest/adbg/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/aes_perf/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/bti_test/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/concurrent/include/
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/concurrent_large/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/create_fail_test/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/crypt/include/
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/enc_fs/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/hash_perf/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/include/
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/large/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/miss/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/os_test/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/rpc_test/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/sdp_basic/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/sims/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/sims_keepalive/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/socket/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/storage_benchmark/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/subkey1/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/subkey2/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/supp_plugin/include
      ${CMAKE_CURRENT_LIST_DIR}/optee_test/ta/tpm_log_test/include)

  set(CSRCS
      optee_test/host/xtest/adbg/src/adbg_case.c
      optee_test/host/xtest/adbg/src/adbg_enum.c
      optee_test/host/xtest/adbg/src/adbg_expect.c
      optee_test/host/xtest/adbg/src/adbg_log.c
      optee_test/host/xtest/adbg/src/adbg_run.c
      optee_test/host/xtest/adbg/src/security_utils_hex.c
      optee_test/host/xtest/aes_perf.c
      optee_test/host/xtest/hash_perf.c
      optee_test/host/xtest/regression_4000.c
      optee_test/host/xtest/regression_5000.c
      optee_test/host/xtest/regression_6000.c
      optee_test/host/xtest/stats.c
      optee_test/host/xtest/xtest_helpers.c
      optee_test/host/xtest/xtest_test.c)

  nuttx_add_application(
    NAME
    ${CONFIG_OPTEE_TEST_CA_PROGNAME}
    SRCS
    optee_test/host/xtest/xtest_main.c
    ${CSRCS}
    INCLUDE_DIRECTORIES
    ${INCDIR}
    STACKSIZE
    ${CONFIG_OPTEE_TEST_CA_STACKSIZE}
    PRIORITY
    ${CONFIG_OPTEE_TEST_CA_PRIORITY})
endif()

if(CONFIG_OPTEE_TEST_TA)

  set(INCDIR
      ${NUTTX_APPS_DIR}/external/optee/optee_test/optee_test/ta/crypt/include
      ${NUTTX_APPS_DIR}/external/optee/optee_test/optee_test/ta/include
      ${NUTTX_APPS_DIR}/external/optee/optee_test/optee_test/ta/storage2/include
  )

  set(CSRCS
      optee_test/ta/crypt/aes_impl.c
      optee_test/ta/crypt/aes_taf.c
      optee_test/ta/crypt/arith_taf.c
      optee_test/ta/crypt/cryp_taf.c
      optee_test/ta/crypt/derive_key_taf.c
      optee_test/ta/crypt/handle.c
      optee_test/ta/crypt/seed_rng_taf.c
      optee_test/ta/crypt/sha2_impl.c
      optee_test/ta/crypt/sha2_taf.c
      optee_test/ta/storage/storage.c)

    ta_add_library(
      NAME
      optee_test_ta
      SRCS
      ${CSRCS}
      INCLUDES
      ${INCDIR})

    ta_add_application(
      NAME ta_crypt
      SRCS optee_test/ta/crypt/ta_crypt_entry.c
      STACKSIZE
      4096
      INCLUDES
      ${INCDIR}
      INSTALL_NAME
      etc/ta/A05B3ECBF1ADE011998B0002A5D5C51B)

    ta_add_application(
      NAME
      ta_storage
      SRCS
      optee_test/ta/storage/ta_storage_entry.c
      STACKSIZE
      4096
      INCLUDES
      ${INCDIR}
      INSTALL_NAME
      etc/ta/A7F289B6DF8A7A479F9932E90C0AD0A2)

    ta_add_application(
      NAME
      ta_storage2
      SRCS
      optee_test/ta/storage2/ta_storage2_entry.c
      STACKSIZE
      4096
      INCLUDES
      ${INCDIR}
      INSTALL_NAME
      etc/ta/9E271E73FBAA7545A77138CAA6F0CCA6)

endif()
