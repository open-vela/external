#
# Copyright (C) 2024 Xiaomi Corporation
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

if(CONFIG_LIB_SSH)

  set(LIBSSH_FLAGS
      -DTHREAD_STACKSIZE=${CONFIG_UTILS_SSH_STACKSIZE}
      -DBLOCKSIZE=4096
      -DBUF_SIZE=4096
      -DCHUNKSIZE=4096
      -DERROR_BUFFERLEN=512
      -DLOG_SIZE=256
      -DMAX_LINE_SIZE=512
      -Dmd5_init=sshmd5_init
      -Dmd5_update=sshmd5_update
      -Dmd5_final=sshmd5_final
      -Dsha1_init=sshsha1_init
      -Dsha256_init=sshsha256_init
      -Dsha384_init=sshsha384_init
      -Dsha512_init=sshsha512_init
      -Dhmac_init=ssh_hmac_init
      -Wno-deprecated-declarations)

  set(LIBSSH_INCDIR ${CMAKE_CURRENT_LIST_DIR}
                    ${NUTTX_APPS_DIR}/system/zlib/zlib)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/libssh/include)

  nuttx_add_library(libssh)

  file(GLOB CSRCS libssh/src/*.c libssh/src/external/*.c libssh/src/threads/*.c)
  list(
    REMOVE_ITEM
    CSRCS
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/dh_crypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/ecdh_crypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/ecdh_gcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/gcrypt_missing.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/getrandom_crypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/getrandom_gcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/gssapi.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/libcrypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/libcrypto-compat.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/libgcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/md_crypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/md_gcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/pki_crypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/pki_gcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/threads/libcrypto.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/threads/libgcrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/libssh/src/threads/winlocks.c)

  target_sources(libssh PRIVATE ${CSRCS})

  target_include_directories(libssh PRIVATE ${LIBSSH_INCDIR})
  target_compile_options(libssh PRIVATE ${LIBSSH_FLAGS})

  if(CONFIG_UTILS_SSH)
    nuttx_add_application(
      NAME
      scp
      SRCS
      libssh/examples/libssh_scp.c
      libssh/examples/authentication.c
      INCLUDE_DIRECTORIES
      ${LIBSSH_INCDIR}
      COMPILE_FLAGS
      ${LIBSSH_FLAGS}
      STACKSIZE
      ${CONFIG_UTILS_LIBSSH_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_LIBSSH_PRIORITY})

    nuttx_add_application(
      NAME
      ssh
      SRCS
      libssh/examples/ssh_client.c
      libssh/examples/connect_ssh.c
      INCLUDE_DIRECTORIES
      ${LIBSSH_INCDIR}
      COMPILE_FLAGS
      ${LIBSSH_FLAGS}
      STACKSIZE
      ${CONFIG_UTILS_LIBSSH_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_LIBSSH_PRIORITY})

    nuttx_add_application(
      NAME
      sshd
      SRCS
      libssh/examples/ssh_server.c
      libssh/examples/knownhosts.c
      INCLUDE_DIRECTORIES
      ${LIBSSH_INCDIR}
      COMPILE_FLAGS
      ${LIBSSH_FLAGS}
      STACKSIZE
      ${CONFIG_UTILS_LIBSSH_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_LIBSSH_PRIORITY})

  endif()

  if(CONFIG_TEST_SSH)
    list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/libssh/src/buffer.c)

    execute_process(
      COMMAND sh -c "touch ${CMAKE_CURRENT_BINARY_DIR}/tests_config.h"
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

    set(INCDIR
        ${NUTTX_APPS_DIR}/testing/cmocka/cmocka/include
        ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/libssh/tests
        ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/libssh/src)
    set(DSRCS
        ${CMAKE_CURRENT_LIST_DIR}/libssh/tests/torture_cmocka.c
        ${CMAKE_CURRENT_LIST_DIR}/libssh/tests/torture_key.c
        ${CMAKE_CURRENT_LIST_DIR}/libssh/tests/torture.c)
    set(LIBSSH_TESTDIR ${CMAKE_CURRENT_LIST_DIR}/libssh/tests/unittests)
    set(MAIN_FUN
        [=[
        #ifndef HAVE_MAIN
        #define torture_run_tests(_) main(int argc, char **argv)
        #endif
      ]=])

    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/def_mainfun.h ${MAIN_FUN})

    set(TEST_FLAG "-include ${CMAKE_CURRENT_BINARY_DIR}/def_mainfun.h")

    set_source_files_properties(
      ${CMAKE_CURRENT_LIST_DIR}/libssh/tests/torture.c
      PROPERTIES COMPILE_FLAGS "-Dmain=unused_main -DTORTURE_SHARED")

    set_source_files_properties(${LIBSSH_TESTDIR}/torture_buffer.c
                                PROPERTIES COMPILE_FLAGS ${TEST_FLAG})

    nuttx_add_application(
      NAME
      cmocka_libssh_buffer
      SRCS
      ${LIBSSH_TESTDIR}/torture_buffer.c
      ${DSRCS}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      DEPENDS
      cmocka
      STACKSIZE
      ${CONFIG_UTILS_SSH_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_SSH_PRIORITY})

    set_source_files_properties(${LIBSSH_TESTDIR}/torture_bytearray.c
                                PROPERTIES COMPILE_FLAGS ${TEST_FLAG})

    nuttx_add_application(
      NAME
      cmocka_libssh_bytearray
      SRCS
      ${LIBSSH_TESTDIR}/torture_bytearray.c
      ${DSRCS}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      DEPENDS
      cmocka
      STACKSIZE
      ${CONFIG_UTILS_SSH_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_SSH_PRIORITY})
  endif()
endif()
