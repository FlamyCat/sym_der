#include "Parser.hpp"

#include "../types/Constant/Constant.hpp"
#include "../types/Fns/Cos/Cos.hpp"
#include "../types/Fns/Exp/Exp.hpp"
#include "../types/Fns/Ln/Ln.hpp"
#include "../types/Fns/Sin/Sin.hpp"
#include "../types/Ops/Div/Div.hpp"
#include "../types/Ops/Mul/Mul.hpp"
#include "../types/Ops/Pow/Pow.hpp"
#include "../types/Ops/Sub/Sub.hpp"
#include "../types/Variable/Variable.hpp"

namespace symder
{
    std::complex<long double> Parser::parseNumber(const std::string& str)
    {
        const bool isImaginary = str.ends_with('i');
        const long double number = std::stold(str);

        auto realPart = isImaginary ? 0 : number;
        auto imagPart = isImaginary ? number : 0;

        return {realPart, imagPart};
    }

    OpType fnFromStr(const std::string& str)
    {
        if (str == "sin")
        {
            return FnSin;
        }
        if (str == "cos")
        {
            return FnCos;
        }
        if (str == "exp")
        {
            return FnExp;
        }
        if (str == "ln")
        {
            return FnLn;
        }
        throw std::logic_error("Unreachable");
    }

    OpType opFromStr(const std::string& str)
    {
        if (str == "+")
        {
            return OpAdd;
        }
        if (str == "-")
        {
            return OpSub;
        }
        if (str == "*")
        {
            return OpMul;
        }
        if (str == "/")
        {
            return OpDiv;
        }
        if (str == "^")
        {
            return OpPow;
        }
        if (str == "sin")
        {
            return FnSin;
        }
        if (str == "cos")
        {
            return FnCos;
        }
        if (str == "exp")
        {
            return FnExp;
        }
        if (str == "ln")
        {
            return FnLn;
        }
        throw std::logic_error("Unreachable");
    }

    std::shared_ptr<Expression> Parser::parse()
    {
        std::deque<std::shared_ptr<Expression>> expressions;

        for (const auto lexingResult = _lexer.parse(); const auto& [type, body] : lexingResult)
        {
            if (type == Number)
            {
                auto expr = std::make_shared<Constant<std::complex<long double>>>(parseNumber(body));
                expressions.push_back(expr);

                continue;
            }

            if (type == Identifier)
            {
                auto expr = std::make_shared<Variable>(body);
                expressions.push_back(expr);

                continue;
            }

            if (type == Fn)
            {
                const auto fnKind = fnFromStr(body);
                std::shared_ptr<Expression> fn;
                auto arg = expressions.back();
                expressions.pop_back();

                switch (fnKind)
                {
                case FnSin:
                    fn = std::make_shared<Sin>(arg);
                    break;
                case FnCos:
                    fn = std::make_shared<Cos>(arg);
                    break;
                case FnExp:
                    fn = std::make_shared<Exp>(arg);
                    break;
                case FnLn:
                    fn = std::make_shared<Ln>(arg);
                    break;
                default:
                    throw std::logic_error("Unreachable");
                }

                expressions.push_back(fn);

                continue;
            }

            if (type == Op)
            {
                const auto opKind = opFromStr(body);

                auto rhs = expressions.back();
                expressions.pop_back();

                auto lhs = expressions.back();
                expressions.pop_back();

                std::shared_ptr<Expression> expr;

                switch (opKind)
                {
                case OpAdd:
                    expr = std::make_shared<Add>(lhs, rhs);
                    break;
                case OpSub:
                    expr = std::make_shared<Sub>(lhs, rhs);
                    break;
                case OpMul:
                    expr = std::make_shared<Mul>(lhs, rhs);
                    break;
                case OpDiv:
                    expr = std::make_shared<Div>(lhs, rhs);
                    break;
                case OpPow:
                    expr = std::make_shared<Pow>(lhs, rhs);
                    break;
                default:
                    throw std::logic_error("Unreachable");
                }

                expressions.push_back(expr);
            }
        }

        return expressions.back();
    }
} // symder
