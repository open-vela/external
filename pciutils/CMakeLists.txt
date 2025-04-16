# ##############################################################################
# external/pciutils/CMakeLists.txt
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

if(CONFIG_PCIUTILS)

  set(PCIUTILS_FLAGS -Wno-shadow -Wno-parentheses
                     $<$<COMPILE_LANGUAGE:C>:-Wno-strict-prototypes>)

  set(PCIUTILS_INCDIR . pciutils pciutils/include ${CMAKE_BINARY_DIR}/include)

  # common sources

  list(
    APPEND
    CMN_SRCS
    pciutils/common.c
    pciutils/lib/access.c
    pciutils/lib/caps.c
    pciutils/lib/dump.c
    pciutils/lib/filter.c
    pciutils/lib/generic.c
    pciutils/lib/init.c
    pciutils/lib/names.c
    pciutils/lib/names-cache.c
    pciutils/lib/names-hash.c
    pciutils/lib/names-hwdb.c
    pciutils/lib/names-net.c
    pciutils/lib/names-parse.c
    pciutils/lib/obsd-device.c
    pciutils/lib/params.c
    pciutils/lib/mmio-ports.c
    pciutils/lmr/margin.c
    pciutils/lmr/margin_hw.c
    pciutils/lmr/margin_log.c
    pciutils/lmr/margin_results.c
    pciutils/ls-caps.c
    pciutils/ls-caps-vendor.c
    pciutils/ls-ecaps.c
    pciutils/ls-kernel.c
    pciutils/ls-map.c
    pciutils/ls-tree.c
    pciutils/ls-vpd.c)

  nuttx_library(pciutils)
  nuttx_sources(${CMN_SRCS})
  nuttx_include_directories(${PCIUTILS_INCDIR})
  nuttx_compile_options(${PCIUTILS_FLAGS})

  # lspci command

  nuttx_add_application(
    NAME
    lspci
    SRCS
    pciutils/lspci.c
    INCLUDE_DIRECTORIES
    ${PCIUTILS_INCDIR}
    COMPILE_FLAGS
    ${PCIUTILS_FLAGS}
    STACKSIZE
    ${CONFIG_PCIUTILS_STACKSIZE}
    PRIORITY
    ${CONFIG_PCIUTILS_PRIORITY}
    DEPENDS
    pciutils)

  # setpci command

  nuttx_add_application(
    NAME
    setpci
    SRCS
    pciutils/setpci.c
    INCLUDE_DIRECTORIES
    ${PCIUTILS_INCDIR}
    COMPILE_FLAGS
    ${PCIUTILS_FLAGS}
    STACKSIZE
    ${CONFIG_PCIUTILS_STACKSIZE}
    PRIORITY
    ${CONFIG_PCIUTILS_PRIORITY}
    DEPENDS
    pciutils)

  # pcilmr command

  nuttx_add_application(
    NAME
    pcilmr
    SRCS
    pciutils/pcilmr.c
    INCLUDE_DIRECTORIES
    ${PCIUTILS_INCDIR}
    COMPILE_FLAGS
    ${PCIUTILS_FLAGS}
    STACKSIZE
    ${CONFIG_PCIUTILS_STACKSIZE}
    PRIORITY
    ${CONFIG_PCIUTILS_PRIORITY}
    DEPENDS
    pciutils)

endif()
