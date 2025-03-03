#ifndef POW_H
#define POW_H
#include "../../Expression.hpp"
#include "../../Constant/Constant.hpp"

namespace symder
{
    class Pow final : public Expression
    {
        std::shared_ptr<Expression> _base;
        std::shared_ptr<Expression> _exp;

    public:
        Pow(const std::shared_ptr<Expression>& base, const std::shared_ptr<Expression>& exp)
            : _base(base),
              _exp(exp) {}

        Pow(const Pow& other) = default;
        Pow(Pow&& other) noexcept = default;
        Pow& operator=(const Pow& other) = default;
        Pow& operator=(Pow&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Pow() override = default;
    };
} // symder

#endif //POW_H
