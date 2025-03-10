#ifndef PARSER_HPP
#define PARSER_HPP
#include <memory>

#include "Lexer.hpp"
#include "../types/Expression.hpp"

namespace symder
{
    class Parser
    {
        Lexer _lexer;

        static std::complex<long double> parseNumber(const std::string& str);

    public:
        explicit Parser(std::string input) : _lexer(std::move(input)) {}

        std::shared_ptr<Expression> parse();

        ~Parser() = default;
    };
} // symder

#endif //PARSER_HPP
