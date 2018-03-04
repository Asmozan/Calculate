#include <gtest/gtest.h>

#include <Rpn/Operations.hpp>

TEST(OperationsShould, add)
{
    EXPECT_EQ(4, operations::add(2,2));
}

TEST(OperationsShould, sub)
{
    EXPECT_EQ(0, operations::minus(2,2));
}

TEST(OperationsShould, divide)
{
    EXPECT_EQ(1, operations::divide(2,2));
}

TEST(OperationsShould, multiply)
{
    EXPECT_EQ(4, operations::multiply(2,2));
}

TEST(OperationsShould, abs)
{
    EXPECT_EQ(2, operations::abs(-2));
}

TEST(OperationsShould, )
{
    EXPECT_EQ(1, operations::angle(90));
}