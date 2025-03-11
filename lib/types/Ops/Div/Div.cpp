#include "Div.hpp"

#include "../../../utils.hpp"
#include "../Sub/Sub.hpp"

namespace symder
{
    std::shared_ptr<Expression> Div::differentiate(const std::string& varName)
    {
        const auto lhsDiff = _lhs->differentiate(varName);
        const auto rhsDiff = _rhs->differentiate(varName);

        const auto numerator = lhsDiff * _rhs - _lhs * rhsDiff;
        const auto denominator = _rhs * _rhs;

        return numerator / denominator;
    }

    std::string Div::toString()
    {
        return std::format("({} / {})", _lhs->toString(), _rhs->toString());
    }

    std::shared_ptr<Expression> Div::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        const auto lhsEvaluated = _lhs->evaluate(vars);
        const auto rhsEvaluated = _rhs->evaluate(vars);

        const auto maybeLhsConst = constValueOf(lhsEvaluated);
        const auto maybeRhsConst = constValueOf(rhsEvaluated);

        if (maybeLhsConst != nullptr && maybeRhsConst != nullptr)
        {
            return std::make_shared<ComplexConstant>(*maybeLhsConst / *maybeRhsConst);
        }

        return lhsEvaluated / rhsEvaluated;
    }
} // symder
