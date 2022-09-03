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

CXXSRCS += $(wildcard connectedhomeip/src/lib/support/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/support/verhoeff/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/support/logging/*.cpp)
CXXSRCS := $(filter-out connectedhomeip/src/lib/support/JniReferences.cpp,$(CXXSRCS))
CXXSRCS := $(filter-out connectedhomeip/src/lib/support/CHIPMem-Simple.cpp,$(CXXSRCS))

CXXSRCS += $(wildcard connectedhomeip/src/lib/core/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/address_resolve/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/asn1/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/ServiceNaming.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/TxtFields.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/ActiveResolveAttempts.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/Advertiser_ImplMinimalMdns.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/IncrementalResolve.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/MinimalMdnsServer.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/Resolver_ImplMinimalMdns.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/minimal_mdns/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/minimal_mdns/core/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/minimal_mdns/responders/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/lib/dnssd/minimal_mdns/records/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/app/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/MessageDef/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/server/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/reporting/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/util/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/time-format-localization-server/time-format-localization-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/administrator-commissioning-server/administrator-commissioning-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ota-requestor/BDXDownloader.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ota-requestor/DefaultOTARequestor.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ota-requestor/DefaultOTARequestorStorage.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ota-requestor/DefaultOTARequestorDriver.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ota-requestor/ota-requestor-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ota-requestor/ExtendedOTARequestorDriver.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/occupancy-sensor-server/occupancy-sensor-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/color-control-server/color-control-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/groups-server/groups-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/general-commissioning-server/general-commissioning-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/software-diagnostics-server/software-diagnostics-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/on-off-server/on-off-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/general-diagnostics-server/general-diagnostics-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/user-label-server/user-label-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/identify-server/identify-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/basic/basic.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/localization-configuration-server/localization-configuration-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/group-key-mgmt-server/group-key-mgmt-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/switch-server/switch-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/ethernet-network-diagnostics-server/ethernet-network-diagnostics-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/network-commissioning/network-commissioning.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/operational-credentials-server/operational-credentials-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/thread-network-diagnostics-server/thread-network-diagnostics-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/wifi-network-diagnostics-server/wifi-network-diagnostics-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/access-control-server/access-control-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/descriptor/descriptor.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/diagnostic-logs-server/diagnostic-logs-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/fixed-label-server/fixed-label-server.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/app/clusters/level-control/level-control.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/messaging/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/controller/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/system/SystemClock.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemError.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemLayer.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemMutex.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemPacketBuffer.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemStats.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemTimer.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/TLVPacketBufferBackingStore.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/WakeEvent.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/system/SystemLayerImplSelect.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/crypto/RandUtils.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/crypto/CHIPCryptoPAL.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/crypto/CHIPCryptoPALmbedTLS.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/transport/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/transport/raw/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/ble/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/inet/InetInterface.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/IPAddress.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/TCPEndPoint.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/UDPEndPointImplSockets.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/InetError.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/IPAddress-StringFuncts.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/IPPacketInfo.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/UDPEndPoint.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/InetArgParser.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/IPPrefix.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/inet/TCPEndPointImplSockets.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/access/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/access/examples/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/setup_payload/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/credentials/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/credentials/examples/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/credentials/attestation_verifier/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/protocols/interaction_model/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/protocols/user_directed_commissioning/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/protocols/secure_channel/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/protocols/bdx/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/protocols/echo/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/zzz_generated/lighting-app/zap-generated/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/zzz_generated/app-common/app-common/zap-generated/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/zzz_generated/app-common/app-common/zap-generated/attributes/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/examples/lighting-app/lighting-common/src/*.cpp)
CXXSRCS += $(wildcard connectedhomeip/examples/platform/linux/Options.cpp)
CXXSRCS += $(wildcard connectedhomeip/examples/platform/linux/CommissionableInit.cpp)
CXXSRCS += $(wildcard connectedhomeip/examples/platform/linux/LinuxCommissionableDataProvider.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/PlatformManagerImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/PosixConfig.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/CHIPLinuxStorage.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/ConfigurationManagerImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/CHIPLinuxStorageIni.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/DiagnosticDataProviderImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/KeyValueStoreManagerImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/SystemTimeSupport.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/DeviceNetworkProvisioningDelegateImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/NetworkCommissioningEthernetDriver.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/NetworkCommissioningWiFiDriver.cpp)
CXXSRCS += $(wildcard connectedhomeip/src/platform/Linux/OTAImageProcessorImpl.cpp)

CXXSRCS += $(wildcard connectedhomeip/src/platform/*.cpp)

CXXSRCS += $(wildcard connectedhomeip/port/src/platform/Linux/Logging.cpp)
CXXSRCS += $(wildcard connectedhomeip/port/src/platform/Linux/BLEManagerImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/port/src/platform/Linux/ConnectivityUtils.cpp)
CXXSRCS += $(wildcard connectedhomeip/port/src/platform/Linux/DeviceInfoProviderImpl.cpp)
CXXSRCS += $(wildcard connectedhomeip/port/src/platform/Linux/ConnectivityManagerImpl.cpp)

MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/port}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/port/src}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/port/src/platform/Linux}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/src}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/src/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/src/lib/dnssd}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/zzz_generated}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/zzz_generated/lighting-app}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/zzz_generated/app-common}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/src/platform/Linux}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/examples/platform/linux}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external//nlassert/nlassert/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/nlio/nlio/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/zblue/zblue/port/include}
MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/inipp/inipp}

MATTERFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" connectedhomeip/examples/lighting-app/lighting-common/include}

CXXFLAGS += -DCHIP_HAVE_CONFIG_H
CXXFLAGS += -fpermissive -std=c++17 -Wno-undef -Wno-format
CXXFLAGS += $(MATTERFLAGS)

PROGNAME  = matter
PRIORITY  = 100
STACKSIZE = 16384
MODULE    = $(CONFIG_EXAMPLES_HELLO)

MAINSRC   = connectedhomeip/port/main.cpp

include $(APPDIR)/Application.mk
