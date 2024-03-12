#include <gtest/gtest.h>

#include "c/client.cpp"
#include "c/eventlog_test.cpp"
#include "c/memq_test.cpp"
#include "c/udpm_test.cpp"

#include "cpp/client.cpp"
#include "cpp/common.cpp"
#include "cpp/memq_test.cpp"

extern "C" int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
