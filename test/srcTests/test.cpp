#include "Example.hpp"
#include "test.hpp"

TEST_F(ExampleShould, returnTrue) {
    EXPECT_EQ(true, example.test());
}