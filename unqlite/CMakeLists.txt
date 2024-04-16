#
# Copyright (C) 2020 Xiaomi Corporation
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

if(CONFIG_UNQLITE)

  # ############################################################################
  # Flags
  # ############################################################################

  set(CFLAGS -Wno-unused-function -Wno-misleading-indentation -Wno-shadow
             -Wstringop-overflow=0)

  list(APPEND CFLAGS -DSXMEM_POOL_NBUCKETS=${CONFIG_SXMEM_POOL_NBUCKETS}
       -DSXMEM_POOL_INCR=${CONFIG_SXMEM_POOL_INCR})

  if(CONFIG_UNQLITE_LOCK_BY_SEM)
    list(APPEND CFLAGS -DUNQLITE_LOCK_BY_SEM)
  endif()

  if(NOT CONFIG_UNQLITE_ENABLE_DIRSYNC)
    list(APPEND CFLAGS -DUNQLITE_DISABLE_DIRSYNC)
  endif()
  if(NOT CONFIG_DISABLE_PTHREAD)
    list(APPEND CFLAGS -DUNQLITE_ENABLE_THREADS)
  endif()
  if(CONFIG_UNQLITE_ENABLE_JX9_HASH_IO)
    list(APPEND CFLAGS -DUNQLITE_ENABLE_JX9_HASH_IO)
  endif()
  if(NOT CONFIG_JX9_ENABLE_DISK_IO)
    list(APPEND CFLAGS -DJX9_DISABLE_BUILTIN_FUNC)
  endif()

  if(CONFIG_JX9_ENABLE_MATH_FUNC)
    list(APPEND CFLAGS -DJX9_ENABLE_MATH_FUNC)
  endif()
  # ############################################################################
  # Sources
  # ############################################################################
  set(CSRCS unqlite/unqlite.c)
  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/unqlite)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(unqlite STATIC)
  target_sources(unqlite PRIVATE ${CSRCS})
  target_include_directories(unqlite PRIVATE ${INCDIR})
  target_compile_options(unqlite PRIVATE ${CFLAGS})

  # ############################################################################
  # Applications Configuration
  # ############################################################################

  if(CONFIG_UNQLITE_ENABLE_TESTS)
    nuttx_add_application(
      NAME
      unqlite_test1
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/1.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test2
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/2.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test3
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/3.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test4
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/4.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test5
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/5.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test6
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/6.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)

    nuttx_add_application(
      NAME
      unqlite_test_huge
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/unqlite_huge.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test_mp3
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/unqlite_mp3.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test_tar
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/unqlite_tar.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)
    nuttx_add_application(
      NAME
      unqlite_test_demovfs
      STACKSIZE
      ${CONFIG_UNQLITE_TESTS_STACKSIZE}
      PRIORITY
      ${CONFIG_UNQLITE_TESTS_PRIORITY}
      SRCS
      unqlite/example/demovfs/unqlite_demovfs.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      unqlite)

  endif()
endif()
