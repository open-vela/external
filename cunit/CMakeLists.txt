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

if(CONFIG_LIB_CUNIT)

  set(CUNIT_INCDIR ${CMAKE_CURRENT_LIST_DIR}/cunit/CUnit)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CUNIT_INCDIR})

  set(CUNIT_DISABLE_TESTS
      OFF
      CACHE BOOL "Disable tests" FORCE)

  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cunit
                   ${CMAKE_CURRENT_BINARY_DIR}/cunit EXCLUDE_FROM_ALL)

  nuttx_add_external_library(cunit)

endif()
