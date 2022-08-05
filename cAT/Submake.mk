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

CSRCS    += $(wildcard src/*.c)
MODULE    = $(CONFIG_LIB_CAT)

ifeq ($(CONFIG_LIB_CAT_USRDATA),y)
CSRCS    += src/cat_usrdata.c
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" src}
endif

ifneq ($(CONFIG_LIB_CAT_EXAMPLES),)
PROGNAME += cat_demo
MAINSRC  += example/demo.c
PROGNAME += cat_basic
MAINSRC  += example/basic.c
PROGNAME += cat_unsolicited
MAINSRC  += example/unsolicited.c
endif

ifneq ($(CONFIG_LIB_CAT_TESTS),)
PROGNAME += cat_test_parse
MAINSRC  += tests/test_parse.c
PROGNAME += cat_test_run
MAINSRC  += tests/test_run.c
PROGNAME += cat_test_read
MAINSRC  += tests/test_read.c
PROGNAME += cat_test_write
MAINSRC  += tests/test_write.c
PROGNAME += cat_test_write_parse
MAINSRC  += tests/test_write_parse.c
PROGNAME += cat_test_write_int_range
MAINSRC  += tests/test_write_int_range.c
PROGNAME += cat_test_write_uint_range
MAINSRC  += tests/test_write_uint_range.c
PROGNAME += cat_test_write_hex_range
MAINSRC  += tests/test_write_hex_range.c
PROGNAME += cat_test_write_hex_buffer
MAINSRC  += tests/test_write_hex_buffer.c
PROGNAME += cat_test_write_string_buffer
MAINSRC  += tests/test_write_string_buffer.c
PROGNAME += cat_test_read_args
MAINSRC  += tests/test_read_args.c
PROGNAME += cat_test_test
MAINSRC  += tests/test_test.c
PROGNAME += cat_test_test_args
MAINSRC  += tests/test_test_args.c
PROGNAME += cat_test_mutex
MAINSRC  += tests/test_mutex.c
PROGNAME += cat_test_unsolicited_read
MAINSRC  += tests/test_unsolicited_read.c
PROGNAME += cat_test_unsolicited_read_stress
MAINSRC  += tests/test_unsolicited_read_stress.c
PROGNAME += cat_test_unsolicited_read_buffer
MAINSRC  += tests/test_unsolicited_read_buffer.c
CFLAGS   += -DCAT_UNSOLICITED_CMD_BUFFER_SIZE=2
PROGNAME += cat_test_unsolicited_read_buffer
MAINSRC  += tests/test_unsolicited_read_buffer.c
PROGNAME += cat_test_hold_state
MAINSRC  += tests/test_hold_state.c
PROGNAME += cat_test_return_read
MAINSRC  += tests/test_return_read.c
PROGNAME += cat_test_return_write
MAINSRC  += tests/test_return_write.c
PROGNAME += cat_test_unsolicited_test
MAINSRC  += tests/test_unsolicited_test.c
PROGNAME += cat_test_return_test
MAINSRC  += tests/test_return_test.c
PROGNAME += cat_test_return_run
MAINSRC  += tests/test_return_run.c
PROGNAME += cat_test_test_only
MAINSRC  += tests/test_test_only.c
PROGNAME += cat_test_search_cmd
MAINSRC  += tests/test_search_cmd.c
PROGNAME += cat_test_order
MAINSRC  += tests/test_order.c
PROGNAME += cat_test_cmd_list
MAINSRC  += tests/test_cmd_list.c
PROGNAME += cat_test_var_access
MAINSRC  += tests/test_var_access.c
PROGNAME += cat_test_shortcuts
MAINSRC  += tests/test_shortcuts.c
endif

PRIORITY  = $(CONFIG_LIB_CAT_PRIORITY)
STACKSIZE = $(CONFIG_LIB_CAT_STACKSIZE)

include $(APPDIR)/Application.mk
