#include "Sub.hpp"

#include "../../../utils.hpp"
#include "../../Constant/Constant.hpp"
#include "../Add/Add.hpp"
#include "../Mul/Mul.hpp"
#include "../Div/Div.hpp"

namespace symder
{
    std::shared_ptr<Expression> Sub::differentiate(const std::string& varName)
    {
        return std::make_shared<Sub>(_lhs->differentiate(varName), _rhs->differentiate(varName));
    }

    std::string Sub::toString()
    {
        return std::format("({} - {})", _lhs->toString(), _rhs->toString());
    }

    std::shared_ptr<Expression> Sub::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        const auto lhsEvaluated = _lhs->evaluate(vars);
        const auto rhsEvaluated = _rhs->evaluate(vars);

        const auto maybeLhsConst = constValueOf(rhsEvaluated);
        const auto maybeRhsConst = constValueOf(rhsEvaluated);

        if (maybeLhsConst != nullptr && maybeRhsConst != nullptr)
            return std::make_shared<ComplexConstant>(*maybeLhsConst - *maybeRhsConst);

        return lhsEvaluated - rhsEvaluated;
    }
} // symder
