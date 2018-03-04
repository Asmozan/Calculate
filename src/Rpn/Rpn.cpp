#include "Rpn.hpp"

#include <iostream>

#include "Helpers.hpp"
#include "Operations.hpp"

double Rpn::getArgument()
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

double Rpn::add()
{
    double second = getArgument();
    double first = getArgument();
    return first+second;
}

double Rpn::minus()
{
    double second = getArgument();
    double first = getArgument();
    return first - second;
}

double Rpn::multiply()
{
    double second = getArgument();
    double first = getArgument();
    return first * second;
}

double Rpn::divide()
{
    double denominator = getArgument();
    double nominator = getArgument();
    if(denominator == 0)
    {
        std::cerr << "ERROR: Can't divide by ZERO!\n";
        return -1;
    };
    return nominator / denominator;
}

double Rpn::abs()
{
    double argument = getArgument();
    return std::abs(argument);
}

double Rpn::angle()
{
    double argument = getArgument();
    return std::sin(argument*M_PI/180.0);
}

Rpn::Rpn()
{
    functions_.emplace("+", [this](){return operations::add(getArgument(), getArgument());});
    functions_.emplace("-", [this](){return operations::minus(getArgument(), getArgument());});
    functions_.emplace("*", [this](){return operations::multiply(getArgument(), getArgument());});
    functions_.emplace("/", [this](){return operations::divide(getArgument(), getArgument());});
    functions_.emplace("abs", [this](){return operations::abs(getArgument());});
    functions_.emplace("angle", [this](){return operations::angle(getArgument());});
}

int Rpn::calculate(const std::string& input)
{
    auto tokens = helpers::split(input);

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