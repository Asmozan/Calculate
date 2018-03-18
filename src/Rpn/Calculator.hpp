#pragma once

#include <string>
#include <stack>
#include <map>
#include <functional>

class Calculator
{
public:
    Calculator();
    explicit Calculator(std::string);
    double calculate();
    void replaceVariablesWithValues();

private:
    double getArgument();
    void defineFunctions();
    void defineVariables();

    std::string input_;
public:
    void setInput(const std::string& input);

private:
    std::stack <double> rpn_stack_;
    std::map <std::string,std::function<double()>> functions_;
};