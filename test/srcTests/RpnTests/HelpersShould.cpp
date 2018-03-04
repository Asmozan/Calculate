#include <gtest/gtest.h>
#include <Rpn/Helpers.hpp>

TEST(HelpersShould, splitString)
{
    std::string input = "Ala ma kota";
    std::vector<std::string> splited {"Ala", "ma", "kota"};
    EXPECT_EQ(splited, helpers::split(input));
}