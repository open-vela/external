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
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/core/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/ldelf/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutils/ext/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libmbedtls/mbedtls/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libmbedtls/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutee/include

CFLAGS += -DARM32
CFLAGS += -DCFG_CORE_DYN_SHM
CFLAGS += -DCFG_NUM_THREADS=1
CFLAGS += -DCFG_OTP_SUPPORT
CFLAGS += -DCFG_OTP_SUPPORT_NO_PROVISION_TMP
CFLAGS += -DCFG_WITH_USER_TA

CFG_HOST_FS_PARENT_PATH ?= /sst
CFLAGS += -DHOST_FS_PARENT_PATH=\"$(CFG_HOST_FS_PARENT_PATH)\"

VPATH += :optee_nuttx/compat

CSRCS += abort.c
CSRCS += atomic.c
CSRCS += core_mmu.c
CSRCS += hmac_memory.c
CSRCS += host_fs.c
CSRCS += ldelf_loader.c
CSRCS += malloc.c
CSRCS += mempool.c
CSRCS += mobj.c
CSRCS += mobj_dyn_shm.c
CSRCS += msg_param.c
CSRCS += notif.c
CSRCS += otp_stubs.c
CSRCS += panic.c
CSRCS += random.c
CSRCS += scall.c
CSRCS += spinlock.c
CSRCS += tee_time_system.c
CSRCS += thread.c
CSRCS += thread_optee_compat.c
CSRCS += trace_ext.c
CSRCS += ts_manager.c
CSRCS += user_access.c
CSRCS += user_mode_ctx.c
CSRCS += vm.c

ifeq ($(strip $(CONFIG_USER_TA_WASM)),y)
CFLAGS += -DUSER_TA_WASM
VPATH += :optee_nuttx/wasm

CSRCS += user_ta_wasm.c
CSRCS += libtee_builtin_wrapper.c
endif

ifeq ($(CONFIG_OPTEE_SERVER_NONE),)
PROGNAME = $(CONFIG_OPTEE_SERVER_PROGNAME)
PRIORITY = $(CONFIG_OPTEE_SERVER_PRIORITY)
STACKSIZE = $(CONFIG_OPTEE_SERVER_STACKSIZE)
VPATH += :optee_nuttx/server
MAINSRC := opteed.c
endif

include $(APPDIR)/Application.mk
