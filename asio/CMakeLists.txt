if(CONFIG_LIB_ASIO)

  set(LIBASIO_DIR ${CMAKE_CURRENT_LIST_DIR}/asio)

  set(CXXFLAGS -Wundef -DASIO_STANDALONE -DASIO_SEPARATE_COMPILATION)

  set(INCDIR
      ${LIBASIO_DIR}/include
      ${CMAKE_SOURCE_DIR}/include)

  list(APPEND CSRCS ${LIBASIO_DIR}/src/asio.cpp)

  if(CONFIG_OPENSSL_MBEDTLS_WRAPPER)
    list(APPEND CSRCS ${LIBASIO_DIR}/src/asio_ssl.cpp)
  endif()

  nuttx_add_library(asio STATIC)

  target_compile_options(asio PRIVATE ${CXXFLAGS})
  target_include_directories(asio PRIVATE ${INCDIR})
  target_sources(asio PRIVATE ${CSRCS})

endif()