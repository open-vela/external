# ##############################################################################
# external/socat/CMakeLists.txt
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

if(CONFIG_UTILS_SOCAT)

  set(SOCAT_FLAGS
      -Wno-undef
      -Wno-shadow
      -Wno-unused-function
      -Wno-builtin-declaration-mismatch
      -Wno-format
      -Wno-unused-variable
      -Wno-parentheses
      -Wno-implicit-function-declaration)

  nuttx_add_application(
    NAME
    socat
    SRCS
    socat/socat.c
    INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_LIST_DIR}/socat
    COMPILE_FLAGS
    ${SOCAT_FLAGS}
    STACKSIZE
    ${CONFIG_UTILS_SOCAT_STACKSIZE}
    PRIORITY
    ${CONFIG_UTILS_SOCAT_PRIORITY})

  file(GLOB TOOL_SRCS socat/*.c)
  list(REMOVE_ITEM TOOL_SRCS
       ${CMAKE_CURRENT_LIST_DIR}/socat/socat.c
       ${CMAKE_CURRENT_LIST_DIR}/socat/filan_main.c
       ${CMAKE_CURRENT_LIST_DIR}/socat/procan_main.c
       ${CMAKE_CURRENT_LIST_DIR}/socat/procan-cdefs.c
       ${CMAKE_CURRENT_LIST_DIR}/socat/procan.c
       ${CMAKE_CURRENT_LIST_DIR}/socat/hostan.c)

  target_sources(socat PRIVATE ${TOOL_SRCS})

  target_include_directories(socat PRIVATE ${SOCAT_INCDIR})
  target_compile_options(socat PRIVATE ${SOCAT_FLAGS})

endif()
