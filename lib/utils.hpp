#ifndef UTILS_HPP
#define UTILS_HPP
#include <memory>

#include "types/Constant/Constant.hpp"

namespace symder
{
    /**
     * Checks if an object of type Known is also of type Supposed
     * @tparam Known a known type of the object
     * @tparam Supposed a subtype of Known that can possibly be the type of the object
     * @param x the object
     * @return whether the object is of type Supposed
     */
    template <typename Known, typename Supposed>
    bool is(const std::shared_ptr<Known>& x)
    {
        return std::dynamic_pointer_cast<Supposed>(x) != nullptr;
    }

    /**
     * Checks if Expression is of type Supposed
     * @tparam Supposed a subtype of Known that can possibly be the type of the object
     * @param x the object
     * @return whether the object is of type Supposed
     */
    template <typename Supposed>
    bool expressionIs(const std::shared_ptr<Expression>& x)
    {
        return is<Expression, Supposed>(x);
    }

    typedef Constant<std::complex<long double>> ComplexConstant;

    /**
     * Checks whether an expression is a complex constant
     * @param x the expression
     * @return whether the expression is a complex constant
     */
    inline bool expressionIsComplexConstant(const std::shared_ptr<Expression>& x)
    {
        return expressionIs<ComplexConstant>(x);
    }

    /**
     * If the expression is a complex constant, returns its value
     * @param x the expression
     * @return the value of the expression if it is a Constant and nullptr otherwise
     */
    inline std::shared_ptr<std::complex<long double>> constValueOf(const std::shared_ptr<Expression>& x)
    {
        return expressionIsComplexConstant(x)
                   ? std::make_shared<std::complex<long double>>(
                       std::dynamic_pointer_cast<ComplexConstant>(x)->get_value())
                   : nullptr;
    }

    /**
     * Constructs a complex constant based on the argument
     * @param x value
     * @return constructed instance
     */
    inline std::shared_ptr<ComplexConstant> complexConstant(std::complex<long double> x)
    {
        return std::make_shared<ComplexConstant>(x);
    }

    inline bool numIsZero(std::complex<long double> num)
    {
        const auto eps = 1e-9;
        return std::abs(num.real()) < eps && std::abs(num.imag()) < eps;
    }
}

#endif //UTILS_HPP
