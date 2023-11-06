# ##############################################################################
# external/zblue/CMakeLists.txt
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

if(CONFIG_BT)

  set(ZBLUE_DIR ${CMAKE_CURRENT_LIST_DIR}/zblue/)
  set(SUBDIR subsys/bluetooth)
  set(ZBLUE_SUBDIR ${ZBLUE_DIR}/${SUBDIR})

  set(ZBLUE_FLAGS)
  set(ZBLUE_INCDIR)
  set(ZBLUE_CSRCS)

  list(APPEND ZBLUE_FLAGS
    -Wno-implicit-function-declaration
    -Wno-unused-but-set-variable
    -Wno-unused-function
    -Wno-unused-variable
    -Wno-implicit-int
    -Wno-shadow
    -Wno-stringop-overread)

  list(APPEND ZBLUE_INCDIR
    ${ZBLUE_DIR}port/include
    # ${ZBLUE_DIR}include
    ${ZBLUE_DIR}subsys/bluetooth
    ${ZBLUE_DIR}subsys/bluetooth/host
    ${ZBLUE_DIR}subsys/bluetooth/services
    ${ZBLUE_DIR}subsys/bluetooth/mesh
    ${ZBLUE_DIR}subsys/bluetooth/common
    ${ZBLUE_DIR}subsys/testsuite/ztest/include
    ${NUTTX_APPS_DIR}/crypto/tinycrypt/tinycrypt/lib/include)

  if(CONFIG_BT_HCI_RAW)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/hci_raw.c)
  endif()

  if(CONFIG_BT_DEBUG_MONITOR)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/monitor.c)
  endif()

  if(CONFIG_BT_TINYCRYPT_ECC)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/hci_ecc.c)
  endif()

  if(CONFIG_BT_A2DP)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/a2dp.c)
  endif()

  if(CONFIG_BT_AVDTP)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/avdtp.c)
  endif()

  if(CONFIG_BT_RFCOMM)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/rfcomm.c)
  endif()

  if(CONFIG_BT_TESTING)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/testing.c)
  endif()

  if(CONFIG_BT_SETTINGS)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/settings.c)
  endif()

  if(CONFIG_BT_HOST_CCM)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/aes_ccm.c)
  endif()

  if(CONFIG_BT_BREDR)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_SUBDIR}/host/keys_br.c
      ${ZBLUE_SUBDIR}/host/l2cap_br.c
      ${ZBLUE_SUBDIR}/host/sdp.c
      ${ZBLUE_SUBDIR}/host/ssp.c)
  endif()

  if(CONFIG_BT_HFP_HF)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_SUBDIR}/host/hfp_hf.c
      ${ZBLUE_SUBDIR}/host/at.c)
  endif()

  if(CONFIG_BT_AUDIO)
    if(CONFIG_BT_ISO)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/audio/iso.c)
    endif()
  endif()

  if(CONFIG_BT_HCI_HOST)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_SUBDIR}/host/uuid.c
      ${ZBLUE_SUBDIR}/host/hci_core.c)

    if(CONFIG_BT_HOST_CRYPTO)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/crypto.c)
    endif()

    if(CONFIG_BT_CONN)
      list(APPEND ZBLUE_CSRCS
        ${ZBLUE_SUBDIR}/host/conn.c
        ${ZBLUE_SUBDIR}/host/l2cap.c
        ${ZBLUE_SUBDIR}/host/att.c
        ${ZBLUE_SUBDIR}/host/gatt.c)
    endif()

    if(CONFIG_BT_SMP)
      list(APPEND ZBLUE_CSRCS
        ${ZBLUE_SUBDIR}/host/smp.c
        ${ZBLUE_SUBDIR}/host/keys.c)
    else()
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/smp_null.c)
    endif()
  endif()

  if(CONFIG_BT_DIS)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/dis.c)
  endif()

  if(CONFIG_BT_BAS)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/bas.c)
  endif()

  if(CONFIG_BT_HRS)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/hrs.c)
  endif()

  if(CONFIG_BT_MESH)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_SUBDIR}/mesh/main.c
      ${ZBLUE_SUBDIR}/mesh/adv.c
      ${ZBLUE_SUBDIR}/mesh/beacon.c
      ${ZBLUE_SUBDIR}/mesh/net.c
      ${ZBLUE_SUBDIR}/mesh/transport.c
      ${ZBLUE_SUBDIR}/mesh/crypto.c
      ${ZBLUE_SUBDIR}/mesh/access.c
      ${ZBLUE_SUBDIR}/mesh/cfg_srv.c
      ${ZBLUE_SUBDIR}/mesh/health_srv.c)
    if(CONFIG_BT_SETTINGS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/settings.c)
    endif()
  endif()

  if(CONFIG_BT_MESH_LOW_POWER)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/lpn.c)
  endif()

  if(CONFIG_BT_MESH_FRIEND)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/friend.c)
  endif()

  if(CONFIG_BT_MESH_PROV)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/prov.c)
  endif()

  if(CONFIG_BT_MESH_PB_ADV)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/pb_adv.c)
  endif()

  if(CONFIG_BT_MESH_PB_GATT)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/pb_gatt.c)
  endif()

  if(CONFIG_BT_MESH_PROXY)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/proxy.c)
  endif()

  if(CONFIG_BT_MESH_CFG_CLI)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/cfg_cli.c)
  endif()

  if(CONFIG_BT_MESH_HEALTH_CLI)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/health_cli.c)
  endif()

  if(CONFIG_BT_MESH_SELF_TEST)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/test.c)
  endif()

  if(CONFIG_BT_MESH_CDB)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/cdb.c)
  endif()

  aux_source_directory(${ZBLUE_SUBDIR}/common ZBLUE_CSRCS)

  if(CONFIG_SETTINGS)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_DIR}subsys/settings/src/settings.c
      ${ZBLUE_DIR}subsys/settings/src/settings_store.c
      ${ZBLUE_DIR}subsys/settings/src/settings_init.c
      ${ZBLUE_DIR}subsys/settings/src/settings_line.c)
    if(CONFIG_SETTINGS_FS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}subsys/settings/src/settings_file.c)
    endif()
    list(APPEND ZBLUE_INCDIR ${ZBLUE_DIR}subsys/settings/include)
  endif()

  if(CONFIG_FILE_SYSTEM)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}port/subsys/fs/fs.c)
  endif()

  if(CONFIG_BT_SHELL)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_DIR}port/subsys/shell/shell.c
      ${ZBLUE_SUBDIR}/shell/bt.c
      ${ZBLUE_SUBDIR}/shell/hci.c)

    nuttx_add_application(
      NAME bt
      SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/bt.c
      INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
      COMPILE_FLAGS ${ZBLUE_FLAGS} -DCONFIG_BT_BT_SHELL)

    if(CONFIG_BT_CONN)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/gatt.c)
      nuttx_add_application(
        NAME gatt
        SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/gatt.c
        INCLUDE_DIRECTORIES {ZBLUE_INCDIR}
        COMPILE_FLAGS {ZBLUE_FLAGS} -DCONFIG_BT_GATT_SHELL)
    endif()

    if(CONFIG_BT_BREDR)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/bredr.c)
      nuttx_add_application(
        NAME bredr
        SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/bredr.c
        INCLUDE_DIRECTORIES {ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS} -DCONFIG_BT_BREDR_SHELL)
    endif()

    if(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/l2cap.c)
      nuttx_add_application(
        NAME l2cap
        SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/l2cap.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS} -DCONFIG_BT_L2CAP_SHELL)
    endif()

    if(CONFIG_BT_RFCOMM)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/rfcomm.c)
      nuttx_add_application(
        NAME rfcomm
        SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/rfcomm.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS} -DCONFIG_BT_RFCOMM_SHELL)
    endif()

    if(CONFIG_BT_AUDIO)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/iso.c)
      nuttx_add_application(
        NAME iso
        SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/iso.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS} -DCONFIG_BT_ISO_SHELL)
    endif()

    if(CONFIG_BT_MESH)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/mesh.c)
      nuttx_add_application(
        NAME mesh
        SRCS ${ZBLUE_DIR}port/${SUBDIR}/shell/mesh.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS})
    endif()
  endif()

  if(CONFIG_BT_TESTER)
    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_DIR}tests/bluetooth/tester/src/bttester.c
      ${ZBLUE_DIR}tests/bluetooth/tester/src/gap.c
      ${ZBLUE_DIR}tests/bluetooth/tester/src/gatt.c)

    if(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}tests/bluetooth/tester/src/l2cap.c)
    endif()

    if(CONFIG_BT_MESH)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}tests/bluetooth/tester/src/mesh.c)
    endif()

    list(APPEND ZBLUE_CSRCS
      ${ZBLUE_DIR}port/drivers/console/uart_pipe.c
      ${ZBLUE_DIR}port/tests/bluetooth/tester/src/system.c
      ${ZBLUE_DIR}port/subsys/power/reboot.c)
    nuttx_add_application(
      NAME bttester
      SRCS ${ZBLUE_DIR}tests/bluetooth/tester/src/main.c
      INCLUDE_DIRECTORIES ${ZBLUE_INCDIR} ${ZBLUE_DIR}tests/bluetooth/tester/src
      COMPILE_FLAGS ${ZBLUE_FLAGS})
  endif()

  list(APPEND ZBLUE_CSRCS
    ${ZBLUE_DIR}port/kernel/sched.c
    ${ZBLUE_DIR}port/kernel/timeout.c
    ${ZBLUE_DIR}port/kernel/work_q.c
    ${ZBLUE_DIR}port/kernel/poll.c
    ${ZBLUE_DIR}port/kernel/mem_slab.c
    ${ZBLUE_DIR}port/kernel/atomic_c.c
    ${ZBLUE_DIR}port/kernel/sem.c
    ${ZBLUE_DIR}port/kernel/mutex.c
    ${ZBLUE_DIR}port/kernel/queue.c
    ${ZBLUE_DIR}port/kernel/thread.c
    ${ZBLUE_DIR}port/kernel/rand32.c
    ${ZBLUE_DIR}port/subsys/net/buf.c
    ${ZBLUE_DIR}port/common/defines.c)

  list(APPEND ZBLUE_CSRCS
    ${ZBLUE_DIR}lib/os/dec.c
    ${ZBLUE_DIR}lib/os/hex.c)

  if(CONFIG_ARCH_CHIP_R328)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}port/chip/xr829/xr829.c)
    list(APPEND ZBLUE_INCDIR
      ${NUTTX_DIR}/arch/arm/src/r328/include/drivers
      ${NUTTX_DIR}/arch/arm/src/r328/include)
  endif()

  if(CONFIG_BT_LIBUSB)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}port/drivers/bluetooth/hci/libusb.c)
  endif()

  if(CONFIG_BT_H4)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}port/drivers/bluetooth/hci/h4.c)
  endif()

  if(CONFIG_ARCH_SIM)
    list(APPEND ZBLUE_FLAGS -O2 -fno-strict-aliasing -ffunction-sections -fdata-sections)
  endif()

  if(CONFIG_BT_SAMPLE)
    if(CONFIG_BT_SAMPLE_PERIPHERAL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}samples/bluetooth/peripheral/src/cts.c)
      nuttx_add_application(
        NAME peripheral
        SRCS ${ZBLUE_DIR}samples/bluetooth/peripheral/src/main.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR} ${ZBLUE_DIR}samples/bluetooth/peripheral/src
        COMPILE_FLAGS ${ZBLUE_FLAGS})
    endif()

    if(CONFIG_BT_SAMPLE_CENTRAL)
      nuttx_add_application(
        NAME central
        SRCS ${ZBLUE_DIR}samples/bluetooth/central/src/main.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS})
    endif()

    if(CONFIG_BT_SAMPLE_MESH)
      nuttx_add_application(
        NAME btmesh
        SRCS ${ZBLUE_DIR}samples/bluetooth/mesh/src/main.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS})

      nuttx_add_application(
        NAME mesh_demo
        SRCS ${ZBLUE_DIR}samples/bluetooth/mesh_demo/src/main.c
        INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
        COMPILE_FLAGS ${ZBLUE_FLAGS})

      if(CONFIG_BT_MESH_PROVISIONER)
        nuttx_add_application(
          NAME mesh_provisioner
          SRCS ${ZBLUE_DIR}samples/bluetooth/mesh_provisioner/src/main.c
          INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
          COMPILE_FLAGS ${ZBLUE_FLAGS})
      endif()
    endif()
  endif()

  if(SCHED_PRIORITY_DEFAULT)
    set(ZBLUE_STACKSIZE ${CONFIG_BT_SAMPLE_STACKSIZE})
  else()
    set(ZBLUE_STACKSIZE ${CONFIG_DEFAULT_TASK_STACKSIZE})
  endif()

  nuttx_add_application(
    NAME zblue
    STACKSIZE ${ZBLUE_STACKSIZE}
    SRCS ${ZBLUE_DIR}port/drivers/bluetooth/hci/hci.c
    INCLUDE_DIRECTORIES ${ZBLUE_INCDIR}
    COMPILE_FLAGS ${ZBLUE_FLAGS})

  nuttx_add_library(zblue)

  target_sources(zblue PRIVATE ${ZBLUE_CSRCS})
  target_include_directories(zblue PRIVATE ${ZBLUE_INCDIR})
  target_compile_options(zblue PRIVATE ${ZBLUE_FLAGS})

  add_custom_target(zblue_prebuild)
  add_custom_command(
    TARGET zblue_prebuild
    PRE_BUILD
    COMMAND ln -sf ../../include/bluetooth ${ZBLUE_DIR}port/include/bluetooth
    COMMAND ln -sf ../../include/drivers ${ZBLUE_DIR}port/include/drivers
    COMMAND ln -sf ../../include/fs ${ZBLUE_DIR}port/include/fs
    COMMAND ln -sf ../../include/settings ${ZBLUE_DIR}port/include/settings
    COMMAND ln -sf ../../include/power ${ZBLUE_DIR}port/include/power
    COMMAND ln -sf ../../include/random ${ZBLUE_DIR}port/include/random
    COMMAND ln -sf ${ZBLUE_DIR}port/include/bluetooth ${ZBLUE_DIR}port/include/zephyr/bluetooth
    COMMAND ln -sf ${ZBLUE_DIR}port/include/random ${ZBLUE_DIR}port/include/zephyr/random
    COMMAND ln -sf ${ZBLUE_DIR}port/include/sys ${ZBLUE_DIR}port/include/zephyr/sys
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/bredr.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/bt.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/gatt.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/l2cap.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/mesh.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/rfcomm.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/ticker.c
    COMMAND ln -sf shell.c ${ZBLUE_DIR}port/subsys/bluetooth/shell/iso.c)
  add_dependencies(zblue zblue_prebuild)

endif()
