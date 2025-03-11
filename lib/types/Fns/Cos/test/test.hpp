#ifndef TEST_HPP
#define TEST_HPP
#include <memory>

#include "../Cos.hpp"
#include "../../../../test/test_utils.hpp"
#include "../../../Variable/Variable.hpp"

namespace cosine
{
    inline void testToString()
    {
        symder::test::runTest("cos", "ToString works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Cos>(arg);

            const auto res = expr->toString();
            symder::test::assertEqual(res, {"cos(x)"});
        });
    }

    inline void testDifferentiation()
    {
        symder::test::runTest("cos", "Differentiation works correctly", []
        {
            auto arg = std::make_shared<symder::Variable>("x");
            const auto expr = std::make_shared<symder::Cos>(arg);

            const auto res = expr->differentiate("x")->toString();

            symder::test::assertEqual(res, {"(0 - (sin(x) * 1))"});
        });
    }
}

#undef TEST_HPP
#endif //TEST_HPP
