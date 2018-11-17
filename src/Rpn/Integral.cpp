#include "Integral.hpp"

#include <iomanip>
#include <iostream>


double Integral::function(std::string input)
{
    calculator_.setInput(input);
    return calculator_.calculate();
}

void Integral::calculate()
{
    const int N = 1000; //liczba punktów/prostokątów podziałowych
    double xp;
    double xk;
    double s;
    double dx;

    calculator_.defineVariable("x", "2");
    calculator_.defineVariable("y", "3");
    s  = 0;
    dx = (xk - xp) / N;

    for(int i = 1; i <= N; i++)
    {
        s += function("2 x x y y * * * * 6 x * + 5 +");
    }
    s *= dx;
}

Integral::Integral() : calculator_(Calculator())
{
}
