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
if(CONFIG_LIB_HARFBUZZ)

  set(HARFBUZZ_DIR ${NUTTX_APPS_DIR}/external/harfbuzz/harfbuzz)

  set(HARFBUZZ_SRCS ${HARFBUZZ_DIR}/src/harfbuzz.cc)

  nuttx_add_library(harfbuzz)

  target_compile_definitions(harfbuzz PRIVATE
    -DHAVE_FREETYPE=1
    -DHB_OPTIMIZE_SIZE=1
    -DHB_OPTIMIZE_SIZE_MORE=1
    -DHB_MINIMIZE_MEMORY_USAGE=1
    -DHB_NO_MT=1
    -DHB_NO_UCD_UNASSIGNED=1
    -DNDEBUG=1
    -DHB_DISABLE_DEPRECATED=1
    -DHB_NDEBUG=1
    -DHB_NO_ATEXIT=1
    -DHB_NO_BUFFER_MESSAGE=1
    -DHB_NO_BUFFER_SERIALIZE=1
    -DHB_NO_BUFFER_VERIFY=1
    -DHB_NO_BITMAP=1
    -DHB_NO_COLOR=1
    -DHB_NO_ERRNO=1
    -DHB_NO_FACE_COLLECT_UNICODES=1
    -DHB_NO_GETENV=1
    -DHB_NO_HINTING=1
    -DHB_NO_LANGUAGE_LONG=1
    -DHB_NO_LANGUAGE_PRIVATE_SUBTAG=1
    -DHB_NO_LAYOUT_COLLECT_GLYPHS=1
    -DHB_NO_LAYOUT_RARELY_USED=1
    -DHB_NO_LAYOUT_UNUSED=1
    -DHB_NO_MATH=1
    -DHB_NO_META=1
    -DHB_NO_METRICS=1
    -DHB_NO_MMAP=1
    -DHB_NO_NAME=1
    -DHB_NO_OPEN=1
    -DHB_NO_OT_FONT_GLYPH_NAMES=1
    -DHB_NO_OT_SHAPE_FRACTIONS=1
    -DHB_NO_PAINT=1
    -DHB_NO_SETLOCALE=1
    -DHB_NO_SUBSET_LAYOUT=1
    -DHB_NO_VERTICAL=1
    -DHB_NO_AAT=1
    -DHB_NO_LEGACY=1
    -DHB_NO_BORING_EXPANSION=1
  )

  target_compile_options(harfbuzz PRIVATE
    -Wno-shadow
    -Wno-sign-compare
    -Wno-format
    -Wno-nonnull
    -Wno-format-signedness
    -Wno-format-truncation
    -Os
  )

  target_sources(harfbuzz PRIVATE ${HARFBUZZ_SRCS})

endif()
