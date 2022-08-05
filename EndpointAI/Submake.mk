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

CSRCS += arm_2d.c
CSRCS += arm_2d_conversion.c
CSRCS += arm_2d_async.c
CSRCS += arm_2d_alpha_blending.c
CSRCS += arm_2d_draw.c
CSRCS += arm_2d_rotation.c
CSRCS += arm_2d_helium.c

CFLAGS += -D__ARM_2D_HAS_ASYNC__=0
CFLAGS += -Wno-undef -flax-vector-conversions -fms-extensions

VPATH += Kernels/Research/Arm-2D/Library/Source


include $(APPDIR)/Application.mk
