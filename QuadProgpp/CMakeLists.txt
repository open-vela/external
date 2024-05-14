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
if(CONFIG_LIB_QUADPROGPP)
  set(LIBQUADPROGPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/QuadProgpp)

  nuttx_add_library(libquadprogpp STATIC)

  set(CXXFLAGS -Wno-shadow -Wno-return-type)

  target_sources(libquadprogpp PRIVATE ${LIBQUADPROGPP_DIR}/src/Array.cc
                                       ${LIBQUADPROGPP_DIR}/src/QuadProg++.cc)
  target_compile_options(libquadprogpp PRIVATE ${CXXFLAGS})

  if(CONFIG_LIB_QUADPROGPP_TESTCASE)
    nuttx_add_application(
      NAME
      QuadProgpp
      SRCS
      ${LIBQUADPROGPP_DIR}/src/main.cc
      COMPILE_FLAGS
      ${CXXFLAGS}
      DEPENDS
      libquadprogpp)
  endif()

endif()
