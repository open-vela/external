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

if(CONFIG_PROTOBUF_C)
  file(GLOB CSRCS protobuf-c/protobuf-c/*.c)
  nuttx_add_library(protobuf-c STATIC)
  target_sources(protobuf-c PRIVATE ${CSRCS})
  target_include_directories(protobuf-c PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/protobuf-c/
  )
  target_link_libraries(apps protobuf-c)
endif()
