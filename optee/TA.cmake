# ##############################################################################
# external/optee/TA.cmake
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

include(${NUTTX_APPS_DIR}/../nuttx/cmake/nuttx_parse_function_args.cmake)

function(ta_add_application)
  # parse args using NuttX helper (same style as nuttx_add_application)
  nuttx_parse_function_args(
    FUNC
    ta_add_application
    ONE_VALUE
    NAME
    STACKSIZE
    PRIORITY
    INSTALL_NAME
    LINK_FLAGS
    MULTI_VALUE
    SRCS
    INCLUDES
    CFLAGS
    ARGN
    ${ARGN})

  # basic validation
  if(NOT NAME)
    message(FATAL_ERROR "ta_add_application: missing required argument NAME")
  endif()

  if(NOT SRCS)
    message(
      FATAL_ERROR "ta_add_application(${NAME}): missing required argument SRCS")
  endif()

  # default local CFLAGS
  set(LOCAL_CFLAGS -DCFG_NUM_THREADS=1)
  if(CONFIG_DEBUG_INFO)
    list(APPEND LOCAL_CFLAGS -DTRACE_LEVEL=3)
  elseif(CONFIG_DEBUG_WARN)
    list(APPEND LOCAL_CFLAGS -DTRACE_LEVEL=2)
  elseif(CONFIG_DEBUG_ERROR)
    list(APPEND LOCAL_CFLAGS -DTRACE_LEVEL=1)
  else()
    list(APPEND LOCAL_CFLAGS -DTRACE_LEVEL=1)
  endif()

  # append user-supplied CFLAGS if any
  if(CFLAGS)
    list(APPEND LOCAL_CFLAGS ${CFLAGS})
  endif()

  # determine TA type: wasm or elf (default)
  if(CONFIG_USER_TA_WASM)
    set(TA_TYPE "wasm")
  elseif(CONFIG_USER_TA_ELF)
    set(TA_TYPE "elf")
  else()
    message(FATAL_ERROR "ta_add_application(${NAME}): No TA type configured!")
  endif()

  # ---- common defaults and base include dirs ----
  set(BASE_INCDIR
      ${NUTTX_APPS_DIR}/frameworks/security/include
      ${NUTTX_APPS_DIR}/frameworks/security/optee_vela/include
      ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/core/include
      ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/lib/libutee/include
      ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/lib/libutils/ext/include
  )

  # Merge includes: base + per-TA INCLUDES
  set(MINCLUDES ${BASE_INCDIR})
  if(INCLUDES)
    list(APPEND MINCLUDES ${INCLUDES})
  endif()

  # ############################################################################
  # WASM path: call wasm_add_application
  # ############################################################################

  if("${TA_TYPE}" STREQUAL "wasm")
    list(APPEND LOCAL_CFLAGS -DUSER_TA_WASM)

    list(APPEND MINCLUDES
         ${NUTTX_APPS_DIR}/interpreters/wamr/wamr/core/iwasm/include)

    set(LOCAL_WLDFLAGS
        -Wl,--export=wasm_TA_CreateEntryPoint
        -Wl,--export=wasm_TA_DestroyEntryPoint
        -Wl,--export=wasm_TA_OpenSessionEntryPoint
        -Wl,--export=wasm_TA_CloseSessionEntryPoint
        -Wl,--export=wasm_TA_InvokeCommandEntryPoint)

    # call wasm_add_application (preserve original semantics)
    message(
      STATUS "ta_add_application: adding WASM application target: ${NAME}")
    wasm_add_application(
      NAME
      ${NAME}
      SRCS
      ${SRCS}
      STACK_SIZE
      ${STACKSIZE}
      WINCLUDES
      ${MINCLUDES}
      WAMR_MODE
      ${CONFIG_OPTEE_TA_FORMAT}
      WLDFLAGS
      ${LOCAL_WLDFLAGS}
      WCFLAGS
      ${LOCAL_CFLAGS}
      INSTALL_NAME
      ${INSTALL_NAME})

  endif()

  # ############################################################################
  # ELF path: call nuttx_add_application
  # ############################################################################

  if("${TA_TYPE}" STREQUAL "elf")
    # default ELF-specific flags
    list(APPEND LOCAL_CFLAGS -fno-lto -mlong-calls)
    if(NOT LINK_FLAGS)
      set(LINK_FLAGS -fno-lto -flinker-output=nolto-rel)
    endif()

    # finally add the application (ELF)
    message(STATUS "ta_add_application: adding ELF application target: ${NAME}")
    nuttx_add_application(
      NAME
      ${NAME}
      SRCS
      ${SRCS}
      STACKSIZE
      ${STACKSIZE}
      PRIORITY
      ${PRIORITY}
      INCLUDE_DIRECTORIES
      ${MINCLUDES}
      COMPILE_FLAGS
      ${LOCAL_CFLAGS}
      LINK_FLAGS
      ${LINK_FLAGS}
      DYNLIB
      y)

    if(INSTALL_NAME)
      add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/TA_elf/${INSTALL_NAME}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/TA_elf
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/bin/${NAME}
                ${CMAKE_BINARY_DIR}/TA_elf/${INSTALL_NAME}
        DEPENDS ELF_${NAME})
      add_custom_target(ta_elf_gen_${NAME}
                        DEPENDS ${CMAKE_BINARY_DIR}/TA_elf/${INSTALL_NAME})

      add_dynamic_rcraws(RAWS ${CMAKE_BINARY_DIR}/TA_elf/${INSTALL_NAME}
                         DEPENDS ta_elf_gen_${NAME})
    endif()
  endif()

endfunction()
