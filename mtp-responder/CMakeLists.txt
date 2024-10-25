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
if(CONFIG_MTP_RESPONDER)

  set(CSRCS mtp-responder/src/mtp_init.c mtp_port.c mtp_usb_driver_nuttx.c)

  set(FILT_OUT_SRCS
      ${CMAKE_CURRENT_LIST_DIR}/mtp-responder/src/mtp_init.c
      ${CMAKE_CURRENT_LIST_DIR}/mtp-responder/src/mtp_util_media_info.c
      ${CMAKE_CURRENT_LIST_DIR}/mtp-responder/src/mtp_usb_driver_ffs.c
      ${CMAKE_CURRENT_LIST_DIR}/mtp-responder/src/mtp_descs_strings.c)

  file(GLOB MTP_CSRCS mtp-responder/src/*.c)

  list(REMOVE_ITEM MTP_CSRCS ${FILT_OUT_SRCS})

  list(APPEND CSRCS ${MTP_CSRCS})

  set(CFLAGS
      -D__le16=uint16_t
      -D__le32=uint32_t
      -D__u16=uint16_t
      -DMSG_STAT=IPC_STAT
      -DSET_USB_NONE=0
      -DMTP_FFS_PATH="/dev/mtp"
      -DM_MMAP_THRESHOLD=0
      -DM_TRIM_THRESHOLD=0
      -DMTP_MAX_PATHNAME_SIZE=CONFIG_PATH_MAX
      -DMTP_MAX_FILENAME_SIZE=CONFIG_NAME_MAX
      -DMTP_DEFAULT_MODEL_NAME=CONFIG_MTP_RESPONDER_DEVICE_NAME
      -DMTP_EXTERNAL_STORAGE_DICLIST=CONFIG_MTP_RESPONDER_EXTERNAL_STORYAGE_DIRECTORY_LIST
      -DMTP_INTERNAL_PATH_CHAR=CONFIG_MTP_RESPONDER_INTRERNAL_STORAGE_PATH
      -DMTP_EXTERNAL_STORAGE_RESERVED_SPACE=CONFIG_MTP_RESPONDER_EXTERNAL_STORAGE_RESERVED_SPACE
      -DMTP_DEFAULT_THREAD_PRIORITY=CONFIG_MTP_RESPONDER_THREAD_PRIORITY)

  if(CONFIG_MTP_RESPONDER_INTRERNAL_STORAGE_LOCK_ON)
    list(APPEND CFLAGS -DUNQLITE_DISABLE_DIRSYNC)
  endif()

  if(CONFIG_MTP_RESPONDER_ICON_PATH)
    list(APPEND CFLAGS -DMTP_DEVICE_ICON=CONFIG_MTP_RESPONDER_ICON_PATH)
  endif()

  if(CONFIG_MTP_RESPONDER_EVENT_OBJECTADDDELETE)
    list(APPEND CFLAGS -DMTP_SUPPORT_OBJECTADDDELETE_EVENT)
  endif()

  set(INCDIR
      ${CMAKE_CURRENT_LIST_DIR}/include
      ${CMAKE_CURRENT_LIST_DIR}/mtp-responder/include
      ${NUTTX_APPS_DIR}/external/glib/glib
      ${NUTTX_APPS_DIR}/external/glib/glib/glib)

  nuttx_add_application(
    MODULE
    ${CONFIG_MTP_RESPONDER}
    NAME
    mtp_responder
    STACKSIZE
    ${CONFIG_MTP_RESPONDER_STACKSIZE}
    PRIORITY
    ${CONFIG_MTP_RESPONDER_PRIORITY}
    SRCS
    ${CSRCS}
    COMPILE_FLAGS
    ${CFLAGS}
    INCLUDE_DIRECTORIES
    ${INCDIR})

endif()
