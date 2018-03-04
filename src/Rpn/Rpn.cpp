#include <cmath>
#include <iostream>

#include "Rpn.hpp"

using boost::lexical_cast;
using boost::bad_lexical_cast;
//using namespace operations;

double Rpn::getArgument()
{
    if(rpn_stack.empty()) throw std::invalid_argument("not enough args");
    double argument = rpn_stack.top();
    rpn_stack.pop();

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
    double second = getArgument();
    double first = getArgument();
    if(second == 0) throw std::invalid_argument("Can't divide by ZERO!");
    return first / second;
}

double Rpn::abs()
{
    double argument = getArgument();
    return std::abs(argument);
}
double Rpn::sin()
{
    double argument = getArgument();
    return std::sin(argument*M_PI/180.0);
}

Rpn::Rpn()
{
    function_map.emplace("+", [this](){return add();});
    function_map.emplace("-", [this](){return minus();});
    function_map.emplace("*", [this](){return multiply();});
    function_map.emplace("/", [this](){return divide();});
    function_map.emplace("abs", [this](){return abs();});
    function_map.emplace("sin", [this](){return sin();});
}



boost::tokenizer<boost::char_separator<char> > Rpn::initialize_calculator(const std::string& input)
{
    boost::char_separator<char> sep {" "};
    boost::tokenizer<boost::char_separator
            <char>> tokenizer{input, sep};

    return tokenizer;
}

int Rpn::calculate(const std::string& input)
{
    auto tokenizer = initialize_calculator(input);
    
    for (auto i = tokenizer.begin();
         i != tokenizer.end(); ++i )
    {
        try
        {
            rpn_stack.push(lexical_cast<int>(*i));
        }
        catch(const bad_lexical_cast & c)
        {

            try{
                rpn_stack.push(function_map.at(*i)());
            }
            catch(const std::invalid_argument& ia)
            {
                std::string temp_helper;
                for(; i != tokenizer.end(); ++i)
                {
                    temp_helper += *i;
                }
                throw std::invalid_argument(temp_helper);

            }

            catch(const std::out_of_range& c ){
                std::string temp_helper = "No function name " + *i;
                throw std::out_of_range(temp_helper);
            }
        }
    }
    if(rpn_stack.size() != 1)
        throw std::invalid_argument("Invalid expression");

    return rpn_stack.top();
}
