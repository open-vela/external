############################################################################
# external/open1722/Makefile
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

include $(APPDIR)/Make.defs

CSRCS += argp.c
CSRCS += open1722/src/avtp/Utils.c
CSRCS += open1722/src/avtp/acf/FlexRay.c
CSRCS += open1722/src/avtp/acf/SensorBrief.c
CSRCS += open1722/src/avtp/acf/custom/Vss.c
CSRCS += open1722/src/avtp/acf/custom/VssBrief.c
CSRCS += open1722/src/avtp/acf/Lin.c
CSRCS += open1722/src/avtp/acf/Sensor.c
CSRCS += open1722/src/avtp/acf/Gpc.c
CSRCS += open1722/src/avtp/acf/Tscf.c
CSRCS += open1722/src/avtp/acf/Can.c
CSRCS += open1722/src/avtp/acf/AcfCommon.c
CSRCS += open1722/src/avtp/acf/CanBrief.c
CSRCS += open1722/src/avtp/acf/Ntscf.c
CSRCS += open1722/src/avtp/acf/Most.c
CSRCS += open1722/src/avtp/CommonHeader.c
CSRCS += open1722/src/avtp/Udp.c

CFLAGS += ${INCDIR_PREFIX}nuttx
CFLAGS += ${INCDIR_PREFIX}open1722
CFLAGS += -D__linux__
CFLAGS += -Wno-unused-variable -Wno-shadow -Wno-unused-function

ifneq ($(CONFIG_UTILS_OPEN1722_ACF_CAN),)
  CSRCS     += open1722/examples/common/common.c
  CSRCS     += open1722/examples/acf-can/acf-can-common.c

  CFLAGS += ${INCDIR_PREFIX}open1722/examples
  CFLAGS += ${INCDIR_PREFIX}open1722/examples/acf-can

  PROGNAME  += acf_can_listener acf_can_talker
  PRIORITY  += $(CONFIG_UTILS_OPEN1722_PRIORITY) $(CONFIG_UTILS_OPEN1722_PRIORITY)
  STACKSIZE += $(CONFIG_UTILS_OPEN1722_STACKSIZE) $(CONFIG_UTILS_OPEN1722_STACKSIZE)
  MODULE    += $(CONFIG_UTILS_OPEN1722) $(CONFIG_UTILS_OPEN1722)

  MAINSRC   += open1722/examples/acf-can/linux/acf-can-listener.c
  MAINSRC   += open1722/examples/acf-can/linux/acf-can-talker.c
endif

include $(APPDIR)/Application.mk
