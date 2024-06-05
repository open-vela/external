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
if(CONFIG_LIB_RAPIDJSON)
  set(LIBRAPIDJSON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/rapidjson)

  set(CXXFLAGS
      -fexceptions
      -Wno-shadow
      -Wno-sign-compare
      -Wno-infinite-recursion
      -Wno-class-memaccess
      -Wno-deprecated-declarations
      -DRAPIDJSON_HAS_STDSTRING=1)
  set(INCDIR ${LIBRAPIDJSON_DIR}/include)
  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_CXX_INCLUDE_DIRECTORIES ${INCDIR})

  if(CONFIG_LIB_RAPIDJSON_TESTCASE)
    list(APPEND INCDIR ${LIBRAPIDJSON_DIR}/test/unittest)
    nuttx_add_application(
      NAME
      unittest
      SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/unittest.cpp
      COMPILE_FLAGS
      ${CXXFLAGS})
  endif()

endif()
