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
if(CONFIG_LIB_THORVG)

  set(LIBTHORVG_DIR ${CMAKE_CURRENT_LIST_DIR}/thorvg)

  set(CXXFLAGS -Wno-shadow -Wno-unused-but-set-variable)

  file(
    GLOB
    CXXSRCS
    ${LIBTHORVG_DIR}/src/common/*.cpp
    ${LIBTHORVG_DIR}/src/bindings/capi/*.cpp
    ${LIBTHORVG_DIR}/src/renderer/*.cpp
    ${LIBTHORVG_DIR}/src/loaders/raw/*.cpp
    ${LIBTHORVG_DIR}/src/renderer/sw_engine/*.cpp)

  nuttx_add_library(thorvg STATIC)
  target_include_directories(
    thorvg
    PRIVATE ${LIBTHORVG_DIR}/inc
            ${LIBTHORVG_DIR}/src/common
            ${LIBTHORVG_DIR}/src/bindings/capi
            ${LIBTHORVG_DIR}/src/renderer
            ${LIBTHORVG_DIR}/src/loaders/raw
            ${LIBTHORVG_DIR}/src/renderer/sw_engine)

  if(CONFIG_THORVG_JPG_LOADER_SUPPORT)
    file(GLOB JPG_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/jpg/*.cpp)
    list(APPEND CXXSRCS ${JPG_LOADER_CXXSRCS})
    target_include_directories(thorvg PRIVATE ${LIBTHORVG_DIR}/src/loaders/jpg)
  endif()

  if(CONFIG_THORVG_LOTTIE_LOADER_SUPPORT)
    file(GLOB LOTTIE_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/lottie/*.cpp)
    list(APPEND CXXSRCS ${LOTTIE_LOADER_CXXSRCS})
    target_include_directories(thorvg
                               PRIVATE ${LIBTHORVG_DIR}/src/loaders/lottie)
  endif()

  if(CONFIG_THORVG_PNG_LOADER_SUPPORT)
    file(GLOB PNG_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/png/*.cpp)
    list(APPEND CXXSRCS ${PNG_LOADER_CXXSRCS})
    target_include_directories(thorvg PRIVATE ${LIBTHORVG_DIR}/src/loaders/png)
  endif()

  if(CONFIG_THORVG_SVG_LOADER_SUPPORT)
    file(GLOB SVG_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/svg/*.cpp)
    list(APPEND CXXSRCS ${SVG_LOADER_CXXSRCS})
    target_include_directories(thorvg PRIVATE ${LIBTHORVG_DIR}/src/loaders/svg)
  endif()

  if(CONFIG_THORVG_TVG_LOADER_SUPPORT)
    file(GLOB TVG_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/tvg/*.cpp)
    list(APPEND CXXSRCS ${TVG_LOADER_CXXSRCS})
    target_include_directories(thorvg PRIVATE ${LIBTHORVG_DIR}/src/loaders/tvg)
  endif()

  if(CONFIG_THORVG_TTF_LOADER_SUPPORT)
    file(GLOB TTF_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/ttf/*.cpp)
    list(APPEND CXXSRCS ${TTF_LOADER_CXXSRCS})
    target_include_directories(thorvg PRIVATE ${LIBTHORVG_DIR}/src/loaders/ttf)
  endif()

  if(CONFIG_THORVG_WEBP_LOADER_SUPPORT)
    file(GLOB WEBP_LOADER_CXXSRCS ${LIBTHORVG_DIR}/src/loaders/webp/*.cpp)
    list(APPEND CXXSRCS ${WEBP_LOADER_CXXSRCS})
    target_include_directories(thorvg PRIVATE ${LIBTHORVG_DIR}/src/loaders/webp)
  endif()

  set(INCDIR ${LIBTHORVG_DIR}/inc)
  set(CAPI_INCDIR ${LIBTHORVG_DIR}/src/bindings/capi)

  target_compile_options(thorvg PRIVATE ${CXXFLAGS})
  target_sources(thorvg PRIVATE ${CXXSRCS})
  target_include_directories(thorvg PRIVATE ./)
  nuttx_export_header(TARGET thorvg INCLUDE_DIRECTORIES ${INCDIR}
                      ${CAPI_INCDIR})
endif()
