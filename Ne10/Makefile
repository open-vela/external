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

SKIP_DSP_CSRCS += Ne10/modules/dsp/NE10_fft_float32.neonintrinsic.c
SKIP_DSP_CSRCS += Ne10/modules/dsp/NE10_fft_int32.neonintrinsic.c
SKIP_DSP_CSRCS += Ne10/modules/dsp/NE10_fft_int16.neonintrinsic.c
SKIP_DSP_CSRCS += Ne10/modules/dsp/NE10_rfft_float32.neonintrinsic.c

CXXEXT := .cpp
CXXSRCS += $(wildcard Ne10/modules/dsp/*.cpp)

CSRCS += $(wildcard Ne10/common/*.c)
CSRCS += $(wildcard Ne10/modules/*.c)
CSRCS += $(filter-out $(SKIP_DSP_CSRCS), $(wildcard Ne10/modules/dsp/*.c))
CSRCS += $(wildcard Ne10/modules/imgproc/*.c)
CSRCS += $(wildcard Ne10/modules/math/*.c)
CSRCS += $(wildcard Ne10/modules/physics/*.c)

ASRCS += $(wildcard Ne10/modules/dsp/*.s)
ASRCS += $(wildcard Ne10/modules/imgproc/*.s)
ASRCS += $(wildcard Ne10/modules/math/*.s)
ASRCS += $(wildcard Ne10/modules/physics/*.s)

FLAGS += -INe10/inc
FLAGS += -INe10/common
FLAGS += -INe10/modules/math

FLAGS += -D__MACH__

FLAGS += -DENABLE_NE10_FIR_FLOAT_NEON
FLAGS += -DENABLE_NE10_FIR_DECIMATE_FLOAT_NEON
FLAGS += -DENABLE_NE10_FIR_INTERPOLATE_FLOAT_NEON
FLAGS += -DENABLE_NE10_FIR_LATTICE_FLOAT_NEON
FLAGS += -DENABLE_NE10_FIR_SPARSE_FLOAT_NEON
FLAGS += -DENABLE_NE10_IIR_LATTICE_FLOAT_NEON

FLAGS += -DENABLE_NE10_IMG_ROTATE_RGBA_NEON

FLAGS += -DENABLE_NE10_PHYSICS_COMPUTE_AABB_VEC2F_NEON
FLAGS += -DENABLE_NE10_PHYSICS_RELATIVE_V_VEC2F_NEON
FLAGS += -DENABLE_NE10_PHYSICS_APPLY_IMPULSE_VEC2F_NEON

FLAGS += -DNE10_ENABLE_DSP
FLAGS += -DNE10_ENABLE_IMGPROC
FLAGS += -DNE10_ENABLE_MATH
FLAGS += -DNE10_ENABLE_PHYSICS

AFLAGS += $(FLAGS)
CFLAGS += $(FLAGS)
CXXFLAGS += $(FLAGS)

include $(APPDIR)/Application.mk
