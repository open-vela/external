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

  nuttx_compile_options_for_all_apps(-D_RIVE_INTERNAL_=1)

  if(CONFIG_LIB_HARFBUZZ AND CONFIG_LIB_SHEENBIDI)
    nuttx_compile_options_for_all_apps(-DWITH_RIVE_TEXT=1)
    nuttx_compile_options_for_all_apps(-D_RIVE_INTERNAL_=1)

    target_include_directories(rive-runtime PRIVATE
        ${NUTTX_APPS_DIR}/external/SheenBidi/SheenBidi/Headers
        ${NUTTX_APPS_DIR}/external/harfbuzz/harfbuzz/src
      )
  endif()

  if(CONFIG_VG_ANIMATION_VIEW_AUDIO)
    nuttx_compile_options_for_all_apps(-DWITH_RIVE_AUDIO=1)
    nuttx_compile_options_for_all_apps(-DEXTERNAL_RIVE_AUDIO_ENGINE=1)
    nuttx_compile_options_for_all_apps(-DWITH_CUSTOM_RIVE_AUDIO=1)

    set(AUDIO_SRCS
      ${RIVE_RUNTIME_DIR}/src/audio/audio_source.cpp
      ${RIVE_RUNTIME_DIR}/src/audio/audio_engine.cpp
      ${RIVE_RUNTIME_DIR}/src/audio/audio_sound.cpp
      ${RIVE_RUNTIME_DIR}/src/audio/audio_reader.cpp)
    list(REMOVE_ITEM RIVE_SRCS ${AUDIO_SRCS})

    target_include_directories(rive-runtime PRIVATE
    ${NUTTX_APPS_DIR}/frameworks/graphics/animengine/rive/audio
    )
  endif()

  if(CONFIG_SCHED_INSTRUMENTATION AND CONFIG_RIVE_RUNTIME_PROFILER)
  target_compile_definitions(
    rive-runtime
    PRIVATE
      "RIVE_RUNTIME_PROFILER_BEGIN=sched_note_begin(NOTE_TAG_GRAPHICS)")
  target_compile_definitions(
    rive-runtime
    PRIVATE "RIVE_RUNTIME_PROFILER_END=sched_note_end(NOTE_TAG_GRAPHICS)")

  # ##########################################################################
  set(RIVE_PROFILER_TAG_DEF
      [=[
#define RIVE_RUNTIME_PROFILER_BEGINEX(str) sched_note_beginex(NOTE_TAG_GRAPHICS, str)
#define RIVE_RUNTIME_PROFILER_ENDEX(str) sched_note_endex(NOTE_TAG_GRAPHICS, str)
    ]=])

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/def_rive_profiler.h
       "${RIVE_PROFILER_TAG_DEF}")
  target_compile_options(
    rive-runtime PRIVATE -include "${CMAKE_CURRENT_BINARY_DIR}/def_rive_profiler.h")
  # ##########################################################################

  endif()


if(CONFIG_RIVE_RUNTIME_LAYOUT)
  nuttx_compile_options_for_all_apps(-DWITH_RIVE_LAYOUT=1)
  target_include_directories(rive-runtime PRIVATE
    ${NUTTX_APPS_DIR}/external/yoga/yoga)
endif()


set_source_files_properties(
  ${RIVE_RUNTIME_DIR}/src/math/aabb.cpp
  ${RIVE_RUNTIME_DIR}/src/math/bezier_utils.cpp
  ${RIVE_RUNTIME_DIR}/src/math/bit_field_loc.cpp
  ${RIVE_RUNTIME_DIR}/src/math/contour_measure.cpp
  ${RIVE_RUNTIME_DIR}/src/math/hit_test.cpp
  ${RIVE_RUNTIME_DIR}/src/math/mat2d_find_max_scale.cpp
  ${RIVE_RUNTIME_DIR}/src/math/mat2d.cpp
  ${RIVE_RUNTIME_DIR}/src/math/n_slicer_helpers.cpp
  ${RIVE_RUNTIME_DIR}/src/math/path_measure.cpp
  ${RIVE_RUNTIME_DIR}/src/math/raw_path_utils.cpp
  ${RIVE_RUNTIME_DIR}/src/math/raw_path.cpp
  ${RIVE_RUNTIME_DIR}/src/math/rectangles_to_contour.cpp
  ${RIVE_RUNTIME_DIR}/src/math/vec2d.cpp
  ${RIVE_RUNTIME_DIR}/src/shapes/paint/color.cpp
    PROPERTIES COMPILE_FLAGS "-O3"
)

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
