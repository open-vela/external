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
if(CONFIG_LIB_JSONC)

  file(GLOB CSRCS ${CMAKE_CURRENT_LIST_DIR}/json-c/*.c)
  nuttx_add_library(jsonc STATIC)
  target_sources(jsonc PRIVATE ${CSRCS})
  target_include_directories(jsonc PRIVATE ${CMAKE_CURRENT_LIST_DIR})

  if(CONFIG_LIB_JSONC_TEST)
    macro(add_lib_jsonc_test_app PROG MAIN)
      nuttx_add_application(
        NAME
        ${PROG}
        STACKSIZE
        ${CONFIG_LIB_JSONC_TEST_STACKSIZE}
        PRIORITY
        ${CONFIG_LIB_JSONC_TEST_PRIORITY}
        SRCS
        ${MAIN}
        INCLUDE_DIRECTORIES
        ${NUTTX_APPS_DIR}/external/json-c/json-c
        ${CMAKE_CURRENT_LIST_DIR})
    endmacro()

    add_lib_jsonc_test_app(jsonc_test_cast json-c/tests/test_cast.c)
    add_lib_jsonc_test_app(jsonc_test_charcase json-c/tests/test_charcase.c)
    add_lib_jsonc_test_app(jsonc_test_compare json-c/tests/test_compare.c)
    add_lib_jsonc_test_app(jsonc_test_deep_copy json-c/tests/test_deep_copy.c)
    add_lib_jsonc_test_app(jsonc_test_double_serializer json-c/tests/test_double_serializer.c)
    add_lib_jsonc_test_app(jsonc_test_float json-c/tests/test_float.c)
    add_lib_jsonc_test_app(jsonc_test_int_add json-c/tests/test_int_add.c)
    add_lib_jsonc_test_app(jsonc_test_int_get json-c/tests/test_int_get.c)
    add_lib_jsonc_test_app(jsonc_test_json_patch json-c/tests/test_json_patch.c)
    add_lib_jsonc_test_app(jsonc_test_json_pointer json-c/tests/test_json_pointer.c)
    add_lib_jsonc_test_app(jsonc_test_locale json-c/tests/test_locale.c)
    add_lib_jsonc_test_app(jsonc_test_null json-c/tests/test_null.c)
    add_lib_jsonc_test_app(jsonc_test_object_iterator json-c/tests/test_object_iterator.c)
    add_lib_jsonc_test_app(jsonc_test_parse_int64 json-c/tests/test_parse_int64.c)
    add_lib_jsonc_test_app(jsonc_test_parse json-c/tests/test_parse.c)
    add_lib_jsonc_test_app(jsonc_test_printbuf json-c/tests/test_printbuf.c)
    add_lib_jsonc_test_app(jsonc_test_set_serializer json-c/tests/test_set_serializer.c)
    add_lib_jsonc_test_app(jsonc_test_set_value json-c/tests/test_set_value.c)
    add_lib_jsonc_test_app(jsonc_test_strerror json-c/tests/test_strerror.c)
    add_lib_jsonc_test_app(jsonc_test_util_file json-c/tests/test_util_file.c)
    add_lib_jsonc_test_app(jsonc_test_visit json-c/tests/test_visit.c)
    add_lib_jsonc_test_app(jsonc_test1 json-c/tests/test1.c)
    add_lib_jsonc_test_app(jsonc_test2 json-c/tests/test2.c)
    add_lib_jsonc_test_app(jsonc_test4 json-c/tests/test4.c)
    add_lib_jsonc_test_app(jsonc_testReplaceExisting json-c/tests/testReplaceExisting.c)
  endif()

endif()
