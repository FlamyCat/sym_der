#ifndef TEST_HPP
#define TEST_HPP
#include <memory>

#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace division
{
    inline void testToString()
    {
        symder::test::runTest("Division", "ToString works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = lhs / rhs;

            symder::test::assertEqual(expr->toString(), {"(x / y)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("Division", "Differentiation works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");
            const auto expr = lhs / rhs;

            const auto res = expr->differentiate("x")->toString();
            symder::test::assertEqual(res, {"(((1 * y) - (x * 0)) / (y * y))"});
        });
    }

    inline void testSubstitution()
    {
        symder::test::runTest("Division", "Substitution works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");
            const auto expr = lhs / rhs;

            auto values = std::unordered_map<std::string, std::complex<long double>>();
            values["x"] = 1.0;
            values["y"] = 1.0;

            const auto res = expr->evaluate(values);

            symder::test::assertEqual(res->toString(), {"1 + 0i"});
        });
    }
}

#undef TEST_HPP
#endif //TEST_HPP
