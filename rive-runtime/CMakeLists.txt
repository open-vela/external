#
# Copyright (C) 2024 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Enable Config
if(CONFIG_LIB_RIVE_RUNTIME)

  set(RIVE_RUNTIME_DIR ${NUTTX_APPS_DIR}/external/rive-runtime/rive-runtime)

  file(GLOB_RECURSE RIVE_SRCS
    ${RIVE_RUNTIME_DIR}/src/*.cpp
  )

  nuttx_add_library(rive-runtime STATIC)

  target_include_directories(rive-runtime PUBLIC
    ${RIVE_RUNTIME_DIR}/include
  )

  if(CONFIG_LIB_HARFBUZZ AND CONFIG_LIB_SHEENBIDI)
    nuttx_compile_options_for_all_apps(-DWITH_RIVE_TEXT=1)

    target_include_directories(rive-runtime PRIVATE
        ${NUTTX_APPS_DIR}/external/SheenBidi/SheenBidi/Headers
        ${NUTTX_APPS_DIR}/external/harfbuzz/harfbuzz/src
      )
  endif()

  target_compile_options(rive-runtime PRIVATE
    -Wno-shadow
    -Wno-sign-compare
    -Wno-class-memaccess
    -Wno-alloc-size-larger-than
    -Wno-format-security
    -Wno-format
    -Wno-nonnull
    -Wno-maybe-uninitialized
    -Wno-stringop-overflow
    -Wno-array-bounds
    -Os
  )

  target_sources(rive-runtime PRIVATE ${RIVE_SRCS})

endif()
