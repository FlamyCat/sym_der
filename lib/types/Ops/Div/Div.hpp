#ifndef DIV_HPP
#define DIV_HPP
#include <memory>

#include "../../Expression.hpp"

namespace symder
{
    class Div final : public Expression
    {
        std::shared_ptr<Expression> _lhs;
        std::shared_ptr<Expression> _rhs;

    public:
        Div(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
            : _lhs(lhs),
              _rhs(rhs) {}

        Div(const Div& other) = default;
        Div(Div&& other) noexcept = default;
        Div& operator=(const Div& other) = default;
        Div& operator=(Div&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Div() override = default;
    };
} // symder

#endif //DIV_HPP
