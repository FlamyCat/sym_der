#ifndef TESTS_HPP
#define TESTS_HPP
#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace subtraction
{
    inline void testToString()
    {
        symder::test::runTest("Subtraction", "ToString works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = lhs - rhs;

            symder::test::assertEqual(expr->toString(), {"(x - y)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("Subtraction", "Differentiation works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");
            const auto expr = (lhs - rhs)->differentiate("x");

            symder::test::assertEqual(expr->toString(), {"(1 - 0)"});
        });
    }

    inline void testSubstitution()
    {
        symder::test::runTest("Subtraction", "Substitution works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");
            const auto expr = lhs - rhs;

            auto values = std::unordered_map<std::string, std::complex<long double>>();
            values["x"] = 1.;
            values["y"] = 1.;

            const auto res = expr->evaluate(values)->toString();

            symder::test::assertEqual(res, {"0 + 0i"});
        });
    }
}

#undef TESTS_HPP
#endif //TESTS_HPP
