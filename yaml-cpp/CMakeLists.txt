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
if(CONFIG_LIB_YAMLCPP)
  set(LIBYAMLCPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/yaml-cpp)

  nuttx_add_library(libyamlcpp STATIC)

  set(CXXFLAGS -Wno-unused-variable -Wno-sign-compare -Wno-shadow
               -Wno-range-loop-construct -fno-var-tracking-assignments)

  set(INCDIR ${LIBYAMLCPP_DIR}/include ${LIBYAMLCPP_DIR}/src)
  file(GLOB CXXSRCS ${LIBYAMLCPP_DIR}/src/*.cpp
       ${LIBYAMLCPP_DIR}/src/contrib/*.cpp)

  if(CONFIG_LIB_YAMLCPP_TESTCASE)
    list(APPEND INCDIR ${LIBYAMLCPP_DIR}/test)
    nuttx_add_application(
      NAME
      yaml_cpp_test
      SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/yaml_cpp_test.cpp
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${CXXFLAGS}
      DEPENDS
      libyamlcpp)
  endif()

  target_sources(libyamlcpp PRIVATE ${CXXSRCS})
  target_compile_options(libyamlcpp PRIVATE ${CXXFLAGS})
  target_include_directories(libyamlcpp PRIVATE ${INCDIR})
endif()
