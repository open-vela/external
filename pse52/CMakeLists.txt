# ##############################################################################
# external/pse52/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_PSE52_TEST)
  # The compilation process for test cases in PSE52 is separate from the Vela
  # compilation process. Below are the steps of this process:
  # 1. Complete the build of the PSE52 test cases and generate the
  # corresponding ELF files. These ELF files are located in the pse52_env
  # Docker container
  # 2. Copy the PSE52 test case ELF files to the `vela/out/$target/bin`
  # directory
  # 3. Then, a full build of Vela will generate the symbols required by
  # the PSE52 testcase ELF files

  # The following steps primarily focus on completing step 2
  add_custom_target(
    gen_PSE52_bin
    COMMAND docker exec pse52_env bash -c
            "/opt/tetware/vsx0/fetch_vsx_elf.sh ANSI.hdr ANSI.os"
    COMMAND docker exec pse52_env bash -c
            "/opt/tetware/vsx0/fetch_vsx_elf.sh POSIX.hdr POSIX.os"
    COMMAND docker exec pse52_env bash -c
            "/opt/tetware/vsx0/fetch_vsx_elf.sh PSE52.hdr XOPEN.os XPG4.hdr XPG4.os"
    COMMAND docker exec pse52_env bash -c
            "/opt/tetware/vsx0/fetch_vsx_elf.sh PTHR.hdr PTHR.os"
    COMMAND docker exec pse52_env bash -c
            "/opt/tetware/vsx0/fetch_vsx_elf.sh PSE52_rt.hdr rt.hdr rt.os"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

  add_dependencies(nuttx_apps_mksymtab gen_PSE52_bin)
endif()
