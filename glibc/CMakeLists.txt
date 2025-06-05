# ##############################################################################
# apps/external/glibc/CMakeLists.txt
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

if(CONFIG_GLIBC_TESTS)
  set(GLIBC_TARBALL glibc-${CONFIG_GLIBC_VERSION}.tar.xz)
  set(GLIBC_URL ${CONFIG_GLIBC_SERVER_URL}/glibc/${GLIBC_TARBALL})

  set(GLIBC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glibc)
  set(STRING_DIR ${GLIBC_DIR}/string)
  set(SUPPORT_DIR ${GLIBC_DIR}/support)
  set(NUTTX_DIR ${CMAKE_SOURCE_DIR})

  if(NOT EXISTS ${GLIBC_DIR})
    FetchContent_Declare(
      glibc
      DOWNLOAD_NAME glibc.tar.xz
      DOWNLOAD_DIR ${CMAKE_CURRENT_LIST_DIR}
      URL "${GLIBC_URL}"
      SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/glibc
      BINARY_DIR ${CMAKE_BINARY_DIR}/apps/external/glibc/glibc
      DOWNLOAD_NO_PROGRESS true
      TIMEOUT 30)

    FetchContent_GetProperties(glibc)

    if(NOT glibc_POPULATED)
      FetchContent_Populate(glibc)
    endif()
  endif()

  if(EXISTS "${STRING_DIR}/test-string.h")
    file(RENAME "${STRING_DIR}/test-string.h" "${STRING_DIR}/test-string.h.bak")
  endif()

  set(CMAKE_INCLUDE_SYSTEM_FLAG_C "-I")
  set(INCDIR
      ${GLIBC_DIR}/sysdeps/generic
      ${GLIBC_DIR}/support
      ${GLIBC_DIR}/include
      ${GLIBC_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/port
      ${CMAKE_CURRENT_SOURCE_DIR}/port/string
      ${CMAKE_CURRENT_SOURCE_DIR}/port/include
      ${NUTTX_DIR}/include/../include)

  set(CFLAGS
      "-include${NUTTX_DIR}/include/nuttx/macro.h"
      "-D__GNULIB_CDEFS"
      "-D__LDOUBLE_REDIRECTS_TO_FLOAT128_ABI=0"
      "-DUSE_CLOCK_GETTIME"
      "-D__time_t=time_t"
      "-D_ISOMAC"
      "-D__memchr_default=CONCATENATE(main,_memchr)"
      "-D__memrchr_default=CONCATENATE(main,_memrchr_default)"
      "-Dsimple_memset=CONCATENATE(main,_simple_memset)"
      "-Dsimple_memcpy=CONCATENATE(main,_simple_memcpy)"
      "-D__strchrnul_default=CONCATENATE(main,___strchrnul_default)"
      "-D__stpcpy_default=CONCATENATE(main,___stpcpy_default)"
      "-D__strlen_default=CONCATENATE(main,___strlen_default)"
      "-Ddo_test=CONCATENATE(main,_do_test)"
      "-Dtest_main=CONCATENATE(test_,main)"
      "-Wno-shadow"
      "-Wno-unused-variable"
      "-Wno-unused-function"
      "-Wno-int-conversion"
      "-Wno-stringop-overread"
      "-Wno-implicit-function-declaration")

  if(NOT DEFINED CONFIG_FS_LARGEFILE)
    list(APPEND CFLAGS "-Doff64_t=int64_t")
  endif()

  set(CSRCS ${CMAKE_CURRENT_SOURCE_DIR}/port/ifunc-impl-list.c
            ${CMAKE_CURRENT_SOURCE_DIR}/port/support/strerrorname_np.c)

  set(SUPPORT_SRCS
      check
      next_to_fault
      oom_error
      support_quote_blob
      support_record_failure
      support_test_compare_blob
      support_test_compare_failure
      support_test_compare_string
      support_test_compare_string_wide
      support_test_verify_impl
      write_message
      xfclose
      xmalloc
      xmemstream
      xmkdir
      xmkdirp
      xmkfifo
      xmmap
      xmprotect
      xmunmap
      xnewlocale
      xsysconf)

  set(STRING_TESTS
      testcopy
      test-bzero
      test-explicit_bzero
      test-memcpy
      test-memcpy-large
      test-memmove
      test-memccpy
      test-mempcpy
      test-memset
      test-memchr
      test-memrchr
      test-rawmemchr
      test-memcmp
      test-memmem
      test-strcpy
      test-strncpy
      test-stpcpy
      test-stpncpy
      tst-strlcpy
      tst-strlcpy2
      test-strcat
      test-strncat
      tst-strlcat
      tst-strlcat2
      test-strcmp
      test-strncmp
      test-strlen
      test-strnlen
      tst-strlen
      test-strchr
      test-strchrnul
      test-strrchr
      test-strstr
      test-strcasestr
      test-strpbrk
      test-strcspn
      test-strspn
      test-strdup
      test-strndup
      tst-strtok
      tst-strtok_r)

  if(CONFIG_LIBC_LOCALE)
    list(
      APPEND
      STRING_TESTS
      tester
      test-strcasecmp
      test-strncasecmp
      tst-strxfrm
      tst-strxfrm2)
  endif()

  foreach(SUPPORT_SRC ${SUPPORT_SRCS})
    list(APPEND CSRCS ${SUPPORT_DIR}/${SUPPORT_SRC}.c)
  endforeach()

  foreach(TEST ${STRING_TESTS})
    string(REPLACE "-" "_" TEST_NAME ${TEST})
    nuttx_add_application(
      NAME
      ${TEST_NAME}
      PRIORITY
      SCHED_PRIORITY_DEFAULT
      STACKSIZE
      ${CONFIG_GLIBC_TESTS_STACKSIZE}
      MODULE
      ${CONFIG_GLIBC_TESTS}
      COMPILE_FLAGS
      ${CFLAGS}
      INCLUDE_DIRECTORIES
      ${INCDIR}
      SRCS
      ${STRING_DIR}/${TEST}.c
      ${CSRCS})
  endforeach()
endif()
