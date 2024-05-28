#
# Copyright (C) 2024 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#

if(CONFIG_LIB_OPENCORE_AMR)

  set(PUBINC_DIR ${CMAKE_CURRENT_LIST_DIR}/libopencore-amr/include)
  set(OC_BASE ${CMAKE_CURRENT_LIST_DIR}/libopencore-amr/opencore)
  set(OSCL ${CMAKE_CURRENT_LIST_DIR}/libopencore-amr/oscl)
  set(AMR_BASE ${OC_BASE}/codecs_v2/audio/gsm_amr)
  set(NBDEC_DIR ${AMR_BASE}/amr_nb/dec)
  set(NBENC_DIR ${AMR_BASE}/amr_nb/enc)
  set(COMMON_DIR ${AMR_BASE}/amr_nb/common)
  set(NBDEC_SRC_DIR ${NBDEC_DIR}/src)
  set(NBENC_SRC_DIR ${NBENC_DIR}/src)
  set(COMMON_SRC_DIR ${COMMON_DIR}/src)
  set(WBDEC_DIR ${AMR_BASE}/amr_wb/dec)
  set(WBDEC_SRC_DIR ${WBDEC_DIR}/src)

  # ############################################################################
  # Flags
  # ############################################################################

  set(CXXFLAGS -Wno-shadow -Wno-undef -Wno-register
               -Dt_qua_gain7b=t_qua_gain7b_amrwb)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB CXXSRCS ${NBDEC_SRC_DIR}/*.cpp ${NBENC_SRC_DIR}/*.cpp
       ${WBDEC_SRC_DIR}/*.cpp ${COMMON_SRC_DIR}/*.cpp)

  list(APPEND CXXSRCS
       ${CMAKE_CURRENT_LIST_DIR}/libopencore-amr/amrnb/wrapper.cpp
       ${CMAKE_CURRENT_LIST_DIR}/libopencore-amr/amrwb/wrapper.cpp)

  set(REMOVE_CXX
      ${NBDEC_SRC_DIR}/decoder_gsm_amr.cpp
      ${NBDEC_SRC_DIR}/decoder_gsm_amr.cpp
      ${NBDEC_SRC_DIR}/pvgsmamrdecoder.cpp
      ${WBDEC_SRC_DIR}/decoder_amr_wb.cpp
      ${NBENC_SRC_DIR}/gsmamr_encoder_wrapper.cpp
      ${COMMON_SRC_DIR}/bits2prm.cpp
      ${COMMON_SRC_DIR}/copy.cpp
      ${COMMON_SRC_DIR}/div_32.cpp
      ${COMMON_SRC_DIR}/l_abs.cpp
      ${COMMON_SRC_DIR}/r_fft.cpp
      ${COMMON_SRC_DIR}/vad1.cpp
      ${COMMON_SRC_DIR}/vad2.cpp)

  list(REMOVE_ITEM CXXSRCS ${REMOVE_CXX})

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR
      ${OSCL}
      ${NBDEC_SRC_DIR}
      ${NBENC_SRC_DIR}
      ${WBDEC_SRC_DIR}
      ${COMMON_DIR}/include
      ${AMR_BASE}/common/dec/include
      ${NBDEC_DIR}/include
      ${NBENC_DIR}/include
      ${WBDEC_DIR}/include
      ${PUBINC_DIR}/opencore-amrnb
      ${PUBINC_DIR}/opencore-amrwb)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(libopencore-amr STATIC)
  target_compile_options(libopencore-amr PRIVATE ${CXXFLAGS})
  target_sources(libopencore-amr PRIVATE ${CXXSRCS})
  target_include_directories(libopencore-amr PUBLIC ${INCDIR})

endif()
