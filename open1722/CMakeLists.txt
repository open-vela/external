# ##############################################################################
# external/open1722/CMakeLists.txt
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

if(CONFIG_LIB_OPEN1722)

  nuttx_add_library(open1722)

  set(OPEN1722_INCDIR ${CMAKE_CURRENT_LIST_DIR}/nuttx
                      ${CMAKE_CURRENT_LIST_DIR}/open1722)
  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES
             ${CMAKE_CURRENT_LIST_DIR}/open1722/include)

  set(OPEN1722_FLAGS -D__linux__ -Wno-unused-variable -Wno-shadow
                     -Wno-unused-function)

  set(OPEN1722_SRCS
      argp.c
      open1722/src/avtp/Utils.c
      open1722/src/avtp/acf/FlexRay.c
      open1722/src/avtp/acf/SensorBrief.c
      open1722/src/avtp/acf/custom/Vss.c
      open1722/src/avtp/acf/custom/VssBrief.c
      open1722/src/avtp/acf/Lin.c
      open1722/src/avtp/acf/Sensor.c
      open1722/src/avtp/acf/Gpc.c
      open1722/src/avtp/acf/Tscf.c
      open1722/src/avtp/acf/Can.c
      open1722/src/avtp/acf/AcfCommon.c
      open1722/src/avtp/acf/CanBrief.c
      open1722/src/avtp/acf/Ntscf.c
      open1722/src/avtp/acf/Most.c
      open1722/src/avtp/CommonHeader.c
      open1722/src/avtp/Udp.c)

  if(CONFIG_UTILS_OPEN1722_ACF_CAN)
    list(APPEND OPEN1722_SRCS open1722/examples/common/common.c
         open1722/examples/acf-can/acf-can-common.c)
    nuttx_add_application(
      NAME
      acf_can_listener
      SRCS
      open1722/examples/acf-can/linux/acf-can-listener.c
      INCLUDE_DIRECTORIES
      ${OPEN1722_INCDIR}
      ${CMAKE_CURRENT_LIST_DIR}/open1722/examples
      ${CMAKE_CURRENT_LIST_DIR}/open1722/examples/acf-can
      COMPILE_FLAGS
      ${OPEN1722_FLAGS}
      STACKSIZE
      ${CONFIG_UTILS_OPEN1722_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_OPEN1722_PRIORITY})

    nuttx_add_application(
      NAME
      acf_can_talker
      SRCS
      open1722/examples/acf-can/linux/acf-can-talker.c
      INCLUDE_DIRECTORIES
      ${OPEN1722_INCDIR}
      ${CMAKE_CURRENT_LIST_DIR}/open1722/examples
      ${CMAKE_CURRENT_LIST_DIR}/open1722/examples/acf-can
      COMPILE_FLAGS
      ${OPEN1722_FLAGS}
      STACKSIZE
      ${CONFIG_UTILS_OPEN1722_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_OPEN1722_PRIORITY})
  endif()

  target_include_directories(open1722 PRIVATE ${OPEN1722_INCDIR})
  target_compile_options(open1722 PRIVATE ${OPEN1722_FLAGS})
  target_sources(open1722 PRIVATE ${OPEN1722_SRCS})

endif()
