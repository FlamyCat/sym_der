#ifndef SIN_HPP
#define SIN_HPP
#include "../../Expression.hpp"

namespace symder
{
    class Sin final : public Expression
    {
        std::shared_ptr<Expression> _arg;

    public:
        explicit Sin(const std::shared_ptr<Expression>& arg)
            : _arg(arg) {}

        Sin(const Sin& other) = default;
        Sin(Sin&& other) noexcept = default;
        Sin& operator=(const Sin& other) = default;
        Sin& operator=(Sin&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Sin() override = default;
    };
} // symder

#endif //SIN_HPP
