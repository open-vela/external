############################################################################
# external/mmc-utils/Makefile
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

PROGNAME  = mmc
PRIORITY  = 100
STACKSIZE = $(CONFIG_DEFAULT_TASK_STACKSIZE)
MODULE    = $(CONFIG_UTILS_MMC)

MAINSRC = mmc-utils/mmc.c
CSRCS  += mmc-utils/mmc_cmds.c
CSRCS  += mmc-utils/lsmmc.c
CSRCS  += mmc-utils/3rdparty/hmac_sha/hmac_sha2.c
CFLAGS += ${DEFINE_PREFIX}VERSION=\"1.0\"

include $(APPDIR)/Application.mk
