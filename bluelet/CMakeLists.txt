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

if(CONFIG_LIB_BLUELET)

  # Source Directories
  set(SUBDIR ${CMAKE_CURRENT_SOURCE_DIR})
  get_filename_component(SUBDIR_NAME ${SUBDIR} NAME)

  # Flags
  set(CFLAGS)
  set(CSRCS)
  set(INCDIR)

  if(EXISTS ${SUBDIR}/${SUBDIR_NAME})
    set(STACKDIR ${SUBDIR}/${SUBDIR_NAME}/src/stack)
    set(ADAPTERDIR ${SUBDIR}/${SUBDIR_NAME}/src/samples/stack_adapter)

    file(GLOB APPEND_FILES ${STACKDIR}/btcommon/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/bluelet/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/hci/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/l2cap/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/avdtp/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/avctp/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/avrcp/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/a2dp/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/sbc/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/sco/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/sdp/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/sdap/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/gap/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${STACKDIR}/ots/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    file(GLOB APPEND_FILES ${ADAPTERDIR}/src/*.c)
    list(APPEND CSRCS ${APPEND_FILES})

    if(CONFIG_LE)
      file(GLOB APPEND_FILES ${STACKDIR}/att/*.c)
      list(APPEND CSRCS ${APPEND_FILES})

      file(GLOB APPEND_FILES ${STACKDIR}/smp/*.c)
      list(APPEND CSRCS ${APPEND_FILES})

      if(CONFIG_LE_AUDIO)
        file(GLOB APPEND_FILES ${STACKDIR}/le_audio/*.c)
        list(APPEND CSRCS ${APPEND_FILES})
      endif()
    endif()

    if(CONFIG_HID)
      file(GLOB APPEND_FILES ${STACKDIR}/hid/*.c)
      list(APPEND CSRCS ${APPEND_FILES})

      list(APPEND INCDIR ${STACKDIR}/hid)
    endif()

    if(CONFIG_RFCOMM)
      file(GLOB APPEND_FILES ${STACKDIR}/rfcomm/*.c)
      list(APPEND CSRCS ${APPEND_FILES})

      file(GLOB APPEND_FILES ${STACKDIR}/spp/*.c)
      list(APPEND CSRCS ${APPEND_FILES})

      list(APPEND INCDIR ${STACKDIR}/rfcomm)
    endif()

    if(CONFIG_OBEX)
      file(GLOB APPEND_FILES ${STACKDIR}/obex/*.c)
      list(APPEND CSRCS ${APPEND_FILES})

      if(CONFIG_MAP)
        file(GLOB APPEND_FILES ${STACKDIR}/map/*.c)
        list(APPEND CSRCS ${APPEND_FILES})
      endif()

      if(CONFIG_BIP)
        file(GLOB APPEND_FILES ${STACKDIR}/bip/*.c)
        list(APPEND CSRCS ${APPEND_FILES})
      endif()

      if(CONFIG_PBAP)
        file(GLOB APPEND_FILES ${STACKDIR}/pbap/*.c)
        list(APPEND CSRCS ${APPEND_FILES})
      endif()
    endif()

    if(CONFIG_HFP)
      file(GLOB APPEND_FILES ${STACKDIR}/hfp/*.c)
      list(APPEND CSRCS ${APPEND_FILES})
    endif()

    if(CONFIG_BNEP)
      file(GLOB APPEND_FILES ${STACKDIR}/bnep/*.c)
      list(APPEND CSRCS ${APPEND_FILES})
  endif()

    if(CONFIG_PAN)
      file(GLOB APPEND_FILES ${STACKDIR}/pan/*.c)
      list(APPEND CSRCS ${APPEND_FILES})
    endif()

    if(CONFIG_BLUELET_HCI_H4)
      list(APPEND CSRCS ${STACKDIR}/portings/btunix/h4tl.c)
    endif()

    if(CONFIG_BLUELET_A2DP_SINK_NUTTX)
      list(APPEND CSRCS ${STACKDIR}/portings/btunix/samples/a2dp_sink_nuttx.c)
    endif()

    list(APPEND CSRCS ${STACKDIR}/portings/btunix/unixdep.c)

    list(APPEND INCDIR ${STACKDIR}/avctp)

    list(APPEND INCDIR ${STACKDIR}/sco)

    list(APPEND INCDIR ${STACKDIR}/map)

    list(APPEND INCDIR ${STACKDIR}/rfcomm)

    list(APPEND INCDIR ${STACKDIR}/smp)

    list(APPEND INCDIR ${STACKDIR}/sdap)

    list(APPEND INCDIR ${STACKDIR}/include)

    list(APPEND INCDIR ${STACKDIR}/gap)

    list(APPEND INCDIR ${STACKDIR}/hid)

    list(APPEND INCDIR ${STACKDIR}/xmlparse)

    list(APPEND INCDIR ${STACKDIR}/avdtp)

    list(APPEND INCDIR ${STACKDIR}/ots)

    list(APPEND INCDIR ${STACKDIR}/sdp)

    list(APPEND INCDIR ${STACKDIR}/pan)

    list(APPEND INCDIR ${STACKDIR}/pbap)

    list(APPEND INCDIR ${STACKDIR}/sbc)

    list(APPEND INCDIR ${STACKDIR}/obex)

    list(APPEND INCDIR ${STACKDIR}/l2cap)

    list(APPEND INCDIR ${STACKDIR}/spp)

    list(APPEND INCDIR ${STACKDIR}/le_audio)

    list(APPEND INCDIR ${STACKDIR}/avrcp)

    list(APPEND INCDIR ${STACKDIR}/bip)

    list(APPEND INCDIR ${STACKDIR}/a2dp)

    list(APPEND INCDIR ${STACKDIR}/hfp)

    list(APPEND INCDIR ${STACKDIR}/hci)

    list(APPEND INCDIR ${STACKDIR}/bnep)

    list(APPEND INCDIR ${STACKDIR}/portings/btunix)

    list(APPEND INCDIR ${STACKDIR}/btsoc/include)

    list(APPEND INCDIR ${STACKDIR}/btsoc/include/avnet)

    list(APPEND INCDIR ${STACKDIR}/btsoc/include/alcatel)

    list(APPEND INCDIR ${STACKDIR}/btsoc/include/nsc)

    list(APPEND INCDIR ${STACKDIR}/btsoc/include/stm)

    list(APPEND INCDIR ${STACKDIR}/btsoc/include/siw)

    list(APPEND INCDIR ${ADAPTERDIR}/inc)

    list(APPEND CFLAGS -Wno-pointer-sign -Wno-format -Wno-unused-variable -Wno-return-type)
    list(APPEND CFLAGS -Wno-unused-value -Wno-unused-but-set-variable -Wno-strict-prototypes)
    list(APPEND CFLAGS -Wno-int-to-pointer-cast -Wno-comment -Wno-parentheses -Wno-unused-function)
    list(APPEND CFLAGS -Wno-incompatible-pointer-types -Wno-trigraphs -Wno-undef -Wno-implicit-int)
    list(APPEND CFLAGS -Wno-shadow -Wno-sequence-point -Wno-stringop-overflow)

    nuttx_add_library(libbluelet STATIC)

    if(CONFIG_BLUELET_EXAMPLES)
      list(APPEND CSRCS ${STACKDIR}/portings/btunix/a2dputil_dep.c)

      nuttx_add_application(
        NAME
        leaudio_broadcast_src
        SRCS
        ${STACKDIR}/portings/btunix/samples/leaudio_broadcast_src.c
        INCLUDE_DIRECTORIES
        ${INCDIR}
        STACKSIZE
        ${CONFIG_BLUELET_EXAMPLES_STACKSIZE}
        PRIORITY
        ${CONFIG_BLUELET_EXAMPLES_PRIORITY}
        COMPILE_FLAGS
        ${CFLAGS}
        DEPENDS
        libbluelet)

      nuttx_add_application(
        NAME
        leaudio_broadcast_snk
        SRCS
        ${STACKDIR}/portings/btunix/samples/leaudio_broadcast_snk.c
        INCLUDE_DIRECTORIES
        ${INCDIR}
        STACKSIZE
        ${CONFIG_BLUELET_EXAMPLES_STACKSIZE}
        PRIORITY
        ${CONFIG_BLUELET_EXAMPLES_PRIORITY}
        COMPILE_FLAGS
        ${CFLAGS}
        DEPENDS
        libbluelet)

    else()
      list(APPEND CSRCS ${STACKDIR}/portings/btunix/a2dputil_dep.c)

    endif()

    # Export Headers
    nuttx_export_header(TARGET libbluelet INCLUDE_DIRECTORIES ${SUBDIR}/${SUBDIR_NAME}/src/samples/stack_adapter/inc)

    # Library Configuration
    target_compile_options(libbluelet PRIVATE ${CFLAGS})
    target_sources(libbluelet PRIVATE ${CSRCS})
    target_include_directories(libbluelet PRIVATE ${INCDIR})

  endif()

endif()