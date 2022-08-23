############################################################################
# apps/external/connectedhomeip/Makefile
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

include $(APPDIR)/Make.defs

CXXEXT = .cpp

CXXSRCS += $(wildcard src/lib/support/*.cpp)
CXXSRCS += $(wildcard src/lib/support/verhoeff/*.cpp)
CXXSRCS += $(wildcard src/lib/support/logging/*.cpp)
CXXSRCS := $(filter-out src/lib/support/JniReferences.cpp,$(CXXSRCS))
CXXSRCS := $(filter-out src/lib/support/CHIPMem-Simple.cpp,$(CXXSRCS))

CXXSRCS += $(wildcard src/lib/core/*.cpp)
CXXSRCS += $(wildcard src/lib/address_resolve/*.cpp)
CXXSRCS += $(wildcard src/lib/asn1/*.cpp)

CXXSRCS += $(wildcard src/lib/dnssd/ServiceNaming.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/TxtFields.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/ActiveResolveAttempts.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/Advertiser_ImplMinimalMdns.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/IncrementalResolve.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/MinimalMdnsServer.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/Resolver_ImplMinimalMdns.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/minimal_mdns/*.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/minimal_mdns/core/*.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/minimal_mdns/responders/*.cpp)
CXXSRCS += $(wildcard src/lib/dnssd/minimal_mdns/records/*.cpp)

CXXSRCS += $(wildcard src/app/*.cpp)
CXXSRCS += $(wildcard src/app/MessageDef/*.cpp)
CXXSRCS += $(wildcard src/app/server/*.cpp)
CXXSRCS += $(wildcard src/app/reporting/*.cpp)
CXXSRCS += $(wildcard src/app/util/*.cpp)
CXXSRCS += $(wildcard src/app/clusters/time-format-localization-server/time-format-localization-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/administrator-commissioning-server/administrator-commissioning-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/ota-requestor/BDXDownloader.cpp)
CXXSRCS += $(wildcard src/app/clusters/ota-requestor/DefaultOTARequestor.cpp)
CXXSRCS += $(wildcard src/app/clusters/ota-requestor/DefaultOTARequestorStorage.cpp)
CXXSRCS += $(wildcard src/app/clusters/ota-requestor/DefaultOTARequestorDriver.cpp)
CXXSRCS += $(wildcard src/app/clusters/ota-requestor/ota-requestor-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/ota-requestor/ExtendedOTARequestorDriver.cpp)
CXXSRCS += $(wildcard src/app/clusters/occupancy-sensor-server/occupancy-sensor-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/color-control-server/color-control-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/groups-server/groups-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/general-commissioning-server/general-commissioning-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/software-diagnostics-server/software-diagnostics-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/on-off-server/on-off-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/general-diagnostics-server/general-diagnostics-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/user-label-server/user-label-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/identify-server/identify-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/basic/basic.cpp)
CXXSRCS += $(wildcard src/app/clusters/localization-configuration-server/localization-configuration-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/group-key-mgmt-server/group-key-mgmt-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/switch-server/switch-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/ethernet-network-diagnostics-server/ethernet-network-diagnostics-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/network-commissioning/network-commissioning.cpp)
CXXSRCS += $(wildcard src/app/clusters/operational-credentials-server/operational-credentials-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/thread-network-diagnostics-server/thread-network-diagnostics-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/wifi-network-diagnostics-server/wifi-network-diagnostics-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/access-control-server/access-control-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/descriptor/descriptor.cpp)
CXXSRCS += $(wildcard src/app/clusters/diagnostic-logs-server/diagnostic-logs-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/fixed-label-server/fixed-label-server.cpp)
CXXSRCS += $(wildcard src/app/clusters/level-control/level-control.cpp)

CXXSRCS += $(wildcard src/messaging/*.cpp)
CXXSRCS += $(wildcard src/controller/*.cpp)

CXXSRCS += $(wildcard src/system/SystemClock.cpp)
CXXSRCS += $(wildcard src/system/SystemError.cpp)
CXXSRCS += $(wildcard src/system/SystemLayer.cpp)
CXXSRCS += $(wildcard src/system/SystemMutex.cpp)
CXXSRCS += $(wildcard src/system/SystemPacketBuffer.cpp)
CXXSRCS += $(wildcard src/system/SystemStats.cpp)
CXXSRCS += $(wildcard src/system/SystemTimer.cpp)
CXXSRCS += $(wildcard src/system/TLVPacketBufferBackingStore.cpp)
CXXSRCS += $(wildcard src/system/WakeEvent.cpp)
CXXSRCS += $(wildcard src/system/SystemLayerImplSelect.cpp)

CXXSRCS += $(wildcard src/crypto/RandUtils.cpp)
CXXSRCS += $(wildcard src/crypto/CHIPCryptoPAL.cpp)
CXXSRCS += $(wildcard src/crypto/CHIPCryptoPALmbedTLS.cpp)

CXXSRCS += $(wildcard src/transport/*.cpp)
CXXSRCS += $(wildcard src/transport/raw/*.cpp)

CXXSRCS += $(wildcard src/ble/*.cpp)

CXXSRCS += $(wildcard src/inet/InetInterface.cpp)
CXXSRCS += $(wildcard src/inet/IPAddress.cpp)
CXXSRCS += $(wildcard src/inet/TCPEndPoint.cpp)
CXXSRCS += $(wildcard src/inet/UDPEndPointImplSockets.cpp)
CXXSRCS += $(wildcard src/inet/InetError.cpp)
CXXSRCS += $(wildcard src/inet/IPAddress-StringFuncts.cpp)
CXXSRCS += $(wildcard src/inet/IPPacketInfo.cpp)
CXXSRCS += $(wildcard src/inet/UDPEndPoint.cpp)
CXXSRCS += $(wildcard src/inet/InetArgParser.cpp)
CXXSRCS += $(wildcard src/inet/IPPrefix.cpp)
CXXSRCS += $(wildcard src/inet/TCPEndPointImplSockets.cpp)

CXXSRCS += $(wildcard src/access/*.cpp)
CXXSRCS += $(wildcard src/access/examples/*.cpp)
CXXSRCS += $(wildcard src/setup_payload/*.cpp)
CXXSRCS += $(wildcard src/credentials/*.cpp)
CXXSRCS += $(wildcard src/credentials/examples/*.cpp)
CXXSRCS += $(wildcard src/credentials/attestation_verifier/*.cpp)

CXXSRCS += $(wildcard src/protocols/interaction_model/*.cpp)
CXXSRCS += $(wildcard src/protocols/user_directed_commissioning/*.cpp)
CXXSRCS += $(wildcard src/protocols/secure_channel/*.cpp)
CXXSRCS += $(wildcard src/protocols/bdx/*.cpp)
CXXSRCS += $(wildcard src/protocols/echo/*.cpp)

CXXSRCS += $(wildcard zzz_generated/lighting-app/zap-generated/*.cpp)
CXXSRCS += $(wildcard zzz_generated/app-common/app-common/zap-generated/*.cpp)
CXXSRCS += $(wildcard zzz_generated/app-common/app-common/zap-generated/attributes/*.cpp)

CXXSRCS += $(wildcard examples/lighting-app/lighting-common/src/*.cpp)
CXXSRCS += $(wildcard examples/platform/linux/Options.cpp)
CXXSRCS += $(wildcard examples/platform/linux/CommissionableInit.cpp)
CXXSRCS += $(wildcard examples/platform/linux/LinuxCommissionableDataProvider.cpp)

CXXSRCS += $(wildcard src/platform/Linux/PlatformManagerImpl.cpp)
CXXSRCS += $(wildcard src/platform/Linux/PosixConfig.cpp)
CXXSRCS += $(wildcard src/platform/Linux/CHIPLinuxStorage.cpp)
CXXSRCS += $(wildcard src/platform/Linux/ConfigurationManagerImpl.cpp)
CXXSRCS += $(wildcard src/platform/Linux/CHIPLinuxStorageIni.cpp)
CXXSRCS += $(wildcard src/platform/Linux/DiagnosticDataProviderImpl.cpp)
CXXSRCS += $(wildcard src/platform/Linux/KeyValueStoreManagerImpl.cpp)
CXXSRCS += $(wildcard src/platform/Linux/SystemTimeSupport.cpp)

CXXSRCS += $(wildcard src/platform/Linux/DeviceNetworkProvisioningDelegateImpl.cpp)
CXXSRCS += $(wildcard src/platform/Linux/NetworkCommissioningEthernetDriver.cpp)
CXXSRCS += $(wildcard src/platform/Linux/NetworkCommissioningWiFiDriver.cpp)
CXXSRCS += $(wildcard src/platform/Linux/OTAImageProcessorImpl.cpp)

CXXSRCS += $(wildcard src/platform/*.cpp)

CXXSRCS += $(wildcard port/src/platform/Linux/Logging.cpp)
CXXSRCS += $(wildcard port/src/platform/Linux/BLEManagerImpl.cpp)
CXXSRCS += $(wildcard port/src/platform/Linux/ConnectivityUtils.cpp)
CXXSRCS += $(wildcard port/src/platform/Linux/DeviceInfoProviderImpl.cpp)
CXXSRCS += $(wildcard port/src/platform/Linux/ConnectivityManagerImpl.cpp)

MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" port}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" port/src}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" port/src/platform/Linux}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/lib/dnssd}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" zzz_generated}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" zzz_generated/lighting-app}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" zzz_generated/app-common}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src/platform/Linux}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" examples/platform/linux}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external//nlassert/nlassert/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/nlio/nlio/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/zblue/zblue/port/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/inipp/inipp}

MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" examples/lighting-app/lighting-common/include}

CXXFLAGS += -DCHIP_HAVE_CONFIG_H
CXXFLAGS += -fpermissive -std=c++17 -Wno-undef -Wno-format
CXXFLAGS += $(MATTERFLAGS)

PROGNAME  = matter
PRIORITY  = 100
STACKSIZE = 16384
MODULE    = $(CONFIG_EXAMPLES_HELLO)

MAINSRC   = port/main.cpp

include $(APPDIR)/Application.mk
