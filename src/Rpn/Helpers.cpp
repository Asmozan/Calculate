#include "Helpers.hpp"

#include <sstream>

namespace helpers
{

std::vector<std::string> split(std::string input)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    char delimiter = ' ';

    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

}   // namespace helpers