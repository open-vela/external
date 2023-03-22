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

MODULE    = $(CONFIG_ANDROID_SERVICEMANAGER)
PRIORITY  = SCHED_PRIORITY_DEFAULT
STACKSIZE = $(CONFIG_ANDROID_SERVICEMANAGER_STACKSIZE)

MAINSRC  += service/service.cpp
PROGNAME += service

CXXFLAGS += -DVENDORSERVICEMANAGER
CXXSRCS  += servicemanager/Access.cpp
CXXSRCS  += servicemanager/ServiceManager.cpp
MAINSRC  += servicemanager/main.cpp
PROGNAME += servicemanager

include $(APPDIR)/Application.mk
