#ifndef TEST_DIFFERENTIATION_HPP
#define TEST_DIFFERENTIATION_HPP
#include "../Variable.hpp"
#include "../../../test/test_utils.hpp"

namespace variable
{
    inline void testDifferentiation()
    {
        symder::test::runTest("Variable", "Differentiate by the same variable", []
        {
            auto expr = symder::Variable("x");
            const auto result = expr.differentiate("x");

            symder::test::assertEqual(result->toString(), {"1"});
        });

        symder::test::runTest("Variable", "Differentiate by different variable", []
        {
            auto expr = symder::Variable("x");
            const auto result = expr.differentiate("y");

            symder::test::assertEqual(result->toString(), {"0"});
        });
    }
}

#undef TEST_DIFFERENTIATION_HPP
#endif //TEST_DIFFERENTIATION_HPP
