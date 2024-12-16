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

if(CONFIG_BT AND CONFIG_ZEPHYR_WORK_QUEUE)

  set(ZBLUE_DIR ${CMAKE_CURRENT_LIST_DIR}/zblue/)
  set(SUBDIR subsys/bluetooth)
  set(ZBLUE_SUBDIR ${ZBLUE_DIR}/${SUBDIR})

  set(ZBLUE_FLAGS)
  set(ZBLUE_INCDIR)
  set(ZBLUE_CSRCS)

  nuttx_add_library(zblue)

  list(
    APPEND
    ZBLUE_INCDIR
    ${ZBLUE_DIR}port/include
    ${ZBLUE_DIR}port/include/kernel/include
    ${ZBLUE_DIR}include/zephyr
    ${ZBLUE_DIR}subsys/bluetooth
    ${ZBLUE_DIR}subsys/bluetooth/host
    ${ZBLUE_DIR}subsys/bluetooth/services
    ${ZBLUE_DIR}subsys/bluetooth/mesh
    ${ZBLUE_DIR}subsys/bluetooth/common
    ${NUTTX_APPS_DIR}/external/tinycrypt/lib/include)

  if(CONFIG_BT_SAMPLE)
    set(STACKSIZE ${CONFIG_BT_SAMPLE_STACKSIZE})
    set(MODULE ${CONFIG_BT_SAMPLE})
  else()
    set(STACKSIZE ${CONFIG_DEFAULT_TASK_STACKSIZE})
    set(MODULE n)
  endif()

  macro(zblue_app PROGNAME MAINSRCS)
    nuttx_add_application(
      NAME
      ${PROGNAME}
      SRCS
      ${MAINSRCS}
      STACKSIZE
      ${STACKSIZE}
      MODULE
      ${MODULE}
      DEPENDS
      zblue)
  endmacro()

  list(
    APPEND
    ZBLUE_CSRCS
    ${ZBLUE_DIR}lib/os/crc8_sw.c
    ${ZBLUE_DIR}lib/os/crc16_sw.c
    ${ZBLUE_DIR}lib/os/crc32_sw.c
    ${ZBLUE_DIR}subsys/net/buf.c
    ${ZBLUE_DIR}port/common/defines.c
    ${ZBLUE_DIR}port/kernel/mempool.c)

  list(
    APPEND
    ZBLUE_FLAGS
    -Wno-implicit-function-declaration
    -Wno-unused-but-set-variable
    -Wno-unused-function
    -Wno-unused-variable
    -Wno-implicit-int
    -Wno-shadow
    -Wno-stringop-overread)

  list(
    APPEND
    ZBLUE_INCDIR
    ${ZBLUE_DIR}port/include
    # ${ZBLUE_DIR}include
    ${ZBLUE_DIR}subsys/bluetooth
    ${ZBLUE_DIR}subsys/bluetooth/host
    ${ZBLUE_DIR}subsys/bluetooth/services
    ${ZBLUE_DIR}subsys/bluetooth/mesh
    ${ZBLUE_DIR}subsys/bluetooth/common
    ${ZBLUE_DIR}subsys/testsuite/ztest/include
    ${NUTTX_APPS_DIR}/crypto/tinycrypt/tinycrypt/lib/include)

  if(CONFIG_BT_HCI)

    if(CONFIG_BT_HCI_RAW)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/hci_raw.c
           ${ZBLUE_SUBDIR}/host/hci_common.c)
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
      list(
        APPEND
        ZBLUE_CSRCS
        ${ZBLUE_SUBDIR}/host/br.c
        ${ZBLUE_SUBDIR}/host/keys_br.c
        ${ZBLUE_SUBDIR}/host/l2cap_br.c
        ${ZBLUE_SUBDIR}/host/sdp.c
        ${ZBLUE_SUBDIR}/host/ssp.c)
    endif()

    if(CONFIG_BT_HFP_HF)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/hfp_hf.c
           ${ZBLUE_SUBDIR}/host/at.c)
    endif()

    if(CONFIG_BT_HCI_HOST)
      list(
        APPEND
        ZBLUE_CSRCS
        ${ZBLUE_SUBDIR}/host/uuid.c
        ${ZBLUE_SUBDIR}/host/addr.c
        ${ZBLUE_SUBDIR}/host/buf.c
        ${ZBLUE_SUBDIR}/host/hci_core.c
        ${ZBLUE_SUBDIR}/host/hci_common.c
        ${ZBLUE_SUBDIR}/host/id.c)

      if(CONFIG_BT_BROADCASTER)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/adv.c)
      endif()

      if(CONFIG_BT_OBSERVER)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/scan.c)
      endif()

      if(CONFIG_BT_HOST_CRYPTO)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/crypto.c)
      else()
        list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/subsys/bluetooth/crypto.c)
      endif()

      if(CONFIG_BT_ECC)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/ecc.c)
      endif()

      if(CONFIG_BT_CONN)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/conn.c
             ${ZBLUE_SUBDIR}/host/l2cap.c ${ZBLUE_SUBDIR}/host/att.c
             ${ZBLUE_SUBDIR}/host/gatt.c)
        if(CONFIG_BT_SMP)
          list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/smp.c
               ${ZBLUE_SUBDIR}/host/keys.c)
        else()
          list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/smp_null.c)
        endif()
      endif()
    endif()

    if(CONFIG_BT_ISO)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/iso.c
           ${ZBLUE_SUBDIR}/host/conn.c)
    endif()

    if(CONFIG_BT_DF)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/host/direction.c)
    endif()
  endif()

  if(CONFIG_BT_AUDIO)

    if(CONFIG_BT_VOCS AND CONFIG_BT_VOCS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/vocs.c)
    endif()

    if(CONFIG_BT_VOCS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/vocs_client.c)
    endif()

    if(CONFIG_BT_AICS AND CONFIG_BT_AICS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/aics.c)
    endif()

    if(CONFIG_BT_AICS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/aics_client.c)
    endif()

    if(CONFIG_BT_VCS AND CONFIG_BT_VCS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/vcs.c)
    endif()

    if(CONFIG_BT_VCS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/vcs_client.c)
    endif()

    if(CONFIG_BT_MICS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/mics.c)
    endif()

    if(CONFIG_BT_MICS AND CONFIG_BT_MICS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/mics_client.c)
    endif()

    if(CONFIG_BT_CCID)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/ccid.c)
    endif()

    if(CONFIG_BT_CSIS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/csis.c)
    endif()

    if(CONFIG_BT_CSIS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/csis_client.c)
    endif()

    if(CONFIG_BT_CSIS AND CONFIG_BT_CSIS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/csis_crypto.c)
    endif()

    if(CONFIG_BT_TBS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/tbs.c)
    endif()

    if(CONFIG_BT_TBS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/tbs_client.c)
    endif()

    if(CONFIG_BT_MCC)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/mcc.c)
    endif()

    if(CONFIG_BT_MCS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/mcs.c)
    endif()

    if(CONFIG_BT_MPL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/mpl.c)
    endif()

    if(CONFIG_MCTL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/media_proxy.c)
    endif()

    if(CONFIG_BT_ASCS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/ascs.c)
    endif()

    if(CONFIG_BT_PACS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/pacs.c)
    endif()

    if(CONFIG_BT_AUDIO_STREAM)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/stream.c
           ${ZBLUE_SUBDIR}/audio/codec.c)
    endif()

    if(CONFIG_BT_AUDIO_UNICAST_SERVER)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/unicast_server.c)
    endif()

    if(CONFIG_BT_AUDIO_CAPABILITIES)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/capabilities.c)
    endif()

    if(CONFIG_BT_AUDIO_UNICAST_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/unicast_client.c)
    endif()

    if(CONFIG_BT_AUDIO_BROADCAST_SOURCE)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/broadcast_source.c)
    endif()

    if(CONFIG_BT_AUDIO_BROADCAST_SINK)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/broadcast_sink.c)
    endif()

    if(CONFIG_BT_BASS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/bass.c)
    endif()

    if(CONFIG_BT_BASS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/bass_client.c)
    endif()

    if(CONFIG_BT_HAS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/has.c)
    endif()

    if(CONFIG_BT_HAS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/audio/has_client.c)
    endif()
  endif()

  if(CONFIG_BT_CONN)

    if(CONFIG_BT_DIS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/dis.c)
    endif()

    if(CONFIG_BT_BAS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/bas.c)
    endif()

    if(CONFIG_BT_HRS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/hrs.c)
    endif()

    if(CONFIG_BT_TPS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/tps.c)
    endif()

    if(CONFIG_BT_IAS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/ias.c)
    endif()

    if(CONFIG_BT_OTS)
      list(
        APPEND
        ZBLUE_CSRCS
        ${ZBLUE_SUBDIR}/services/ots/ots.c
        ${ZBLUE_SUBDIR}/services/ots/ots_l2cap.c
        ${ZBLUE_SUBDIR}/services/ots/ots_obj_manager.c
        ${ZBLUE_SUBDIR}/services/ots/ots_oacp.c
        ${ZBLUE_SUBDIR}/services/ots/ots_olcp.c)

      if(CONFIG_BT_OTS_DIR_LIST_OBJ)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/ots/ots_dir_list.c)
      endif()

      if(CONFIG_BT_OTS_CLIENT)
        list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/services/ots/ots_client.c
             ${ZBLUE_SUBDIR}/services/ots/ots_l2cap.c)
      endif()
    endif()
  endif()

  if(CONFIG_BT_MESH)

    list(
      APPEND
      ZBLUE_CSRCS
      ${ZBLUE_SUBDIR}/mesh/main.c
      ${ZBLUE_SUBDIR}/mesh/cfg.c
      ${ZBLUE_SUBDIR}/mesh/adv.c
      ${ZBLUE_SUBDIR}/mesh/beacon.c
      ${ZBLUE_SUBDIR}/mesh/net.c
      ${ZBLUE_SUBDIR}/mesh/subnet.c
      ${ZBLUE_SUBDIR}/mesh/app_keys.c
      ${ZBLUE_SUBDIR}/mesh/transport.c
      ${ZBLUE_SUBDIR}/mesh/rpl.c
      ${ZBLUE_SUBDIR}/mesh/heartbeat.c
      ${ZBLUE_SUBDIR}/mesh/crypto.c
      ${ZBLUE_SUBDIR}/mesh/access.c
      ${ZBLUE_SUBDIR}/mesh/msg.c
      ${ZBLUE_SUBDIR}/mesh/cfg_srv.c
      ${ZBLUE_SUBDIR}/mesh/health_srv.c)

    if(CONFIG_BT_MESH_ADV_LEGACY)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/adv_legacy.c)
    endif()

    if(CONFIG_BT_MESH_ADV_EXT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/adv_ext.c)
    endif()

    if(CONFIG_BT_SETTINGS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/settings.c)
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

    if(CONFIG_BT_MESH_PROV_DEVICE)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/prov_device.c)
    endif()

    if(CONFIG_BT_MESH_PROVISIONER)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/provisioner.c)
    endif()

    if(CONFIG_BT_MESH_PB_ADV)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/pb_adv.c)
    endif()

    if(CONFIG_BT_MESH_PB_GATT_COMMON)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/pb_gatt.c)
    endif()

    if(CONFIG_BT_MESH_PB_GATT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/pb_gatt_srv.c)
    endif()

    if(CONFIG_BT_MESH_PB_GATT_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/pb_gatt_cli.c)
    endif()

    if(CONFIG_BT_MESH_GATT_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/gatt_cli.c)
    endif()

    if(CONFIG_BT_MESH_PROXY_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/proxy_cli.c)
    endif()

    if(CONFIG_BT_MESH_GATT_PROXY)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/proxy_srv.c)
    endif()

    if(CONFIG_BT_MESH_GATT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/proxy_msg.c)
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
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/common/log.c)

  if(CONFIG_BT_RPA)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/common/rpa.c)
  endif()

  if(CONFIG_SETTINGS)
    list(
      APPEND
      ZBLUE_CSRCS
      ${ZBLUE_DIR}/subsys/settings/src/settings.c
      ${ZBLUE_DIR}/subsys/settings/src/settings_store.c
      ${ZBLUE_DIR}/subsys/settings/src/settings_init.c
      ${ZBLUE_DIR}/subsys/settings/src/settings_line.c)

    if(CONFIG_SETTINGS_FS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/subsys/settings/src/settings_file.c)
    endif()
    if(CONFIG_SETTINGS_NVS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/subsys/flash/flash.c
           ${ZBLUE_DIR}/subsys/fs/nvs/nvs.c
           ${ZBLUE_DIR}/subsys/settings/src/settings_nvs.c)
    endif()
    list(APPEND ZBLUE_INCDIR ${ZBLUE_DIR}/subsys/settings/include)
  endif()

  if(CONFIG_FILE_SYSTEM)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/subsys/fs/fs.c)
  endif()

  # im in CONFIG_BT_SHELL
  if(CONFIG_BT_SHELL)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/bt.c
         ${ZBLUE_SUBDIR}/shell/hci.c ${ZBLUE_DIR}/subsys/shell/shell_utils.c)

    if(CONFIG_BT_MIBLE_TEST)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/mible_test.c)
    endif()

    if(CONFIG_BT_CONN)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/gatt.c)
    endif()

    if(CONFIG_BT_BREDR)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/bredr.c)
    endif()

    if(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/l2cap.c)
    endif()

    if(CONFIG_BT_RFCOMM)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/rfcomm.c)
    endif()

    if(CONFIG_BT_ISO)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/iso.c)
    endif()

    if(CONFIG_BT_VCS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/vcs.c)
    endif()

    if(CONFIG_BT_VCS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/vcs_client.c)
    endif()

    if(CONFIG_BT_MICS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/mics.c)
    endif()

    if(CONFIG_BT_MICS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/mics_client.c)
    endif()

    if(CONFIG_BT_CSIS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/csis.c)
    endif()

    if(CONFIG_BT_CSIS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/csis_client.c)
    endif()

    if(CONFIG_BT_MCS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/mpl.c)
    endif()

    if(CONFIG_BT_MCC)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/mcc.c)
    endif()

    if(CONFIG_BT_MCS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/media_controller.c)
    endif()

    if(CONFIG_BT_AUDIO_STREAM)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/audio.c)
    endif()

    if(CONFIG_BT_BASS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/bass.c)
    endif()

    if(CONFIG_BT_BASS_CLIENT)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/shell/bass_client.c)
    endif()

    if(CONFIG_BT_MESH_SHELL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_SUBDIR}/mesh/shell.c)
      zblue_app(mesh ${ZBLUE_DIR}/tests/bluetooth/mesh_shell/src/main.c)
    endif()

    if(CONFIG_SETTINGS_FS)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/subsys/fs/shell.c)
    endif()

    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/subsys/shell/shell.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/subsys/power/reboot.c)

  if(CONFIG_BT_TESTER)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/tests/bluetooth/tester/src/bttester.c)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/tests/bluetooth/tester/src/gap.c)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/tests/bluetooth/tester/src/gatt.c)

    if(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/tests/bluetooth/tester/src/l2cap.c)
    endif()

    if(CONFIG_BT_MESH)
      list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/tests/bluetooth/tester/src/mesh.c)
    endif()
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/drivers/console/uart_pipe.c)
    list(APPEND ZBLUE_CSRCS
         ${ZBLUE_DIR}/port/tests/bluetooth/tester/src/system.c)
    zblue_app(bttester ${ZBLUE_DIR}/tests/bluetooth/tester/src/main.c)
    list(APPEND ZBLUE_INCDIR ${ZBLUE_DIR}/tests/bluetooth/tester/src)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/sched.c)

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/timeout.c)

  if(CONFIG_ZTEST_TIMEOUT)
    zblue_app(test_timeout ${ZBLUE_DIR}/port/tests/kernel/test_timeout.c)
  endif()

  if(CONFIG_ZEPHYR_WORK_QUEUE)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/kernel/work.c)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/kernel/system_work_q.c)
  else()
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/work_q.c)
  endif()

  if(CONFIG_ZTEST_WORK_Q)
    zblue_app(test_workq ${ZBLUE_DIR}/port/tests/kernel/test_workq.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/poll.c)

  if(CONFIG_ZTEST_POLL)
    zblue_app(test_poll ${ZBLUE_DIR}/port/tests/kernel/test_poll.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/mem_slab.c)

  if(CONFIG_ZTEST_MEMSLAB)
    zblue_app(test_memslab ${ZBLUE_DIR}/port/tests/kernel/test_mem_slab.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/sem.c)
  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/mutex.c)
  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/queue.c)

  if(CONFIG_ZTEST_QUEUE)
    zblue_app(test_queue ${ZBLUE_DIR}/port/tests/kernel/test_queue.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/kernel/thread.c)

  if(CONFIG_ZTEST_THREAD)
    zblue_app(test_thread ${ZBLUE_DIR}/port/tests/kernel/test_thread.c)
  endif()

  if(CONFIG_ZTEST_NVM)
    zblue_app(test_nvm ${ZBLUE_DIR}/port/tests/fs/test_nvm.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/lib/os/dec.c ${ZBLUE_DIR}/lib/os/hex.c)

  if(CONFIG_ARCH_CHIP_R328)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/chip/xr829/xr829.c)
    list(APPEND ZBLUE_INCDIR ${NUTTX_DIR}/arch/arm/src/r328/include/drivers)
    list(APPEND ZBLUE_INCDIR ${NUTTX_DIR}/arch/arm/src/r328/include)
  endif()

  if(CONFIG_BT_LIBUSB)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/drivers/bluetooth/hci/libusb.c)
  endif()

  if(CONFIG_BT_H4)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/drivers/bluetooth/hci/h4.c)
  endif()

  if(CONFIG_BT_USERCHAN)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/drivers/bluetooth/hci/userchan.c)
  endif()

  if(CONFIG_BT_NATIVE)
    list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/drivers/bluetooth/hci/native.c)
  endif()

  list(
    APPEND
    ZBLUE_FLAGS
    -Wno-format-zero-length
    -Wno-implicit-function-declaration
    -Wno-unused-but-set-variable
    -Wno-unused-function
    -Wno-unused-variable
    -Wno-format
    -Wno-pointer-sign
    -Wno-strict-prototypes
    -Wno-implicit-int
    -Wno-shadow
    -Wno-int-to-pointer-cast
    -Wno-pointer-to-int-cast
    -Wno-undef)

  if(CONFIG_BT_SAMPLE)
    if(CONFIG_BT_SAMPLE_BROADCASTER)
      zblue_app(broadcaster
                ${ZBLUE_DIR}/samples/bluetooth/broadcaster/src/main.c)
      list(APPEND ZBLUE_INCDIR ${ZBLUE_DIR}/samples/bluetooth/broadcaster/src)
    endif()

    if(CONFIG_BT_SAMPLE_OBSERVER)
      zblue_app(observer ${ZBLUE_DIR}/samples/bluetooth/observer/src/main.c)
      list(APPEND ZBLUE_INCDIR ${ZBLUE_DIR}/samples/bluetooth/observer/src)
    endif()

    if(CONFIG_BT_SAMPLE_PERIPHERAL)
      zblue_app(peripheral ${ZBLUE_DIR}/samples/bluetooth/peripheral/src/main.c)
      list(APPEND ZBLUE_INCDIR ${ZBLUE_DIR}/samples/bluetooth/peripheral/src)
      list(APPEND ZBLUE_CSRCS
           ${ZBLUE_DIR}/samples/bluetooth/peripheral/src/cts.c)
    endif()

    if(CONFIG_BT_SAMPLE_CENTRAL)
      zblue_app(central ${ZBLUE_DIR}/samples/bluetooth/central/src/main.c)
    endif()

    if(CONFIG_BT_SAMPLE_MESH)
      if(NOT CONFIG_BT_MESH_PROV)
        zblue_app(btmesh ${ZBLUE_DIR}/samples/bluetooth/mesh_demo/src/main.c)
      else()
        zblue_app(btmesh ${ZBLUE_DIR}/samples/bluetooth/mesh_test/src/main.c)
        list(APPEND ZBLUE_CSRCS
             ${ZBLUE_DIR}/samples/bluetooth/mesh_test/src/board.c)
      endif()
      if(CONFIG_BT_MESH_PROVISIONER)
        zblue_app(mesh_provisioner
                  ${ZBLUE_DIR}/samples/bluetooth/mesh_provisioner/src/main.c)
      endif()
    endif()
  endif()

  if(CONFIG_BT_H4_ENABLE)
    zblue_app(hci_uart ${ZBLUE_DIR}/port/drivers/bluetooth/hci/h4_uart.c)
  endif()

  list(APPEND ZBLUE_CSRCS ${ZBLUE_DIR}/port/drivers/init.c)

  target_sources(zblue PRIVATE ${ZBLUE_CSRCS})
  target_include_directories(zblue PUBLIC ${ZBLUE_INCDIR})
  target_compile_options(zblue PUBLIC ${ZBLUE_FLAGS})

  set(NSH_FILE "${NUTTX_APPS_DIR}/nshlib/nsh_command.c")
  set(NSH_CMD_END_MARK "  { NULL,       NULL,         1, 1, NULL }")
  set(NSH_ZBLUE_HEADER "#ifdef CONFIG_BT_SHELL\n")
  set(NSH_ZBLUE_CMD
      "  { \"zblue\",    cmd_zblue,    1, CONFIG_NSH_MAXARGUMENTS, \"zblue\" },\n"
  )
  set(NSH_ZBLUE_END "#endif")
  set(NSH_ZBLUE "\n${NSH_ZBLUE_HEADER}${NSH_ZBLUE_CMD}${NSH_ZBLUE_END}")
  set(NSH_CMD_END_MARK1 "  { NULL,       NULL,         0, 0, NULL }")
  set(NSH_EXTERN_ZBLUE
      "extern int cmd_zblue(FAR struct nsh_vtbl_s *vtbl, int argc, char *argv[]);\n"
  )
  set(NSH_ZBLUE_EXTERN "${NSH_ZBLUE_HEADER}${NSH_EXTERN_ZBLUE}${NSH_ZBLUE_END}")
  set(NSH_POS1 "static int cmd_unrecognized")
  set(NSH_POS "static int  cmd_unrecognized")

  if(CONFIG_BT_SHELL)
    file(READ ${NSH_FILE} NSH_FILE_CONTENTS)
    string(REPLACE "${NSH_POS}" "${NSH_ZBLUE_EXTERN}\n\n${NSH_POS1}"
                   NSH_FILE_CONTENTS "${NSH_FILE_CONTENTS}")
    string(REPLACE "${NSH_CMD_END_MARK}" "${NSH_ZBLUE}\n\n${NSH_CMD_END_MARK1}"
                   NSH_FILE_CONTENTS "${NSH_FILE_CONTENTS}")
    file(WRITE ${NSH_FILE} "${NSH_FILE_CONTENTS}")
  endif()
endif()
