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

if(CONFIG_LIB_LC3)

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB CSRCS lc3/src/*.c)

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/lc3/include)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(lc3 STATIC)
  target_sources(lc3 PRIVATE ${CSRCS})
  target_include_directories(lc3 PUBLIC ${INCDIR})

endif()
