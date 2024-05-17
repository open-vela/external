#
# Copyright (C) 2020 Xiaomi Corporation
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

if(CONFIG_LIB_OPUS)

  # ############################################################################
  # Sources
  # ############################################################################

  # ADD_SUBDIRECTORY: celt
  file(GLOB CELT_SOURCES opus/celt/*.c)
  set(CELT_SOURCES_X86_RTCD
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/x86cpu.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/x86_celt_map.c)
  set(CELT_SOURCES_SSE ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/pitch_sse.c)
  set(CELT_SOURCES_SSE2 ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/pitch_sse2.c
                        ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/vq_sse2)
  set(CELT_SOURCES_SSE4_1
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/celt_lpc_sse4_1.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/x86/pitch_sse4_1.c)
  set(CELT_SOURCES_ARM_RTCD
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/armcpu.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/arm_celt_map.c)
  set(CELT_SOURCES_ARM_ASM
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/celt_pitch_xcorr_arm.s)
  set(CELT_AM_SOURCES_ARM_ASM
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/armopts.s.in)
  set(CELT_SOURCES_ARM_NEON_INTR
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/celt_neon_intr.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/pitch_neon_intr.c)
  set(CELT_SOURCES_ARM_NE10
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/celt_fft_ne10.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/celt_mdct_ne10.c)

  # ADD_SUBDIRECTORY: silk
  file(GLOB SILK_SOURCES opus/silk/*.c)
  file(GLOB SILK_SOURCES_FIXED opus/silk/fixed/*.c)
  file(GLOB SILK_SOURCES_FLOAT opus/silk/float/*.c)
  set(SILK_SOURCES_X86_RTCD
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/x86/x86_silk_map.c)
  set(SILK_SOURCES_SSE4_1
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/x86/NSQ_sse4_1.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/x86/NSQ_del_dec_sse4_1.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/x86/VAD_sse4_1.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/x86/VQ_WMat_EC_sse4_1.c)
  set(SILK_SOURCES_ARM_RTCD
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/arm/arm_silk_map.c)
  set(SILK_SOURCES_ARM_NEON_INTR
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/arm/biquad_alt_neon_intr.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/arm/LPC_inv_pred_gain_neon_intr.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/arm/NSQ_del_dec_neon_intr.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/arm/NSQ_neon.c)
  set(SILK_SOURCES_FIXED_SSE4_1
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/fixed/x86/vector_ops_FIX_sse4_1.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/fixed/x86/burg_modified_FIX_sse4_1.c)
  set(SILK_SOURCES_FIXED_ARM_NEON_INTR
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/fixed/arm/warped_autocorrelation_FIX_neon_intr.c
  )

  # ADD_SUBDIRECTORY: src
  set(OPUS_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_decoder.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_encoder.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_multistream.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_multistream_encoder.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_multistream_decoder.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_projection_encoder.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_projection_decoder.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/mapping_matrix.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/repacketizer.c)
  set(OPUS_SOURCES_FLOAT
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/analysis.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/mlp.c
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/mlp_data.c)

  set(CSRCS ${CELT_SOURCES} ${OPUS_SOURCES} ${OPUS_SOURCES_FLOAT}
            ${SILK_SOURCES} ${SILK_SOURCES_FIXED})

  if(CONFIG_ARCH_ARM)
    foreach(ASM_FILE ${CELT_SOURCES_ARM_ASM})
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/celt_pitch_xcorr_arm-gnu.S )
      list(APPEND CSRCS ${CMAKE_CURRENT_BINARY_DIR}/celt_pitch_xcorr_arm-gnu.S)
    endforeach()

    if(CONFIG_ARM_NEON)
      list(APPEND CSRCS ${CELT_SOURCES_ARM_NEON_INTR}
           ${SILK_SOURCES_ARM_NEON_INTR} ${SILK_SOURCES_FIXED_ARM_NEON_INTR})
      set(CFLAGS ${CFLAGS} -fno-aggressive-loop-optimizations
                 -Wno-maybe-uninitialized)
    endif()

    if(CONFIG_LIB_NE10)
      list(APPEND CSRCS ${CELT_SOURCES_ARM_NE10})
    endif()
  endif()

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR
      ${CMAKE_CURRENT_LIST_DIR}
      ${CMAKE_CURRENT_LIST_DIR}/opus/
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt
      ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm
      ${CMAKE_CURRENT_LIST_DIR}/opus/include
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/fixed
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/arm
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/mips
      ${CMAKE_CURRENT_LIST_DIR}/opus/silk/x86)

  # ############################################################################
  # Compiler Flags
  # ############################################################################

  if(CONFIG_ARCH_ARM)
    set(EMBEDDEDCFLAGS -DEMBEDDED_ARM=1)
  else()
    set(EMBEDDEDCFLAGS -DEMBEDDED_ARM=0)
  endif()

  set(OPUS_FLAGS -DHAVE_CONFIG_H -DOPUS_WILL_BE_SLOW)
  list(APPEND CFLAGS ${EMBEDDEDCFLAGS} ${OPUS_FLAGS})

  # ############################################################################
  # Library Configuration
  # ############################################################################

  if(CONFIG_ARCH_ARM)
    add_custom_target(
      GNU-S
      COMMAND
        ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/arm2gnu.pl
        ${CMAKE_CURRENT_LIST_DIR}/opus/celt/arm/celt_pitch_xcorr_arm.s >
        ${CMAKE_CURRENT_BINARY_DIR}/celt_pitch_xcorr_arm-gnu.S
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
  endif()

  if(CONFIG_LIB_OPUS_DECODE_TEST)
    nuttx_add_application(
      NAME
      opus_dectest
      SRCS
      ${CMAKE_CURRENT_LIST_DIR}/opus/tests/test_opus_decode.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      ${CMAKE_CURRENT_LIST_DIR}/opus/tests
      STACKSIZE
      ${CONFIG_LIB_OPUS_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_OPUS_PRIORITY})
  endif()

  if(CONFIG_LIB_OPUS_ENCODE_TEST)
    nuttx_add_application(
      NAME
      opus_enctest
      SRCS
      ${CMAKE_CURRENT_LIST_DIR}/opus/tests/test_opus_encode.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      ${CMAKE_CURRENT_LIST_DIR}/opus/tests
      STACKSIZE
      ${CONFIG_LIB_OPUS_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_OPUS_PRIORITY})

    list(APPEND CSRCS
         ${CMAKE_CURRENT_LIST_DIR}/opus/tests/opus_encode_regressions.c)
  endif()

  if(CONFIG_LIB_OPUS_DEMO)
    nuttx_add_application(
      NAME
      opus_demo
      SRCS
      ${CMAKE_CURRENT_LIST_DIR}/opus/src/opus_demo.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      STACKSIZE
      ${CONFIG_LIB_OPUS_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_OPUS_PRIORITY})
  endif()

  nuttx_add_library(libopus STATIC)

  if(CONFIG_ARCH_ARM)
    add_dependencies(libopus GNU-S)
  endif()

  target_compile_options(libopus PRIVATE ${CFLAGS})
  target_sources(libopus PRIVATE ${CSRCS})
  target_include_directories(libopus PUBLIC ${INCDIR})

endif()
