#pragma once

#include <string>
#include <stack>
#include <map>
#include <functional>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <exception>

class Rpn
{
public:
    Rpn();
    Rpn(std::string);
    int calculate(const std::string &);

private:
    double getArgument();
    void defineFunctions();

    std::stack <double> rpn_stack_;
    std::map <std::string,std::function<double()>> functions_;
};