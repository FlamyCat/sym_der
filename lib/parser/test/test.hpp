#ifndef TEST_HPP
#define TEST_HPP
#include <memory>

#include "../Parser.hpp"
#include "../../test/test_utils.hpp"
#include "../../types/Fns/Cos/Cos.hpp"
#include "../../types/Variable/Variable.hpp"

namespace parser
{
    inline void additionTest()
    {
        symder::test::runTest("Parser", "Addition test", []
        {
            std::string expression{"x + y"};

            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");
            const auto expectedExpr = lhs + rhs;

            auto parser = symder::Parser(std::move(expression));

            const auto actualExpr = parser.parse();

            symder::test::assertEqual(expectedExpr->toString(), actualExpr->toString());
        });
    }

    inline void priorityTest()
    {
        symder::test::runTest("Parser", "Priority test", []
        {
            std::string expression{"x + y * z"};

            const auto x = std::make_shared<symder::Variable>("x");
            const auto y = std::make_shared<symder::Variable>("y");
            const auto z = std::make_shared<symder::Variable>("z");

            const auto expectedExpr = x + y * z;

            auto parser = symder::Parser(std::move(expression));
            const auto actualExpr = parser.parse();

            symder::test::assertEqual(expectedExpr->toString(), actualExpr->toString());
        });
    }

    inline void parenTest()
    {
        symder::test::runTest("Parser", "Paren test", []
        {
            std::string expression{"x * (y + z)"};
            auto parser = symder::Parser(std::move(expression));

            const auto x = std::make_shared<symder::Variable>("x");
            const auto y = std::make_shared<symder::Variable>("y");
            const auto z = std::make_shared<symder::Variable>("z");

            const auto expectedExpr = x * (y + z);
            const auto actualExpr = parser.parse();

            symder::test::assertEqual(expectedExpr->toString(), actualExpr->toString());
        });
    }

    inline void fnTest()
    {
        symder::test::runTest("Parser", "Function test", []
        {
            const auto expression{"x + Cos(y)"};
            auto parser = symder::Parser(expression);

            const auto x = std::make_shared<symder::Variable>("x");
            auto y = std::make_shared<symder::Variable>("y");
            const auto cosine = std::make_shared<symder::Cos>(y);

            const auto expectedExpr = x + cosine;
            const auto actualExpr = parser.parse();

            symder::test::assertEqual(expectedExpr->toString(), actualExpr->toString());
        });
    }
}

#undef TEST_HPP
#endif //TEST_HPP
