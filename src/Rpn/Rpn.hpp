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
    double sin();
    std::stack <double> rpn_stack;
    std::map <std::string,std::function<double()>>
            function_map;

    boost::tokenizer<boost::char_separator<char>>
    initialize_calculator(const std::string& input);
};