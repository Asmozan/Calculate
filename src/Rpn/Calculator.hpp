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
    void defineVariable(const std::string& variable, const std::string& value);

private:
    double getArgument();
    void defineFunctions();

    std::string input_;
public:
    void setInput(const std::string& input);

private:
    std::stack <double> rpn_stack_;
    std::map <std::string,std::function<double()>> functions_;
    std::map<std::string, std::string> variables_;
};