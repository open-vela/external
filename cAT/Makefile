#
# Copyright (C) 2021 Xiaomi Corporation
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

CSRCS    += $(wildcard cAT/src/*.c)
MODULE    = $(CONFIG_LIB_CAT)

ifneq ($(CONFIG_LIB_CAT_EXAMPLES),)
PROGNAME += cat_demo
MAINSRC  += cAT/example/demo.c
PROGNAME += cat_basic
MAINSRC  += cAT/example/basic.c
PROGNAME += cat_unsolicited
MAINSRC  += cAT/example/unsolicited.c
endif

ifneq ($(CONFIG_LIB_CAT_TESTS),)
PROGNAME += cat_test_parse
MAINSRC  += cAT/tests/test_parse.c
PROGNAME += cat_test_run
MAINSRC  += cAT/tests/test_run.c
PROGNAME += cat_test_read
MAINSRC  += cAT/tests/test_read.c
PROGNAME += cat_test_write
MAINSRC  += cAT/tests/test_write.c
PROGNAME += cat_test_write_parse
MAINSRC  += cAT/tests/test_write_parse.c
PROGNAME += cat_test_write_int_range
MAINSRC  += cAT/tests/test_write_int_range.c
PROGNAME += cat_test_write_uint_range
MAINSRC  += cAT/tests/test_write_uint_range.c
PROGNAME += cat_test_write_hex_range
MAINSRC  += cAT/tests/test_write_hex_range.c
PROGNAME += cat_test_write_hex_buffer
MAINSRC  += cAT/tests/test_write_hex_buffer.c
PROGNAME += cat_test_write_string_buffer
MAINSRC  += cAT/tests/test_write_string_buffer.c
PROGNAME += cat_test_read_args
MAINSRC  += cAT/tests/test_read_args.c
PROGNAME += cat_test_test
MAINSRC  += cAT/tests/test_test.c
PROGNAME += cat_test_test_args
MAINSRC  += cAT/tests/test_test_args.c
PROGNAME += cat_test_mutex
MAINSRC  += cAT/tests/test_mutex.c
PROGNAME += cat_test_unsolicited_read
MAINSRC  += cAT/tests/test_unsolicited_read.c
PROGNAME += cat_test_unsolicited_read_stress
MAINSRC  += cAT/tests/test_unsolicited_read_stress.c
PROGNAME += cat_test_unsolicited_read_buffer
MAINSRC  += cAT/tests/test_unsolicited_read_buffer.c
PROGNAME += cat_test_hold_state
MAINSRC  += cAT/tests/test_hold_state.c
PROGNAME += cat_test_return_read
MAINSRC  += cAT/tests/test_return_read.c
PROGNAME += cat_test_return_write
MAINSRC  += cAT/tests/test_return_write.c
PROGNAME += cat_test_unsolicited_test
MAINSRC  += cAT/tests/test_unsolicited_test.c
PROGNAME += cat_test_return_test
MAINSRC  += cAT/tests/test_return_test.c
PROGNAME += cat_test_return_run
MAINSRC  += cAT/tests/test_return_run.c
PROGNAME += cat_test_test_only
MAINSRC  += cAT/tests/test_test_only.c
PROGNAME += cat_test_search_cmd
MAINSRC  += cAT/tests/test_search_cmd.c
PROGNAME += cat_test_order
MAINSRC  += cAT/tests/test_order.c
PROGNAME += cat_test_cmd_list
MAINSRC  += cAT/tests/test_cmd_list.c
PROGNAME += cat_test_var_access
MAINSRC  += cAT/tests/test_var_access.c
PROGNAME += cat_test_shortcuts
MAINSRC  += cAT/tests/test_shortcuts.c
endif

PRIORITY  = $(CONFIG_LIB_CAT_PRIORITY)
STACKSIZE = $(CONFIG_LIB_CAT_STACKSIZE)

include $(APPDIR)/Application.mk
