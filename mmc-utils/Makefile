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
STACKSIZE = 4096
MODULE    = $(CONFIG_UTILS_MMC)

MAINSRC = mmc-utils/mmc.c
CSRCS  += mmc-utils/mmc_cmds.c
CSRCS  += mmc-utils/lsmmc.c
CSRCS  += mmc-utils/3rdparty/hmac_sha/hmac_sha2.c
CSRCS  += mmc-utils/3rdparty/hmac_sha/sha2.c
CFLAGS += -Wno-shadow
CFLAGS += ${DEFINE_PREFIX}__u32=uint32_t ${DEFINE_PREFIX}__u64=uint64_t
CFLAGS += ${DEFINE_PREFIX}__u8=uint8_t   ${DEFINE_PREFIX}__u16=uint16_t
CFLAGS += ${DEFINE_PREFIX}sha224=mmc_sha224
CFLAGS += ${DEFINE_PREFIX}sha224_init=mmc_sha224_init
CFLAGS += ${DEFINE_PREFIX}sha224_update=mmc_sha224_update
CFLAGS += ${DEFINE_PREFIX}sha224_final=mmc_sha224_final
CFLAGS += ${DEFINE_PREFIX}sha256=mmc_sha256
CFLAGS += ${DEFINE_PREFIX}sha256_init=mmc_sha256_init
CFLAGS += ${DEFINE_PREFIX}sha256_update=mmc_sha256_update
CFLAGS += ${DEFINE_PREFIX}sha256_final=mmc_sha256_final
CFLAGS += ${DEFINE_PREFIX}sha384=mmc_sha384
CFLAGS += ${DEFINE_PREFIX}sha384_init=mmc_sha384_init
CFLAGS += ${DEFINE_PREFIX}sha384_update=mmc_sha384_update
CFLAGS += ${DEFINE_PREFIX}sha384_final=mmc_sha384_final
CFLAGS += ${DEFINE_PREFIX}sha512=mmc_sha512
CFLAGS += ${DEFINE_PREFIX}sha512_init=mmc_sha512_init
CFLAGS += ${DEFINE_PREFIX}sha512_update=mmc_sha512_update
CFLAGS += ${DEFINE_PREFIX}sha512_final=mmc_sha512_final
CFLAGS += ${DEFINE_PREFIX}VERSION=\"1.0\"

include $(APPDIR)/Application.mk
