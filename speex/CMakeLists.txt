# ##############################################################################
# external/speex/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_LIB_SPEEX)

  set(SPEEXDIR ${CMAKE_CURRENT_LIST_DIR}/speex)
  set(CSRCSDIR ${CMAKE_CURRENT_LIST_DIR}/speex/libspeex)

  file(GLOB CSRCS speex/libspeex/*.c)
  list(REMOVE_ITEM CSRCS
       ${CSRCSDIR}/testenc.c
       ${CSRCSDIR}/testenc_wb.c
       ${CSRCSDIR}/testenc_uwb.c)

  set(INCDIR ${SPEEXDIR} ${SPEEXDIR}/include)

  set(SPEEX_FLAGS
      -DHAVE_CONFIG_H
      -Dkiss_fft_alloc=spx_kiss_fft_alloc
      -Dkiss_fftr_alloc=spx_kiss_fftr_alloc
      -Dkiss_fft_stride=spx_kiss_fft_stride
      -Dkiss_fft=spx_kiss_fft
      -Dkiss_fftr=spx_kiss_fftr
      -Dkiss_fftri=spx_kiss_fftri
      -Wno-shadow
      -Wno-unused-function
      -Wno-strict-prototypes
      -Wno-literal-conversion
      -Wno-incompatible-pointer-types)

  add_custom_target(speex_context
      COMMAND cd ${SPEEXDIR}
      COMMAND ${SPEEXDIR}/autogen.sh 1>/dev/null
      COMMAND ${SPEEXDIR}/configure --disable-sse --enable-fixed-point 1>/dev/null
      WORKING_DIRECTORY ${SPEEXDIR})

  if(CONFIG_LIB_SPEEX_NB_TEST)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_SPEEX_NB_TEST}
      NAME
      speex_nbtest
      STACKSIZE
      ${CONFIG_LIB_SPEEX_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_SPEEX_PRIORITY}
      SRCS
      ${CSRCSDIR}/testenc.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${SPEEX_FLAGS}
      DEPENDS
      speex)
  endif()

  if(CONFIG_LIB_SPEEX_WB_TEST)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_SPEEX_WB_TEST}
      NAME
      speex_wbtest
      STACKSIZE
      ${CONFIG_LIB_SPEEX_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_SPEEX_PRIORITY}
      SRCS
      ${CSRCSDIR}/testenc_wb.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${SPEEX_FLAGS}
      DEPENDS
      speex)
  endif()

  if(CONFIG_LIB_SPEEX_UWB_TEST)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_SPEEX_UWB_TEST}
      NAME
      speex_uwbtest
      STACKSIZE
      ${CONFIG_LIB_SPEEX_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_SPEEX_PRIORITY}
      SRCS
      ${CSRCSDIR}/testenc_uwb.c
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${SPEEX_FLAGS}
      DEPENDS
      speex)
  endif()

  nuttx_add_library(speex STATIC)


  add_dependencies(speex speex_context)
  target_sources(speex PRIVATE ${CSRCS})
  target_include_directories(speex PUBLIC ${INCDIR})
  target_compile_options(speex PRIVATE ${SPEEX_FLAGS})

endif()
