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
          mtp-responder/src/mtp_usb_driver_slp.c mtp-responder/src/mtp_descs_strings.c
CSRCS  += $(filter-out $(OCSRCS), \
            $(wildcard mtp-responder/src/*.c))

CFLAGS += -D__le16=uint16_t -D__le32=uint32_t -D__u16=uint16_t
CFLAGS += -DMSG_STAT=IPC_STAT -DSET_USB_NONE=0 -DMTP_FFS_PATH=\"/dev/mtp\"

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/mtp-responder
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/mtp-responder/mtp-responder/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/glib/glib/glib

PRIORITY  = $(CONFIG_MTP_RESPONDER_PRIORITY)
STACKSIZE = $(CONFIG_MTP_RESPONDER_STACKSIZE)
MODULE    = $(CONFIG_MTP_RESPONDER)

MAINSRC  += mtp-responder/src/mtp_init.c
PROGNAME += mtp_responder

include $(APPDIR)/Application.mk
