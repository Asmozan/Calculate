#include "RpnShould.hpp"

TEST_F(RpnShould, createObjectRpn)
{ }

TEST_F(RpnShould, returnStack)
{
    EXPECT_EQ(5, rpn.calculate("5"));
}

TEST_F(RpnShould, addTwoNumbers)
{
    EXPECT_EQ(5, rpn.calculate("2 3 +"));
}

TEST_F(RpnShould, addThreeNumbers)
{
    EXPECT_EQ(9, rpn.calculate("2 3 4 + +"));
}

TEST_F(RpnShould, subtractTwoNumbers)
{
    EXPECT_EQ(-1, rpn.calculate("2 3 -"));
}

TEST_F(RpnShould, substractThreeNumbers)
{
    EXPECT_EQ(3, rpn.calculate("2 3 4 - -"));
}

TEST_F(RpnShould, combineTwoOperations)
{
    EXPECT_EQ(0, rpn.calculate("1 2 + 3 -"));
}

TEST_F(RpnShould, multiplyTwoNumbers)
{
    EXPECT_EQ(6, rpn.calculate("2 3 *"));
}

TEST_F(RpnShould, multiplyThreeNumbers)
{
    EXPECT_EQ(18, rpn.calculate("2 3 3 * *"));
}

TEST_F(RpnShould, divideTwoNumbers)
{
    EXPECT_EQ(2, rpn.calculate("4 2 /"));
}

TEST_F(RpnShould, divideThreeNumbers)
{
    EXPECT_EQ(1, rpn.calculate("4 8 2 / /"));
}

TEST_F(RpnShould, returnAbsValue)
{
    EXPECT_EQ(1, rpn.calculate("-1 abs"));
}

TEST_F(RpnShould, combineAllPrevious)
{
    EXPECT_EQ(1, rpn.calculate("1 1 1 1 1 + - * / abs"));
}

TEST_F(RpnShould, returnSinAt1)
{
    EXPECT_EQ(0, rpn.calculate("1 angle"));
}

TEST_F(RpnShould, returnSinAt90)
{
    EXPECT_EQ(1, rpn.calculate("90 angle"));
}