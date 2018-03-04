#include "RpnShould.hpp"

TEST_F(RpnShould, should_create_object_rpn)
{}

TEST_F(RpnShould, should_return_stack)
{
    EXPECT_EQ(5, rpn.calculate("5"));
}
TEST_F(RpnShould, should_add_two_numbers)
{
    EXPECT_EQ(5, rpn.calculate("2 3 +"));
}
TEST_F(RpnShould, should_add_three_numbers)
{
    EXPECT_EQ(9, rpn.calculate("2 3 4 + +"));
}
TEST_F(RpnShould, should_subtraction_two_numbers)
{
    EXPECT_EQ(-1, rpn.calculate("2 3 -"));
}

TEST_F(RpnShould, should_substract_three_numbers)
{
    EXPECT_EQ(3, rpn.calculate("2 3 4 - -"));
}

TEST_F(RpnShould, should_combine_two_operations)
{
    EXPECT_EQ(0, rpn.calculate("1 2 + 3 -"));
}

TEST_F(RpnShould, should_multiply_two_numbers)
{
    EXPECT_EQ(6, rpn.calculate("2 3 *"));
}
TEST_F(RpnShould, should_multiply_three_numbers)
{
    EXPECT_EQ(18, rpn.calculate("2 3 3 * *"));
}
TEST_F(RpnShould, should_divide_two_numbers)
{
    EXPECT_EQ(2, rpn.calculate("4 2 /"));
}
TEST_F(RpnShould, should_divide_three_numbers)
{
    EXPECT_EQ(1, rpn.calculate("4 8 2 / /"));
}
TEST_F(RpnShould, should_throw_exception_when_second_argument_is_zero)
{
    EXPECT_THROW(rpn.calculate("1 0 /"), std::invalid_argument);
}
TEST_F(RpnShould, should_throw_exception_when_not_enought_arguments)
{
    EXPECT_THROW(rpn.calculate("1 -"), std::invalid_argument);
}
TEST_F(RpnShould, should_throw_when_is_too_many_operations)
{
    EXPECT_THROW(rpn.calculate("1 -"), std::invalid_argument);
}
TEST_F(RpnShould, should_throw_exception_when_is_too_many_numbers)
{
    EXPECT_THROW(rpn.calculate("1 1 1 -"), std::invalid_argument);
}
TEST_F(RpnShould, should_throw_exception_when_string_is_empty)
{
    EXPECT_THROW(rpn.calculate(""), std::invalid_argument);
}
TEST_F(RpnShould, should_return_abs_value)
{
    EXPECT_EQ(1, rpn.calculate("-1 abs"));
}
TEST_F(RpnShould, should_combine_all_previous)
{
    EXPECT_EQ(1, rpn.calculate(" 1 1 1 1 1 + - * / abs"));
}
TEST_F(RpnShould, should_return_sin_at_1)
{
    EXPECT_EQ(0, rpn.calculate("1 sin"));
}

TEST_F(RpnShould, should_return_sin_at_90)
{
    EXPECT_EQ(1, rpn.calculate("90 sin"));
}

TEST_F(RpnShould, should_throw_if_invalid_name_of_operation)
{
    EXPECT_THROW(rpn.calculate(" -1 bas"), std::out_of_range);
}

TEST_F(RpnShould, should_throw_if_wrong_number)
{
    EXPECT_THROW(rpn.calculate(" -1 bas"), std::out_of_range);
}