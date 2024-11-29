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

if(CONFIG_RILD)
  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/ril/include)

  file(GLOB LIBRIL_SRCS "ril/libril/*.cpp")
  file(GLOB RIL_UTILS_SRCS "ril/librilutils/*.c")
  set(RILD_SRCS ${LIBRIL_SRCS} ${RIL_UTILS_SRCS})
  set(RILD_INC ${CMAKE_CURRENT_LIST_DIR}/ril/libril
               ${CMAKE_CURRENT_LIST_DIR}/ril/librilutils)

  if(CONFIG_GOLDFISH_RIL)
    set(TEMP_FILE "${CMAKE_BINARY_DIR}/advancedFeatures.ini")

    add_custom_command(
      OUTPUT ${TEMP_FILE}
      COMMAND
        ${CMAKE_COMMAND} -E echo "ModemSimulator = on" > ${TEMP_FILE}
      COMMENT "advancedFeatures.ini"
      VERBATIM
    )

    add_custom_target(generate_temp_file ALL DEPENDS ${TEMP_FILE})

    file(GLOB APPEND_FILES ${CMAKE_CURRENT_LIST_DIR}/ril/reference-ril/*.c)
    list(APPEND RILD_SRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${CMAKE_CURRENT_LIST_DIR}/ril/reference-ril)
    list(APPEND RILD_INC ${APPEND_FILES})
  endif()

  nuttx_add_application(
    MODULE
    ${CONFIG_RILD}
    NAME
    rild
    STACKSIZE
    ${CONFIG_RILD_STACKSIZE}
    PRIORITY
    ${CONFIG_RILD_PRIORITY}
    SRCS
    ril/rild/rild.c ${RILD_SRCS}
    INCLUDE_DIRECTORIES
    ${RILD_INC}
  )
endif()
