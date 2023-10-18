############################################################################
# external/sqlite/Makefile
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

SQLITEDIR=$(APPDIR)/external/sqlite/sqlite
BUILDDIR=$(APPDIR)/external/sqlite/build

CSRCS += ${BUILDDIR}/sqlite3.c

CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/sqlite
CFLAGS += ${DEFINE_PREFIX}_HAVE_SQLITE_CONFIG_H
CFLAGS += -Wno-unused-variable -Wno-undef -Wno-unused-function -Wno-shadow

ifneq ($(CONFIG_UTILS_SQLITE),)
PROGNAME  = sqlite3
PRIORITY  = 100
STACKSIZE = ${CONFIG_UTILS_SQLITE_STACKSIZE}
MAINSRC = ${BUILDDIR}/shell.c
endif

context::
	mkdir -p ${BUILDDIR} && \
	cd ${BUILDDIR} && \
	${SQLITEDIR}/configure 1> /dev/null && \
	make sqlite3.c -j 1> /dev/null

clean::
	$(call DELFILE, ${BUILDDIR}/*.o)

distclean::
	$(call DELDIR, ${BUILDDIR})

include $(APPDIR)/Application.mk

