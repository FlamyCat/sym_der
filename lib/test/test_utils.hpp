#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP
#include <format>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>

namespace symder::test
{
    struct AssertionError final : std::runtime_error
    {
        explicit AssertionError(const std::string& s) : std::runtime_error(s) {}
    };

    template <typename T>
    void assertEqual(T lhs, T rhs)
    {
        if (lhs != rhs)
            throw AssertionError(std::format("Assertion \"lhs == rhs\" failed.\nLhs:\n\t{}\nRhs:\n\t{}", lhs, rhs));
    }

    // The ReSharper thinks that the lambda may be declared const, though it's not true (it will lead to a compilation error)
    // ReSharper disable once CppParameterMayBeConst
    inline void runTest(const std::string& group, const std::string& name, void testMethod())
    {
        const auto separator = "=========================\n";
        const auto smallSeparator = "-------------------------\n";

        std::cout << separator;
        std::cout << "Running test " << std::quoted(group) << " | " << std::quoted(name) << std::endl;
        std::cout << smallSeparator;

        try
        {
            testMethod();
            std::cout << "OK" << std::endl;
        }
        catch (const AssertionError& e)
        {
            std::cout << "Test failed" << std::endl;
            std::cout << e.what() << std::endl;
        }

        std::cout << separator;
        std::cout << std::endl;
    }
}

#endif //TESTUTILS_HPP
