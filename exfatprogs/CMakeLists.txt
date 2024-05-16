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
if(CONFIG_UTILS_EXFATPROGS)

  nuttx_add_library(exfatprogs STATIC)

  set(CSRCS exfatprogs/lib/libexfat.c)
  set(DEFINITIONS
      __le16=uint16_t
      __le32=uint32_t
      __le64=uint64_t
      __u8=uint8_t
      __u16=uint16_t
      __u32=uint32_t
      __u64=uint64_t)

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}
             ${CMAKE_CURRENT_LIST_DIR}/exfatprogs/include)

  macro(add_exfatprogs_app PROG MAIN)
    nuttx_add_application(
      MODULE
      ${CONFIG_UTILS_EXFATPROGS}
      NAME
      ${PROG}
      STACKSIZE
      ${CONFIG_UTILS_EXFATPROGS_STACKSIZE}
      PRIORITY
      ${CONFIG_UTILS_EXFATPROGS_PRIORITY}
      SRCS
      ${MAIN}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      DEFINITIONS
      ${DEFINITIONS}
      DEPENDS
      exfatprogs)
  endmacro()

  if(CONFIG_UTILS_EXFATPROGS_DUMP)
    add_exfatprogs_app(dumpexfat exfatprogs/dump/dump.c)
  endif()

  if(CONFIG_UTILS_EXFATPROGS_LABEL)
    add_exfatprogs_app(labelexfat exfatprogs/label/label.c)
  endif()

  if(CONFIG_UTILS_EXFATPROGS_TUNE)
    add_exfatprogs_app(tuneexfat exfatprogs/tune/tune.c)
  endif()

  if(CONFIG_UTILS_EXFATPROGS_FSCK)
    list(APPEND INCDIR ${CMAKE_CURRENT_LIST_DIR}/exfatprogs/fsck)
    list(APPEND CSRCS exfatprogs/fsck/repair.c exfatprogs/fsck/de_iter.c)
    add_exfatprogs_app(fsckexfat exfatprogs/fsck/fsck.c)
  endif()

  if(CONFIG_UTILS_EXFATPROGS_MKFS)
    list(APPEND INCDIR ${CMAKE_CURRENT_LIST_DIR}/exfatprogs/mkfs)
    list(APPEND CSRCS exfatprogs/mkfs/upcase.c exfatprogs/mkfs/mkfs.c)
    add_exfatprogs_app(mkfsexfat exfatprogs/mkfs/mkfs.c)
  endif()

  target_sources(exfatprogs PRIVATE ${CSRCS})
  target_compile_definitions(exfatprogs PRIVATE ${DEFINITIONS})
  target_include_directories(exfatprogs PRIVATE ${INCDIR})
endif()
