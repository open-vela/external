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
  set(BTDIR ${ZBLUE_DIR}/subsys/bluetooth)
  set(HOSTDIR ${BTDIR}/host)
  set(CLASSICDIR ${HOSTDIR}/classic)

  set(CFLAGS)
  set(INCDIR)
  set(CSRCS)

  list(APPEND CFLAGS
    -Wno-implicit-function-declaration
    -Wno-unused-but-set-variable
    -Wno-unused-function
    -Wno-unused-variable
    -Wno-implicit-int
    -Wno-shadow
    -Wno-stringop-overread)

  list(APPEND INCDIR
    ${ZBLUE_DIR}port/include
    ${ZBLUE_DIR}port/include/zephyr
    ${ZBLUE_DIR}port/kernel/include
    ${ZBLUE_DIR}subsys/bluetooth
    ${ZBLUE_DIR}subsys/bluetooth/audio
    ${ZBLUE_DIR}subsys/bluetooth/host
    ${ZBLUE_DIR}subsys/bluetooth/mesh
    ${ZBLUE_DIR}subsys/bluetooth/services
    ${ZBLUE_DIR}subsys/testsuite/ztest/include
    ${NUTTX_APPS_DIR}/crypto/tinycrypt/tinycrypt/lib/include)

  set(CSRCS
    ${BTDIR}/common/addr.c
    ${BTDIR}/common/dummy.c
    ${BTDIR}/common/bt_str.c
  )

  if(CONFIG_BT_RPA)
    list(APPEND CSRCS ${BTDIR}/common/rpa.c)
  endif()

  if(CONFIG_BT_EAD)
    list(APPEND CSRCS ${BTDIR}/lib/ead.c)
  endif()

  if(CONFIG_BT_HCI)
    if(CONFIG_BT_HCI_RAW)
      list(APPEND CSRCS ${HOSTDIR}/hci_raw.c ${HOSTDIR}/hci_common.c)
    endif()
    if(CONFIG_BT_MONITOR)
      list(APPEND CSRCS ${HOSTDIR}/monitor.c)
    endif()
    if(CONFIG_BT_TINYCRYPT_ECC)
      list(APPEND CSRCS ${HOSTDIR}/hci_ecc.c)
    endif()
    if(CONFIG_BT_SETTINGS)
      list(APPEND CSRCS ${HOSTDIR}/settings.c)
    endif()
    if(CONFIG_BT_HOST_CCM)
      list(APPEND CSRCS ${HOSTDIR}/aes_ccm.c)
    endif()
    if(CONFIG_BT_LONG_WQ)
      list(APPEND CSRCS ${HOSTDIR}/long_wq.c)
    endif()

    if(CONFIG_BT_HCI_HOST)
      list(APPEND CSRCS
        ${HOSTDIR}/uuid.c ${HOSTDIR}/addr.c
        ${HOSTDIR}/buf.c ${HOSTDIR}/data.c
        ${HOSTDIR}/hci_core.c ${HOSTDIR}/hci_common.c
        ${HOSTDIR}/id.c
      )

      if(CONFIG_BT_BROADCASTER)
        list(APPEND CSRCS ${HOSTDIR}/adv.c)
      endif()
      if(CONFIG_BT_OBSERVER)
        list(APPEND CSRCS ${HOSTDIR}/scan.c)
      endif()

      if(CONFIG_BT_USE_PSA_API)
        if(CONFIG_BT_HOST_CRYPTO)
          list(APPEND CSRCS ${HOSTDIR}/crypto_psa.c)
        endif()
      else()
        if(CONFIG_BT_HOST_CRYPTO)
          list(APPEND CSRCS ${HOSTDIR}/crypto_tc.c)
        endif()
      endif()

      if(CONFIG_BT_ECC)
        list(APPEND CSRCS ${HOSTDIR}/ecc.c)
      endif()

      if(CONFIG_BT_CONN)
        list(APPEND CSRCS
          ${HOSTDIR}/conn.c ${HOSTDIR}/l2cap.c
          ${HOSTDIR}/att.c ${HOSTDIR}/gatt.c
        )

        if(CONFIG_BT_SMP)
          list(APPEND CSRCS ${HOSTDIR}/smp.c ${HOSTDIR}/keys.c)
        else()
          list(APPEND CSRCS ${HOSTDIR}/smp_null.c)
        endif()
      endif()

      if(CONFIG_BT_ISO)
        list(APPEND CSRCS ${HOSTDIR}/iso.c ${HOSTDIR}/conn.c)
      endif()
      if(CONFIG_BT_CHANNEL_SOUNDING)
        list(APPEND CSRCS ${HOSTDIR}/cs.c)
      endif()
      if(CONFIG_BT_DF)
        list(APPEND CSRCS ${HOSTDIR}/direction.c)
      endif()
    endif() # CONFIG_BT_HCI_HOST

    if(CONFIG_BT_CLASSIC)
      if(CONFIG_BT_A2DP)
        list(APPEND CSRCS ${CLASSICDIR}/a2dp.c ${CLASSICDIR}/a2dp_codec_sbc.c)
      endif()
      if(CONFIG_BT_AVDTP)
        list(APPEND CSRCS ${CLASSICDIR}/avdtp.c)
      endif()
      if(CONFIG_BT_AVRCP)
        list(APPEND CSRCS ${CLASSICDIR}/avrcp.c)
      endif()
      if(CONFIG_BT_AVCTP)
        list(APPEND CSRCS ${CLASSICDIR}/avctp.c)
      endif()
      if(CONFIG_BT_RFCOMM)
        list(APPEND CSRCS ${CLASSICDIR}/rfcomm.c)
      endif()

      list(APPEND CSRCS
        ${CLASSICDIR}/br.c
        ${CLASSICDIR}/keys_br.c
        ${CLASSICDIR}/l2cap_br.c
        ${CLASSICDIR}/sdp.c
        ${CLASSICDIR}/ssp.c
        ${CLASSICDIR}/sco.c
      )

      if(CONFIG_BT_HFP_HF)
        list(APPEND CSRCS ${CLASSICDIR}/hfp_hf.c ${CLASSICDIR}/at.c)
      endif()
      if(CONFIG_BT_HFP_AG)
        list(APPEND CSRCS ${CLASSICDIR}/hfp_ag.c)
      endif()

      if(CONFIG_BT_SHELL)
        list(APPEND CSRCS ${CLASSICDIR}/shell/bredr.c)

        if(CONFIG_BT_RFCOMM)
          list(APPEND CSRCS ${CLASSICDIR}/shell/rfcomm.c)
        endif()
        if(CONFIG_BT_A2DP)
          list(APPEND CSRCS ${CLASSICDIR}/shell/a2dp.c)
        endif()
        if(CONFIG_BT_AVRCP)
          list(APPEND CSRCS ${CLASSICDIR}/shell/avrcp.c)
        endif()
      endif() # CONFIG_BT_SHELL
    endif() # CONFIG_BT_CLASSIC

    if(CONFIG_BT_SHELL)
      list(APPEND CSRCS ${HOSTDIR}/shell/bt.c)

      if(CONFIG_BT_CONN)
        list(APPEND CSRCS ${HOSTDIR}/shell/gatt.c)
      endif()
      if(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
        list(APPEND CSRCS ${HOSTDIR}/shell/l2cap.c)
      endif()
      if(CONFIG_BT_ISO)
        list(APPEND CSRCS ${HOSTDIR}/shell/iso.c)
      endif()
      if(CONFIG_BT_CHANNEL_SOUNDING)
        list(APPEND CSRCS ${HOSTDIR}/shell/cs.c)
      endif()
    endif() # CONFIG_BT_SHELL
  endif() # CONFIG_BT_HCI

  set(SVRSDIR ${BTDIR}/services)

  if(CONFIG_BT_CONN)
    if(CONFIG_BT_DIS)
      list(APPEND CSRCS ${SVRSDIR}/dis.c)
    endif()
    if(CONFIG_BT_CTS)
      list(APPEND CSRCS ${SVRSDIR}/cts.c)
    endif()
    if(CONFIG_BT_HRS)
      list(APPEND CSRCS ${SVRSDIR}/hrs.c)
    endif()
    if(CONFIG_BT_TPS)
      list(APPEND CSRCS ${SVRSDIR}/tps.c)
    endif()

    if(CONFIG_BT_BAS)
      list(APPEND CSRCS ${SVRSDIR}/bas/bas.c)
      if(CONFIG_BT_BAS_BLS)
        list(APPEND CSRCS ${SVRSDIR}/bas/bas_bls.c)
      endif()
      if(CONFIG_BT_BAS_BCS)
        list(APPEND CSRCS ${SVRSDIR}/bas/bas_bcs.c)
      endif()
    endif()

    if(CONFIG_BT_OTS)
      list(APPEND CSRCS
        ${SVRSDIR}/ots/ots.c
        ${SVRSDIR}/ots/ots_l2cap.c
        ${SVRSDIR}/ots/ots_obj_manager.c
        ${SVRSDIR}/ots/ots_oacp.c
        ${SVRSDIR}/ots/ots_olcp.c
      )
    endif()

    if(CONFIG_BT_OTS_DIR_LIST_OBJ)
      list(APPEND CSRCS ${SVRSDIR}/ots/ots_dir_list.c)
    endif()
    if(CONFIG_BT_OTS_CLIENT)
      list(APPEND CSRCS
        ${SVRSDIR}/ots/ots_client.c
        ${SVRSDIR}/ots/ots_l2cap.c
      )
    endif()

    if(CONFIG_BT_IAS)
      list(APPEND CSRCS ${SVRSDIR}/ias/ias.c)
      if(CONFIG_BT_SHELL)
        list(APPEND CSRCS ${SVRSDIR}/ias/shell/ias.c)
      endif()
    endif()

    if(CONFIG_BT_IAS_CLIENT)
      list(APPEND CSRCS ${SVRSDIR}/ias/ias_client.c)
      if(CONFIG_BT_SHELL)
        list(APPEND CSRCS ${SVRSDIR}/ias/shell/ias_client.c)
      endif()
    endif()

    if(CONFIG_BT_ZEPHYR_NUS)
      list(APPEND CSRCS
        ${SVRSDIR}/nus/nus.c
        ${SVRSDIR}/nus/nus_inst.c
      )
      if(CONFIG_BT_ZEPHYR_NUS_AUTO_START_BLUETOOTH)
        list(APPEND CSRCS ${SVRSDIR}/nus/bt_nus_auto_start_bt.c)
      endif()
    endif()
  endif()

  set(MESHDIR ${BTDIR}/mesh)

  if(CONFIG_BT_MESH)
    list(APPEND CSRCS
      ${MESHDIR}/main.c
      ${MESHDIR}/cfg.c
      ${MESHDIR}/adv.c
      ${MESHDIR}/beacon.c
      ${MESHDIR}/net.c
      ${MESHDIR}/subnet.c
      ${MESHDIR}/app_keys.c
      ${MESHDIR}/heartbeat.c
      ${MESHDIR}/crypto.c
      ${MESHDIR}/access.c
      ${MESHDIR}/msg.c
      ${MESHDIR}/cfg_srv.c
      ${MESHDIR}/health_srv.c
      ${MESHDIR}/va.c
      ${MESHDIR}/transport.c
    )

    if(CONFIG_BT_MESH_ADV_LEGACY)
      list(APPEND CSRCS ${MESHDIR}/adv_legacy.c)
    endif()
    if(CONFIG_BT_MESH_ADV_EXT)
      list(APPEND CSRCS ${MESHDIR}/adv_ext.c)
    endif()
    if(CONFIG_BT_SETTINGS)
      list(APPEND CSRCS ${MESHDIR}/settings.c)
    endif()
    if(CONFIG_BT_MESH_RPL_STORAGE_MODE_SETTINGS)
      list(APPEND CSRCS ${MESHDIR}/rpl.c)
    endif()
    if(CONFIG_BT_MESH_LOW_POWER)
      list(APPEND CSRCS ${MESHDIR}/lpn.c)
    endif()
    if(CONFIG_BT_MESH_FRIEND)
      list(APPEND CSRCS ${MESHDIR}/friend.c)
    endif()
    if(CONFIG_BT_MESH_PROV)
      list(APPEND CSRCS ${MESHDIR}/prov.c)
    endif()
    if(CONFIG_BT_MESH_PROVISIONEE)
      list(APPEND CSRCS ${MESHDIR}/provisionee.c)
    endif()
    if(CONFIG_BT_MESH_PROVISIONER)
      list(APPEND CSRCS ${MESHDIR}/provisioner.c)
    endif()
    if(CONFIG_BT_MESH_PB_ADV)
      list(APPEND CSRCS ${MESHDIR}/pb_adv.c)
    endif()
    if(CONFIG_BT_MESH_PB_GATT_COMMON)
      list(APPEND CSRCS ${MESHDIR}/pb_gatt.c)
    endif()
    if(CONFIG_BT_MESH_PB_GATT)
      list(APPEND CSRCS ${MESHDIR}/pb_gatt_srv.c)
    endif()
    if(CONFIG_BT_MESH_PB_GATT_CLIENT)
      list(APPEND CSRCS ${MESHDIR}/pb_gatt_cli.c)
    endif()
    if(CONFIG_BT_MESH_GATT_CLIENT)
      list(APPEND CSRCS ${MESHDIR}/gatt_cli.c)
    endif()
    if(CONFIG_BT_MESH_PROXY_CLIENT)
      list(APPEND CSRCS ${MESHDIR}/proxy_cli.c)
    endif()
    if(CONFIG_BT_MESH_GATT_PROXY)
      list(APPEND CSRCS ${MESHDIR}/proxy_srv.c)
    endif()
    if(CONFIG_BT_MESH_GATT)
      list(APPEND CSRCS ${MESHDIR}/proxy_msg.c)
    endif()
    if(CONFIG_BT_MESH_CFG_CLI)
      list(APPEND CSRCS ${MESHDIR}/cfg_cli.c)
    endif()
    if(CONFIG_BT_MESH_HEALTH_CLI)
      list(APPEND CSRCS ${MESHDIR}/health_cli.c)
    endif()
    if(CONFIG_BT_MESH_SAR_CFG_CLI)
      list(APPEND CSRCS ${MESHDIR}/sar_cfg_cli.c)
    endif()
    if(CONFIG_BT_MESH_SAR_CFG_SRV)
      list(APPEND CSRCS ${MESHDIR}/sar_cfg_srv.c)
    endif()
    if(CONFIG_BT_MESH_SAR_CFG)
      list(APPEND CSRCS ${MESHDIR}/sar_cfg.c)
    endif()
    if(CONFIG_BT_MESH_OP_AGG_SRV)
      list(APPEND CSRCS ${MESHDIR}/op_agg_srv.c)
    endif()
    if(CONFIG_BT_MESH_OP_AGG_CLI)
      list(APPEND CSRCS ${MESHDIR}/op_agg_cli.c)
    endif()
    if(CONFIG_BT_MESH_OP_AGG)
      list(APPEND CSRCS ${MESHDIR}/op_agg.c)
    endif()
    if(CONFIG_BT_MESH_LARGE_COMP_DATA_SRV)
      list(APPEND CSRCS ${MESHDIR}/large_comp_data_srv.c)
    endif()
    if(CONFIG_BT_MESH_LARGE_COMP_DATA_CLI)
      list(APPEND CSRCS ${MESHDIR}/large_comp_data_cli.c)
    endif()
    if(CONFIG_BT_MESH_PRIV_BEACON_SRV)
      list(APPEND CSRCS ${MESHDIR}/priv_beacon_srv.c)
    endif()
    if(CONFIG_BT_MESH_PRIV_BEACON_CLI)
      list(APPEND CSRCS ${MESHDIR}/priv_beacon_cli.c)
    endif()
    if(CONFIG_BT_MESH_SELF_TEST)
      list(APPEND CSRCS ${MESHDIR}/test.c)
    endif()
    if(CONFIG_BT_MESH_CDB)
      list(APPEND CSRCS ${MESHDIR}/cdb.c)
    endif()
    if(CONFIG_BT_MESH_BLOB_SRV)
      list(APPEND CSRCS ${MESHDIR}/blob_srv.c)
    endif()
    if(CONFIG_BT_MESH_BLOB_CLI)
      list(APPEND CSRCS ${MESHDIR}/blob_cli.c)
    endif()
    if(CONFIG_BT_MESH_BLOB_IO_FLASH)
      list(APPEND CSRCS ${MESHDIR}/blob_io_flash.c)
    endif()
    if(CONFIG_BT_MESH_DFU_CLI)
      list(APPEND CSRCS ${MESHDIR}/dfu_cli.c)
    endif()
    if(CONFIG_BT_MESH_DFU_SRV)
      list(APPEND CSRCS ${MESHDIR}/dfu_srv.c)
    endif()
    if(CONFIG_BT_MESH_DFD_SRV)
      list(APPEND CSRCS ${MESHDIR}/dfd_srv.c)
    endif()
    if(CONFIG_BT_MESH_DFU_SLOTS)
      list(APPEND CSRCS ${MESHDIR}/dfu_slot.c)
    endif()
    if(CONFIG_BT_MESH_DFU_METADATA)
      list(APPEND CSRCS ${MESHDIR}/dfu_metadata.c)
    endif()
    if(CONFIG_BT_MESH_RPR_CLI)
      list(APPEND CSRCS ${MESHDIR}/rpr_cli.c)
    endif()
    if(CONFIG_BT_MESH_RPR_SRV)
      list(APPEND CSRCS ${MESHDIR}/rpr_srv.c)
    endif()
    if(CONFIG_BT_MESH_OD_PRIV_PROXY_CLI)
      list(APPEND CSRCS ${MESHDIR}/od_priv_proxy_cli.c)
    endif()
    if(CONFIG_BT_MESH_OD_PRIV_PROXY_SRV)
      list(APPEND CSRCS ${MESHDIR}/od_priv_proxy_srv.c)
    endif()
    if(CONFIG_BT_MESH_SOL_PDU_RPL_CLI)
      list(APPEND CSRCS ${MESHDIR}/sol_pdu_rpl_cli.c)
    endif()
    if(CONFIG_BT_MESH_SOL_PDU_RPL_SRV)
      list(APPEND CSRCS ${MESHDIR}/sol_pdu_rpl_srv.c)
    endif()
    if(CONFIG_BT_MESH_BRG_CFG_CLI)
      list(APPEND CSRCS ${MESHDIR}/brg_cfg_cli.c)
    endif()
    if(CONFIG_BT_MESH_BRG_CFG_SRV)
      list(APPEND CSRCS ${MESHDIR}/brg_cfg_srv.c ${MESHDIR}/brg_cfg.c)
    endif()
    if(CONFIG_BT_MESH_SOLICITATION)
      list(APPEND CSRCS ${MESHDIR}/solicitation.c)
    endif()
    if(CONFIG_BT_MESH_STATISTIC)
      list(APPEND CSRCS ${MESHDIR}/statistic.c)
    endif()
    if(CONFIG_BT_MESH_ACCESS_DELAYABLE_MSG)
      list(APPEND CSRCS ${MESHDIR}/delayable_msg.c)
    endif()
    if(CONFIG_BT_MESH_USES_TINYCRYPT)
      list(APPEND CSRCS ${MESHDIR}/crypto_tc.c)
    else()
      list(APPEND CSRCS ${MESHDIR}/crypto_psa.c)
    endif()
    if(CONFIG_BT_TESTING)
      list(APPEND CSRCS ${MESHDIR}/testing.c)
    endif()

    if(CONFIG_BT_MESH_SHELL)
      list(APPEND CSRCS
        ${MESHDIR}/shell/shell.c
        ${MESHDIR}/shell/utils.c
      )

      if(CONFIG_BT_MESH_SHELL_HEALTH_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/health.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_CFG_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/cfg.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_LARGE_COMP_DATA_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/large_comp_data.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_OP_AGG_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/op_agg.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_PRIV_BEACON_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/priv_beacon.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_RPR_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/rpr.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_SAR_CFG_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/sar.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_BLOB_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/blob.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_BLOB_SRV)
        list(APPEND CSRCS ${MESHDIR}/shell/blob.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_BLOB_IO_FLASH)
        list(APPEND CSRCS ${MESHDIR}/shell/blob.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_DFU_SLOT)
        list(APPEND CSRCS ${MESHDIR}/shell/dfu.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_DFU_METADATA)
        list(APPEND CSRCS ${MESHDIR}/shell/dfu.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_DFU_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/dfu.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_DFU_SRV)
        list(APPEND CSRCS ${MESHDIR}/shell/dfu.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_DFD_SRV)
        list(APPEND CSRCS ${MESHDIR}/shell/dfd.c)
      endif()
      if(CONFIG_BT_MESH_OD_PRIV_PROXY_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/od_priv_proxy.c)
      endif()
      if(CONFIG_BT_MESH_SOL_PDU_RPL_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/sol_pdu_rpl.c)
      endif()
      if(CONFIG_BT_MESH_SHELL_BRG_CFG_CLI)
        list(APPEND CSRCS ${MESHDIR}/shell/brg_cfg.c)
      endif()
      if(CONFIG_BT_HCI_MESH_EXT)
        list(APPEND CSRCS ${MESHDIR}/shell/hci.c)
      endif()
    endif() # CONFIG_BT_MESH_SHELL
  endif() # CONFIG_BT_MESH

  set(AUDIODIR ${BTDIR}/audio)

  if(CONFIG_BT_AUDIO)
    list(APPEND CSRCS ${AUDIODIR}/audio.c)

    if(CONFIG_BT_VOCS)
      list(APPEND CSRCS ${AUDIODIR}/vocs.c)
    endif()
    if(CONFIG_BT_VOCS_CLIENT)
      list(APPEND CSRCS ${AUDIODIR}/vocs_client.c)
    endif()
    if(CONFIG_BT_AICS)
      list(APPEND CSRCS ${AUDIODIR}/aics.c)
    endif()
    if(CONFIG_BT_AICS_CLIENT)
      list(APPEND CSRCS ${AUDIODIR}/aics_client.c)
    endif()
    if(CONFIG_BT_VCP_VOL_REND)
      list(APPEND CSRCS ${AUDIODIR}/vcp_vol_rend.c)
    endif()
    if(CONFIG_BT_VCP_VOL_CTLR)
      list(APPEND CSRCS ${AUDIODIR}/vcp_vol_ctlr.c)
    endif()
    if(CONFIG_BT_MICP_MIC_DEV)
      list(APPEND CSRCS ${AUDIODIR}/micp_mic_dev.c)
    endif()
    if(CONFIG_BT_MICP_MIC_CTLR)
      list(APPEND CSRCS ${AUDIODIR}/micp_mic_ctlr.c)
    endif()
    if(CONFIG_BT_CONN)
      list(APPEND CSRCS ${AUDIODIR}/ccid.c)
    endif()
    if(CONFIG_BT_CSIP_SET_MEMBER)
      list(APPEND CSRCS ${AUDIODIR}/csip_set_member.c)
    endif()
    if(CONFIG_BT_CSIP_SET_COORDINATOR)
      list(APPEND CSRCS ${AUDIODIR}/csip_set_coordinator.c)
    endif()
    if(CONFIG_BT_CSIP_SET_MEMBER AND CONFIG_BT_CSIP_SET_COORDINATOR)
      list(APPEND CSRCS ${AUDIODIR}/csip_crypto.c)
    endif()
    if(CONFIG_BT_TBS)
      list(APPEND CSRCS ${AUDIODIR}/tbs.c)
    endif()
    if(CONFIG_BT_TBS_CLIENT)
      list(APPEND CSRCS ${AUDIODIR}/tbs_client.c)
    endif()
    if(CONFIG_BT_MCC)
      list(APPEND CSRCS ${AUDIODIR}/mcc.c)
    endif()
    if(CONFIG_BT_MCS)
      list(APPEND CSRCS ${AUDIODIR}/mcs.c)
    endif()
    if(CONFIG_BT_MPL)
      list(APPEND CSRCS ${AUDIODIR}/mpl.c)
    endif()
    if(CONFIG_MCTL)
      list(APPEND CSRCS ${AUDIODIR}/media_proxy.c)
    endif()
    if(CONFIG_BT_ASCS)
      list(APPEND CSRCS ${AUDIODIR}/ascs.c)
    endif()
    if(CONFIG_BT_PACS)
      list(APPEND CSRCS ${AUDIODIR}/pacs.c)
    endif()
    if(CONFIG_BT_BAP_STREAM)
      list(APPEND CSRCS ${AUDIODIR}/bap_stream.c ${AUDIODIR}/codec.c ${AUDIODIR}/bap_iso.c)
    endif()
    if(CONFIG_BT_BAP_BASE)
      list(APPEND CSRCS ${AUDIODIR}/bap_base.c)
    endif()
    if(CONFIG_BT_BAP_UNICAST_SERVER)
      list(APPEND CSRCS ${AUDIODIR}/bap_unicast_server.c)
    endif()
    if(CONFIG_BT_BAP_UNICAST_CLIENT)
      list(APPEND CSRCS ${AUDIODIR}/bap_unicast_client.c)
    endif()
    if(CONFIG_BT_BAP_BROADCAST_SOURCE)
      list(APPEND CSRCS ${AUDIODIR}/bap_broadcast_source.c)
    endif()
    if(CONFIG_BT_BAP_BROADCAST_SINK)
      list(APPEND CSRCS ${AUDIODIR}/bap_broadcast_sink.c)
    endif()
    if(CONFIG_BT_BAP_SCAN_DELEGATOR)
      list(APPEND CSRCS ${AUDIODIR}/bap_scan_delegator.c)
    endif()
    if(CONFIG_BT_BAP_BROADCAST_ASSISTANT)
      list(APPEND CSRCS ${AUDIODIR}/bap_broadcast_assistant.c)
    endif()
    if(CONFIG_BT_HAS)
      list(APPEND CSRCS ${AUDIODIR}/has.c)
    endif()
    if(CONFIG_BT_HAS_CLIENT)
      list(APPEND CSRCS ${AUDIODIR}/has_client.c)
    endif()
    if(CONFIG_BT_CAP)
      list(APPEND CSRCS ${AUDIODIR}/cap_stream.c)
    endif()
    if(CONFIG_BT_CAP_ACCEPTOR)
      list(APPEND CSRCS ${AUDIODIR}/cap_acceptor.c)
    endif()
    if(CONFIG_BT_CAP_INITIATOR)
      list(APPEND CSRCS ${AUDIODIR}/cap_initiator.c)
    endif()
    if(CONFIG_BT_CAP_COMMANDER)
      list(APPEND CSRCS ${AUDIODIR}/cap_commander.c)
    endif()
    if(CONFIG_BT_CAP_INITIATOR_UNICAST AND CONFIG_BT_CAP_COMMANDER)
      list(APPEND CSRCS ${AUDIODIR}/cap_common.c)
    endif()
    if(CONFIG_BT_TMAP)
      list(APPEND CSRCS ${AUDIODIR}/tmap.c)
    endif()
    if(CONFIG_BT_GMAP)
      list(APPEND CSRCS ${AUDIODIR}/gmap_client.c ${AUDIODIR}/gmap_server.c)
    endif()
    if(CONFIG_BT_PBP)
      list(APPEND CSRCS ${AUDIODIR}/pbp.c)
    endif()

    if(CONFIG_BT_SHELL)
      if(CONFIG_BT_VCP_VOL_REND)
        list(APPEND CSRCS ${AUDIODIR}/shell/vcp_vol_rend.c)
      endif()
      if(CONFIG_BT_VCP_VOL_CTLR)
        list(APPEND CSRCS ${AUDIODIR}/shell/vcp_vol_ctlr.c)
      endif()
      if(CONFIG_BT_MICP_MIC_DEV)
        list(APPEND CSRCS ${AUDIODIR}/shell/micp_mic_dev.c)
      endif()
      if(CONFIG_BT_MICP_MIC_CTLR)
        list(APPEND CSRCS ${AUDIODIR}/shell/micp_mic_ctlr.c)
      endif()
      if(CONFIG_BT_CSIP_SET_MEMBER)
        list(APPEND CSRCS ${AUDIODIR}/shell/csip_set_member.c)
      endif()
      if(CONFIG_BT_CSIP_SET_COORDINATOR)
        list(APPEND CSRCS ${AUDIODIR}/shell/csip_set_coordinator.c)
      endif()
      if(CONFIG_BT_TBS)
        list(APPEND CSRCS ${AUDIODIR}/shell/tbs.c)
      endif()
      if(CONFIG_BT_TBS_CLIENT)
        list(APPEND CSRCS ${AUDIODIR}/shell/tbs_client.c)
      endif()
      if(CONFIG_BT_MPL)
        list(APPEND CSRCS ${AUDIODIR}/shell/mpl.c)
      endif()
      if(CONFIG_BT_MCC)
        list(APPEND CSRCS ${AUDIODIR}/shell/mcc.c)
      endif()
      if(CONFIG_BT_MCS)
        list(APPEND CSRCS ${AUDIODIR}/shell/media_controller.c)
      endif()
      if(CONFIG_BT_HAS_PRESET_SUPPORT)
        list(APPEND CSRCS ${AUDIODIR}/shell/has.c)
      endif()
      if(CONFIG_BT_CAP_ACCEPTOR)
        list(APPEND CSRCS ${AUDIODIR}/shell/cap_acceptor.c)
      endif()
      if(CONFIG_BT_CAP_INITIATOR)
        list(APPEND CSRCS ${AUDIODIR}/shell/cap_initiator.c)
      endif()
      if(CONFIG_BT_CAP_COMMANDER)
        list(APPEND CSRCS ${AUDIODIR}/shell/cap_commander.c)
      endif()
      if(CONFIG_BT_HAS_CLIENT)
        list(APPEND CSRCS ${AUDIODIR}/shell/has_client.c)
      endif()
      if(CONFIG_BT_TMAP)
        list(APPEND CSRCS ${AUDIODIR}/shell/tmap.c)
      endif()
      if(CONFIG_BT_GMAP)
        list(APPEND CSRCS ${AUDIODIR}/shell/gmap.c)
      endif()
      if(CONFIG_BT_BAP_STREAM)
        list(APPEND CSRCS ${AUDIODIR}/shell/bap.c)
      endif()
      if(CONFIG_LIBLC3 AND CONFIG_USB_DEVICE_AUDIO)
        list(APPEND CSRCS ${AUDIODIR}/shell/bap_usb.c)
      endif()
      if(CONFIG_BT_BAP_SCAN_DELEGATOR)
        list(APPEND CSRCS ${AUDIODIR}/shell/bap_scan_delegator.c)
      endif()
      if(CONFIG_BT_BAP_BROADCAST_ASSISTANT)
        list(APPEND CSRCS ${AUDIODIR}/shell/bap_broadcast_assistant.c)
      endif()
      if(CONFIG_BT_PBP)
        list(APPEND CSRCS ${AUDIODIR}/shell/pbp.c)
      endif()
    endif() # CONFIG_BT_SHELL
  endif() # CONFIG_BT_AUDIO

  if(CONFIG_BT_CRYPTO)
    list(APPEND CSRCS ${BTDIR}/crypto/bt_crypto.c)

    if(CONFIG_BT_USE_PSA_API)
      list(APPEND CSRCS ${BTDIR}/crypto/bt_crypto_psa.c)
    else()
      list(APPEND CSRCS ${BTDIR}/crypto/bt_crypto_tc.c)
    endif()
  endif()

  if(CONFIG_SETTINGS)
    set(SETTINGS_DIR zblue/subsys/settings/src)

    list(APPEND CSRCS
      ${SETTINGS_DIR}/settings_store.c
      ${SETTINGS_DIR}/settings.c
      ${SETTINGS_DIR}/settings_init.c
      ${SETTINGS_DIR}/settings_line.c
    )

    if(CONFIG_SETTINGS_FILE)
      list(APPEND CSRCS ${SETTINGS_DIR}/settings_file.c)
    endif()
    if(CONFIG_SETTINGS_NVS)
      list(APPEND CSRCS ${SETTINGS_DIR}/settings_nvs.c)
    endif()
    if(CONFIG_SETTINGS_NONE)
      list(APPEND CSRCS ${SETTINGS_DIR}/settings_none.c)
    endif()
    if(CONFIG_SETTINGS_SHELL)
      list(APPEND CSRCS ${SETTINGS_DIR}/settings_shell.c)
    endif()
  endif()

  list(APPEND CSRCS
    zblue/kernel/system_work_q.c
    zblue/kernel/work.c
    zblue/lib/net_buf/buf_simple.c
    zblue/lib/utils/dec.c
    zblue/lib/utils/hex.c
    zblue/port/kernel/atomic_c.c
    zblue/port/kernel/device.c
    zblue/port/kernel/fatal.c
    zblue/port/kernel/init.c
    zblue/port/kernel/mem_slab.c
    zblue/port/kernel/mutex.c
    zblue/port/kernel/poll.c
    zblue/port/kernel/queue.c
    zblue/port/kernel/sched.c
    zblue/port/kernel/sem.c
    zblue/port/kernel/thread.c
    zblue/port/kernel/timeout.c
    zblue/port/lib/net_buf/buf.c
    zblue/port/lib/os/assert.c
    zblue/port/sections/defines.c
    zblue/port/subsys/fs/fs.c
  )

  if(CONFIG_BT_H4)
    list(APPEND CSRCS zblue/port/drivers/bluetooth/hci/h4.c)
  endif()

  if(CONFIG_BT_SAMPLE)
    set(ZBLUE_STACKSIZE ${CONFIG_BT_SAMPLE_STACKSIZE})
  else()
    set(ZBLUE_STACKSIZE ${CONFIG_DEFAULT_TASK_STACKSIZE})
  endif()

  if(CONFIG_BT_SHELL)
    nuttx_add_application(
      NAME zblue
      STACKSIZE ${ZBLUE_STACKSIZE}
      SRCS ${ZBLUE_DIR}port/subsys/shell/shell.c
      INCLUDE_DIRECTORIES ${INCDIR}
      COMPILE_FLAGS ${CFLAGS})
  endif()

  if(CONFIG_BT_SAMPLE)
    if(CONFIG_BT_SAMPLE_PERIPHERAL)
      nuttx_add_application(
        NAME peripheral
        STACKSIZE ${ZBLUE_STACKSIZE}
        SRCS ${ZBLUE_DIR}samples/bluetooth/peripheral/src/main.c
        INCLUDE_DIRECTORIES ${INCDIR}
        COMPILE_FLAGS ${CFLAGS})
    endif()

    if(CONFIG_BT_SAMPLE_CENTRAL)
      nuttx_add_application(
        NAME central
        STACKSIZE ${ZBLUE_STACKSIZE}
        SRCS ${ZBLUE_DIR}samples/bluetooth/central/src/main.c
        INCLUDE_DIRECTORIES ${INCDIR}
        COMPILE_FLAGS ${CFLAGS})
    endif()

    if(CONFIG_BT_SAMPLE_HFP_HF)
      nuttx_add_application(
        NAME hfp_hf
        STACKSIZE ${ZBLUE_STACKSIZE}
        SRCS ${ZBLUE_DIR}samples/bluetooth/handsfree/src/main.c
        INCLUDE_DIRECTORIES ${INCDIR}
        COMPILE_FLAGS ${CFLAGS})
    endif()
  endif()

  nuttx_add_library(zblue)

  target_sources(zblue PRIVATE ${CSRCS})
  target_include_directories(zblue PRIVATE ${INCDIR})
  target_compile_options(zblue PRIVATE ${CFLAGS})

  set(ZINC ${APPDIR}/external/zblue/zblue/include/zephyr)
  set(PORTINC ${ZBLUE_DIR}port/include/zephyr)

  set(SYMLINK_FILES
    app_memory/mem_domain.h
    arch/arch_interface.h
    arch/common/ffs.h
    debug/stack.h
    devicetree/ordinals.h
    fatal.h
    fatal_types.h
    fs/fs.h
    fs/fs_interface.h
    irq.h
    irq_offload.h
    kernel_includes.h
    kernel/internal/smp.h
    kernel/obj_core.h
    kernel/stats.h
    kernel/thread_stack.h
    kernel_version.h
    linker/sections.h
    linker/section_tags.h
    spinlock.h
    shell/shell_types.h
    shell/shell_fprintf.h
    shell/shell_string_conv.h
    sys/__assert.h
    sys/atomic.h
    sys/atomic_c.h
    sys/atomic_types.h
    sys/byteorder.h
    sys/check.h
    sys/crc.h
    sys/dlist.h
    sys/list_gen.h
    sys/math_extras.h
    sys/math_extras_impl.h
    sys/mem_stats.h
    sys/rb.h
    sys/sflist.h
    sys/slist.h
    sys/sys_heap.h
    sys/time_units.h
    sys/util.h
    sys/util_macro.h
    sys/util_loops.h
    sys/util_listify.h
    tracing/tracing_macros.h
    types.h
  )

  add_custom_target(create_symlinks ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/app_memory
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/debug
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/devicetree
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/fs
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/linker
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/arch/common
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PORTINC}/kernel/internal
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${ZINC}/bluetooth ${PORTINC}/bluetooth
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${ZINC}/drivers ${PORTINC}/drivers
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${ZINC}/settings ${PORTINC}/settings
  )

  foreach(file ${SYMLINK_FILES})
    add_custom_command(TARGET create_symlinks POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E create_symlink ${ZINC}/${file} ${PORTINC}/${file}
    )
  endforeach()
  add_dependencies(zblue create_symlinks)

  add_custom_target(clean_symlinks
    COMMAND ${CMAKE_COMMAND} -E remove -f .built
    COMMAND ${CMAKE_COMMAND} -E remove -f ${PORTINC}/bluetooth
    COMMAND ${CMAKE_COMMAND} -E remove -f ${PORTINC}/drivers
    COMMAND ${CMAKE_COMMAND} -E remove -f ${PORTINC}/settings
  )

  foreach(file ${SYMLINK_FILES})
    add_custom_command(TARGET clean_symlinks POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E remove -f ${PORTINC}/${file}
    )
  endforeach()

endif()
