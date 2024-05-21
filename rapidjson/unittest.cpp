// Tencent is pleased to support the open source community by making RapidJSON available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip. All rights reserved.
//
// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "unittest.h"
#include "rapidjson/rapidjson.h"

#include "allocatorstest.cpp"
#include "bigintegertest.cpp"
#include "documenttest.cpp"
#include "dtoatest.cpp"
#include "encodedstreamtest.cpp"
#include "encodingstest.cpp"
#include "filestreamtest.cpp"
#include "fwdtest.cpp"
#include "istreamwrappertest.cpp"
#include "itoatest.cpp"
#include "jsoncheckertest.cpp"
#include "namespacetest.cpp"
#include "ostreamwrappertest.cpp"
#include "pointertest.cpp"
#include "prettywritertest.cpp"
#include "readertest.cpp"
#include "regextest.cpp"
#include "schematest.cpp"
#include "simdtest.cpp"
#include "strfunctest.cpp"
#include "stringbuffertest.cpp"
#include "strtodtest.cpp"
#include "valuetest.cpp"
#include "writertest.cpp"

#ifdef __clang__
#pragma GCC diagnostic push
#if __has_warning("-Wdeprecated")
#pragma GCC diagnostic ignored "-Wdeprecated"
#endif
#endif

AssertException::~AssertException() throw() {}

#ifdef __clang__
#pragma GCC diagnostic pop
#endif

extern "C" int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::cout << "RapidJSON v" << RAPIDJSON_VERSION_STRING << std::endl;

#ifdef _MSC_VER
    _CrtMemState memoryState = { 0 };
    (void)memoryState;
    _CrtMemCheckpoint(&memoryState);
    //_CrtSetBreakAlloc(X);
    //void *testWhetherMemoryLeakDetectionWorks = malloc(1);
#endif

    int ret = RUN_ALL_TESTS();

#ifdef _MSC_VER
    // Current gtest constantly leak 2 blocks at exit
    _CrtMemDumpAllObjectsSince(&memoryState);
#endif
    return ret;
}