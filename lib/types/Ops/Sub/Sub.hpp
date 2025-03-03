#ifndef SUB_HPP
#define SUB_HPP
#include <memory>

#include "../../Expression.hpp"

namespace symder
{
    class Sub final : public Expression
    {
        std::shared_ptr<Expression> _lhs;
        std::shared_ptr<Expression> _rhs;

    public:
        Sub(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
            : _lhs(lhs),
              _rhs(rhs) {}

        Sub(const Sub& other) = default;
        Sub(Sub&& other) noexcept = default;
        Sub& operator=(const Sub& other) = default;
        Sub& operator=(Sub&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Sub() override = default;
    };
} // symder

#endif //SUB_HPP
