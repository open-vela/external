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

if(CONFIG_LIB_YOGA)

  set(LIBYOGA_DIR ${CMAKE_CURRENT_LIST_DIR}/yoga)

  # ############################################################################
  # Flags
  # ############################################################################

  set(CFLAGS -Wno-shadow -std=c++11)

  if(${GCCVER} NOT EQUAL 13)
    list(APPEND CFLAGS -Wno-array-bounds)
  endif()

  # ############################################################################
  # Sources
  # ############################################################################

  file(GLOB CXXSRCS ${LIBYOGA_DIR}/yoga/*.cpp ${LIBYOGA_DIR}/yoga/event/*.cpp
       ${LIBYOGA_DIR}/yoga/internal/*.cpp)

  # ############################################################################
  # Include Directory
  # ############################################################################

  set(INCDIR ${LIBYOGA_DIR})

  # ############################################################################
  # Library Configuration
  # ############################################################################

  nuttx_add_library(libyoga STATIC)
  target_sources(libyoga PRIVATE ${CXXSRCS})
  target_include_directories(libyoga PRIVATE ${INCDIR})
  target_compile_options(libyoga PRIVATE ${CFLAGS})
  nuttx_export_header(TARGET libyoga INCLUDE_DIRECTORIES ${INCDIR})

endif()
