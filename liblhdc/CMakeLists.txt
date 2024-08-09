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

if(CONFIG_LIB_LHDC)

  set(LIB_SRC_PATH ${CMAKE_CURRENT_LIST_DIR}/liblhdc/libs)

  if(${CONFIG_ARCH} STREQUAL "sim")
    nuttx_add_extra_library(${LIB_SRC_PATH}/x86/lhdcv4_dec/liblhdcDec_x86.a
                            ${LIB_SRC_PATH}/x86/lhdcv5_dec/liblhdcv5dec_x86.a)

  elseif(${CONFIG_ARCH} STREQUAL "arm")
    nuttx_add_extra_library(${LIB_SRC_PATH}/arm32/lhdcv4_dec/liblhdc-dec_arm.a
                            ${LIB_SRC_PATH}/arm32/lhdcv5_dec/liblhdcv5dec_arm.a)
  endif()

endif()
