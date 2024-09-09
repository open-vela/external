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

if(CONFIG_LIB_CMARK_GFM)

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(cmark-static)
  set(CFLAGS -DCMARK_DEBUG_NODES=0)

  file(GLOB CSRCS cmark-gfm/src/*.c)
  file(GLOB ECSRCS cmark-gfm/extensions/*.c)
  list(REMOVE_ITEM CSRCS ${CMAKE_CURRENT_LIST_DIR}/cmark-gfm/src/main.c)
  target_sources(cmark-static PRIVATE ${CSRCS} ${ECSRCS})

  target_include_directories(cmark-static PRIVATE ./ ./cmark-gfm/extensions
                                                  ./cmark-gfm/src)
endif()
