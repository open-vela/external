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

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_client/optee_client/public
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutee/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutils/ext/include
CFLAGS += ${INCDIR_PREFIX}optee_test/host/supp_plugin/include
CFLAGS += ${INCDIR_PREFIX}optee_test/host/xtest
CFLAGS += ${INCDIR_PREFIX}optee_test/host/xtest/adbg/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/aes_perf/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/bti_test/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/concurrent/include/
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/concurrent_large/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/create_fail_test/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/crypt/include/
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/enc_fs/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/hash_perf/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/include/
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/large/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/miss/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/os_test/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/rpc_test/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/sdp_basic/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/sims/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/sims_keepalive/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/socket/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/storage_benchmark/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/subkey1/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/subkey2/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/supp_plugin/include
CFLAGS += ${INCDIR_PREFIX}optee_test/ta/tpm_log_test/include

CSRCS += optee_test/host/xtest/adbg/src/adbg_case.c
CSRCS += optee_test/host/xtest/adbg/src/adbg_enum.c
CSRCS += optee_test/host/xtest/adbg/src/adbg_expect.c
CSRCS += optee_test/host/xtest/adbg/src/adbg_log.c
CSRCS += optee_test/host/xtest/adbg/src/adbg_run.c
CSRCS += optee_test/host/xtest/adbg/src/security_utils_hex.c
CSRCS += optee_test/host/xtest/aes_perf.c
CSRCS += optee_test/host/xtest/hash_perf.c
CSRCS += optee_test/host/xtest/regression_4000.c
CSRCS += optee_test/host/xtest/regression_5000.c
CSRCS += optee_test/host/xtest/regression_6000.c
CSRCS += optee_test/host/xtest/stats.c
CSRCS += optee_test/host/xtest/xtest_helpers.c
CSRCS += optee_test/host/xtest/xtest_test.c
MAINSRC = optee_test/host/xtest/xtest_main.c
PROGNAME = $(CONFIG_OPTEE_TEST_CA_PROGNAME)
PRIORITY = $(CONFIG_OPTEE_TEST_CA_PRIORITY)
STACKSIZE = $(CONFIG_OPTEE_TEST_CA_STACKSIZE)

include $(APPDIR)/Application.mk
