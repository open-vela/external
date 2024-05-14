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
if(CONFIG_LIB_QPOASES)
  set(LIBQPOASES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/qpoases)

  nuttx_add_library(libqpoases STATIC)

  set(CXXFALGS
      -D__DSPACE__=1
      -Wno-format-truncation
      -Wno-unused-variable
      -Wno-undef
      -Wno-misleading-indentation
      -Wno-shadow
      -Wno-use-after-free
      $<$<COMPILE_LANGUAGE:C>:-Wno-strict-prototypes>
      $<$<COMPILE_LANGUAGE:CXX>:-Wno-overloaded-virtual>)

  set(INCDIR ${LIBQPOASES_DIR}/include ${LIBQPOASES_DIR}/interfaces/c)
  file(GLOB CXXSRCS ${LIBQPOASES_DIR}/src/*.cpp
       ${LIBQPOASES_DIR}/interfaces/c/*.cpp)

  if(CONFIG_LIB_QPOASES_TESTCASE)
    macro(add_qpoases_test NAME DIR SUFFIX)
      nuttx_add_application(
        NAME
        ${NAME}
        SRCS
        ${LIBQPOASES_DIR}/${DIR}/${NAME}.${SUFFIX}
        INCLUDE_DIRECTORIES
        ${INCDIR}
        COMPILE_FLAGS
        ${CXXFALGS}
        DEPENDS
        libqpoases)
    endmacro()

    set(C_TEST test_c_example1 test_c_example1a test_c_example1b)
    set(CPP_TEST
        test_bench
        test_constraintProduct1
        test_constraintProduct2
        test_example1
        test_example1a
        test_example1b
        test_example2
        test_example5
        test_example6
        test_example7
        test_exampleLP
        test_externalChol1
        test_gradientShift
        test_guessedWS1
        test_hs268
        test_identitySqproblem
        test_infeasible1
        test_janick1
        test_janick2
        test_matrices
        test_matrices2
        test_matrices3
        test_qrecipe
        test_qrecipeSchur
        test_runAllOqpExamples
        test_sebastien1
        test_smallSchur
        test_vanBarelsUnboundedQP)

    set(EXAMPLES
        example1
        example1a
        example1b
        example2
        example3
        example3b
        example4
        example5
        exampleLP
        qrecipe
        qrecipeSchur)

    foreach(NAME ${C_TEST})
      add_qpoases_test(${NAME} testing/c c)
    endforeach()

    foreach(NAME ${CPP_TEST})
      add_qpoases_test(${NAME} testing/cpp cpp)
    endforeach()

    foreach(NAME ${EXAMPLES})
      add_qpoases_test(${NAME} examples cpp)
    endforeach()

  endif()

  target_sources(libqpoases PRIVATE ${CXXSRCS})
  target_compile_options(libqpoases PRIVATE ${CXXFALGS})
  target_include_directories(libqpoases PRIVATE ${INCDIR})

endif()
