# ##############################################################################
# external/sqlite/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_LIB_SQLITE)

  set(SQLITEDIR ${CMAKE_CURRENT_LIST_DIR}/sqlite)
  set(BUILDDIR ${CMAKE_CURRENT_BINARY_DIR}/build)
  set(INCDIR ${BUILDDIR})
  set(CSRCS ${BUILDDIR}/sqlite3.c)
  set(UTILS_SRC ${BUILDDIR}/shell.c)
  set(FLAGS -Wno-unused-variable -Wno-unused-function -Wno-shadow
            -DSQLITE_OMIT_LOAD_EXTENSION)

  add_custom_command(
    OUTPUT ${CSRCS} ${UTILS_SRC}
    COMMAND mkdir -p ${BUILDDIR}
    COMMAND ${SQLITEDIR}/configure 1>/dev/null
    COMMAND make sqlite3.c -j 1>/dev/null
    WORKING_DIRECTORY ${BUILDDIR})

  nuttx_add_library(sqlite)
  target_sources(sqlite PRIVATE ${CSRCS})
  target_include_directories(sqlite PRIVATE ${INCDIR})
  target_compile_options(sqlite PRIVATE ${FLAGS})

  if(CONFIG_UTILS_SQLITE)
    nuttx_add_application(
      MODULE
      ${CONFIG_UTILS_SQLITE}
      NAME
      sqlite3
      STACKSIZE
      ${CONFIG_UTILS_SQLITE_STACKSIZE}
      PRIORITY
      100
      SRCS
      ${UTILS_SRC}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      COMPILE_FLAGS
      ${FLAGS}
      DEPENDS
      sqlite)
  endif()

endif()
