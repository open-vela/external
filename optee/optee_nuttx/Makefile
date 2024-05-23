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

CFLAGS += ${INCDIR_PREFIX}optee_nuttx/include
ifeq ($(CONFIG_OPTEE_COMPAT_MITEE_FS),y)
CFLAGS += ${INCDIR_PREFIX}optee_nuttx/include/mitee_compat
endif
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/core/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/ldelf/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutils/ext/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutee/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/crypto/mbedtls/mbedtls/library

CFLAGS += -DARM32
CFLAGS += -DCFG_CORE_DYN_SHM
CFLAGS += -DCFG_NUM_THREADS=1
CFLAGS += -DCFG_OTP_SUPPORT
CFLAGS += -DCFG_OTP_SUPPORT_NO_PROVISION_TMP
CFLAGS += -DCFG_WITH_USER_TA

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

ifeq ($(CONFIG_TEE_CORE_DEBUG),y)
CFLAGS += -DCFG_TEE_CORE_DEBUG
CSRCS += optee_nuttx/compat/spin_lock_debug.c
endif

CFG_HOST_FS_PARENT_PATH ?= $(CONFIG_OPTEE_HOST_FS_PARENT_PATH)
CFLAGS += -DHOST_FS_PARENT_PATH=\"$(CFG_HOST_FS_PARENT_PATH)\"

CSRCS += optee_nuttx/compat/abort.c
CSRCS += optee_nuttx/compat/atomic.c
CSRCS += optee_nuttx/compat/core_mmu.c
CSRCS += optee_nuttx/compat/hmac_memory.c
CSRCS += optee_nuttx/compat/host_fs.c
CSRCS += optee_nuttx/compat/ldelf_loader.c
CSRCS += optee_nuttx/compat/malloc.c
CSRCS += optee_nuttx/compat/mempool.c
CSRCS += optee_nuttx/compat/mobj.c
CSRCS += optee_nuttx/compat/mobj_dyn_shm.c
CSRCS += optee_nuttx/compat/msg_param.c
CSRCS += optee_nuttx/compat/notif.c
CSRCS += optee_nuttx/compat/otp_stubs.c
CSRCS += optee_nuttx/compat/panic.c
CSRCS += optee_nuttx/compat/random.c
CSRCS += optee_nuttx/compat/scall.c
CSRCS += optee_nuttx/compat/spinlock.c
CSRCS += optee_nuttx/compat/tee_time_system.c
CSRCS += optee_nuttx/compat/thread.c
CSRCS += optee_nuttx/compat/thread_optee_compat.c
CSRCS += optee_nuttx/compat/trace_ext.c
CSRCS += optee_nuttx/compat/ts_manager.c
CSRCS += optee_nuttx/compat/user_access.c
CSRCS += optee_nuttx/compat/user_mode_ctx.c
CSRCS += optee_nuttx/compat/vm.c

ifneq ($(CONFIG_OPTEE_RPMB_FS),)
CSRCS += optee_nuttx/compat/rpmb_fs.c
endif

ifeq ($(CONFIG_OPTEE_COMPAT_MITEE_FS),y)
CFLAGS += -DFS_STORAGE_DIR_PRIVATE=\"/sst/\"

CSRCS += optee_nuttx/compat/mitee_compat/huk_subkey.c
CSRCS += optee_nuttx/compat/mitee_compat/mitee_crypt.c
CSRCS += optee_nuttx/compat/mitee_compat/tee_fs_rpc.c
CSRCS += optee_nuttx/compat/mitee_compat/tee_fs_key_manager_compat.c
CSRCS += optee_nuttx/compat/mitee_compat/tee_obj.c
CSRCS += optee_nuttx/compat/mitee_compat/tee_ree_fs.c
CSRCS += optee_nuttx/compat/mitee_compat/tee_svc_compat.c
CSRCS += optee_nuttx/compat/mitee_compat/tee_svc_storage.c
endif

ifeq ($(strip $(CONFIG_USER_TA_WASM)),y)
CFLAGS += -DUSER_TA_WASM

CSRCS += optee_nuttx/wasm/user_ta_wasm.c
CSRCS += optee_nuttx/wasm/libtee_builtin_wrapper.c
endif

ifeq ($(CONFIG_OPTEE_SERVER_NONE),)
PROGNAME = $(CONFIG_OPTEE_SERVER_PROGNAME)
PRIORITY = $(CONFIG_OPTEE_SERVER_PRIORITY)
STACKSIZE = $(CONFIG_OPTEE_SERVER_STACKSIZE)
MAINSRC = optee_nuttx/server/opteed.c
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
