#
# Copyright (C) 2024 Xiaomi Corporation
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

CXXEXT := .cpp

RIVE_RUNTIME_DIR = ${INCDIR_PREFIX}$(APPDIR)/external/rive-runtime/rive-runtime

CXXFLAGS += -Wno-shadow -Wno-sign-compare -Wno-class-memaccess -Wno-alloc-size-larger-than
CXXFLAGS += -Wno-format-security -Wno-format -Wno-nonnull -Wno-maybe-uninitialized -Wno-stringop-overflow -Wno-array-bounds

CXXSRCS += $(shell find -L rive-runtime/src -path rive-runtime/src/audio -prune -o -name *.cpp -print)

CXXFLAGS += -D_RIVE_INTERNAL_=1

ifeq ($(CONFIG_VG_ANIMATION_VIEW_AUDIO),y)
CXXFLAGS += -DWITH_RIVE_AUDIO=1
CXXFLAGS += -DEXTERNAL_RIVE_AUDIO_ENGINE=1
CXXFLAGS += -DWITH_CUSTOM_RIVE_AUDIO=1
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/frameworks/graphics/animengine/rive/audio
endif

ifeq ($(and $(CONFIG_LIB_HARFBUZZ),$(CONFIG_LIB_SHEENBIDI)),y)
CXXFLAGS += -DWITH_RIVE_TEXT=1
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/SheenBidi/SheenBidi/Headers
CXXFLAGS +=  ${INCDIR_PREFIX}$(APPDIR)/external/harfbuzz/harfbuzz/src
endif

ifeq ($(and $(CONFIG_SCHED_INSTRUMENTATION),$(CONFIG_RIVE_RUNTIME_PROFILER)),y)
CXXFLAGS += "-DRIVE_RUNTIME_PROFILER_BEGIN=sched_note_begin(NOTE_TAG_GRAPHICS)"
CXXFLAGS += "-DRIVE_RUNTIME_PROFILER_END=sched_note_end(NOTE_TAG_GRAPHICS)"

CXXFLAGS += "-DRIVE_RUNTIME_PROFILER_BEGINEX(str)=sched_note_beginex(NOTE_TAG_GRAPHICS, str)"
CXXFLAGS += "-DRIVE_RUNTIME_PROFILER_ENDEX(str)=sched_note_endex(NOTE_TAG_GRAPHICS, str)"
endif

ifeq ($(RIVE_RUNTIME_LAYOUT),)
CXXFLAGS += -DWITH_RIVE_LAYOUT=1
CXXFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/yoga/yoga
endif

CXXFLAGS += -Os -ftree-vectorize
include $(APPDIR)/Application.mk
