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
      -DARM32
      -DCFG_CORE_DYN_SHM
      -DCFG_NUM_THREADS=1
      -DCFG_OTP_SUPPORT
      -DCFG_OTP_SUPPORT_NO_PROVISION_TMP
      -DCFG_WITH_USER_TA
      -DHOST_FS_PARENT_PATH=\"${CFG_HOST_FS_PARENT_PATH}\")

  if(CONFIG_TEE_CORE_DEBUG)
    list(APPEND CFLAGS -DCFG_TEE_CORE_DEBUG)
  endif()

  # ############################################################################
  # Sources
  # ############################################################################

  set(CSRCS
      optee_nuttx/compat/abort.c
      optee_nuttx/compat/atomic.c
      optee_nuttx/compat/core_mmu.c
      optee_nuttx/compat/hmac_memory.c
      optee_nuttx/compat/host_fs.c
      optee_nuttx/compat/ldelf_loader.c
      optee_nuttx/compat/malloc.c
      optee_nuttx/compat/mempool.c
      optee_nuttx/compat/mobj.c
      optee_nuttx/compat/mobj_dyn_shm.c
      optee_nuttx/compat/msg_param.c
      optee_nuttx/compat/notif.c
      optee_nuttx/compat/otp_stubs.c
      optee_nuttx/compat/panic.c
      optee_nuttx/compat/random.c
      optee_nuttx/compat/scall.c
      optee_nuttx/compat/spinlock.c
      optee_nuttx/compat/tee_time_system.c
      optee_nuttx/compat/thread.c
      optee_nuttx/compat/thread_optee_compat.c
      optee_nuttx/compat/trace_ext.c
      optee_nuttx/compat/ts_manager.c
      optee_nuttx/compat/user_access.c
      optee_nuttx/compat/user_mode_ctx.c
      optee_nuttx/compat/vm.c)

  if(CONFIG_TEE_CORE_DEBUG)
    list(APPEND CSRCS optee_nuttx/compat/spin_lock_debug.c)
  endif()

  if(CONFIG_OPTEE_RPMB_FS)
    list(APPEND CSRCS optee_nuttx/compat/rpmb_fs.c)
  endif()

  if(CONFIG_OPTEE_COMPAT_MITEE_FS)
    list(
      APPEND
      CSRCS
      optee_nuttx/compat/mitee_compat/huk_subkey.c
      optee_nuttx/compat/mitee_compat/mitee_crypt.c
      optee_nuttx/compat/mitee_compat/tee_fs_rpc.c
      optee_nuttx/compat/mitee_compat/tee_fs_key_manager_compat.c
      optee_nuttx/compat/mitee_compat/tee_obj.c
      optee_nuttx/compat/mitee_compat/tee_ree_fs.c
      optee_nuttx/compat/mitee_compat/tee_svc_compat.c
      optee_nuttx/compat/mitee_compat/tee_svc_storage.c)

    list(APPEND CFLAGS -DFS_STORAGE_DIR_PRIVATE=\"/sst/\")
  endif()

  if(CONFIG_USER_TA_WASM)
    list(APPEND CSRCS optee_nuttx/wasm/user_ta_wasm.c
         optee_nuttx/wasm/libtee_builtin_wrapper.c)

    list(APPEND CFLAGS -DUSER_TA_WASM)
  endif()

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/optee_nuttx/include)
  if(CONFIG_OPTEE_COMPAT_MITEE_FS)
    list(APPEND INCDIR
         ${CMAKE_CURRENT_LIST_DIR}/optee_nuttx/include/mitee_compat)
  endif()

  list(
    APPEND
    INCDIR
    ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/core/include
    ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/ldelf/include
    ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/lib/libutils/ext/include
    ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/lib/libutee/include
    ${NUTTX_APPS_DIR}/crypto/mbedtls/mbedtls/library)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(optee_nuttx STATIC)
  target_sources(optee_nuttx PRIVATE ${CSRCS})
  target_include_directories(optee_nuttx PRIVATE ${INCDIR})
  target_compile_options(optee_nuttx PRIVATE ${CFLAGS})

  # ############################################################################
  # Applications Configuration
  # ############################################################################

  if(NOT CONFIG_OPTEE_SERVER_NONE)
    nuttx_add_application(
      NAME
      ${CONFIG_OPTEE_SERVER_PROGNAME}
      STACKSIZE
      ${CONFIG_OPTEE_SERVER_STACKSIZE}
      PRIORITY
      ${CONFIG_OPTEE_SERVER_PRIORITY}
      SRCS
      optee_nuttx/server/opteed.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      optee_nuttx)
  endif()

endif()
