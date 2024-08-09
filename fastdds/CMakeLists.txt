if(CONFIG_FASTDDS)
  include(ExternalProject)

  set(LIB_FASTDDS_DIR ${CMAKE_CURRENT_LIST_DIR}/Fast-DDS)
  set(BUILD_MEMORY_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/memory)
  set(BUILD_FASTDDS_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/external/fastdds)
  set(EXTERNAL_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

  set(NUTTX 1)
  set(HAVE_CXX20 1)
  set(HAVE_CXX17 0)
  set(FASTDDS_IS_BIG_ENDIAN_TARGET 0)
  set(IS_THIRDPARTY_BOOST_OK 1)
  set(SQLITE3_SUPPORT 0)
  set(COMPILE_TOOLS OFF)

  if(CONFIG_FASTDDS_ENABLE_OLD_LOG_MACROS)
    set(ENABLE_OLD_LOG_MACROS_ 1)
  endif()

  if(CONFIG_FASTDDS_LOG_NO_INFO)
    set(LOG_NO_INFO 1)
  endif()

  if(CONFIG_FASTDDS_LOG_NO_WARNING)
    set(LOG_NO_WARNING 1)
  endif()

  if(CONFIG_FASTDDS_LOG_NO_ERROR)
    set(LOG_NO_ERROR 1)
  endif()

  set(BUILD_SHARED_LIBS OFF)
  set(SECURITY 0)
  set(TINYXML2_SOURCE_DIR "${EXTERNAL_DIR}/tinyxml2/tinyxml2")
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${LIB_FASTDDS_DIR}/cmake/modules)

  set(FASTDDS_FLAGS
      -pedantic
      -Wextra
      -Wno-unknown-pragmas
      -Wno-error=deprecated-declarations
      -fexceptions
      -U__VXWORKS__
      -Wno-shadow
      -Wno-undef
      -Wno-unused-parameter
      -DBOOST_INTERPROCESS_SHARED_DIR_PATH="${CONFIG_FS_SHMFS_VFS_PATH}")

  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    list(APPEND FASTDDS_FLAGS -Wno-psabi)
  endif()

  include_directories(${CMAKE_CURRENT_LIST_DIR}/Fast-CDR/include
                      ${CMAKE_CURRENT_BINARY_DIR}/Fast-CDR/include)
  include_directories(${CMAKE_CURRENT_LIST_DIR}/Fast-DDS/include
                      ${CMAKE_CURRENT_BINARY_DIR}/Fast-DDS/include)
  include_directories(${CMAKE_CURRENT_LIST_DIR}/memory/include)
  include_directories(${LIB_FASTDDS_DIR}/thirdparty/nlohmann-json)
  include_directories(${LIB_FASTDDS_DIR}/thirdparty/filewatch)
  include_directories(${LIB_FASTDDS_DIR}/thirdparty/boost/include)
  include_directories(${LIB_FASTDDS_DIR}/thirdparty/optionparser)
  include_directories(${BUILD_FASTDDS_INSTALL_PREFIX}/include)
  include_directories(${BUILD_FASTDDS_INSTALL_PREFIX}/include/foonathan_memory)
  include_directories(${TINYXML2_SOURCE_DIR}/)
  link_directories(${BUILD_FASTDDS_INSTALL_PREFIX}/lib)

  set(PROJECT_SOURCE_DIR ${LIB_FASTDDS_DIR})
  set(USE_THIRDPARTY_SHARED_MUTEX ON)
  set(BUILD_SHARED_LIBS OFF)

  set(BIN_INSTALL_DIR
      bin/
      CACHE PATH "Installation directory for binaries")
  set(INCLUDE_INSTALL_DIR
      "include/"
      CACHE PATH "Installation directory for C++ headers")
  set(LIB_INSTALL_DIR
      lib/
      CACHE PATH "Installation directory for libraries")
  set(DATA_INSTALL_DIR
      share/
      CACHE PATH "Installation directory for data")
  set(DOC_DIR "${DATA_INSTALL_DIR}/doc")
  set(DOC_INSTALL_DIR
      ${DOC_DIR}
      CACHE PATH "Installation directory for documentation")
  set(LICENSE_INSTALL_DIR
      ${DATA_INSTALL_DIR}/${PROJECT_NAME}
      CACHE PATH "Installation directory for licenses")
  set(Asio_INCLUDE_DIR ${EXTERNAL_DIR}/asio/asio/asio/include)
  set(CMAKE_DL_LIBS
      ""
      CACHE STRING "Disable dl.so")
  set(FOONATHAN_MEMORY_BUILD_TOOLS OFF)

  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -I${NUTTX_DIR}/libs/libxx/libcxx/include -I${NUTTX_DIR}/include -I${CMAKE_BINARY_DIR}/include"
  )
  add_subdirectory(${BUILD_MEMORY_SRC_DIR})
  nuttx_add_external_library(foonathan_memory)
  target_compile_options(foonathan_memory PRIVATE ${FASTDDS_FLAGS})

  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Fast-CDR)
  nuttx_add_external_library(fastcdr)
  target_compile_options(fastcdr PRIVATE ${FASTDDS_FLAGS})

  include(CMakeDependentOption)
  set(INTERNAL_DEBUG ON)
  set(SHM_TRANSPORT_DEFAULT OFF)

  add_subdirectory(${LIB_FASTDDS_DIR})
  nuttx_add_external_library(fastdds)
  target_compile_options(fastdds PRIVATE ${FASTDDS_FLAGS})

  set(DDS_EXAMPLE_SOURCES "")

  function(add_example_src_file arg)
    set(DDS_EXAMPLE_SOURCES
        ${arg}/HelloWorld_main.cpp ${arg}/HelloWorldPublisher.cpp
        ${arg}/HelloWorldSubscriber.cpp ${arg}/HelloWorldPubSubTypes.cxx
        ${arg}/HelloWorldTypeObjectSupport.cxx
        PARENT_SCOPE)
  endfunction()

  if(CONFIG_FASTDDS_HelloWorldExample)
    set(DDS_EXAMPLE_DIR ${LIB_FASTDDS_DIR}/examples/cpp/dds/HelloWorldExample)
    add_example_src_file(${DDS_EXAMPLE_DIR})

  elseif(CONFIG_FASTDDS_HelloWorldExampleTCP)
    set(DDS_EXAMPLE_DIR
        ${LIB_FASTDDS_DIR}/examples/cpp/dds/HelloWorldExampleTCP)
    add_example_src_file(${DDS_EXAMPLE_DIR})

  elseif(CONFIG_FASTDDS_HelloWorldExampleSharedMem)
    set(DDS_EXAMPLE_DIR
        ${LIB_FASTDDS_DIR}/examples/cpp/dds/HelloWorldExampleSharedMem)
    add_example_src_file(${DDS_EXAMPLE_DIR})

  elseif(CONFIG_FASTDDS_ZeroCopyExample)
    set(DDS_EXAMPLE_DIR ${LIB_FASTDDS_DIR}/examples/cpp/dds/ZeroCopyExample)
    add_example_src_file(${DDS_EXAMPLE_DIR})
  elseif(CONFIG_FASTDDS_BasicConfigurationExample)
    set(DDS_EXAMPLE_DIR
        ${LIB_FASTDDS_DIR}/examples/cpp/dds/BasicConfigurationExample)
    set(DDS_EXAMPLE_SOURCES
        ${DDS_EXAMPLE_DIR}/BasicConfiguration_main.cpp
        ${DDS_EXAMPLE_DIR}/BasicConfigurationPublisher.cpp
        ${DDS_EXAMPLE_DIR}/BasicConfigurationSubscriber.cpp
        ${DDS_EXAMPLE_DIR}/HelloWorldPubSubTypes.cxx
        ${DDS_EXAMPLE_DIR}/HelloWorldTypeObjectSupport.cxx)
  elseif(CONFIG_FASTDDS_DiscoveryServerExample)
    set(DDS_EXAMPLE_DIR
        ${LIB_FASTDDS_DIR}/examples/cpp/dds/DiscoveryServerExample)
    set(DDS_EXAMPLE_SOURCES
        ${DDS_EXAMPLE_DIR}/DiscoveryServer_main.cpp
        ${DDS_EXAMPLE_DIR}/DiscoveryServerPublisher.cpp
        ${DDS_EXAMPLE_DIR}/DiscoveryServerServer.cpp
        ${DDS_EXAMPLE_DIR}/DiscoveryServerSubscriber.cpp
        ${DDS_EXAMPLE_DIR}/types/HelloWorldPubSubTypes.cxx
        ${DDS_EXAMPLE_DIR}/types/HelloWorldTypeObjectSupport.cxx)
  endif()

  if(NOT CONFIG_FASTDDS_NoExample)
    nuttx_add_application(
      NAME
      DDSHelloWorldExample
      SRCS
      ${DDS_EXAMPLE_SOURCES}
      INCLUDE_DIRECTORIES
      ${DDS_EXAMPLE_DIR}
      COMPILE_FLAGS
      ${FASTDDS_FLAGS}
      DEPENDS
      fastcdr
      foonathan_memory
      fastdds
      fastdds::optionparser
      STACKSIZE
      2097152
      PRIORITY
      100)
  endif()
endif()
