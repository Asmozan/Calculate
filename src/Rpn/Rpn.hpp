#pragma once

#include <string>
#include <stack>
#include <map>
#include <functional>

class Rpn
{
public:
    Rpn();
    explicit Rpn(std::string);
    int calculate(const std::string &);

private:
    double getArgument();
    void defineFunctions();

    std::stack <double> rpn_stack_;
    std::map <std::string,std::function<double()>> functions_;
};