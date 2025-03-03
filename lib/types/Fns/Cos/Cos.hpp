#ifndef COS_HPP
#define COS_HPP
#include <memory>

#include "../../Expression.hpp"

namespace symder
{
    class Cos final : public Expression
    {
        std::shared_ptr<Expression> _arg;

    public:
        explicit Cos(const std::shared_ptr<Expression>& arg)
            : _arg(arg) {}

        Cos(const Cos& other) = default;
        Cos(Cos&& other) noexcept = default;
        Cos& operator=(const Cos& other) = default;
        Cos& operator=(Cos&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Cos() override = default;
    };
} // symder

#endif //COS_HPP
