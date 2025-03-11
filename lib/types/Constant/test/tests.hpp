#ifndef TESTS_HPP
#define TESTS_HPP
#include "../Constant.hpp"
#include "../../../test/test_utils.hpp"

namespace constant
{
    inline void testDifferentiation()
    {
        symder::test::runTest("Constant", "Differentiation always returns 0", []
        {
            auto expr = symder::Constant(1);
            const auto result = expr.differentiate("x");

            symder::test::assertEqual(result->toString(), {"0"});
        });
    }

    inline void testToString()
    {
        symder::test::runTest("Constant", "ToString works correctly for int", []
        {
            auto expr = symder::Constant(-1);
            const auto result = expr.toString();

            symder::test::assertEqual(result, {"-1"});
        });

        symder::test::runTest("Constant", "ToString works correctly for float", []
        {
            auto expr = symder::Constant(-1.0);
            const auto result = stod(expr.toString());
            symder::test::assertEqual(result, -1.0);
        });

        symder::test::runTest("Constant", "ToString works correctly for complex", []
        {
            auto expr = symder::Constant(std::complex(1, 1));
            const auto result = expr.toString();

            symder::test::assertEqual(result, {"1 + 1i"});
        });
    }
}

#undef TESTS_HPP
#endif //TESTS_HPP
