#
# Copyright (C) 2021 Xiaomi Corporation
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
if(CONFIG_LIB_DBUS)

  nuttx_add_library(dbus STATIC)

  set(CFLAGS -DDBUS_COMPILATION -D__linux__ -DLOG_DAEMON=0 -DLOG_AUTH=0
             -Dprint_message=dbus_print_message)
  set(INCDIR
      ${CMAKE_CURRENT_LIST_DIR}
      ${CMAKE_CURRENT_LIST_DIR}/dbus
      ${CMAKE_CURRENT_LIST_DIR}/dbus/dbus
      ${CMAKE_CURRENT_LIST_DIR}/dbus/tools
      ${CMAKE_CURRENT_LIST_DIR}/dbus/test
      ${NUTTX_APPS_DIR}/external
      ${NUTTX_APPS_DIR}/external/glib/glib
      ${NUTTX_APPS_DIR}/external/glib/glib/glib)

  if(NOT CONFIG_DBUS_DAEMON)
    if(CONFIG_LIB_DBUS_RPMSG_SERVER_CPUNAME)
      list(APPEND CFLAGS
           -DDBUS_RPMSG_SERVER_CPUNAME=CONFIG_LIB_DBUS_RPMSG_SERVER_CPUNAME)
    endif()
  endif()
  # libdbus source files
  set(CSRCS
      dbus/dbus/dbus-address.c
      dbus/dbus/dbus-auth.c
      dbus/dbus/dbus-bus.c
      dbus/dbus/dbus-connection.c
      dbus/dbus/dbus-credentials.c
      dbus/dbus/dbus-errors.c
      dbus/dbus/dbus-keyring.c
      dbus/dbus/dbus-marshal-header.c
      dbus/dbus/dbus-marshal-byteswap.c
      dbus/dbus/dbus-marshal-recursive.c
      dbus/dbus/dbus-marshal-validate.c
      dbus/dbus/dbus-message.c
      dbus/dbus/dbus-misc.c
      dbus/dbus/dbus-nonce.c
      dbus/dbus/dbus-object-tree.c
      dbus/dbus/dbus-pending-call.c
      dbus/dbus/dbus-resources.c
      dbus/dbus/dbus-server.c
      dbus/dbus/dbus-server-socket.c
      dbus/dbus/dbus-server-debug-pipe.c
      dbus/dbus/dbus-sha.c
      dbus/dbus/dbus-signature.c
      dbus/dbus/dbus-syntax.c
      dbus/dbus/dbus-timeout.c
      dbus/dbus/dbus-threads.c
      dbus/dbus/dbus-transport.c
      dbus/dbus/dbus-transport-socket.c
      dbus/dbus/dbus-watch.c
      dbus/dbus/dbus-uuidgen.c
      dbus/dbus/dbus-transport-unix.c
      dbus/dbus/dbus-server-unix.c
      dbus/dbus/dbus-dataslot.c
      dbus/dbus/dbus-file.c
      dbus/dbus/dbus-hash.c
      dbus/dbus/dbus-internals.c
      dbus/dbus/dbus-list.c
      dbus/dbus/dbus-marshal-basic.c
      dbus/dbus/dbus-memory.c
      dbus/dbus/dbus-mempool.c
      dbus/dbus/dbus-string.c
      dbus/dbus/dbus-sysdeps.c
      dbus/dbus/dbus-pipe.c
      dbus/dbus/dbus-file-unix.c
      dbus/dbus/dbus-pipe-unix.c
      dbus/dbus/dbus-sysdeps-unix.c
      dbus/dbus/dbus-sysdeps-pthread.c
      dbus/dbus/dbus-userdb.c
      dbus/tools/dbus-print-message.c
      dbus/tools/tool-common.c
      dbus/dbus/dbus-test-tap.c)

  if(CONFIG_DBUS_DAEMON)
    list(APPEND INCDIR ${NUTTX_APPS_DIR}/external/libexpat/libexpat/expat/lib)
    # dbus utils source files
    list(
      APPEND
      CSRCS
      dbus/dbus/dbus-asv-util.c
      dbus/dbus/dbus-mainloop.c
      dbus/dbus/dbus-message-util.c
      dbus/dbus/dbus-shell.c
      dbus/dbus/dbus-pollable-set.c
      dbus/dbus/dbus-pollable-set-poll.c
      dbus/dbus/dbus-string-util.c
      dbus/dbus/dbus-sysdeps-util.c
      dbus/dbus/dbus-userdb-util.c
      dbus/dbus/dbus-sysdeps-util-unix.c
      dbus/dbus/dbus-spawn-unix.c
      dbus/dbus/dbus-pollable-set-epoll.c)
    # dbus daemon source files
    list(
      APPEND
      CSRCS
      dbus/bus/activation.c
      dbus/bus/apparmor.c
      dbus/bus/audit.c
      dbus/bus/bus.c
      dbus/bus/config-loader-expat.c
      dbus/bus/config-parser.c
      dbus/bus/config-parser-common.c
      dbus/bus/connection.c
      dbus/bus/containers.c
      dbus/bus/desktop-file.c
      dbus/bus/dispatch.c
      dbus/bus/driver.c
      dbus/bus/expirelist.c
      dbus/bus/policy.c
      dbus/bus/selinux.c
      dbus/bus/services.c
      dbus/bus/signals.c
      dbus/bus/test.c
      dbus/bus/utils.c
      dbus/bus/dir-watch-default.c
      dbus/bus/stats.c)

    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_DBUS}
      NAME
      dbusdaemon
      STACKSIZE
      ${CONFIG_DBUS_STACKSIZE}
      PRIORITY
      ${CONFIG_DBUS_PRIORITY}
      SRCS
      dbus/bus/main.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      dbus)
  endif()

  if(CONFIG_DBUS_SEND)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_DBUS}
      NAME
      dbussend
      STACKSIZE
      ${CONFIG_DBUS_STACKSIZE}
      PRIORITY
      ${CONFIG_DBUS_PRIORITY}
      SRCS
      dbus/tools/dbus-send.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      dbus)
  endif()

  if(CONFIG_DBUS_MONITOR)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_DBUS}
      NAME
      dbusmonitor
      STACKSIZE
      ${CONFIG_DBUS_STACKSIZE}
      PRIORITY
      ${CONFIG_DBUS_PRIORITY}
      SRCS
      dbus/tools/dbus-monitor.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      dbus)
  endif()

  if(CONFIG_DBUS_TEST_TOOL)
    list(APPEND CSRCS dbus/tools/dbus-echo.c dbus/tools/dbus-spam.c)

    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_DBUS}
      NAME
      dbustesttool
      STACKSIZE
      ${CONFIG_DBUS_STACKSIZE}
      PRIORITY
      ${CONFIG_DBUS_PRIORITY}
      SRCS
      dbus/tools/test-tool.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      dbus)
  endif()

  if(CONFIG_DBUS_UPDATE_ACTIVATION_ENVIRONMENT)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_DBUS}
      NAME
      dbus_update_activation_environment
      STACKSIZE
      ${CONFIG_DBUS_STACKSIZE}
      PRIORITY
      ${CONFIG_DBUS_PRIORITY}
      SRCS
      dbus/tools/dbus-update-activation-environment.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      dbus)
  endif()

  if(CONFIG_DBUS_TEST)
    list(APPEND CFLAGS -DDBUS_ENABLE_EMBEDDED_TESTS=1)
    list(
      APPEND
      CSRCS
      dbus/test/disable-crash-handling.c
      dbus/test/test-utils.c
      dbus/test/internals/dbus-message-util.c
      dbus/test/internals/dbus-auth-util.c
      dbus/test/internals/mempool.c
      dbus/test/internals/address.c
      dbus/test/internals/sha.c
      dbus/test/internals/dbus-marshal-recursive-util.c
      dbus/test/internals/dbus-sysdeps-util.c
      dbus/test/internals/dbus-marshal-byteswap-util.c
      dbus/test/internals/dbus-auth-script.c
      dbus/test/internals/dbus-string-util.c
      dbus/test/internals/dbus-marshal-validate-util.c
      dbus/test/internals/dbus-message-factory.c
      dbus/test/internals/dbus-credentials-util.c)

    set(MAIN_SRC_LIST
        dbus/test/name-test/test-ids.c
        dbus/test/name-test/test-pending-call-disconnected.c
        dbus/test/name-test/test-pending-call-dispatch.c
        dbus/test/name-test/test-pending-call-timeout.c
        dbus/test/name-test/test-privserver-client.c
        dbus/test/name-test/test-shutdown.c
        dbus/test/name-test/test-threads-init.c
        dbus/test/test-privserver.c
        dbus/test/test-service.c
        dbus/test/internals/hash.c
        dbus/test/internals/printf.c
        dbus/test/internals/atomic.c
        dbus/test/internals/message-internals.c
        dbus/test/internals/marshal-recursive.c
        dbus/test/internals/misc-internals.c)

    set(PROGNAME_LIST
        dbus_test_ids
        dbus_test_pending_call_disconnected
        dbus_test_pending_call_dispatch
        dbus_test_pending_call_timeout
        dbus_test_privserver_client
        dbus_test_shutdown
        dbus_test_threads_init
        dbus_test_privserver
        dbus_test_service
        dbus_test_hash
        dbus_test_printf
        dbus_test_atomic
        dbus_test_message_internals
        dbus_test_marshal_recursive
        dbus_test_misc_internals)

    list(LENGTH MAIN_SRC_LIST list_len)
    math(EXPR list_len "${list_len} - 1")

    foreach(idx RANGE ${list_len})
      list(GET MAIN_SRC_LIST ${idx} source_file)
      list(GET PROGNAME_LIST ${idx} prog_name)
      nuttx_add_application(
        MODULE
        ${CONFIG_LIB_DBUS}
        NAME
        ${prog_name}
        STACKSIZE
        ${CONFIG_DBUS_STACKSIZE}
        PRIORITY
        ${CONFIG_DBUS_PRIORITY}
        SRCS
        ${source_file}
        INCLUDE_DIRECTORIES
        ${INCDIR}
        COMPILE_FLAGS
        ${CFLAGS}
        DEPENDS
        dbus)
    endforeach()
  endif()

  target_sources(dbus PRIVATE ${CSRCS})
  target_include_directories(dbus PRIVATE ${INCDIR})
  target_compile_options(dbus PRIVATE ${CFLAGS})

endif()
