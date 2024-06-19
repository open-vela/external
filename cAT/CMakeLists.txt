#
# Copyright (C) 2021 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#
if(CONFIG_LIB_CAT)

  nuttx_add_library(libcat STATIC)
  file(GLOB CSRCS cAT/src/*.c)
  target_sources(libcat PRIVATE ${CSRCS})

  macro(add_cat_app NAME DIR)
    nuttx_add_application(
      MODULE
      ${CONFIG_LIB_CAT}
      NAME
      cat_${NAME}
      SRCS
      cAT/${DIR}/${NAME}.c
      STACKSIZE
      ${CONFIG_LIB_CAT_STACKSIZE}
      PRIORITY
      ${CONFIG_LIB_CAT_PRIORITY}
      DEPENDS
      libcat)
  endmacro()

  if(CONFIG_LIB_CAT_EXAMPLES)
    add_cat_app(demo example)
    add_cat_app(basic example)
    add_cat_app(unsolicited example)
  endif()

  if(CONFIG_LIB_CAT_TESTS)
    add_cat_app(test_parse tests)
    add_cat_app(test_run tests)
    add_cat_app(test_read tests)
    add_cat_app(test_write tests)
    add_cat_app(test_write_parse tests)
    add_cat_app(test_write_int_range tests)
    add_cat_app(test_write_uint_range tests)
    add_cat_app(test_write_hex_range tests)
    add_cat_app(test_write_hex_buffer tests)
    add_cat_app(test_write_string_buffer tests)
    add_cat_app(test_read_args tests)
    add_cat_app(test_test tests)
    add_cat_app(test_test_args tests)
    add_cat_app(test_mutex tests)
    add_cat_app(test_unsolicited_read tests)
    add_cat_app(test_unsolicited_read_stress tests)
    add_cat_app(test_unsolicited_read_buffer tests)
    add_cat_app(test_hold_state tests)
    add_cat_app(test_return_read tests)
    add_cat_app(test_return_write tests)
    add_cat_app(test_unsolicited_test tests)
    add_cat_app(test_return_test tests)
    add_cat_app(test_return_run tests)
    add_cat_app(test_test_only tests)
    add_cat_app(test_search_cmd tests)
    add_cat_app(test_order tests)
    add_cat_app(test_cmd_list tests)
    add_cat_app(test_var_access tests)
    add_cat_app(test_shortcuts tests)
  endif()
endif()
