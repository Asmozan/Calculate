#pragma once

#include <string>
#include "Calculator.hpp"

class Integral
{
public:
    Integral();

private:
    double function(std::string);
    void calculate();
    Calculator calculator_;
};
