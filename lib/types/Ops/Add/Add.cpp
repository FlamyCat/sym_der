#include "Add.hpp"

#include "../../../utils.hpp"
#include "../../Constant/Constant.hpp"

namespace symder
{
    std::shared_ptr<Expression> Add::differentiate(const std::string& varName)
    {
        return std::make_shared<Add>(_lhs->differentiate(varName), _rhs->differentiate(varName));
    }

    std::string Add::toString()
    {
        return std::format("({} + {})", _lhs->toString(), _rhs->toString());
    }

    std::shared_ptr<Expression> Add::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        const auto lhsEvaluated = _lhs->evaluate(vars);
        const auto rhsEvaluated = _rhs->evaluate(vars);

        const auto maybeLhsConst = constValueOf(lhsEvaluated);
        const auto maybeRhsConst = constValueOf(rhsEvaluated);

        if (maybeLhsConst != nullptr && maybeRhsConst != nullptr)
            return std::make_shared<ComplexConstant>(*maybeLhsConst + *maybeRhsConst);

        return lhsEvaluated + rhsEvaluated;
    }
} // symder
