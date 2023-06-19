#
# Copyright (C) 2023 Xiaomi Corporation
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

CFLAGS += ${INCDIR_PREFIX}mri
CFLAGS += ${INCDIR_PREFIX}mri/cmsis
CFLAGS += ${INCDIR_PREFIX}mri/cmsis/LPC43xx

CFLAGS += -DMRI_ALLWAYS_HARDWARE_BREAKPOINT
CFLAGS += -DMRI_THREAD_MRI=0
CFLAGS += -DSIGTRAP=5
CFLAGS += -DSIGBUS=7
CFLAGS += -DSIGSEGV=11
CFLAGS += -DSIGILL=4

CSRCS += mri/architectures/armv7-m/armv7-m.c
CSRCS += ${wildcard mri/core/*.c}
CSRCS += mri/memory/native/native-mem.c
CSRCS += mri/rtos/rtos_nuttx.c
CSRCS += mri/semihost/semihost.c
CSRCS += mri/semihost/mbed/semihost_mbed.c
CSRCS += mri/semihost/newlib/semihost_newlib.c

ASRCS += mri/semihost/newlib/newlib_stubs.S

include $(APPDIR)/Application.mk
