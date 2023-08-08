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

PRIORITY  = $(CONFIG_THORVG_PRIORITY)
STACKSIZE = $(CONFIG_THORVG_STACKSIZE)
MODULE    = $(CONFIG_THORVG)

CXXEXT    = .cpp

CFLAGS   += ${INCDIR_PREFIX}thorvg/src/bindings/capi
CFLAGS   += ${INCDIR_PREFIX}thorvg/src/lib/sw_engine

CXXFLAGS += ${INCDIR_PREFIX}./
CXXFLAGS += ${INCDIR_PREFIX}thorvg/inc
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/lib
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/lib/sw_engine
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/loaders/jpg
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/loaders/lottie
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/loaders/png
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/loaders/raw
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/loaders/svg
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/loaders/tvg
CXXFLAGS += ${INCDIR_PREFIX}thorvg/src/utils

CFLAGS   += -Wno-shadow
CXXFLAGS += -Wno-shadow -Wno-unused-but-set-variable

CXXSRCS  += $(wildcard thorvg/src/bindings/capi/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/lib/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/lib/sw_engine/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/loaders/jpg/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/loaders/lottie/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/loaders/png/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/loaders/raw/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/loaders/svg/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/loaders/tvg/*$(CXXEXT))
CXXSRCS  += $(wildcard thorvg/src/utils/*$(CXXEXT))

include $(APPDIR)/Application.mk
