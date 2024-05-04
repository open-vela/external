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
if(CONFIG_LIB_JSONC)

  file(GLOB CSRCS ${CMAKE_CURRENT_LIST_DIR}/json-c/*.c)
  nuttx_add_library(jsonc STATIC)
  target_sources(jsonc PRIVATE ${CSRCS})
  target_include_directories(jsonc PRIVATE ${CMAKE_CURRENT_LIST_DIR})

endif()
