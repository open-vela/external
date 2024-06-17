#
# Copyright (C) 2021 Xiaomi Corporation
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
if(CONFIG_LIB_GOOGLETEST)
  set(GTEST_DIR ${CMAKE_CURRENT_LIST_DIR}/googletest/googletest)
  set(GMOCK_DIR ${CMAKE_CURRENT_LIST_DIR}/googletest/googlemock)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_CXX_INCLUDE_DIRECTORIES ${GTEST_DIR}/include
             ${GMOCK_DIR}/include)

  nuttx_add_library(googletest STATIC)

  set(CXXFLAGS -DGTEST_HAS_POSIX_RE=0 -Wno-maybe-uninitialized
               -Wno-array-bounds -Wno-alloc-size-larger-than)

  set(INCDIR ${GTEST_DIR} ${GMOCK_DIR})
  target_sources(googletest PRIVATE ${GTEST_DIR}/src/gtest-all.cc
                                    ${GMOCK_DIR}/src/gmock-all.cc)
  target_compile_options(googletest PRIVATE ${CXXFLAGS})
  target_include_directories(googletest PRIVATE ${INCDIR})

  if(CONFIG_UTILS_GTEST)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_GOOGLETEST}
      NAME
      ${CONFIG_UTILS_GTEST_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_GTEST_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_GTEST_PRIORITY}
      SRCS
      ${GTEST_DIR}/src/gtest_main.cc
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CXXFLAGS}
      DEPENDS
      googletest)
  endif()

  if(CONFIG_UTILS_GMOCK)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_GOOGLETEST}
      NAME
      ${CONFIG_UTILS_GMOCK_PROGNAME}
      STACKSIZE
      ${CONFIG_UTILS_GMOCK_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_GMOCK_PRIORITY}
      SRCS
      ${GMOCK_DIR}/src/gmock_main.cc
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CXXFLAGS}
      DEPENDS
      googletest)
  endif()

endif()
