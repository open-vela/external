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

# Enable Config
if(CONFIG_LIB_BOX2D)

  set(LIBBOX2D_DIR ${CMAKE_CURRENT_LIST_DIR}/box2d)

  set(CFLAGS -Wno-shadow -Wno-undef)
  set(CXXFLAGS -Wno-shadow -Wno-unused-but-set-variable)

  file(GLOB_RECURSE CXXSRCS ${LIBBOX2D_DIR}/src/*.cpp)

  set(INCDIR ${LIBBOX2D_DIR}/include ${LIBBOX2D_DIR}/src)

  nuttx_add_library(libbox2d STATIC)
  target_compile_options(libbox2d PRIVATE ${CFLAGS}) #
  target_compile_options(libbox2d PRIVATE ${CXXFLAGS}) #
  target_sources(libbox2d PRIVATE ${CXXSRCS})
  target_include_directories(libbox2d PRIVATE ${INCDIR})
  nuttx_export_header(TARGET libbox2d INCLUDE_DIRECTORIES
                      ${LIBBOX2D_DIR}/include)
endif()
