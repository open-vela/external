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

if(CONFIG_LIB_CURL)

  set(CURL_FLAGS
      -DHAVE_CONFIG_H
      -DMAXINFO=256
      -DBUFFSIZE=64
      -DMAX_PARAMETERS=16
      -Dconfig_init=curl_config_init
      -Dconfig_free=curl_config_free
      -Dstr2num=curl_str2num)

  set(CURL_INCDIR
      ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/curl/lib
      ${CMAKE_CURRENT_LIST_DIR}/curl/src ${NUTTX_APPS_DIR}/system/zlib/zlib)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/curl/include)

  nuttx_add_library(curl)

  file(GLOB CURL_SRCS curl/lib/*.c curl/lib/vauth/*.c curl/lib/vquic/*.c
       curl/lib/vtls/*.c)

  if(CONFIG_UTILS_CURL)
    set(HELP_C ${CMAKE_CURRENT_BINARY_DIR}/curl/tool_listhelp.c)

    add_custom_command(
      OUTPUT ${HELP_C}
      COMMAND ${CMAKE_COMMAND} -E make_directory
              ${CMAKE_CURRENT_BINARY_DIR}/curl
      COMMAND
        grep -r "Category" ${CMAKE_CURRENT_LIST_DIR}/curl/docs/cmdline-opts/ |
        grep "important" | cut -d ":" -f 1 | xargs
        ${CMAKE_CURRENT_LIST_DIR}/curl/docs/cmdline-opts/gen.pl listhelp >
        ${HELP_C}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Generating help.c from .d files"
      VERBATIM)
    add_custom_target(
      gen_help_c ALL
      DEPENDS ${HELP_C}
      COMMENT "Custom target for help.c")
    add_dependencies(curl gen_help_c)

    file(GLOB TOOL_SRCS curl/src/*.c)
    list(REMOVE_ITEM TOOL_SRCS
         ${CMAKE_CURRENT_LIST_DIR}/curl/src/tool_listhelp.c
         ${CMAKE_CURRENT_LIST_DIR}/curl/src/tool_main.c)
    list(APPEND CURL_SRCS ${HELP_C} ${TOOL_SRCS})

    nuttx_add_application(
      NAME
      ${CONFIG_UTILS_CURL_PROGNAME}
      SRCS
      curl/src/tool_main.c
      INCLUDE_DIRECTORIES
      ${CURL_INCDIR}
      COMPILE_FLAGS
      ${CURL_FLAGS}
      PRIORITY
      ${CONFIG_UTILS_CURL_PRIORITY}
      STACKSIZE
      ${CONFIG_UTILS_CURL_STACKSIZE}
      DEPENDS
      curl)
  endif()

  target_include_directories(curl PRIVATE ${CURL_INCDIR})
  target_compile_options(curl PRIVATE ${CURL_FLAGS})
  target_sources(curl PRIVATE ${CURL_SRCS})

endif()
