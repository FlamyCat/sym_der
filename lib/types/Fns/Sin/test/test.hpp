#ifndef TEST_HPP
#define TEST_HPP
#include <memory>

#include "../Sin.hpp"
#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace sine
{
    inline void testToString()
    {
        symder::test::runTest("sin", "ToString works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Sin>(arg);

            const auto res = expr->toString();
            symder::test::assertEqual(res, {"sin(x)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("sin", "Differentiation works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Sin>(arg);

            const auto res = expr->differentiate("x")->toString();

            symder::test::assertEqual(res, {"(cos(x) * 1)"});
        });
    }
}

#undef TEST_HPP
#endif //TEST_HPP
