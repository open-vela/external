#
# Copyright (C) 2020 Xiaomi Corporation
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

if(CONFIG_BENCHTEST)

  set(BENCHTESTS_DIR ${CMAKE_CURRENT_LIST_DIR}/benchtests)

  set(CSRCS
      benchtests/json-lib.c
      port/error.c
      port/ifunc-impl-list.c
      port/programs/xmalloc.c
      port/string/generic.c
      port/support/support_test_main.c
      port/support/support.c
      port/support/timespec.c
      port/support/xthread.c)

  set(CFLAGS
      -Wno-unused-function
      -Wno-unused-variable
      -Wno-shadow
      -DDURATION=${CONFIG_BENCHTEST_DURATION}
      -DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC
      -Dxmalloc=benchtests_xmalloc
      -Dxasprintf=benchtests_xasprintf
      -Derror=benchtest_error
      -Dgeneric_memcpy=benchtests_memcpy
      -Dgeneric_memmove=benchtests_memmove
      -Dgeneric_memset=benchtests_memset)

  set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/port)
  include_directories(${INCDIR})

  if(CONFIG_BENCHTEST_STRING)
    set(BENCH_BZERO benchtests/bench-bzero.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_bzero
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_BZERO})

    set(BENCH_MEMCCPY benchtests/bench-memccpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memccpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMCCPY})

    set(BENCH_MEMCHR benchtests/bench-memchr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memchr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMCHR})

    set(BENCH_MEMCMP benchtests/bench-memcmp.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memcmp
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMCMP})

    set(BENCH_MEMCPY benchtests/bench-memcpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memcpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMCPY})

    set(BENCH_MEMMEM benchtests/bench-memmem.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memmem
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMMEM})

    set(BENCH_MEMMOVE benchtests/bench-memmove.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memmove
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMMOVE})

    set(BENCH_MEMPCPY benchtests/bench-mempcpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_mempcpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMPCPY})

    set(BENCH_MEMRCHR benchtests/bench-memrchr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memrchr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMRCHR})

    set(BENCH_MEMSET benchtests/bench-memset.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memset
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMSET})

    set(BENCH_MEMSET_ZERO benchtests/bench-memset-zero.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_memset_zero
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MEMSET_ZERO})

    set(BENCH_RAWMEMCHR benchtests/bench-rawmemchr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_rawmemchr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_RAWMEMCHR})

    set(BENCH_STPCPY benchtests/bench-stpcpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_stpcpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STPCPY})

    set(BENCH_STPNCPY benchtests/bench-stpncpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_stpncpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STPNCPY})

    set(BENCH_STRCASECMP benchtests/bench-strcasecmp.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strcasecmp
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCASECMP})

    set(BENCH_STRCASESTR benchtests/bench-strcasestr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strcasestr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCASESTR})

    set(BENCH_STRCAT benchtests/bench-strcat.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strcat
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCAT})

    set(BENCH_STRCHR benchtests/bench-strchr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strchr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCHR})

    set(BENCH_STRCHRNUL benchtests/bench-strchrnul.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strchrnul
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCHRNUL})

    set(BENCH_STRCMP benchtests/bench-strcmp.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strcmp
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCMP})

    set(BENCH_STRCPY benchtests/bench-strcpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strcpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCPY})

    set(BENCH_STRCSPN benchtests/bench-strcspn.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strcspn
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRCSPN})

    set(BENCH_STRLEN benchtests/bench-strlen.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strlen
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRLEN})

    set(BENCH_STRNCASECMP benchtests/bench-strncasecmp.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strncasecmp
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRNCASECMP})

    set(BENCH_STRNCAT benchtests/bench-strncat.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strncat
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRNCAT})

    set(BENCH_STRNCMP benchtests/bench-strncmp.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strncmp
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRNCMP})

    set(BENCH_STRNCPY benchtests/bench-strncpy.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strncpy
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRNCPY})

    set(BENCH_STRNLEN benchtests/bench-strnlen.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strnlen
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRNLEN})

    set(BENCH_STRPBRK benchtests/bench-strpbrk.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strpbrk
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRPBRK})

    set(BENCH_STRRCHR benchtests/bench-strrchr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strrchr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRRCHR})

    set(BENCH_STRSEP benchtests/bench-strsep.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strsep
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRSEP})

    set(BENCH_STRSPN benchtests/bench-strspn.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strspn
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRSPN})

    set(BENCH_STRSTR benchtests/bench-strstr.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strstr
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRSTR})

    set(BENCH_STRTOK benchtests/bench-strtok.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_strtok
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_STRTOK})
  endif()

  execute_process(
    COMMAND ${CMAKE_COMMAND} -E env python buildbench.py bench-string
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    RESULT_VARIABLE result)

  execute_process(
    COMMAND ${CMAKE_COMMAND} -E env python buildbench.py stdio-common-benchset
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    RESULT_VARIABLE result)

  set(BENCH_FFS benchtests/bench-string-ffs.c ${CSRCS})
  nuttx_add_application(
    NAME
    bench_ffs
    PRIORITY
    ${CONFIG_BENCHTEST_PRIORITY}
    STACKSIZE
    ${CONFIG_BENCHTEST_STACKSIZE}
    COMPILE_FLAGS
    ${CFLAGS}
    SRCS
    ${BENCH_FFS})

  set(BENCH_FFSLL benchtests/bench-string-ffsll.c ${CSRCS})
  nuttx_add_application(
    NAME
    bench_ffsll
    PRIORITY
    ${CONFIG_BENCHTEST_PRIORITY}
    STACKSIZE
    ${CONFIG_BENCHTEST_STACKSIZE}
    COMPILE_FLAGS
    ${CFLAGS}
    SRCS
    ${BENCH_FFSLL})

  set(BENCH_STRTOD benchtests/bench-strtod.c ${CSRCS})
  nuttx_add_application(
    NAME
    bench_strtod
    PRIORITY
    ${CONFIG_BENCHTEST_PRIORITY}
    STACKSIZE
    ${CONFIG_BENCHTEST_STACKSIZE}
    COMPILE_FLAGS
    ${CFLAGS}
    SRCS
    ${BENCH_STRTOD})

  set(BENCH_SPRINTF benchtests/stdio-common-benchset-sprintf.c ${CSRCS})
  nuttx_add_application(
    NAME
    bench_sprintf
    PRIORITY
    ${CONFIG_BENCHTEST_PRIORITY}
    STACKSIZE
    ${CONFIG_BENCHTEST_STACKSIZE}
    COMPILE_FLAGS
    ${CFLAGS}
    SRCS
    ${BENCH_SPRINTF})

  set(BENCH_MALLOC_THREAD benchtests/bench-malloc-thread.c ${CSRCS})
  nuttx_add_application(
    NAME
    bench_malloc_thread
    PRIORITY
    ${CONFIG_BENCHTEST_PRIORITY}
    STACKSIZE
    ${CONFIG_BENCHTEST_STACKSIZE}
    COMPILE_FLAGS
    ${CFLAGS}
    SRCS
    ${BENCH_MALLOC_THREAD})

  set(BENCH_MALLOC_SIMPLE benchtests/bench-malloc-simple.c ${CSRCS})
  nuttx_add_application(
    NAME
    bench_malloc_simple
    PRIORITY
    ${CONFIG_BENCHTEST_PRIORITY}
    STACKSIZE
    ${CONFIG_BENCHTEST_STACKSIZE}
    COMPILE_FLAGS
    ${CFLAGS}
    SRCS
    ${BENCH_MALLOC_SIMPLE})

  if(NOT CONFIG_LIBM_NONE)
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E env python buildbench.py bench-math
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
      RESULT_VARIABLE result)

    set(BENCH_ACOS benchtests/bench-math-acos.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_acos
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ACOS})

    set(BENCH_ACOSH benchtests/bench-math-acosh.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_acosh
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ACOSH})

    set(BENCH_ASIN benchtests/bench-math-asin.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_asin
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ASIN})

    set(BENCH_ASINH benchtests/bench-math-asinh.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_asinh
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ASINH})

    set(BENCH_ATAN benchtests/bench-math-atan.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_atan
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ATAN})

    set(BENCH_ATAN2 benchtests/bench-math-atan2.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_atan2
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ATAN2})

    set(BENCH_ATANH benchtests/bench-math-atanh.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_atanh
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ATANH})

    set(BENCH_CBRT benchtests/bench-math-cbrt.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_cbrt
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_CBRT})

    set(BENCH_COS benchtests/bench-math-cos.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_cos
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_COS})

    set(BENCH_COSF benchtests/bench-math-cosf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_cosf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_COSF})

    set(BENCH_COSH benchtests/bench-math-cosh.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_cosh
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_COSH})

    set(BENCH_ERF benchtests/bench-math-erf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_erf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ERF})

    set(BENCH_ERFC benchtests/bench-math-erfc.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_erfc
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ERFC})

    set(BENCH_EXP benchtests/bench-math-exp.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_exp
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXP})

    set(BENCH_EXP10 benchtests/bench-math-exp10.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_exp10
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXP10})

    set(BENCH_EXP10F benchtests/bench-math-exp10f.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_exp10f
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXP10F})

    set(BENCH_EXP2 benchtests/bench-math-exp2.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_exp2
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXP2})

    set(BENCH_EXP2F benchtests/bench-math-exp2f.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_exp2f
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXP2F})

    set(BENCH_EXPF benchtests/bench-math-expf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_expf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXPF})

    set(BENCH_EXPM1 benchtests/bench-math-expm1.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_expm1
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_EXPM1})

    set(BENCH_FMAX benchtests/bench-math-fmax.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_fmax
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_FMAX})

    set(BENCH_FMAXF benchtests/bench-math-fmaxf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_fmaxf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_FMAXF})

    set(BENCH_FMIN benchtests/bench-math-fmin.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_fmin
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_FMIN})

    set(BENCH_FMINF benchtests/bench-math-fminf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_fminf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_FMINF})

    set(BENCH_HYPOT benchtests/bench-math-hypot.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_hypot
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_HYPOT})

    set(BENCH_HYPOTF benchtests/bench-math-hypotf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_hypotf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_HYPOTF})

    set(BENCH_ILOGB benchtests/bench-math-ilogb.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_ilogb
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ILOGB})

    set(BENCH_ILOGBF benchtests/bench-math-ilogbf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_ilogbf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ILOGBF})

    set(BENCH_ISFINITE benchtests/bench-math-isfinite.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_isfinite
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ISFINITE})

    set(BENCH_ISINF benchtests/bench-math-isinf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_isinf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ISINF})

    set(BENCH_ISNAN benchtests/bench-math-isnan.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_isnan
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ISNAN})

    set(BENCH_J0 benchtests/bench-math-j0.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_j0
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_J0})

    set(BENCH_J1 benchtests/bench-math-j1.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_j1
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_J1})

    set(BENCH_LGAMMA benchtests/bench-math-lgamma.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_lgamma
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LGAMMA})

    set(BENCH_LOG benchtests/bench-math-log.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_log
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOG})

    set(BENCH_LOG10 benchtests/bench-math-log10.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_log10
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOG10})

    set(BENCH_LOG1P benchtests/bench-math-log1p.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_log1p
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOG1P})

    set(BENCH_LOG2 benchtests/bench-math-log2.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_log2
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOG2})

    set(BENCH_LOG2F benchtests/bench-math-log2f.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_log2f
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOG2F})

    set(BENCH_LOGB benchtests/bench-math-logb.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_logb
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOGB})

    set(BENCH_LOGBF benchtests/bench-math-logbf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_logbf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOGBF})

    set(BENCH_LOGF benchtests/bench-math-logf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_logf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_LOGF})

    set(BENCH_MODF benchtests/bench-math-modf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_modf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_MODF})

    set(BENCH_POW benchtests/bench-math-pow.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_pow
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_POW})

    set(BENCH_POWF benchtests/bench-math-powf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_powf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_POWF})

    set(BENCH_RINT benchtests/bench-math-rint.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_rint
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_RINT})

    set(BENCH_SIN benchtests/bench-math-sin.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_sin
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_SIN})

    set(BENCH_SINCOS benchtests/bench-math-sincos.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_sincos
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_SINCOS})

    set(BENCH_SINCOSF benchtests/bench-math-sincosf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_sincosf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_SINCOSF})

    set(BENCH_SINF benchtests/bench-math-sinf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_sinf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_SINF})

    set(BENCH_SINH benchtests/bench-math-sinh.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_sinh
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_SINH})

    set(BENCH_SQRT benchtests/bench-math-sqrt.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_sqrt
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_SQRT})

    set(BENCH_TAN benchtests/bench-math-tan.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_tan
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_TAN})

    set(BENCH_TANH benchtests/bench-math-tanh.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_tanh
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_TANH})

    set(BENCH_TGAMMA benchtests/bench-math-tgamma.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_tgamma
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_TGAMMA})

    set(BENCH_TRUNC benchtests/bench-math-trunc.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_trunc
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_TRUNC})

    set(BENCH_TRUNCF benchtests/bench-math-truncf.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_truncf
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_TRUNCF})

    set(BENCH_Y0 benchtests/bench-math-y0.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_y0
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_Y0})

    set(BENCH_Y1 benchtests/bench-math-y1.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_y1
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_Y1})

    set(BENCH_CBRTL benchtests/bench-math-cbrtl.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_cbrtl
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_CBRTL})
  endif()

  if(CONFIG_DISABLE_PTHREAD)
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E env python buildbench.py bench-pthread
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
      RESULT_VARIABLE result)

    set(BENCH_PTHREAD_ONCE benchtests/bench-pthread-pthread_once.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_pthread_once
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_PTHREAD_ONCE})

    set(BENCH_THREAD_CREATE benchtests/bench-pthread-thread_create.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_thread_create
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_THREAD_CREATE})

    if(CONFIG_PTHREAD_SPINLOCKS)
      set(BENCH_PTHREAD_LOCKS benchtests/bench-pthread-locks.c ${CSRCS})
      nuttx_add_application(
        NAME
        bench_pthread_locks
        PRIORITY
        ${CONFIG_BENCHTEST_PRIORITY}
        STACKSIZE
        ${CONFIG_BENCHTEST_STACKSIZE}
        COMPILE_FLAGS
        ${CFLAGS}
        SRCS
        ${BENCH_PTHREAD_LOCKS})
    endif()
  endif()

  if(CONFIG_CRYPTO_RANDOM_POOL)
    set(BENCH_ARC4RANDOM benchtests/bench-arc4random.c ${CSRCS})
    nuttx_add_application(
      NAME
      bench_arc4random
      PRIORITY
      ${CONFIG_BENCHTEST_PRIORITY}
      STACKSIZE
      ${CONFIG_BENCHTEST_STACKSIZE}
      COMPILE_FLAGS
      ${CFLAGS}
      SRCS
      ${BENCH_ARC4RANDOM})
  endif()

endif()
