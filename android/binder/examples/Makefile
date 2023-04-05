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

MODULE    = $(CONFIG_BINDER_EXAMPLES)
PRIORITY  = SCHED_PRIORITY_DEFAULT
STACKSIZE = $(CONFIG_BINDER_EXAMPLES_STACKSIZE)

AIDLFLAGS = --lang=cpp -Iaidl_demo -haidl_demo -oaidl_demo
AIDLSRCS += aidl_demo/ITestStuff.aidl
CXXFLAGS += -Iaidl_demo

CXXSRCS  += aidl_demo/ITestStuff.cpp
MAINSRC  += aidl_demo/TestClient.cpp
PROGNAME += TestClient
MAINSRC  += aidl_demo/TestServer.cpp
PROGNAME += TestServer

MAINSRC  += aidl_demo/TestClientCpc.cpp
PROGNAME += TestClientCpc
MAINSRC  += aidl_demo/TestServerCpc.cpp
PROGNAME += TestServerCpc

include $(APPDIR)/Application.mk
