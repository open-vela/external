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
if(CONFIG_LIB_FFMPEG)

  # call origin build system to generate libffmpeg
  nuttx_call_apps_makefile(TARGET ffmpeg TARGET_BIN libffmpeg.a)

  # only do register in cmake
  macro(register_ffmpeg_app PROG)
    nuttx_add_application(
      NAME ${PROG} STACKSIZE ${CONFIG_UTILS_FFMPEG_STACKSIZE} PRIORITY
      ${CONFIG_UTILS_FFMPEG_PRIORITY})
  endmacro()

  string(FIND "${CONFIG_LIB_FFMPEG_CONFIGURATION}" "--enable-ffmpeg"
              ffmpeg_position)
  string(FIND "${CONFIG_LIB_FFMPEG_CONFIGURATION}" "--enable-ffprobe"
              ffprobe_position)

  if(NOT ffmpeg_position EQUAL -1)
    register_ffmpeg_app(ffmpeg)
  endif()
  if(NOT ffprobe_position EQUAL -1)
    register_ffmpeg_app(ffprobe)
  endif()

  if(CONFIG_FFMPEG_UTILS_GRAPH2DOT)
    register_ffmpeg_app(graph2dot)
  endif()

  if(CONFIG_LIB_FFMPEG_TEST)
    register_ffmpeg_app(ffmpeg_api_band)
    register_ffmpeg_app(ffmpeg_api_flac)
    register_ffmpeg_app(ffmpeg_api_h264_slice)
    register_ffmpeg_app(ffmpeg_api_h264)
    register_ffmpeg_app(ffmpeg_api_seek)
    register_ffmpeg_app(ffmpeg_api_threadmessage)
    register_ffmpeg_app(ffmpeg_fft)
  endif()

endif()
