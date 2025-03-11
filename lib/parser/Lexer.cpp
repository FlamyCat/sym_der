#include "Lexer.hpp"

#include <algorithm>
#include <format>
#include <stdexcept>

namespace symder
{
    void Lexer::normalizeInput()
    {
        std::transform(_input.begin(), _input.end(), _input.begin(), [](unsigned char c) { return std::tolower(c); });
    }

    bool Lexer::isFn(const std::string& s) const
    {
        return _validFns.contains(s);
    }

    bool Lexer::bufIsFn()
    {
        return isFn({_buf.begin(), _buf.end()});
    }

    bool Lexer::isOp(const char c) const
    {
        return _validOps.contains(c);
    }

    void Lexer::pushBuf()
    {
        if (_buf.empty())
            return;

        std::string body{_buf.begin(), _buf.end()};

        if (_currentToken == Undefined)
            throw std::logic_error(std::format("Undefined token: {}", std::move(body)));

        if (isFn(body))
        {
            if (body == "sin")
            {
                _ops.push_back(FnSin);
                _buf.clear();
                return;
            }
            if (body == "cos")
            {
                _ops.push_back(FnCos);
                _buf.clear();
                return;
            }
            if (body == "ln")
            {
                _ops.push_back(FnLn);
                _buf.clear();
                return;
            }
            if (body == "exp")
            {
                _ops.push_back(FnExp);
                _buf.clear();
                return;
            }
            throw std::logic_error(std::format("Undefined fn: {}", std::move(body)));
        }

        _output.push_back({_currentToken, std::move(body)});

        _currentToken = Undefined;
        _buf.clear();
    }

    int Lexer::priorityOf(const OpType opType)
    {
        switch (opType)
        {
        case FnCos:
        case FnSin:
        case FnExp:
        case FnLn:
            return 1;

        case OpPow:
            return 2;

        case OpMul:
        case OpDiv:
            return 3;

        case OpAdd:
        case OpSub:
            return 4;

        case Lparen:
            return 5;

        default:
            throw std::logic_error("Unreachable");
        }
    }

    bool Lexer::isValidNumberPart(const char c)
    {
        return isdigit(c) || c == '.' || c == 'i';
    }

    bool Lexer::isValidIdentPart(const char c)
    {
        return isalpha(c) || c == '_';
    }

    std::string opToString(const OpType opType)
    {
        switch (opType)
        {
        case OpAdd:
            return "+";
        case OpSub:
            return "-";
        case OpMul:
            return "*";
        case OpDiv:
            return "/";
        case OpPow:
            return "^";
        case FnSin:
            return "sin";
        case FnCos:
            return "cos";
        case FnExp:
            return "exp";
        case FnLn:
            return "ln";
        default:
            throw std::logic_error("Unreachable");
        }
    }

    OpType charToOp(const char c)
    {
        switch (c)
        {
        case '+':
            return OpAdd;
        case '-':
            return OpSub;
        case '*':
            return OpMul;
        case '/':
            return OpDiv;
        case '^':
            return OpPow;
        case '(':
            return Lparen;

        default:
            throw std::logic_error("Unreachable");
        }
    }

    std::deque<Token> Lexer::parse()
    {
        normalizeInput();
        for (auto it = _input.begin(); it != _input.end(); ++it)
        {
            auto statusMsg = std::format("Reading {} at {}", *it, it - _input.begin());

            if (isspace(*it))
            {
                pushBuf();
                continue;
            }

            if (*it == ')')
            {
                pushBuf();
                while (_ops.back() != Lparen && !_ops.empty())
                {
                    _output.push_back({Op, opToString(_ops.back())});
                    _ops.pop_back();
                }

                _ops.pop_back();

                continue;
            }

            if (*it == '(')
            {
                pushBuf();
                _ops.push_back(Lparen);
                continue;
            }

            if (isOp(*it))
            {
                pushBuf();
                auto curOp = charToOp(*it);
                if (!_ops.empty() && priorityOf(curOp) >= priorityOf(_ops.back()))
                {
                    switch (curOp)
                    {
                    case OpAdd:
                    case OpSub:
                    case OpMul:
                    case OpDiv:
                    case OpPow:
                        _output.push_back({Op, {opToString(_ops.back())}});
                        break;
                    case FnSin:
                    case FnCos:
                    case FnExp:
                    case FnLn:
                        _output.push_back({Fn, {opToString(_ops.back())}});
                        break;
                    case Lparen:
                        throw std::logic_error("Unreachable");
                    }
                }

                _ops.push_back(curOp);
                continue;
            }

            switch (_currentToken)
            {
            case Number:
                if (!isValidNumberPart(*it))
                    throw std::logic_error(std::format("{}: reading number but current char cannot be a number part",
                                                       statusMsg));
                _buf.push_back(*it);
                break;
            case Identifier:
                if (!isValidIdentPart(*it))
                    throw std::logic_error(
                        std::format("{}: reading identifier but current char cannot be an identifier part", statusMsg));

                _buf.push_back(*it);
                break;
            case Undefined:
                if (isValidNumberPart(*it))
                    _currentToken = Number;
                else if (isValidIdentPart(*it))
                    _currentToken = Identifier;

                _buf.push_back(*it);
                break;
            default:
                break;
            }
        }

        pushBuf();

        while (!_ops.empty())
        {
            const auto op = _ops.back();
            _ops.pop_back();
            switch (op)
            {
            case OpAdd:
            case OpSub:
            case OpMul:
            case OpDiv:
            case OpPow:
                _output.push_back({Op, {opToString(op)}});
                break;
            case FnSin:
            case FnCos:
            case FnExp:
            case FnLn:
                _output.push_back({Fn, {opToString(op)}});
                break;
            case Lparen:
                throw std::logic_error("Unreachable");
            }
        }


        return std::move(_output);
    }
} // symder
