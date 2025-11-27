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

if(CONFIG_LIB_YAML)
  nuttx_add_library(libyaml STATIC)

  set (YAML_VERSION_MAJOR 0)
  set (YAML_VERSION_MINOR 2)
  set (YAML_VERSION_PATCH 5)
  set (YAML_VERSION_STRING "${YAML_VERSION_MAJOR}.${YAML_VERSION_MINOR}.${YAML_VERSION_PATCH}")

  set (INCDIR ${CMAKE_CURRENT_LIST_DIR}/libyaml/include)

  set(SRCS
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/api.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/dumper.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/emitter.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/loader.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/parser.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/reader.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/scanner.c
    ${CMAKE_CURRENT_LIST_DIR}/libyaml/src/writer.c
    )

  target_sources(libyaml PRIVATE ${SRCS})

  target_compile_definitions(libyaml PRIVATE
    YAML_VERSION_MAJOR=${YAML_VERSION_MAJOR}
    YAML_VERSION_MINOR=${YAML_VERSION_MINOR}
    YAML_VERSION_PATCH=${YAML_VERSION_PATCH}
    YAML_VERSION_STRING="${YAML_VERSION_STRING}"
    )


  target_include_directories(libyaml PRIVATE ${INCDIR})
endif()
