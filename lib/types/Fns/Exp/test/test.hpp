#ifndef TEST_HPP
#define TEST_HPP
#include <memory>

#include "../Exp.hpp"
#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace exponent
{
    inline void testToString()
    {
        symder::test::runTest("Exponent", "ToString works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Exp>(arg);

            symder::test::assertEqual(expr->toString(), {"exp(x)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("Exponent", "Differentiation works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Exp>(arg);

            const auto result = expr->differentiate("x")->toString();
            symder::test::assertEqual(result, {"(exp(x) * 1)"});
        });
    }
}

#undef TEST_HPP
#endif //TEST_HPP
