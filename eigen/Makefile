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

CXXEXT = .cpp

CFLAGS += -Wno-unused-but-set-variable -Wno-maybe-uninitialized
CSRCS += $(wildcard eigen/blas/*.c)
CSRCS += $(wildcard eigen/blas/f2c/*.c)
CXXSRCS += $(wildcard eigen/blas/*.cpp)

CXXFLAGS += ${INCDIR_PREFIX}eigen
CXXFLAGS += ${INCDIR_PREFIX}eigen/Eigen
CXXFLAGS += ${INCDIR_PREFIX}eigen/Eigen/src
CXXFLAGS += ${INCDIR_PREFIX}eigen/unsupported

# Default compilation parameters for third-party libraries
CXXFLAGS += ${DEFINE_PREFIX}EIGEN_TEST_MAX_SIZE=320
            ${DEFINE_PREFIX}EIGEN_TEST_PART_1=1 ${DEFINE_PREFIX}EIGEN_TEST_PART_2=1
            ${DEFINE_PREFIX}EIGEN_TEST_PART_3=1 ${DEFINE_PREFIX}EIGEN_TEST_PART_4=1
            ${DEFINE_PREFIX}EIGEN_TEST_PART_5=1 ${DEFINE_PREFIX}EIGEN_TEST_PART_6=1
            ${DEFINE_PREFIX}EIGEN_TEST_PART_7=1 ${DEFINE_PREFIX}EIGEN_TEST_PART_8=1
            ${DEFINE_PREFIX}EIGEN_TEST_PART_9=1 ${DEFINE_PREFIX}EIGEN_TEST_PART_10=1
            ${DEFINE_PREFIX}EIGEN_TEST_PART_11=1 ${DEFINE_PREFIX}EIGEN_TEST_PART_12=1

# Compatible with NuttX conflict resolution and added compilation options
CXXFLAGS += -U__GLIBCXX__
CXXFLAGS += -DEIGEN_NO_IO
CXXFLAGS += -fno-var-tracking-assignments
CXXFLAGS += -Wno-unused-function -Wno-unused-variable -Wno-maybe-uninitialized
CXXFLAGS += -Wno-unused-local-typedefs -Wno-unused-parameter -Wno-return-type
CXXFLAGS += -Wno-dangling-reference -Wno-nonnull

define eigen_add_benchmark
  PROGNAME += $2
  MAINSRC += eigen/test/$2.cpp
  PRIORITY += SCHED_PRIORITY_DEFAULT
  STACKSIZE += $(CONFIG_DEFAULT_TASK_STACKSIZE)
endef

ifneq ($(CONFIG_LIB_EIGEN_TESTCASE),)
# Unsupported test cases
EIGEN_EXCLUDE_CASE := accelerate_support cholmod_support eigen2support \
klu_support metis_support pardiso_support pastix_support spqr_support superlu_support umfpack_support

# Add test cases with compilation errors
EIGEN_EXCLUDE_CASE += bdcsvd boostmultiprec bug1213 jacobisvd qtvector sycl_basic

EIGEN_ALL_CASE := $(wildcard eigen/test/*.cpp)

# Filter unnecessary files
BENCHMARKS := $(filter-out $(EIGEN_EXCLUDE_CASE), $(patsubst %.cpp,%,$(notdir $(EIGEN_ALL_CASE))))

$(foreach benchmark,$(BENCHMARKS),$(eval $(call eigen_add_benchmark,test,$(benchmark))))
endif
include $(APPDIR)/Application.mk
