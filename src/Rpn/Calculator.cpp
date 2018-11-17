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
            rpn_stack_.push(std::stod(token));
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

void Calculator::defineVariable(const std::string& variable, const std::string& value)
{
    variables_[variable] = value;
}

void Calculator::replaceVariablesWithValues()
{
    std::cout << input_;


    for (auto variable : variables_)
    {
        std::regex re("\\b(\\w*"+variable.first+"\\w*)\\b");

        input_ = std::regex_replace(input_, re, variables_.at(variable.first));
    }
    std::cout << input_;
}

void Calculator::setInput(const std::string& input)
{
    input_ = input;
}
