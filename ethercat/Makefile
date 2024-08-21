#
# Copyright (C) 2024 Xiaomi Corporation
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
ifeq ($(CONFIG_ETHERCAT_MASTER),y)

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/ethercat/ethercat/devices

CSRCS += \
    ethercat/master/soe_request.c \
    ethercat/master/slave_config.c \
    ethercat/master/slave.c \
    ethercat/master/sdo_request.c \
    ethercat/master/sdo_entry.c \
    ethercat/master/sdo.c \
    ethercat/master/reg_request.c \
    ethercat/master/pdo_list.c \
    ethercat/master/pdo_entry.c \
    ethercat/master/pdo.c \
    ethercat/master/os.c \
    ethercat/master/master_socket.c \
    ethercat/master/module.c \
    ethercat/master/mbox_gateway_request.c \
    ethercat/master/master.c \
    ethercat/master/mailbox.c \
    ethercat/master/fsm_soe.c \
    ethercat/master/fsm_slave_scan.c \
    ethercat/master/fsm_slave_config.c \
    ethercat/master/fsm_reboot.c \
    ethercat/master/fsm_mbox_gateway.c \
    ethercat/master/fsm_master.c \
    ethercat/master/fsm_foe.c \
    ethercat/master/fsm_coe.c \
    ethercat/master/domain.c \
    ethercat/master/device.c \
    ethercat/master/datagram_pair.c \
    ethercat/master/datagram.c \
    ethercat/master/coe_emerg_ring.c \
    ethercat/master/sync_config.c \
    ethercat/master/sync.c \
    ethercat/master/soe_errors.c \
    ethercat/master/fsm_slave.c \
    ethercat/master/fsm_sii.c \
    ethercat/master/fsm_pdo_entry.c \
    ethercat/master/fsm_pdo.c \
    ethercat/master/fsm_change.c \
    ethercat/master/fmmu_config.c \
    ethercat/master/doxygen.c \
    ethercat/master/dict_request.c \
    ethercat/master/ioctl.c \

CFLAGS += ${DEFINE_PREFIX}VERSION='"${VERSION}"'

ifeq ($(CONFIG_ETHERCAT_MASTER_EXAMMPLE),y)
MAINSRC   += ethercat/examples/velaos/main.c
PROGNAME  += $(CONFIG_ETHERCAT_MASTER_PROGNAME)
PRIORITY  += $(CONFIG_ETHERCAT_MASTER_PRIORITY)
STACKSIZE += $(CONFIG_ETHERCAT_MASTER_STACKSIZE)
MODULE    += $(CONFIG_ETHERCAT_MASTER)
endif

endif

ifeq ($(CONFIG_ETHERCAT_TOOL),y)
CXXEXT := .cpp
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/ethercat/ethercat/master
CXXFLAGS += ${DEFINE_PREFIX}VERSION='"${VERSION}"'

CXXSRCS += \
    ethercat/tool/Command.cpp \
    ethercat/tool/CommandAlias.cpp \
    ethercat/tool/CommandCrc.cpp \
    ethercat/tool/CommandCStruct.cpp \
    ethercat/tool/CommandConfig.cpp \
    ethercat/tool/CommandData.cpp \
    ethercat/tool/CommandDebug.cpp \
    ethercat/tool/CommandDomains.cpp \
    ethercat/tool/CommandDownload.cpp \
    ethercat/tool/CommandFoeRead.cpp \
    ethercat/tool/CommandFoeWrite.cpp \
    ethercat/tool/CommandGraph.cpp \
    ethercat/tool/CommandMaster.cpp \
    ethercat/tool/CommandPdos.cpp \
    ethercat/tool/CommandRegRead.cpp \
    ethercat/tool/CommandRegWrite.cpp \
    ethercat/tool/CommandRescan.cpp \
    ethercat/tool/CommandSdos.cpp \
    ethercat/tool/CommandSiiRead.cpp \
    ethercat/tool/CommandSiiWrite.cpp \
    ethercat/tool/CommandSlaves.cpp \
    ethercat/tool/CommandSoeRead.cpp \
    ethercat/tool/CommandSoeWrite.cpp \
    ethercat/tool/CommandStates.cpp \
    ethercat/tool/CommandUpload.cpp \
    ethercat/tool/CommandVersion.cpp \
    ethercat/tool/CommandXml.cpp \
    ethercat/tool/DataTypeHandler.cpp \
    ethercat/tool/FoeCommand.cpp \
    ethercat/tool/MasterDevice.cpp \
    ethercat/tool/NumberListParser.cpp \
    ethercat/tool/SdoCommand.cpp \
    ethercat/tool/SoeCommand.cpp \
    ethercat/tool/sii_crc.cpp

ifeq ($(CONFIG_ETHERCAT_TOOL_ENABLE_EOE),y)
CXXSRCS += \
    ethercat/tool/CommandEoe.cpp \
    ethercat/tool/CommandEoeAddIf.cpp \
    ethercat/tool/CommandEoeDelIf.cpp \
    ethercat/tool/CommandIp.cpp
endif

PROGNAME  += $(CONFIG_ETHERCAT_TOOL_PROGNAME)
PRIORITY  += $(CONFIG_ETHERCAT_TOOL_PRIORITY)
STACKSIZE += $(CONFIG_ETHERCAT_TOOL_STACKSIZE)
MODULE    += $(CONFIG_ETHERCAT_TOOL)
MAINSRC   += ethercat/tool/main.cpp
endif

include $(APPDIR)/Application.mk
