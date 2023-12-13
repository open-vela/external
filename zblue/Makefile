#
# Copyright (C) 2020 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

SUBDIR = zblue/subsys/bluetooth

ifeq ($(CONFIG_BT_HCI_RAW),y)
  CSRCS += $(SUBDIR)/host/hci_raw.c
endif
ifeq ($(CONFIG_BT_DEBUG_MONITOR),y)
  CSRCS += $(SUBDIR)/host/monitor.c
endif
ifeq ($(CONFIG_BT_TINYCRYPT_ECC),y)
  CSRCS += $(SUBDIR)/host/hci_ecc.c
endif
ifeq ($(CONFIG_BT_A2DP),y)
  CSRCS += $(SUBDIR)/host/a2dp.c
endif
ifeq ($(CONFIG_BT_AVDTP),y)
  CSRCS += $(SUBDIR)/host/avdtp.c
endif
ifeq ($(CONFIG_BT_RFCOMM),y)
  CSRCS += $(SUBDIR)/host/rfcomm.c
endif
ifeq ($(CONFIG_BT_TESTING),y)
  CSRCS += $(SUBDIR)/host/testing.c
endif
ifeq ($(CONFIG_BT_SETTINGS),y)
  CSRCS += $(SUBDIR)/host/settings.c
endif
ifeq ($(CONFIG_BT_HOST_CCM),y)
  CSRCS += $(SUBDIR)/host/aes_ccm.c
endif

ifeq ($(CONFIG_BT_BREDR),y)
  CSRCS += $(SUBDIR)/host/keys_br.c
  CSRCS += $(SUBDIR)/host/l2cap_br.c
  CSRCS += $(SUBDIR)/host/sdp.c
  CSRCS += $(SUBDIR)/host/ssp.c
endif

ifeq ($(CONFIG_BT_HFP_HF),y)
  CSRCS += $(SUBDIR)/host/hfp_hf.c
  CSRCS += $(SUBDIR)/host/at.c
endif

ifeq ($(CONFIG_BT_AUDIO),y)
  ifeq ($(CONFIG_BT_ISO),y)
    CSRCS += $(SUBDIR)/host/audio/iso.c
  endif
endif

ifeq ($(CONFIG_BT_HCI_HOST),y)
  CSRCS += $(SUBDIR)/host/uuid.c
  CSRCS += $(SUBDIR)/host/hci_core.c

  ifeq ($(CONFIG_BT_HOST_CRYPTO),y)
    CSRCS += $(SUBDIR)/host/crypto.c
  endif

  ifeq ($(CONFIG_BT_CONN),y)
    CSRCS += $(SUBDIR)/host/conn.c
    CSRCS += $(SUBDIR)/host/l2cap.c
    CSRCS += $(SUBDIR)/host/att.c
    CSRCS += $(SUBDIR)/host/gatt.c
  endif

  ifeq ($(CONFIG_BT_SMP),y)
    CSRCS += $(SUBDIR)/host/smp.c
    CSRCS += $(SUBDIR)/host/keys.c
  else
    CSRCS += $(SUBDIR)/host/smp_null.c
  endif
endif

ifeq ($(CONFIG_BT_DIS),y)
  CSRCS += $(SUBDIR)/services/dis.c
endif

ifeq ($(CONFIG_BT_BAS),y)
  CSRCS += $(SUBDIR)/services/bas.c
endif

ifeq ($(CONFIG_BT_HRS),y)
  CSRCS += $(SUBDIR)/services/hrs.c
endif

ifeq ($(CONFIG_BT_MESH),y)
  CSRCS += $(SUBDIR)/mesh/main.c
  CSRCS += $(SUBDIR)/mesh/adv.c
  CSRCS += $(SUBDIR)/mesh/beacon.c
  CSRCS += $(SUBDIR)/mesh/net.c
  CSRCS += $(SUBDIR)/mesh/transport.c
  CSRCS += $(SUBDIR)/mesh/crypto.c
  CSRCS += $(SUBDIR)/mesh/access.c
  CSRCS += $(SUBDIR)/mesh/cfg_srv.c
  CSRCS += $(SUBDIR)/mesh/health_srv.c
  ifeq ($(CONFIG_BT_SETTINGS),y)
    CSRCS += $(SUBDIR)/mesh/settings.c
  endif
endif

ifeq ($(CONFIG_BT_MESH_LOW_POWER),y)
  CSRCS += $(SUBDIR)/mesh/lpn.c
endif
ifeq ($(CONFIG_BT_MESH_FRIEND),y)
  CSRCS += $(SUBDIR)/mesh/friend.c
endif
ifeq ($(CONFIG_BT_MESH_PROV),y)
  CSRCS += $(SUBDIR)/mesh/prov.c
endif
ifeq ($(CONFIG_BT_MESH_PB_ADV),y)
  CSRCS += $(SUBDIR)/mesh/pb_adv.c
endif
ifeq ($(CONFIG_BT_MESH_PB_GATT),y)
  CSRCS += $(SUBDIR)/mesh/pb_gatt.c
endif
ifeq ($(CONFIG_BT_MESH_PROXY),y)
  CSRCS += $(SUBDIR)/mesh/proxy.c
endif
ifeq ($(CONFIG_BT_MESH_CFG_CLI),y)
  CSRCS += $(SUBDIR)/mesh/cfg_cli.c
endif
ifeq ($(CONFIG_BT_MESH_HEALTH_CLI),y)
  CSRCS += $(SUBDIR)/mesh/health_cli.c
endif
ifeq ($(CONFIG_BT_MESH_SELF_TEST),y)
  CSRCS += $(SUBDIR)/mesh/test.c
endif
ifeq ($(CONFIG_BT_MESH_CDB),y)
  CSRCS += $(SUBDIR)/mesh/cdb.c
endif

CSRCS += $(wildcard $(SUBDIR)/common/*.c)

ifeq ($(CONFIG_SETTINGS),y)
  CSRCS += zblue/subsys/settings/src/settings.c
  CSRCS += zblue/subsys/settings/src/settings_store.c
  CSRCS += zblue/subsys/settings/src/settings_init.c
  CSRCS += zblue/subsys/settings/src/settings_line.c
  ifeq ($(CONFIG_SETTINGS_FS),y)
    CSRCS += zblue/subsys/settings/src/settings_file.c
  else ifeq ($(CONFIG_SETTINGS_NONE),y)
    CSRCS += zblue/subsys/settings/src/settings_none.c
  endif
  CFLAGS += ${INCDIR_PREFIX}zblue/subsys/settings/include
endif

ifeq ($(CONFIG_FILE_SYSTEM),y)
  CSRCS += zblue/port/subsys/fs/fs.c
endif

ifeq ($(CONFIG_BT_SHELL),y)
  CSRCS += zblue/port/subsys/shell/shell.c

  CSRCS    += $(SUBDIR)/shell/bt.c
  CSRCS    += $(SUBDIR)/shell/hci.c
  MAINSRC  += zblue/port/subsys/bluetooth/shell/bt.c
  PROGNAME += bt
  zblue/port/subsys/bluetooth/shell/bt.c_CFLAGS    += -DCONFIG_BT_BT_SHELL
  zblue/port/subsys/bluetooth/shell/bt.c_CELFFLAGS += -DCONFIG_BT_BT_SHELL

  ifeq ($(CONFIG_BT_CONN),y)
    CSRCS    += $(SUBDIR)/shell/gatt.c
    MAINSRC  += zblue/port/subsys/bluetooth/shell/gatt.c
    PROGNAME += gatt
    zblue/port/subsys/bluetooth/shell/gatt.c_CFLAGS    += -DCONFIG_BT_GATT_SHELL
    zblue/port/subsys/bluetooth/shell/gatt.c_CELFFLAGS += -DCONFIG_BT_GATT_SHELL
  endif
  ifeq ($(CONFIG_BT_BREDR),y)
    CSRCS    += $(SUBDIR)/shell/bredr.c
    MAINSRC  += zblue/port/subsys/bluetooth/shell/bredr.c
    PROGNAME += bredr
    zblue/port/subsys/bluetooth/shell/bredr.c_CFLAGS    += -DCONFIG_BT_BREDR_SHELL
    zblue/port/subsys/bluetooth/shell/bredr.c_CELFFLAGS += -DCONFIG_BT_BREDR_SHELL
  endif
  ifeq ($(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL),y)
    CSRCS    += $(SUBDIR)/shell/l2cap.c
    MAINSRC  += zblue/port/subsys/bluetooth/shell/l2cap.c
    PROGNAME += l2cap
    zblue/port/subsys/bluetooth/shell/l2cap.c_CFLAGS    += -DCONFIG_BT_L2CAP_SHELL
    zblue/port/subsys/bluetooth/shell/l2cap.c_CELFFLAGS += -DCONFIG_BT_L2CAP_SHELL
  endif
  ifeq ($(CONFIG_BT_RFCOMM),y)
    CSRCS    += $(SUBDIR)/shell/rfcomm.c
    MAINSRC  += zblue/port/subsys/bluetooth/shell/rfcomm.c
    PROGNAME += rfcomm
    zblue/port/subsys/bluetooth/shell/rfcomm.c_CFLAGS    += -DCONFIG_BT_RFCOMM_SHELL
    zblue/port/subsys/bluetooth/shell/rfcomm.c_CELFFLAGS += -DCONFIG_BT_RFCOMM_SHELL
  endif

  ifeq ($(CONFIG_BT_AUDIO),y)
    ifeq ($(CONFIG_BT_ISO),y)
      CSRCS    += $(SUBDIR)/shell/iso.c
      MAINSRC  += zblue/port/subsys/bluetooth/shell/iso.c
      PROGNAME += iso
      zblue/port/subsys/bluetooth/shell/iso.c_CFLAGS    += -DCONFIG_BT_ISO_SHELL
      zblue/port/subsys/bluetooth/shell/iso.c_CELFFLAGS += -DCONFIG_BT_ISO_SHELL
    endif
  endif

  ifeq ($(CONFIG_BT_MESH),y)
    ifeq ($(CONFIG_BT_MESH_SHELL),y)
      CSRCS    += $(SUBDIR)/mesh/shell.c
      MAINSRC  += zblue/port/subsys/bluetooth/shell/mesh.c
      PROGNAME += mesh
    endif
  endif

endif

ifeq ($(CONFIG_BT_TESTER),y)
  CSRCS += zblue/tests/bluetooth/tester/src/bttester.c
  CSRCS += zblue/tests/bluetooth/tester/src/gap.c
  CSRCS += zblue/tests/bluetooth/tester/src/gatt.c
  ifeq ($(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL),y)
    CSRCS += zblue/tests/bluetooth/tester/src/l2cap.c
  endif
  ifeq ($(CONFIG_BT_MESH),y)
    CSRCS += zblue/tests/bluetooth/tester/src/mesh.c
  endif
  CSRCS += zblue/port/drivers/console/uart_pipe.c
  CSRCS += zblue/port/tests/bluetooth/tester/src/system.c

  CSRCS += zblue/port/subsys/power/reboot.c

  MAINSRC  += zblue/tests/bluetooth/tester/src/main.c
  PROGNAME += bttester

  CFLAGS += ${INCDIR_PREFIX}zblue/tests/bluetooth/tester/src
endif

CSRCS += zblue/port/kernel/sched.c
CSRCS += zblue/port/kernel/timeout.c
CSRCS += zblue/port/kernel/work_q.c
CSRCS += zblue/port/kernel/poll.c
CSRCS += zblue/port/kernel/mem_slab.c
CSRCS += zblue/port/kernel/atomic_c.c
CSRCS += zblue/port/kernel/sem.c
CSRCS += zblue/port/kernel/mutex.c
CSRCS += zblue/port/kernel/queue.c
CSRCS += zblue/port/kernel/thread.c
CSRCS += zblue/port/subsys/net/buf.c
CSRCS += zblue/port/common/defines.c

CSRCS += zblue/lib/os/dec.c
CSRCS += zblue/lib/os/hex.c

ifeq ($(CONFIG_ARCH_CHIP_R328),y)
  CSRCS += zblue/port/chip/xr829/xr829.c
  CFLAGS += ${INCDIR_PREFIX}$(TOPDIR)/arch/arm/src/r328/include/drivers
  CFLAGS += ${INCDIR_PREFIX}$(TOPDIR)/arch/arm/src/r328/include
endif

ifeq ($(CONFIG_BT_LIBUSB),y)
  CSRCS += zblue/port/drivers/bluetooth/hci/libusb.c
endif

ifeq ($(CONFIG_BT_H4),y)
  CSRCS += zblue/port/drivers/bluetooth/hci/h4.c
endif

CFLAGS += -Wno-implicit-function-declaration -Wno-unused-but-set-variable
CFLAGS += -Wno-unused-function -Wno-unused-variable -Wno-implicit-int -Wno-shadow
CFLAGS += -Wno-stringop-overread

CFLAGS += ${INCDIR_PREFIX}zblue/port/include
CFLAGS += ${INCDIR_PREFIX}zblue/subsys/bluetooth
CFLAGS += ${INCDIR_PREFIX}zblue/subsys/bluetooth/host
CFLAGS += ${INCDIR_PREFIX}zblue/subsys/bluetooth/services
CFLAGS += ${INCDIR_PREFIX}zblue/subsys/bluetooth/mesh
CFLAGS += ${INCDIR_PREFIX}zblue/subsys/bluetooth/common

ifeq ($(CONFIG_ARCH_SIM),y)
  CFLAGS += -O2 -fno-strict-aliasing
  CFLAGS += -ffunction-sections -fdata-sections
endif

ifneq ($(CONFIG_BT_SAMPLE),)

  ifneq ($(CONFIG_BT_SAMPLE_PERIPHERAL),)
    PROGNAME += peripheral
    CSRCS += zblue/samples/bluetooth/peripheral/src/cts.c
    MAINSRC += zblue/samples/bluetooth/peripheral/src/main.c
    CFLAGS += ${INCDIR_PREFIX}zblue/samples/bluetooth/peripheral/src
  endif

  ifneq ($(CONFIG_BT_SAMPLE_CENTRAL),)
    PROGNAME += central
    MAINSRC += zblue/samples/bluetooth/central/src/main.c
  endif

  ifneq ($(CONFIG_BT_SAMPLE_MESH),)
    PROGNAME += btmesh
    MAINSRC += zblue/samples/bluetooth/mesh/src/main.c
    PROGNAME += mesh_demo
    MAINSRC += zblue/samples/bluetooth/mesh_demo/src/main.c
    ifneq ($(CONFIG_BT_MESH_PROVISIONER),)
      PROGNAME += mesh_provisioner
      MAINSRC += zblue/samples/bluetooth/mesh_provisioner/src/main.c
    endif
  endif

endif

PROGNAME += zblue
MAINSRC  += zblue/port/drivers/bluetooth/hci/hci.c

PRIORITY  = SCHED_PRIORITY_DEFAULT
ifneq ($(CONFIG_BT_SAMPLE),)
  STACKSIZE = $(CONFIG_BT_SAMPLE_STACKSIZE)
  MODULE    = $(CONFIG_BT_SAMPLE)
else
  STACKSIZE = $(CONFIG_DEFAULT_TASK_STACKSIZE)
  MODULE    = n
endif

depend::
	$(Q) ln -sf ../../include/bluetooth zblue/port/include/bluetooth
	$(Q) ln -sf ../../include/drivers zblue/port/include/drivers
	$(Q) ln -sf ../../include/fs zblue/port/include/fs
	$(Q) ln -sf ../../include/settings zblue/port/include/settings
	$(Q) ln -sf ../../include/power zblue/port/include/power
	$(Q) ln -sf ../../include/random zblue/port/include/random
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/bredr.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/bt.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/gatt.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/l2cap.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/mesh.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/rfcomm.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/ticker.c
	$(Q) ln -sf shell.c zblue/port/subsys/bluetooth/shell/iso.c

clean::
	$(call DELFILE, .built)
	$(call DELFILE, zblue/port/include/bluetooth)
	$(call DELFILE, zblue/port/include/drivers)
	$(call DELFILE, zblue/port/include/fs)
	$(call DELFILE, zblue/port/include/settings)
	$(call DELFILE, zblue/port/include/power)
	$(call DELFILE, zblue/port/include/random)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/bredr.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/bt.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/gatt.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/l2cap.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/mesh.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/rfcomm.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/ticker.c)
	$(call DELFILE, zblue/port/subsys/bluetooth/shell/iso.c)

include $(APPDIR)/Application.mk