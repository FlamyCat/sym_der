#ifndef EXP_HPP
#define EXP_HPP
#include "../../Expression.hpp"

namespace symder
{
    class Exp final : public Expression
    {
        std::shared_ptr<Expression> _arg;

    public:
        explicit Exp(const std::shared_ptr<Expression>& arg)
            : _arg(arg) {}

        Exp(const Exp& other) = default;
        Exp(Exp&& other) noexcept = default;
        Exp& operator=(const Exp& other) = default;
        Exp& operator=(Exp&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        ~Exp() override = default;
    };
} // symder

#endif //EXP_HPP
