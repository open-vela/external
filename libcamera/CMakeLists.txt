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

if(CONFIG_LIB_CAMERA)
  nuttx_add_library(libcamera STATIC)

  # ############################################################################
  # Include Directory
  # ############################################################################

  set (INCDIR ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/libcamera/include)

  if(CONFIG_LIB_YAML)
    list(APPEND INCDIR ${NUTTX_APPS_DIR}/external/yaml/yaml/include/)
  endif()

  # ############################################################################
  # Sources
  # ############################################################################
  set(LOCAL_CSRCS)
  file(GLOB LOCAL_CSRCS
    ${CMAKE_CURRENT_LIST_DIR}/src/libcamera/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/base/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/pipeline/vela/*.cpp
  )

  file(GLOB IPA_CPP_FILES
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/ipa*.cpp
  )

  list(REMOVE_ITEM LOCAL_CSRCS
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/device_enumerator_udev.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/dma_buf_allocator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/src/libcamera/source_paths.cpp
    ${IPA_CPP_FILES}
  )

  target_sources(libcamera PRIVATE ${LOCAL_CSRCS})
  target_compile_definitions(libcamera PRIVATE LIBCAMERA_BASE_PRIVATE
                                               HAVE_MEMFD_CREATE
                                               LIBCAMERA_DATA_DIR="/data"
                                               YAML_VERSION_MAJOR=0
                                               YAML_VERSION_MINOR=2
                                               YAML_VERSION_PATCH=5
                                               YAML_VERSION_STRING="0.2.5")


  target_include_directories(libcamera PRIVATE ${INCDIR})

  nuttx_add_application(
    NAME
    libcamera_app
    SRCS
    main.cpp
    STACKSIZE
    32768
    INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/libcamera/include
    DEPENDS
    libcamera)
endif()

