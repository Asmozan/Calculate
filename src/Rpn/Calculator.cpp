#include "Calculator.hpp"

#include <iostream>
#include <regex>

#include "Helpers.hpp"
#include "Operations.hpp"

Calculator::Calculator()
{
    defineFunctions();
}

Calculator::Calculator(std::string input)
{
    replaceVariablesWithValues();
    defineFunctions();
    calculate();
}

double Calculator::getArgument()
{
    if(rpn_stack_.empty())
    {
        std::cerr << "ERROR: Not enough arguments\n";
        return -1;
    }

    double argument = rpn_stack_.top();
    rpn_stack_.pop();

    return argument;
}

double Calculator::calculate()
{
    auto tokens = helpers::split(input_);

    for (const auto& token : tokens)
    {
        if(functions_.find(token) != functions_.end())
        {
            rpn_stack_.push(functions_.at(token)());
        }
        else
        {
            rpn_stack_.push(std::stoi(token));
        }
    }

    return rpn_stack_.top();
}

void Calculator::defineFunctions()
{
    functions_.emplace("+", [this](){return operations::add(getArgument(), getArgument());});
    functions_.emplace("-", [this](){return operations::minus(getArgument(), getArgument());});
    functions_.emplace("*", [this](){return operations::multiply(getArgument(), getArgument());});
    functions_.emplace("/", [this](){return operations::divide(getArgument(), getArgument());});
    functions_.emplace("abs", [this](){return operations::abs(getArgument());});
    functions_.emplace("angle", [this](){return operations::angle(getArgument());});
}

void Calculator::defineVariables()
{
    std::map<std::string, std::string> variables = {{"x", "6"}};
}

void Calculator::replaceVariablesWithValues()
{
    std::cout << input_;
    std::map<std::string, std::string> variables = {{"x", "6"}};

    std::regex re("\\b(\\w*"+variables.begin()->first+"\\w*)\\b");

    input_ = std::regex_replace(input_, re, variables.at(variables.begin()->first));
    std::cout << input_;
}

void Calculator::setInput(const std::string& input)
{
    input_ = input;
}
