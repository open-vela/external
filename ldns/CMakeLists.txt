#
# Copyright (C) 2024 Xiaomi Corporation
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

if(CONFIG_LDNS)

    set(LDNS_FLAGS
        -DHAVE_CONFIG_H
        -Wno-unused-function
        -Wno-stringop-overread
        -Wno-undef)

    set(LDNS_INCDIR
        ${CMAKE_CURRENT_LIST_DIR}/config
        ${CMAKE_CURRENT_LIST_DIR}/ldns)

    file(GLOB LDNS_SRCS
        ${CMAKE_CURRENT_LIST_DIR}/ldns/*.c)

    set(LDNS_FILTER_OUT_SRCS
        ${CMAKE_CURRENT_LIST_DIR}/ldns/linktest.c)

    list(REMOVE_ITEM LDNS_SRCS ${LDNS_FILTER_OUT_SRCS})

    nuttx_add_library(ldns STATIC)
    target_sources(ldns PRIVATE ${LDNS_SRCS})
    target_include_directories(ldns PRIVATE ${LDNS_INCDIR})
    target_compile_options(ldns PRIVATE ${LDNS_FLAGS})

endif()
