#ifndef TESTS_HPP
#define TESTS_HPP
#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace addition
{
    inline void testToString()
    {
        symder::test::runTest("Addition", "ToString works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = lhs + rhs;

            symder::test::assertEqual(expr->toString(), {"(x + y)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("Addition", "Differentiation works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = (lhs + rhs)->differentiate("x");

            symder::test::assertEqual(expr->toString(), {"(1 + 0)"});
        });
    }

    inline void testSubstitution()
    {
        symder::test::runTest("Addition", "Substitution works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = lhs + rhs;

            std::unordered_map<std::string, std::complex<long double>> values{};
            values["x"] = 1.;
            values["y"] = 1.;

            const auto res = expr->evaluate(values);

            symder::test::assertEqual(res->toString(), {"2 + 0i"});
        });
    }
}

#undef TESTS_HPP
#endif //TESTS_HPP
