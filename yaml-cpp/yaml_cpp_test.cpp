#include <gtest/gtest.h>

#include "binary_test.cpp"
#include "ostream_wrapper_test.cpp"
#include "parser_test.cpp"
#include "regex_test.cpp"

#include "node/node_test.cpp"

#include "integration/emitter_test.cpp"
#include "integration/encoding_test.cpp"
#include "integration/error_messages_test.cpp"
#include "integration/gen_emitter_test.cpp"
#include "integration/handler_spec_test.cpp"
#include "integration/handler_test.cpp"
#include "integration/load_node_test.cpp"
#include "integration/node_spec_test.cpp"

extern "C" int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
