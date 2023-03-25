#
# Copyright (C) 2023 Xiaomi Corporation
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

CXXEXT = .cpp

CXXSRCS += binder/ndk/ibinder.cpp
CXXSRCS += binder/ndk/parcel.cpp
CXXSRCS += binder/ndk/process.cpp
CXXSRCS += binder/ndk/service_manager.cpp
CXXSRCS += binder/ndk/stability.cpp
CXXSRCS += binder/ndk/status.cpp

CXXSRCS += binder/ActivityManager.cpp
CXXSRCS += binder/Binder.cpp
CXXSRCS += binder/BpBinder.cpp
CXXSRCS += binder/BufferedTextOutput.cpp
CXXSRCS += binder/Debug.cpp
CXXSRCS += binder/FdTrigger.cpp
CXXSRCS += binder/IActivityManager.cpp
CXXSRCS += binder/IBatteryStats.cpp
CXXSRCS += binder/IInterface.cpp
CXXSRCS += binder/IMemory.cpp
CXXSRCS += binder/IPCThreadState.cpp
CXXSRCS += binder/IPermissionController.cpp
CXXSRCS += binder/IProcessInfoService.cpp
CXXSRCS += binder/IResultReceiver.cpp
CXXSRCS += binder/IServiceManager.cpp
CXXSRCS += binder/IShellCallback.cpp
CXXSRCS += binder/IUidObserver.cpp
CXXSRCS += binder/LazyServiceRegistrar.cpp
CXXSRCS += binder/libbinder_rpc_unstable.cpp
CXXSRCS += binder/MemoryBase.cpp
CXXSRCS += binder/MemoryDealer.cpp
CXXSRCS += binder/MemoryHeapBase.cpp
CXXSRCS += binder/Parcel.cpp
CXXSRCS += binder/ParcelableHolder.cpp
CXXSRCS += binder/ParcelFileDescriptor.cpp
CXXSRCS += binder/PermissionCache.cpp
CXXSRCS += binder/PermissionController.cpp
CXXSRCS += binder/PersistableBundle.cpp
CXXSRCS += binder/ProcessInfoService.cpp
CXXSRCS += binder/ProcessState.cpp
CXXSRCS += binder/RpcServer.cpp
CXXSRCS += binder/RpcSession.cpp
CXXSRCS += binder/RpcState.cpp
CXXSRCS += binder/RpcTransportRaw.cpp
CXXSRCS += binder/Stability.cpp
CXXSRCS += binder/Static.cpp
CXXSRCS += binder/Status.cpp
CXXSRCS += binder/TextOutput.cpp
CXXSRCS += binder/Utils.cpp

AIDLSRCS += $(shell find binder/aidl -name *.aidl)
AIDLFLAGS = --lang=cpp -Ibinder/aidl -hbinder/aidl -obinder/aidl

CXXSRCS  += $(patsubst %$(AIDLEXT),%$(CXXEXT),$(AIDLSRCS))

MODULE    = $(CONFIG_ANDROID_BINDER_TEST)
PRIORITY  = SCHED_PRIORITY_DEFAULT
STACKSIZE = $(CONFIG_ANDROID_BINDER_TEST_STACKSIZE)

ifeq ($(CONFIG_ANDROID_BINDER_LIB_TEST), y)
MAINSRC  += binder/tests/binderLibTest.cpp
PROGNAME += binderLibTest
endif

ifeq ($(CONFIG_ANDROID_BINDER_DRIVER_TEST), y)
MAINSRC  += binder/tests/binderDriverInterfaceTest.cpp
PROGNAME += binderDrvTest
endif

include $(APPDIR)/Application.mk
