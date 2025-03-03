#ifndef ADD_HPP
#define ADD_HPP
#include <memory>

#include "../../Expression.hpp"

namespace symder
{
    class Add final : public Expression
    {
        std::shared_ptr<Expression> _lhs;
        std::shared_ptr<Expression> _rhs;

    public:
        Add(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
            : _lhs(lhs),
              _rhs(rhs) {}

        Add(const Add& other) = default;
        Add(Add&& other) noexcept = default;
        Add& operator=(const Add& other) = default;
        Add& operator=(Add&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Add() override = default;
    };
} // symder

#endif //ADD_HPP
