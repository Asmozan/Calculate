#include "CalculatorShould.hpp"

TEST_F(CalculatorShould, createObjectcalculator)
{ }

TEST_F(CalculatorShould, returnStack)
{
    calculator.setInput("5");

    EXPECT_EQ(5, calculator.calculate());
}

TEST_F(CalculatorShould, addTwoNumbers)
{
    calculator.setInput("2 3 +");

    EXPECT_EQ(5, calculator.calculate());
}

TEST_F(CalculatorShould, addThreeNumbers)
{
    calculator.setInput("1 3 5 + +");

    EXPECT_EQ(9, calculator.calculate());
}

TEST_F(CalculatorShould, subtractTwoNumbers)
{
    calculator.setInput("0 1 -");

    EXPECT_EQ(-1, calculator.calculate());
}

TEST_F(CalculatorShould, substractThreeNumbers)
{
    calculator.setInput("2 3 4 - -");

    EXPECT_EQ(3, calculator.calculate());
}

TEST_F(CalculatorShould, combineTwoOperations)
{
    calculator.setInput("1 2 + 3 -");

    EXPECT_EQ(0, calculator.calculate());
}

TEST_F(CalculatorShould, multiplyTwoNumbers)
{
    calculator.setInput("2 3 *");

    EXPECT_EQ(6, calculator.calculate());
}

TEST_F(CalculatorShould, multiplyThreeNumbers)
{
    calculator.setInput("2 3 4 * *");

    EXPECT_EQ(24, calculator.calculate());
}

TEST_F(CalculatorShould, divideTwoNumbers)
{
    calculator.setInput("4 2 /");

    EXPECT_EQ(2, calculator.calculate());
}

TEST_F(CalculatorShould, divideThreeNumbers)
{
    calculator.setInput("4 8 2 / /");

    EXPECT_EQ(1, calculator.calculate());
}

TEST_F(CalculatorShould, returnAbsValue)
{
    calculator.setInput("-1 abs");

    EXPECT_EQ(1, calculator.calculate());
}

TEST_F(CalculatorShould, combineAllPrevious)
{
    calculator.setInput("1 1 1 1 1 + - * / abs");

    EXPECT_EQ(1, calculator.calculate());
}

TEST_F(CalculatorShould, returnSinAt1)
{
    calculator.setInput("1 angle");

    EXPECT_EQ(0.0174524, calculator.calculate());
}

TEST_F(CalculatorShould, returnSinAt90)
{
    calculator.setInput("90 angle");

    EXPECT_EQ(1, calculator.calculate());
}

TEST_F(CalculatorShould, handleVariables)
{
    calculator.setInput("x x +");
    calculator.replaceVariablesWithValues();

    EXPECT_EQ(12, calculator.calculate());
}

TEST_F(CalculatorShould, handleVariablesAndConsts)
{
    calculator.setInput("x 2 +");
    calculator.replaceVariablesWithValues();

    EXPECT_EQ(8, calculator.calculate());
}

TEST_F(CalculatorShould, handleDouble)
{
    calculator.setInput("2.2 2.2 +");

    EXPECT_EQ(4.4, calculator.calculate());
}