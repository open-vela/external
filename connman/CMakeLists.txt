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

if(CONFIG_CONNMAN)

  set(CONNMAN_FLAGS
      -DCONNMAN_PLUGIN_BUILTIN
      -DHAVE_CONFIG_H
      -DSTORAGEDIR="${CONFIG_CONNMAN_STORAGEDIR}"
      -DPLUGINDIR="${CONFIG_CONNMAN_STORAGEDIR}"
      -DVPN_STORAGEDIR="${CONFIG_CONNMAN_VPN_STORAGEDIR}"
      -DCONFIGDIR="${CONFIG_CONNMAN_CONFIGDIR}"
      -DSTATEDIR="${CONFIG_CONNMAN_STATEDIR}"
      -Wno-format
      -Wno-shadow
      -Wno-strict-prototypes
      -Dprint_backtrace=conn_print_backtrace)

  set(BINARY_CONNMAN_DIR ${CMAKE_BINARY_DIR}/apps/external/connman)
  set(CONNMAN_INCDIR
      ${CMAKE_CURRENT_LIST_DIR}
      ${CMAKE_CURRENT_LIST_DIR}/include
      ${CMAKE_CURRENT_LIST_DIR}/connman
      ${CMAKE_CURRENT_LIST_DIR}/connman/include
      ${CMAKE_CURRENT_LIST_DIR}/connman/sdk
      ${BINARY_CONNMAN_DIR}/
      ${BINARY_CONNMAN_DIR}/connman
      ${NUTTX_APPS_DIR}/external/glib/glib/glib
      ${NUTTX_APPS_DIR}/external/glib/glib
      ${NUTTX_APPS_DIR}/external/glib
      ${NUTTX_APPS_DIR}/external/dbus/dbus
      ${NUTTX_APPS_DIR}/include
      ${NUTTX_APPS_DIR}/external/ofono/include)

  if(TARGET nuttx)
    set_property(
      TARGET nuttx
      APPEND
      PROPERTY NUTTX_INCLUDE_DIRECTORIES ${BINARY_CONNMAN_DIR}/connman)
  endif()

  # Prefer a single gdbus implementation to avoid duplicate symbols between ofono and connman.
  # CONFIG_OFONO determines which gdbus implementation to use:
  # - If CONFIG_OFONO is enabled, expose ofono's gdbus headers
  # - Otherwise, expose connman's gdbus headers
  if(CONFIG_OFONO)
    list(APPEND CONNMAN_INCDIR ${NUTTX_APPS_DIR}/external/ofono/ofono/gdbus)
  else()
    list(APPEND CONNMAN_INCDIR ${CMAKE_CURRENT_LIST_DIR}/connman/gdbus)
  endif()

  if(CONFIG_CONNMAN_WASM)
    list(APPEND WRCFLAGS --bounds-checks=0)

  wasm_add_application(
      NAME
      connman
      SRCS
      connman/src/main.c
      STACK_SIZE
      ${CONFIG_CONNMAN_STACKSIZE}
      INITIAL_MEMORY_SIZE
      196608
      WINCLUDES
      ${CONNMAN_INCDIR}
      WAMR_MODE
      AOT
      WRCFLAGS
      ${WRCFLAGS}
      WCFLAGS
      ${CONNMAN_FLAGS}
      INSTALL_NAME
      etc/connman.aot
    )
  else()
    nuttx_add_application(
      NAME
      connmand
      SRCS
      connman/src/main.c
      INCLUDE_DIRECTORIES
      ${CONNMAN_INCDIR}
      COMPILE_FLAGS
      ${CONNMAN_FLAGS}
      STACKSIZE
      ${CONFIG_CONNMAN_STACKSIZE}
      PRIORITY
      ${CONFIG_CONNMAN_PRIORITY})
  endif()

  nuttx_add_library(connman)

  set(CONNMAN_CSRCS)
  file(GLOB CSRCS connman/src/*.c)
  list(
    REMOVE_ITEM
    CSRCS
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/connmand-wait-online.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/firewall-nftables.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/inotify.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/clock.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/timezone.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/ntp.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/6to4.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/dnsproxy.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/wispr.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/timeserver.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/stats.c
    ${CMAKE_CURRENT_LIST_DIR}/connman/src/wpad.c)
  list(APPEND CONNMAN_CSRCS ${CSRCS})

  file(GLOB CSRCS connman/src/shared/*.c)
  list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/connman/src/shared/mnlg.c)
  list(APPEND CONNMAN_CSRCS ${CSRCS})

  file(GLOB CSRCS connman/gdhcp/*.c)
  list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/connman/gdhcp/ipv4ll.c)
  list(APPEND CONNMAN_CSRCS ${CSRCS})

  # Select gdbus source files based on CONFIG_OFONO
  if(NOT CONFIG_OFONO)
    # Use connman's own gdbus implementation
    file(GLOB CSRCS connman/gdbus/*.c)
  else()
    # Use ofono's gdbus implementation
    file(GLOB CSRCS ${NUTTX_APPS_DIR}/external/ofono/ofono/gdbus/*.c)
  endif()
  list(APPEND CONNMAN_CSRCS ${CSRCS})

  file(GLOB CSRCS connman/sdk/*.c)
  list(APPEND CONNMAN_CSRCS ${CSRCS})

  set(PLUGIN_MODULES)

  if(CONFIG_OFONO)
    list(APPEND CONNMAN_CSRCS connman/plugins/ofono.c)
    list(APPEND PLUGIN_MODULES ofono)
  endif()

  if(CONFIG_CONNMAN_LIB_WAPI)
    list(APPEND CONNMAN_CSRCS connman/plugins/wifi_wapi.c)
    list(APPEND PLUGIN_MODULES wifi)
  endif()

  if(CONFIG_CONNMAN_LIB_BLUETOOTH)
  list(APPEND CONNMAN_CSRCS connman/plugins/bluetooth_mipan.c)
  list(APPEND PLUGIN_MODULES bluetooth_mipan)
  endif()

  if(CONFIG_CONNMAN_CTL)
    file(GLOB CSRCS connman/client/*.c)
    list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/connman/client/main.c
         ${CMAKE_CURRENT_LIST_DIR}/connman/client/main_nuttx.c
         ${CMAKE_CURRENT_LIST_DIR}/connman/client/input.c)
    list(APPEND CONNMAN_CSRCS ${CSRCS})

    nuttx_add_application(
      NAME
      connmanctl
      SRCS
      connman/client/main_nuttx.c
      INCLUDE_DIRECTORIES
      ${CONNMAN_INCDIR}
      COMPILE_FLAGS
      ${CONNMAN_FLAGS}
      STACKSIZE
      ${CONFIG_CONNMAN_CTL_STACKSIZE})
  endif()

  if(NOT EXISTS ${BINARY_CONNMAN_DIR}/connman)
    file(MAKE_DIRECTORY ${BINARY_CONNMAN_DIR}/connman)
  endif()

  if(EXISTS ${BINARY_CONNMAN_DIR}/connman/connman)
    file(REMOVE ${BINARY_CONNMAN_DIR}/connman/connman)
  endif()
  nuttx_create_symlink(${CMAKE_CURRENT_LIST_DIR}/connman/include
                       ${BINARY_CONNMAN_DIR}/connman/connman)

  if(NOT EXISTS ${BINARY_CONNMAN_DIR}/connman/connman/version.h)
    file(WRITE ${BINARY_CONNMAN_DIR}/connman/connman/version.h)
  endif()

  execute_process(
    COMMAND ${CMAKE_CURRENT_LIST_DIR}/connman/src/genbuiltin ${PLUGIN_MODULES}
    OUTPUT_FILE ${BINARY_CONNMAN_DIR}/builtin.h)

  if(CONFIG_CONNMAN_WASM)
    wasm_add_library(
    NAME
    connmanlib
    SRCS
    ${CONNMAN_CSRCS}
    WINCLUDES
    ${CONNMAN_INCDIR}
    WCFLAGS
    ${CONNMAN_FLAGS})
  endif()

  target_sources(connman PRIVATE ${CONNMAN_CSRCS})
  target_include_directories(connman PRIVATE ${CONNMAN_INCDIR})
  target_compile_options(connman PRIVATE ${CONNMAN_FLAGS})

endif()
