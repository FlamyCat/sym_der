#include "Pow.hpp"

#include "../../../utils.hpp"
#include "../../Constant/Constant.hpp"
#include "../../Fns/Exp/Exp.hpp"
#include "../../Fns/Ln/Ln.hpp"

namespace symder
{
    std::shared_ptr<Expression> Pow::differentiate(const std::string& varName)
    {
        const auto baseDiff = _base->differentiate(varName);
        const auto expDiff = _exp->differentiate(varName);

        return std::make_shared<Exp>(_exp * std::make_shared<Ln>(_base)) *
            (_exp * baseDiff / expDiff + expDiff * std::make_shared<Ln>(_base));
    }

    std::string Pow::toString()
    {
        return std::format("({} ^ {})", _base->toString(), _exp->toString());
    }

    std::shared_ptr<Expression> Pow::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        const auto lhsEvaluated = _base->evaluate(vars);
        const auto rhsEvaluated = _exp->evaluate(vars);

        const auto maybeLhsConst = constValueOf(lhsEvaluated);
        const auto maybeRhsConst = constValueOf(rhsEvaluated);

        if (maybeLhsConst != nullptr && maybeRhsConst != nullptr)
            return std::make_shared<ComplexConstant>(pow(*maybeLhsConst, *maybeRhsConst));

        return lhsEvaluated ^ rhsEvaluated;
    }
} // symder
