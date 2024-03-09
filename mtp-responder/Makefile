#
# Copyright (C) 2022 Xiaomi Corporation
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

include $(APPDIR)/Make.defs

OCSRCS += mtp-responder/src/mtp_init.c mtp-responder/src/mtp_util_media_info.c \
          mtp-responder/src/mtp_usb_driver_ffs.c mtp-responder/src/mtp_descs_strings.c
CSRCS  += $(filter-out $(OCSRCS), \
            $(wildcard mtp-responder/src/*.c))

CFLAGS += -D__le16=uint16_t -D__le32=uint32_t -D__u16=uint16_t
CFLAGS += -DMSG_STAT=IPC_STAT -DSET_USB_NONE=0 -DMTP_FFS_PATH=\"/dev/mtp\"
CFLAGS += -DM_MMAP_THRESHOLD=0 -DM_TRIM_THRESHOLD=0 -Dfork=vfork
CFLAGS += -DMTP_MAX_PATHNAME_SIZE=CONFIG_PATH_MAX -DMTP_MAX_FILENAME_SIZE=CONFIG_NAME_MAX
CFLAGS += -DMTP_DEFAULT_MODEL_NAME=CONFIG_MTP_RESPONDER_DEVICE_NAME
CFLAGS += -DMTP_EXTERNAL_STORAGE_DICLIST=CONFIG_MTP_RESPONDER_EXTERNAL_STORYAGE_DIRECTORY_LIST
CFLAGS += -DMTP_INTERNAL_PATH_CHAR=CONFIG_MTP_RESPONDER_INTRERNAL_STORAGE_PATH
CFLAGS += -DMTP_EXTERNAL_STORAGE_RESERVED_SPACE=CONFIG_MTP_RESPONDER_EXTERNAL_STORAGE_RESERVED_SPACE

ifdef CONFIG_MTP_RESPONDER_INTRERNAL_STORAGE_LOCK_ON
CFLAGS += -DMTP_INTERNAL_STORAGE_LOCK_ON
endif

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/mtp-responder/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/mtp-responder/mtp-responder/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib/glib

PRIORITY  = $(CONFIG_MTP_RESPONDER_PRIORITY)
STACKSIZE = $(CONFIG_MTP_RESPONDER_STACKSIZE)
MODULE    = $(CONFIG_MTP_RESPONDER)

MAINSRC  += mtp-responder/src/mtp_init.c
PROGNAME += mtp_responder

ASRCS := $(wildcard $(ASRCS))
CSRCS := $(wildcard $(CSRCS))
CXXSRCS := $(wildcard $(CXXSRCS))
MAINSRC := $(wildcard $(MAINSRC))
NOEXPORTSRCS = $(ASRCS)$(CSRCS)$(CXXSRCS)$(MAINSRC)

ifneq ($(NOEXPORTSRCS),)
BIN := $(APPDIR)/staging/libmtp-responder.a
endif

include $(APPDIR)/Application.mk
