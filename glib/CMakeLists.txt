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
if(CONFIG_LIB_GLIB)

  set(CFLAGS
      -DG_LOG_DOMAIN=\"GLib\"
      -DGLIB_COMPILATION
      -Db_coverage=false
      -DGLIB_CHARSETALIAS_DIR=\"/etc/locale/lib/\"
      -DSIGWINCH=21
      -DSIGABRT=22
      -DNSIG=_NSIG)
  set(INCDIR ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/glib
             ${CMAKE_CURRENT_LIST_DIR}/glib/glib)

  file(GLOB GLIB_C_SRCS glib/glib/g*.c)

  file(GLOB WIN_OUT_SRCS glib/glib/*win32*.c)

  set(GLIB_FILTER_OUT
      ${WIN_OUT_SRCS} ${CMAKE_CURRENT_LIST_DIR}/glib/glib/gtester.c
      ${CMAKE_CURRENT_LIST_DIR}/glib/glib/gstdio-private.c
      ${CMAKE_CURRENT_LIST_DIR}/glib/glib/gjournal-private.c)
  if(NOT CONFIG_LIB_PCRE2)
    list(APPEND GLIB_FILTER_OUT ${CMAKE_CURRENT_LIST_DIR}/glib/glib/gregex.c)
  endif()
  list(REMOVE_ITEM GLIB_C_SRCS ${GLIB_FILTER_OUT})
  list(APPEND GLIB_C_SRCS glib/glib/libcharset/localcharset.c)

  nuttx_add_library(glib STATIC)
  target_sources(glib PRIVATE ${GLIB_C_SRCS})
  target_include_directories(glib PRIVATE ${INCDIR})
  target_compile_options(glib PRIVATE ${CFLAGS})

endif()
