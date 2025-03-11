#ifndef LEXER_HPP
#define LEXER_HPP
#include <deque>
#include <unordered_set>

#include "OpType.hpp"
#include "Token.hpp"

namespace symder
{
    class Lexer
    {
        // Constants
        const std::string _validOps{"+-*/^"};
        const std::unordered_set<std::string> _validFns{"sin", "cos", "exp", "ln"};
        const std::string _stringЕxpr;

        std::deque<Token> _output;
        std::deque<char> _buf;
        std::deque<OpType> _ops;
        std::string _input;
        TokenType _currentToken = Undefined;

        void normalizeInput();

        bool isFn(const std::string& s) const;
        bool bufIsFn();
        bool isOp(char c) const;

        void pushBuf();

        static int priorityOf(OpType opType);

        static bool isValidNumberPart(char c);
        static bool isValidIdentPart(char c);

    public:
        [[nodiscard]] explicit Lexer(std::string&& input)
            : _input(std::move(input)) {}

        [[nodiscard]] explicit Lexer(const std::string& stringЕxpr)
            : _stringЕxpr(stringЕxpr) {}

        std::deque<Token> parse();

        ~Lexer() = default;
    };
} // symder

#endif //LEXER_HPP
