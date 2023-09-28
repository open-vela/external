#
# Copyright (C) 2023 Xiaomi Corporation
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

#All tas are stored in the "vendor/bes/boards/best1600_ep/src/etc/ta".

#00F2AA8A5024E411ABE20002A5D5C51B
cd optee_test/ta/storage
./build_wasm_storage.sh n60
cd -

#9E271E73FBAA7545A77138CAA6F0CCA6
cd optee_test/ta/storage2/
./build_wasm_storage2.sh n60
cd -

#A05B3ECBF1ADE011998B0002A5D5C51B
cd optee_test/ta/crypt/
./build_wasm_crypt.sh n60
cd -
