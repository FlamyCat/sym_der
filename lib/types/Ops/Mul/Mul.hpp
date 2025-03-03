#ifndef MUL_HPP
#define MUL_HPP
#include <memory>

#include "../../Expression.hpp"

namespace symder
{
    class Expression;

    class Mul final : public Expression
    {
        std::shared_ptr<Expression> _lhs;
        std::shared_ptr<Expression> _rhs;

    public:
        Mul(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
            : _lhs(lhs),
              _rhs(rhs)
        {
        }

        Mul(const Mul& other) = default;
        Mul(Mul&& other) noexcept = default;
        Mul& operator=(const Mul& other) = default;
        Mul& operator=(Mul&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Mul() override = default;
    };
} // symder

#endif //MUL_HPP
