#include "Rpn.hpp"

#include <iostream>

#include "Helpers.hpp"
#include "Operations.hpp"

Rpn::Rpn()
{
    defineFunctions();
}

Rpn::Rpn(std::string input)
{
    defineFunctions();
    calculate(input);
}

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

void Rpn::defineFunctions()
{
    functions_.emplace("+", [this](){return operations::add(getArgument(), getArgument());});
    functions_.emplace("-", [this](){return operations::minus(getArgument(), getArgument());});
    functions_.emplace("*", [this](){return operations::multiply(getArgument(), getArgument());});
    functions_.emplace("/", [this](){return operations::divide(getArgument(), getArgument());});
    functions_.emplace("abs", [this](){return operations::abs(getArgument());});
    functions_.emplace("angle", [this](){return operations::angle(getArgument());});
}