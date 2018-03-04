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
    int calculate(const std::string &);

private:
    double getArgument();
    double add();
    double minus();
    double multiply();
    double divide();
    double abs();
    double angle();

    std::stack <double> rpn_stack_;
    std::map <std::string,std::function<double()>> functions_;
};