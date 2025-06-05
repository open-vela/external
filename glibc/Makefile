############################################################################
# apps/external/glibc/Makefile
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

GLIBC_URL := $(CONFIG_GLIBC_SERVER_URL)/glibc/glibc-$(CONFIG_GLIBC_VERSION).tar.xz

PORT_DIR	= $(CURDIR)/port
GLIBC_DIR	= $(CURDIR)/glibc
STRING_DIR	= $(GLIBC_DIR)/string
SUPPORT_DIR	= $(GLIBC_DIR)/support

PRIORITY	= SCHED_PRIORITY_DEFAULT
STACKSIZE	= $(CONFIG_GLIBC_TESTS_STACKSIZE)
MODULE		= $(CONFIG_GLIBC_TESTS)

NUTTX_DIR = $(APPDIR)/../nuttx

# Remove -isystem from CFLAGS, make sure the 'nuttx/include' include before 'glibc/include'
CFLAGS := $(shell echo "$(CFLAGS)" | sed -E 's/-isystem[[:space:]]+[^[:space:]]+//g; s/-isystem[^[:space:]]+//g')

CFLAGS += -I$(NUTTX_DIR)/include
CFLAGS += -I$(PORT_DIR)/include
CFLAGS += -I$(PORT_DIR)/string
CFLAGS += -I$(PORT_DIR)/
CFLAGS += -I$(GLIBC_DIR)
CFLAGS += -I$(GLIBC_DIR)/include
CFLAGS += -I$(GLIBC_DIR)/support
CFLAGS += -I$(GLIBC_DIR)/sysdeps/generic
CFLAGS += -include$(NUTTX_DIR)/include/nuttx/macro.h

CFLAGS += -D__GNULIB_CDEFS
CFLAGS += -D__LDOUBLE_REDIRECTS_TO_FLOAT128_ABI=0
CFLAGS += -DUSE_CLOCK_GETTIME
CFLAGS += -D__time_t=time_t
CFLAGS += -D_ISOMAC


ifndef ($(CONFIG_FS_LARGEFILE),y)
CFLAGS += -Doff64_t=int64_t
endif

CFLAGS += -D__memchr_default="CONCATENATE(main,_memchr)"
CFLAGS += -D__memrchr_default="CONCATENATE(main,_memrchr_default)"
CFLAGS += -Dsimple_memset="CONCATENATE(main,_simple_memset)"
CFLAGS += -Dsimple_memset="CONCATENATE(main,_simple_memset)"
CFLAGS += -Dsimple_memcpy="CONCATENATE(main,_simple_memcpy)"
CFLAGS += -D__strchrnul_default="CONCATENATE(main,___strchrnul_default)"
CFLAGS += -D__stpcpy_default="CONCATENATE(main,___stpcpy_default)"
CFLAGS += -D__strlen_default="CONCATENATE(main,___strlen_default)"
CFLAGS += -Ddo_test="CONCATENATE(main,_do_test)"
CFLAGS += -Dtest_main="CONCATENATE(test_,main)"

CFLAGS += -Wno-shadow
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-int-conversion
CFLAGS += -Wno-stringop-overread
CFLAGS += -Wno-implicit-function-declaration

support := \
  check \
  next_to_fault \
  oom_error \
  support_quote_blob \
  support_record_failure \
  support_test_compare_blob \
  support_test_compare_failure \
  support_test_compare_string \
  support_test_compare_string_wide \
  support_test_verify_impl \
  write_message \
  xfclose \
  xmalloc \
  xmemstream \
  xmkdir \
  xmkdirp \
  xmkfifo \
  xmmap \
  xmprotect \
  xmunmap \
  xnewlocale \
  xsysconf

string-tests := \
  testcopy \
  test-bzero \
  test-explicit_bzero \
  test-memcpy \
  test-memcpy-large \
  test-memmove \
  test-memccpy \
  test-mempcpy \
  test-memset \
  test-memchr \
  test-memrchr \
  test-rawmemchr \
  test-memcmp \
  test-memmem \
  test-strcpy \
  test-strncpy \
  test-stpcpy \
  test-stpncpy \
  tst-strlcpy \
  tst-strlcpy2 \
  test-strcat \
  test-strncat \
  tst-strlcat \
  tst-strlcat2 \
  test-strcmp \
  test-strncmp \
  test-strlen \
  test-strnlen \
  tst-strlen \
  test-strchr \
  test-strchrnul \
  test-strrchr \
  test-strstr \
  test-strcasestr \
  test-strpbrk \
  test-strcspn \
  test-strspn \
  test-strdup \
  test-strndup \
  tst-strtok \
  tst-strtok_r

ifeq ($(CONFIG_LIBC_LOCALE),y)
string-tests +=  \
  tester \
  test-strcasecmp \
  test-strncasecmp \
  tst-strxfrm \
  tst-strxfrm2
endif

# bug-strcoll1
# bug-strcoll2
# bug-strncat1
# bug-strpbrk1
# bug-strspn1
# bug-strtok1
# tst-memmove-overflow
# tst-strerror-fail
# test-strnlen-nonarray
# bug-envz1
# inl-tester
# noinl-tester
# stratcliff
# test-bcopy
# test-endian-file-scope
# test-endian-sign-conversion
# test-endian-types
# test-ffs
# test-memcmpeq
# test-sig_np
# tst-bswap
# tst-cmp
# tst-endian
# tst-inlcall
# tst-strfry
# tst-svc
# tst-svc2
# tst-xbzero-opt

CSRCS	+= $(PORT_DIR)/ifunc-impl-list.c
CSRCS	+= $(PORT_DIR)/support/strerrorname_np.c
CSRCS += $(addsuffix .c,$(addprefix $(SUPPORT_DIR)/,$(support)))

MAINSRC := $(addsuffix .c,$(addprefix $(STRING_DIR)/,$(string-tests)))
PROGNAME := $(subst -,_,$(string-tests))

glibc.source:
ifeq ($(wildcard glibc/.git),)
	$(Q) if [ ! -f glibc.tar.xz ]; then \
			wget -q --show-progress -O glibc.tar.xz $(GLIBC_URL); \
		fi; \
	$(Q) tar -xf glibc.tar.xz; \
	$(Q) mv glibc-$(CONFIG_GLIBC_VERSION) glibc;
endif

replace-headers: glibc.source
	$(Q) if [ -e $(STRING_DIR)/test-string.h ]; then \
		mv $(STRING_DIR)/test-string.h $(STRING_DIR)/test-string.h.bak; \
	fi

restore-files:
	$(Q) if [ -e $(STRING_DIR)/test-string.h.bak ]; then \
		mv $(STRING_DIR)/test-string.h.bak $(STRING_DIR)/test-string.h; \
	fi

context:: glibc.source replace-headers

distclean:: restore-files
ifeq ($(wildcard glibc/.git),)
	$(Q) $(call DELDIR, glibc)
	$(Q) $(call DELFILE, glibc.tar.xz)
endif

include $(APPDIR)/Application.mk
