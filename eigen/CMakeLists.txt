#
# Copyright (C) 2024 Xiaomi Corporation
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

if(CONFIG_LIB_EIGEN)
  set(LIBEIGEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/eigen)

  nuttx_add_library(libeigen STATIC)

  set(CXXFLAGS
      -Wno-unused-but-set-variable
      -fno-var-tracking-assignments
      -Wno-unused-function
      -Wno-unused-variable
      -Wno-maybe-uninitialized
      -Wno-unused-local-typedefs
      -Wno-unused-parameter
      -Wno-return-type
      -Wno-nonnull
      -Wno-stringop-overflow
      -U__GLIBCXX__
      -DEIGEN_TEST_MAX_SIZE=320
      -DEIGEN_TEST_PART_1=1
      -DEIGEN_TEST_PART_2=1
      -DEIGEN_TEST_PART_3=1
      -DEIGEN_TEST_PART_4=1
      -DEIGEN_TEST_PART_5=1
      -DEIGEN_TEST_PART_6=1
      -DEIGEN_TEST_PART_7=1
      -DEIGEN_TEST_PART_8=1
      -DEIGEN_TEST_PART_9=1
      -DEIGEN_TEST_PART_10=1
      -DEIGEN_TEST_PART_11=1
      -DEIGEN_TEST_PART_12=1
      $<$<COMPILE_LANGUAGE:C++>:-Wno-dangling-reference>)

  file(GLOB CSRCS ${LIBEIGEN_DIR}/blas/*.c ${LIBEIGEN_DIR}/blas/f2c/*.c
       ${LIBEIGEN_DIR}/blas/*.cpp)

  set(INCDIR ${LIBEIGEN_DIR} ${LIBEIGEN_DIR}/Eigen/src
             ${LIBEIGEN_DIR}/unsupported)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_INCLUDE_DIRECTORIES ${INCDIR})
  target_sources(libeigen PRIVATE ${CSRCS})
  target_compile_options(libeigen PRIVATE ${CXXFLAGS})
  target_include_directories(libeigen PRIVATE ${INCDIR})

  if(CONFIG_LIB_EIGEN_TESTCASE)
    macro(add_eigen_test NAME)
      nuttx_add_application(
        NAME
        ${NAME}
        SRCS
        ${LIBEIGEN_DIR}/test/${NAME}.cpp
        INCLUDE_DIRECTORIES
        ${INCDIR}
        COMPILE_FLAGS
        ${CXXFLAGS}
        DEPENDS
        libeigen)
    endmacro()

    set(TEST
        clz
        rand
        meta
        maxsizevector
        numext
        sizeof
        dynalloc
        first_aligned
        type_alias
        nullary
        mixingtypes
        float_conversion
        io
        vectorization_logic
        basicstuff
        constexpr
        constructor
        linearstructure
        integer_types
        unalignedcount
        exceptions
        redux
        visitor
        block
        corners
        symbolic_index
        indexed_view
        reshape
        swap
        resize
        conservative_resize
        product_small
        product_extra
        skew_symmetric_matrix3
        adjoint
        miscmatrices
        commainitializer
        mapped_matrix
        mapstride
        unaryviewstride
        mapstaticmethods
        array_cwise
        array_for_matrix
        array_replicate
        array_reverse
        ref
        is_same_dense
        triangular
        selfadjoint
        product_selfadjoint
        product_symm
        product_syrk
        product_trmv
        product_trmm
        product_trsolve
        product_mmtr
        product_notemporary
        stable_norm
        permutationmatrices
        bandmatrix
        cholesky
        determinant
        inverse
        qr
        qr_colpivoting
        qr_fullpivoting
        upperbidiagonalization
        jacobi
        householder
        geo_orthomethods
        geo_quaternion
        geo_eulerangles
        geo_parametrizedline
        geo_alignedbox
        geo_hyperplane
        geo_homogeneous
        stdvector
        stdvector_overload
        stdlist
        stdlist_overload
        stddeque
        stddeque_overload
        sparse_block
        sparse_product
        sparse_ref
        sparse_solvers
        sparse_permutations
        simplicial_cholesky
        conjugate_gradient
        incomplete_cholesky
        bicgstab
        lscg
        sparselu
        sparseqr
        umeyama
        nestbyvalue
        dontalign
        evaluators
        sizeoverflow
        prec_inverse_4x4
        vectorwiseop
        special_numbers
        dense_storage
        ctorleak
        inplace_decomposition
        half_float
        bfloat16_float
        array_of_string
        num_dimensions
        stl_iterators
        blasutil
        random_matrix
        initializer_list_construction
        diagonal_matrix_variadic_ctor
        serializer
        tuple_test
        threads_eventcount
        threads_runqueue
        product_threaded
        fastmath)

    foreach(NAME ${TEST})
      add_eigen_test(${NAME})
    endforeach()
  endif()

endif()
