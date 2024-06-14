#
# Copyright (C) 2023 Xiaomi Corporation
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

if(CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD OR CONFIG_OPTEE_EXAMPLES_TA_HELLOWORLD)
  if(CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD)
    nuttx_add_application(
      NAME
      ${CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD_PROGNAME}
      STACKSIZE
      ${CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD_STACKSIZE}
      PRIORITY
      ${CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD_PRIORITY}
      SRCS
      optee_examples/hello_world/host/main.c
      INCLUDE_DIRECTORIES
      ${CMAKE_CURRENT_LIST_DIR}/optee_examples/hello_world/ta/include)
  endif()
  if(CONFIG_OPTEE_EXAMPLES_TA_HELLOWORLD)
    nuttx_add_library(ta_example)
    target_sources(
      ta_example
      PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/optee_examples/hello_world/ta/hello_world_ta.c
    )
    target_compile_definitions(ta_example
                               PRIVATE HELLO_WORLD_TA_NAME=\"hello_world.ta\")
    target_include_directories(
      ta_example
      PRIVATE
        ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/lib/libutee/include
        ${NUTTX_APPS_DIR}/external/optee/optee_os/optee_os/lib/libutils/ext/include
        ${CMAKE_CURRENT_SOURCE_DIR}/optee_examples/hello_world/ta/include)
  endif()
endif()
