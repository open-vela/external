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

CXXEXT := .cpp


OC_BASE = libopencore-amr/opencore
AMR_BASE = $(OC_BASE)/codecs_v2/audio/gsm_amr
OSCL = libopencore-amr/oscl
PUBINC_DIR = libopencore-amr/include

NBDEC_DIR = $(AMR_BASE)/amr_nb/dec
NBENC_DIR = $(AMR_BASE)/amr_nb/enc
COMMON_DIR = $(AMR_BASE)/amr_nb/common
NBDEC_SRC_DIR = $(NBDEC_DIR)/src
NBENC_SRC_DIR = $(NBENC_DIR)/src
COMMON_SRC_DIR = $(COMMON_DIR)/src
WBDEC_DIR = $(AMR_BASE)/amr_wb/dec
WBDEC_SRC_DIR = $(WBDEC_DIR)/src

CXXFLAGS += ${INCDIR_PREFIX}$(OSCL)
CXXFLAGS += ${INCDIR_PREFIX}$(NBDEC_SRC_DIR)
CXXFLAGS += ${INCDIR_PREFIX}$(NBENC_SRC_DIR)
CXXFLAGS += ${INCDIR_PREFIX}$(COMMON_DIR)/include
CXXFLAGS += ${INCDIR_PREFIX}$(NBDEC_DIR)/include
CXXFLAGS += ${INCDIR_PREFIX}$(NBENC_DIR)/include
CXXFLAGS += ${INCDIR_PREFIX}$(AMR_BASE)/common/dec/include
CXXFLAGS += ${INCDIR_PREFIX}$(WBDEC_SRC_DIR)
CXXFLAGS += ${INCDIR_PREFIX}$(WBDEC_DIR)/include
CXXFLAGS += ${INCDIR_PREFIX}$(PUBINC_DIR)/opencore-amrnb
CXXFLAGS += ${INCDIR_PREFIX}$(PUBINC_DIR)/opencore-amrwb

CXXSRCS  += libopencore-amr/amrnb/wrapper.cpp
CXXSRCS  += libopencore-amr/amrwb/wrapper.cpp

CXXSRCS  += $(wildcard $(NBDEC_SRC_DIR)/*.cpp)
CXXSRCS  += $(wildcard $(NBENC_SRC_DIR)/*.cpp)
CXXSRCS  += $(wildcard $(COMMON_SRC_DIR)/*.cpp)
CXXSRCS  += $(wildcard $(WBDEC_SRC_DIR)/*.cpp)

REMOVE_CXX = $(NBDEC_SRC_DIR)/decoder_gsm_amr.cpp \
             $(NBDEC_SRC_DIR)/decoder_gsm_amr.cpp \
             $(NBDEC_SRC_DIR)/pvgsmamrdecoder.cpp \
             $(NBENC_SRC_DIR)/gsmamr_encoder_wrapper.cpp \
             $(COMMON_SRC_DIR)/bits2prm.cpp \
             $(COMMON_SRC_DIR)/copy.cpp \
             $(COMMON_SRC_DIR)/div_32.cpp \
             $(COMMON_SRC_DIR)/l_abs.cpp \
             $(COMMON_SRC_DIR)/r_fft.cpp \
             $(COMMON_SRC_DIR)/vad1.cpp \
             $(COMMON_SRC_DIR)/vad2.cpp \
             $(WBDEC_SRC_DIR)/decoder_amr_wb.cpp \

CXXSRCS := $(filter-out $(REMOVE_CXX),$(CXXSRCS))


CXXFLAGS += -Wno-shadow -Wno-undef -Wno-register
CXXFLAGS += -Dt_qua_gain7b=t_qua_gain7b_amr -DLog2=Log2_amr

include $(APPDIR)/Application.mk
