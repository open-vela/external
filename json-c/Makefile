#
# Copyright (C) 2023 Xiaomi Corporation
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

PRIORITY  = $(CONFIG_LIB_JSONC_PRIORITY)
STACKSIZE = $(CONFIG_LIB_JSONC_STACKSIZE)
MODULE    = $(CONFIG_LIB_JSONC)

CSRCS += $(wildcard ./json-c/*.c)

CFLAGS   += ${INCDIR_PREFIX}.

ifeq ($(CONFIG_LIB_JSONC_TEST),y)
	CFLAGS   += ${INCDIR_PREFIX}$(APPDIR)/external/json-c/json-c
	PRIORITY  = $(CONFIG_LIB_JSONC_TEST_PRIORITY)
	STACKSIZE = $(CONFIG_LIB_JSONC_TEST_STACKSIZE)
	MAINSRC  += json-c/tests/test_cast.c
	MAINSRC  += json-c/tests/test_charcase.c
	MAINSRC  += json-c/tests/test_compare.c
	MAINSRC  += json-c/tests/test_deep_copy.c
	MAINSRC  += json-c/tests/test_double_serializer.c
	MAINSRC  += json-c/tests/test_float.c
	MAINSRC  += json-c/tests/test_int_add.c
	MAINSRC  += json-c/tests/test_int_get.c
	MAINSRC  += json-c/tests/test_json_patch.c
	MAINSRC  += json-c/tests/test_json_pointer.c
	MAINSRC  += json-c/tests/test_locale.c
	MAINSRC  += json-c/tests/test_null.c
	MAINSRC  += json-c/tests/test_object_iterator.c
	MAINSRC  += json-c/tests/test_parse_int64.c
	MAINSRC  += json-c/tests/test_parse.c
	MAINSRC  += json-c/tests/test_printbuf.c
	MAINSRC  += json-c/tests/test_set_serializer.c
	MAINSRC  += json-c/tests/test_set_value.c
	MAINSRC  += json-c/tests/test_strerror.c
	MAINSRC  += json-c/tests/test_util_file.c
	MAINSRC  += json-c/tests/test_visit.c
	MAINSRC  += json-c/tests/test1.c
	MAINSRC  += json-c/tests/test2.c
	MAINSRC  += json-c/tests/test4.c
	MAINSRC  += json-c/tests/testReplaceExisting.c
	PROGNAME += jsonc_test_cast
	PROGNAME += jsonc_test_charcase
	PROGNAME += jsonc_test_compare
	PROGNAME += jsonc_test_deep_copy
	PROGNAME += jsonc_test_double_serializer
	PROGNAME += jsonc_test_float
	PROGNAME += jsonc_test_int_add
	PROGNAME += jsonc_test_int_get
	PROGNAME += jsonc_test_json_patch
	PROGNAME += jsonc_test_json_pointer
	PROGNAME += jsonc_test_locale
	PROGNAME += jsonc_test_null
	PROGNAME += jsonc_test_object_iterator
	PROGNAME += jsonc_test_parse_int64
	PROGNAME += jsonc_test_parse
	PROGNAME += jsonc_test_printbuf
	PROGNAME += jsonc_test_set_serializer
	PROGNAME += jsonc_test_set_value
	PROGNAME += jsonc_test_strerror
	PROGNAME += jsonc_test_util_file
	PROGNAME += jsonc_test_visit
	PROGNAME += jsonc_test1
	PROGNAME += jsonc_test2
	PROGNAME += jsonc_test4
	PROGNAME += jsonc_testReplaceExisting
endif

include $(APPDIR)/Application.mk
