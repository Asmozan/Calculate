#include <iostream>
#include <cmath>
#include "Operations.hpp"

namespace operations
{

    double add(double second, double first)
    {
        return first+second;
    }

    double minus(double first, double second)
    {
        return first - second;
    }

    double multiply(double second, double first)
    {
        return first * second;
    }

    double divide(double nominator, double denominator)
    {
        if(denominator == 0)
        {
            std::cerr << "ERROR: Can't divide by ZERO!\n";
            return -1;
        };
        return nominator / denominator;
    }

    double abs(double argument)
    {
        return std::abs(argument);
    }

    double angle(double argument)
    {
        return std::sin(argument*M_PI/180.0);
    }

}   // operations