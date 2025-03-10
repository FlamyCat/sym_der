#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include "TokenType.hpp"

struct Token
{
    symder::TokenType type;
    std::string body;
};

#endif //TOKEN_HPP
