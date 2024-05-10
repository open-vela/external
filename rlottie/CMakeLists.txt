# ##############################################################################
# external/rlottie/CMakeLists.txt
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

if(CONFIG_LIB_RLOTTIE)

  set(LIBRLOTTIE_DIR ${CMAKE_CURRENT_LIST_DIR}/rlottie)

  set(CXXFLAGS -Wno-format -Wno-volatile -Wno-unused-value -Wno-shadow)

  file(
    GLOB
    CXXSRCS
    ${LIBRLOTTIE_DIR}/src/lottie/*.cpp
    ${LIBRLOTTIE_DIR}/src/binding/c/*.cpp
    ${LIBRLOTTIE_DIR}/src/vector/*.cpp
    ${LIBRLOTTIE_DIR}/src/vector/freetype/*.cpp
    ${LIBRLOTTIE_DIR}/src/vector/stb/*.cpp)

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR} ${LIBRLOTTIE_DIR}/inc
             ${LIBRLOTTIE_DIR}/src/vector ${LIBRLOTTIE_DIR}/src/vector/freetype)

  if(CONFIG_ARM_NEON AND CONFIG_ARM64_NEON)
    list(APPEND CXXSRCS ${LIBRLOTTIE_DIR}/src/vector/pixman/*.S)
  endif(CONFIG_ARM_NEON AND CONFIG_ARM64_NEON)

  nuttx_add_library(librlottie STATIC)

  nuttx_export_header(TARGET librlottie INCLUDE_DIRECTORIES
                      ${LIBRLOTTIE_DIR}/inc)

  target_compile_options(librlottie PRIVATE ${CXXFLAGS})
  target_sources(librlottie PRIVATE ${CXXSRCS})
  target_include_directories(librlottie PRIVATE ${INCDIR})

  if(CONFIG_LOTTIE_TEST)
    file(MAKE_DIRECTORY ${NUTTX_BOARD_DIR}/resource/rlottie)
    file(COPY_FILE rlottie/example/resource/mask.json
         ${NUTTX_BOARD_DIR}/resource/rlottie)

    list(APPEND CXXFLAGS -Wno-unused-but-set-variable)

    list(APPEND INCDIR ${LIBRLOTTIE_DIR}/src/test)

    set(DEFINITOINS DEMO_DIR=\"/resource/rlottie\")

    nuttx_add_application(
      NAME
      gtest_rlottie
      SRCS
      rlottie/test/testsuite.cpp
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CXXFLAGS}
      STACKSIZE
      ${CONFIG_LOTTIE_TEST_STACKSIZE}
      PRIORITY
      ${CONFIG_LOTTIE_TEST_PRIORITY}
      MODULE
      ${CONFIG_LOTTIE_TEST}
      DEFINITIONS
      ${DEFINITOINS}
      DEPENDS
      librlottie)
  endif()
endif()
