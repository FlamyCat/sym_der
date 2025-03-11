#ifndef TESTS_HPP
#define TESTS_HPP
#include <memory>

#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace multiplication
{
    inline void testToString()
    {
        symder::test::runTest("Multiplication", "ToString works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = lhs * rhs;

            symder::test::assertEqual(expr->toString(), {"(x * y)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("Multiplication", "Differentiation works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");
            const auto expr = lhs * rhs;

            symder::test::assertEqual(expr->differentiate("x")->toString(), {"((1 * y) + (x * 0))"});
        });
    }

    inline void testSubstitution()
    {
        symder::test::runTest("Multiplication", "Substitution works correctly", []
        {
            const auto lhs = std::make_shared<symder::Variable>("x");
            const auto rhs = std::make_shared<symder::Variable>("y");

            const auto expr = lhs * rhs;

            auto values = std::unordered_map<std::string, std::complex<long double>>();
            values["x"] = 2.;
            values["y"] = 2.;

            symder::test::assertEqual(expr->evaluate(values)->toString(), {"4 + 0i"});
        });
    }
}

#undef TESTS_HPP
#endif //TESTS_HPP
