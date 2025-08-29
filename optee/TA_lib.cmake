# ##############################################################################
# external/optee/TA_lib.cmake
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

function(ta_add_library)
  # parse args using NuttX helper (same style as nuttx_add_application)
  nuttx_parse_function_args(
    FUNC
    ta_add_library
    ONE_VALUE
    NAME
    MULTI_VALUE
    SRCS
    INCLUDES
    CFLAGS
    ARGN
    ${ARGN})

  # basic validation
  if(NOT NAME)
    message(FATAL_ERROR "ta_add_library: missing NAME")
  endif()

  if(NOT SRCS)
    message(FATAL_ERROR "ta_add_library(${NAME}): missing SRCS")
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

  if(CFLAGS)
    list(APPEND LOCAL_CFLAGS ${CFLAGS})
  endif()

  # ---- common defaults and base include dirs ----
  set(BASE_INCDIR
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

  if(CONFIG_USER_TA_WASM)
    message(STATUS "ta_add_library: adding WASM library target: ${NAME}")
    wasm_add_library(
      NAME
      ${NAME}
      SRCS
      ${SRCS}
      WINCLUDES
      ${MINCLUDES}
      WCFLAGS
      ${LOCAL_CFLAGS})
  endif()

  # ############################################################################
  # ELF path: call nuttx_add_application
  # ############################################################################

  if(CONFIG_USER_TA_ELF)
    message(STATUS "ta_add_library: adding ELF library target: ${NAME}")
    list(APPEND LOCAL_CFLAGS -fno-lto -mlong-calls)
    nuttx_library(${NAME})
    nuttx_sources(${SRCS})
    nuttx_include_directories(${MINCLUDES})
    nuttx_compile_options(${LOCAL_CFLAGS})
  endif()

endfunction()
