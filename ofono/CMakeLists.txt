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

if(CONFIG_OFONO)
  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/include)

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}
             ${CMAKE_CURRENT_BINARY_DIR}
             ${CMAKE_CURRENT_LIST_DIR}/ell
             ${CMAKE_CURRENT_LIST_DIR}/ofono
             ${CMAKE_CURRENT_LIST_DIR}/ofono/src
             ${CMAKE_CURRENT_LIST_DIR}/ofono/gatchat
             ${CMAKE_CURRENT_LIST_DIR}/ofono/gril
             ${CMAKE_CURRENT_LIST_DIR}/ofono/gdbus
             ${NUTTX_APPS_DIR}/external
             ${NUTTX_APPS_DIR}/external/glib/glib/glib
             ${NUTTX_APPS_DIR}/external/glib/glib
             ${NUTTX_APPS_DIR}/external/dbus/dbus)

  set(CFLAGS
    -DHAVE_CONFIG_H
    -DPLUGINDIR=CONFIG_OFONO_PLUGIN_DIR
    -DOFONO_PLUGIN_BUILTIN
    -Dprint_buf=ofono_gril_print_buf
    -DHAVE_EXPLICIT_BZERO
    -DHAVE_RAWMEMCHR)

  set(CSRCS)
  set(ATCSRCS)
  set(BUILTIN_PLUGIN)

  # ELL (Embedded Linux library)
  set(ELL_SRCS ell/ell/util.c ell/ell/test.c ell/ell/strv.c ell/ell/utf8.c
               ell/ell/queue.c ell/ell/timeout.c ell/ell/main.c ell/ell/idle.c
               ell/ell/signal.c ell/ell/io.c ell/ell/checksum.c ell/ell/log.c
               ell/ell/uuid.c ell/ell/file.c ell/ell/uintset.c ell/ell/string.c)

  # OFONO Modem
  if(CONFIG_OFONO_RILMODEM)
    file(GLOB APPEND_FILES ofono/drivers/rilmodem/*.c)
    list(APPEND CSRCS ${APPEND_FILES})
    list(APPEND CSRCS ofono/plugins/rildev.c ofono/plugins/ril.c)
    list(APPEND BUILTIN_PLUGIN rildev ril rilmodem provision)
  endif()

  if(CONFIG_OFONO_ATMODEM)
    file(GLOB APPEND_FILES ofono/drivers/atmodem/*.c ofono/gatchat/*.c)
    list(APPEND ATCSRCS ${APPEND_FILES})
    list(REMOVE_ITEM ATCSRCS ${CMAKE_CURRENT_LIST_DIR}/ofono/gatchat/test-server.c
                             ${CMAKE_CURRENT_LIST_DIR}/ofono/gatchat/gsmdial.c
                             ${CMAKE_CURRENT_LIST_DIR}/ofono/gatchat/test-qcdm.c)
    list(APPEND BUILTIN_PLUGIN atmodem)
  endif()

  if(CONFIG_OFONO_PHONESIM)
    file(GLOB APPEND_FILES ofono/drivers/hfpmodem/*.c)
    list(APPEND CSRCS ${APPEND_FILES})
    list(APPEND CSRCS ofono/plugins/phonesim.c)
    list(APPEND BUILTIN_PLUGIN hfpmodem phonesim)
  endif()

  set(BUILTIN_H ${CMAKE_CURRENT_BINARY_DIR}/builtin.h)
  string(REPLACE ";" " " BUILTIN_PLUGIN_LIST "${BUILTIN_PLUGIN}")
  string(REPLACE "$" "$$" ESCAPED_BUILTIN_PLUGIN_LIST "${BUILTIN_PLUGIN_LIST}")

  nuttx_add_library(ofono)

  add_custom_command(
    OUTPUT ${BUILTIN_H}
    COMMAND
      ./ofono/src/genbuiltin ${ESCAPED_BUILTIN_PLUGIN_LIST} > ${BUILTIN_H}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating builtin.h"
    VERBATIM
  )

  add_custom_target(GenerateOfonoBuiltIn ALL
    DEPENDS ${BUILTIN_H})
  add_dependencies(ofono GenerateOfonoBuiltIn)

  if(CONFIG_OFONO_UNITTEST)
    file(GLOB APPEND_FILES ofono/gril/*.c)
    list(APPEND CSRCS ${APPEND_FILES})
    list(APPEND CSRCS ofono/gatchat/ringbuffer.c ofono/src/common.c
                      ofono/src/log.c ofono/src/simutil.c ofono/src/smsutil.c
                      ofono/src/storage.c ofono/src/stkutil.c ofono/src/util.c
                      ofono/unit/rilmodem-test-engine.c
                      ofono/unit/rilmodem-test-server.c)
    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_rilmodem_cb
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-rilmodem-cb.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_rilmodem_cs
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-rilmodem-cs.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_rilmodem_gprs
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-rilmodem-gprs.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_rilmodem_sms
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-rilmodem-sms.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_util
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-util.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_simutil
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-simutil.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_sms
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-sms.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      test_stkutil
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/unit/test-stkutil.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )
  else()

    # ofono gatchat file(needby ofono emulator)
    list(APPEND CSRCS ${ATCSRCS}
                      ofono/gatchat/gatchat.c ofono/gatchat/gatio.c
                      ofono/gatchat/gatresult.c ofono/gatchat/gatserver.c
                      ofono/gatchat/gatutil.c ofono/gatchat/ringbuffer.c)

    # ofono gprs provision file
    list(APPEND CSRCS ofono/plugins/mbpi.c ofono/plugins/provision.c)

    # ofono core source file and compile flags
    file(GLOB APPEND_FILES ofono/gdbus/*.c ofono/gril/*.c ofono/src/*.c)
    list(APPEND CSRCS ${APPEND_FILES})
    list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/ofono/src/main.c)

    nuttx_add_application(
      MODULE
      ${CONFIG_OFONO}
      NAME
      ofonod
      STACKSIZE
      ${CONFIG_OFONO_STACKSIZE}
      PRIORITY
      ${CONFIG_OFONO_PRIORITY}
      SRCS
      ofono/src/main.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CFLAGS}
      DEPENDS
      ofono
    )
  endif()

  target_include_directories(ofono PRIVATE ${INCDIR})
  target_compile_options(ofono PRIVATE ${CFLAGS})
  target_sources(ofono PRIVATE ${CSRCS} ${ELL_SRCS})
endif()
