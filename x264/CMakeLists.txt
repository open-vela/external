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

if(CONFIG_LIB_X264)

  # ############################################################################
  # Configuration
  # ############################################################################

  # call origin build system to generate libx264
  nuttx_call_apps_makefile(TARGET x264 TARGET_BIN libx264.a)

    # only do register in cmake
  macro(register_x264_app PROG)
    nuttx_add_application(
      NAME ${PROG} STACKSIZE ${CONFIG_UTILS_X264_STACKSIZE} PRIORITY
      ${CONFIG_UTILS_X264_PRIORITY})
  endmacro()

  string(FIND "${CONFIG_UTILS_X264}" "y" x264_position)

  if(NOT x264_position EQUAL -1)
    register_x264_app(x264)
  endif()

endif()

