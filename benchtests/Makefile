#
# Copyright (C) 2020 Xiaomi Corporation
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

PRIORITY  = $(CONFIG_BENCHTEST_PRIORITY)
STACKSIZE = $(CONFIG_BENCHTEST_STACKSIZE)
MODULE    = $(CONFIG_BENCHTEST)

CFLAGS   += -DDURATION=$(CONFIG_BENCHTEST_DURATION)
CFLAGS   += -DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC
CFLAGS   += ${INCDIR_PREFIX}$(APPDIR)/external/benchtests/port
CFLAGS   += -Dxmalloc=benchtests_xmalloc

CSRCS    += benchtests/json-lib.c
CSRCS    += port/error.c
CSRCS    += port/ifunc-impl-list.c
CSRCS    += port/programs/xmalloc.c
CSRCS    += port/string/generic.c
CSRCS    += port/support/support_test_main.c
CSRCS    += port/support/support.c
CSRCS    += port/support/timespec.c
CSRCS    += port/support/xthread.c

#bench-string

ifeq ($(CONFIG_BENCHTEST_STRING),y)
PROGNAME += bench_bzero
MAINSRC  += benchtests/bench-bzero.c
PROGNAME += bench_memccpy
MAINSRC  += benchtests/bench-memccpy.c
PROGNAME += bench_memchr
MAINSRC  += benchtests/bench-memchr.c
PROGNAME += bench_memcmp
MAINSRC  += benchtests/bench-memcmp.c
PROGNAME += bench_memcpy
MAINSRC  += benchtests/bench-memcpy.c
PROGNAME += bench_memmem
MAINSRC  += benchtests/bench-memmem.c
PROGNAME += bench_memmove
MAINSRC  += benchtests/bench-memmove.c
PROGNAME += bench_mempcpy
MAINSRC  += benchtests/bench-mempcpy.c
PROGNAME += bench_memrchr
MAINSRC  += benchtests/bench-memrchr.c
PROGNAME += bench_memset
MAINSRC  += benchtests/bench-memset.c
PROGNAME += bench_memset_zero
MAINSRC  += benchtests/bench-memset-zero.c
PROGNAME += bench_rawmemchr
MAINSRC  += benchtests/bench-rawmemchr.c
PROGNAME += bench_stpcpy
MAINSRC  += benchtests/bench-stpcpy.c
PROGNAME += bench_stpncpy
MAINSRC  += benchtests/bench-stpncpy.c
PROGNAME += bench_strcasecmp
MAINSRC  += benchtests/bench-strcasecmp.c
PROGNAME += bench_strcasestr
MAINSRC  += benchtests/bench-strcasestr.c
PROGNAME += bench_strcat
MAINSRC  += benchtests/bench-strcat.c
PROGNAME += bench_strchr
MAINSRC  += benchtests/bench-strchr.c
PROGNAME += bench_strchrnul
MAINSRC  += benchtests/bench-strchrnul.c
PROGNAME += bench_strcmp
MAINSRC  += benchtests/bench-strcmp.c
PROGNAME += bench_strcpy
MAINSRC  += benchtests/bench-strcpy.c
PROGNAME += bench_strcspn
MAINSRC  += benchtests/bench-strcspn.c
PROGNAME += bench_strlen
MAINSRC  += benchtests/bench-strlen.c
PROGNAME += bench_strncasecmp
MAINSRC  += benchtests/bench-strncasecmp.c
PROGNAME += bench_strncat
MAINSRC  += benchtests/bench-strncat.c
PROGNAME += bench_strncmp
MAINSRC  += benchtests/bench-strncmp.c
PROGNAME += bench_strncpy
MAINSRC  += benchtests/bench-strncpy.c
PROGNAME += bench_strnlen
MAINSRC  += benchtests/bench-strnlen.c
PROGNAME += bench_strpbrk
MAINSRC  += benchtests/bench-strpbrk.c
PROGNAME += bench_strrchr
MAINSRC  += benchtests/bench-strrchr.c
PROGNAME += bench_strsep
MAINSRC  += benchtests/bench-strsep.c
PROGNAME += bench_strspn
MAINSRC  += benchtests/bench-strspn.c
PROGNAME += bench_strstr
MAINSRC  += benchtests/bench-strstr.c
PROGNAME += bench_strtok
MAINSRC  += benchtests/bench-strtok.c
endif

#other

context::
	python buildbench.py bench-string
	python buildbench.py stdio-common-benchset

PROGNAME += bench_ffs
MAINSRC  += benchtests/bench-string-ffs.c
PROGNAME += bench_ffsll
MAINSRC  += benchtests/bench-string-ffsll.c
PROGNAME += bench_strtod
MAINSRC  += benchtests/bench-strtod.c
PROGNAME += bench_sprintf
MAINSRC  += benchtests/stdio-common-benchset-sprintf.c
PROGNAME += bench_malloc_thread
MAINSRC  += benchtests/bench-malloc-thread.c
PROGNAME += bench_malloc_simple
MAINSRC  += benchtests/bench-malloc-simple.c

ifneq ($(CONFIG_LIBM_NONE),y)
context::
	python buildbench.py bench-math

PROGNAME += bench_acos
MAINSRC  += benchtests/bench-math-acos.c
PROGNAME += bench_acosh
MAINSRC  += benchtests/bench-math-acosh.c
PROGNAME += bench_asin
MAINSRC  += benchtests/bench-math-asin.c
PROGNAME += bench_asinh
MAINSRC  += benchtests/bench-math-asinh.c
PROGNAME += bench_atan
MAINSRC  += benchtests/bench-math-atan.c
PROGNAME += bench_atan2
MAINSRC  += benchtests/bench-math-atan2.c
PROGNAME += bench_atanh
MAINSRC  += benchtests/bench-math-atanh.c
PROGNAME += bench_cbrt
MAINSRC  += benchtests/bench-math-cbrt.c
PROGNAME += bench_cos
MAINSRC  += benchtests/bench-math-cos.c
PROGNAME += bench_cosf
MAINSRC  += benchtests/bench-math-cosf.c
PROGNAME += bench_cosh
MAINSRC  += benchtests/bench-math-cosh.c
PROGNAME += bench_erf
MAINSRC  += benchtests/bench-math-erf.c
PROGNAME += bench_erfc
MAINSRC  += benchtests/bench-math-erfc.c
PROGNAME += bench_exp
MAINSRC  += benchtests/bench-math-exp.c
PROGNAME += bench_exp10
MAINSRC  += benchtests/bench-math-exp10.c
PROGNAME += bench_exp10f
MAINSRC  += benchtests/bench-math-exp10f.c
PROGNAME += bench_exp2
MAINSRC  += benchtests/bench-math-exp2.c
PROGNAME += bench_exp2f
MAINSRC  += benchtests/bench-math-exp2f.c
PROGNAME += bench_expf
MAINSRC  += benchtests/bench-math-expf.c
PROGNAME += bench_expm1
MAINSRC  += benchtests/bench-math-expm1.c
PROGNAME += bench_fmax
MAINSRC  += benchtests/bench-math-fmax.c
PROGNAME += bench_fmaxf
MAINSRC  += benchtests/bench-math-fmaxf.c
PROGNAME += bench_fmin
MAINSRC  += benchtests/bench-math-fmin.c
PROGNAME += bench_fminf
MAINSRC  += benchtests/bench-math-fminf.c
PROGNAME += bench_hypot
MAINSRC  += benchtests/bench-math-hypot.c
PROGNAME += bench_hypotf
MAINSRC  += benchtests/bench-math-hypotf.c
PROGNAME += bench_ilogb
MAINSRC  += benchtests/bench-math-ilogb.c
PROGNAME += bench_ilogbf
MAINSRC  += benchtests/bench-math-ilogbf.c
PROGNAME += bench_isfinite
MAINSRC  += benchtests/bench-math-isfinite.c
PROGNAME += bench_isinf
MAINSRC  += benchtests/bench-math-isinf.c
PROGNAME += bench_isnan
MAINSRC  += benchtests/bench-math-isnan.c
PROGNAME += bench_j0
MAINSRC  += benchtests/bench-math-j0.c
PROGNAME += bench_j1
MAINSRC  += benchtests/bench-math-j1.c
PROGNAME += bench_lgamma
MAINSRC  += benchtests/bench-math-lgamma.c
PROGNAME += bench_log
MAINSRC  += benchtests/bench-math-log.c
PROGNAME += bench_log10
MAINSRC  += benchtests/bench-math-log10.c
PROGNAME += bench_log1p
MAINSRC  += benchtests/bench-math-log1p.c
PROGNAME += bench_log2
MAINSRC  += benchtests/bench-math-log2.c
PROGNAME += bench_log2f
MAINSRC  += benchtests/bench-math-log2f.c
PROGNAME += bench_logb
MAINSRC  += benchtests/bench-math-logb.c
PROGNAME += bench_logbf
MAINSRC  += benchtests/bench-math-logbf.c
PROGNAME += bench_logf
MAINSRC  += benchtests/bench-math-logf.c
PROGNAME += bench_modf
MAINSRC  += benchtests/bench-math-modf.c
PROGNAME += bench_pow
MAINSRC  += benchtests/bench-math-pow.c
PROGNAME += bench_powf
MAINSRC  += benchtests/bench-math-powf.c
PROGNAME += bench_rint
MAINSRC  += benchtests/bench-math-rint.c
PROGNAME += bench_sin
MAINSRC  += benchtests/bench-math-sin.c
PROGNAME += bench_sincos
MAINSRC  += benchtests/bench-math-sincos.c
PROGNAME += bench_sincosf
MAINSRC  += benchtests/bench-math-sincosf.c
PROGNAME += bench_sinf
MAINSRC  += benchtests/bench-math-sinf.c
PROGNAME += bench_sinh
MAINSRC  += benchtests/bench-math-sinh.c
PROGNAME += bench_sqrt
MAINSRC  += benchtests/bench-math-sqrt.c
PROGNAME += bench_tan
MAINSRC  += benchtests/bench-math-tan.c
PROGNAME += bench_tanh
MAINSRC  += benchtests/bench-math-tanh.c
PROGNAME += bench_tgamma
MAINSRC  += benchtests/bench-math-tgamma.c
PROGNAME += bench_trunc
MAINSRC  += benchtests/bench-math-trunc.c
PROGNAME += bench_truncf
MAINSRC  += benchtests/bench-math-truncf.c
PROGNAME += bench_y0
MAINSRC  += benchtests/bench-math-y0.c
PROGNAME += bench_y1
MAINSRC  += benchtests/bench-math-y1.c
PROGNAME += bench_cbrtl
MAINSRC  += benchtests/bench-math-cbrtl.c
endif

ifneq ($(CONFIG_DISABLE_PTHREAD),y)
context::
	python buildbench.py bench-pthread

PROGNAME += bench_pthread_once
MAINSRC  += benchtests/bench-pthread-pthread_once.c
PROGNAME += bench_thread_create
MAINSRC  += benchtests/bench-pthread-thread_create.c
  ifneq ($(CONFIG_PTHREAD_SPINLOCKS),)
    PROGNAME += bench_pthread_locks
    MAINSRC  += benchtests/bench-pthread-locks.c
  endif
endif

ifneq ($(CONFIG_CRYPTO_RANDOM_POOL),)
PROGNAME += bench_arc4random
MAINSRC  += benchtests/bench-arc4random.c
endif

include $(APPDIR)/Application.mk
