#ifndef TEST_HPP
#define TEST_HPP
#include "../Ln.hpp"
#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace logarithm
{
    inline void testToString()
    {
        symder::test::runTest("Logarithm", "ToString works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Ln>(arg);

            symder::test::assertEqual(expr->toString(), {"ln(x)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("Logarithm", "Differentiation works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Ln>(arg);

            const auto result = expr->differentiate("x")->toString();
            symder::test::assertEqual(result, {"(1 / x)"});
        });
    }
}

#undef TEST_HPP
#endif //TEST_HPP
