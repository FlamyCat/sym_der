#include "Mul.hpp"

#include "../../../utils.hpp"
#include "../Add/Add.hpp"
#include "../Sub/Sub.hpp"
#include "../Div/Div.hpp"

namespace symder {
    std::shared_ptr<Expression> Mul::differentiate(const std::string& varName)
    {
        return std::make_shared<Add>(
            Add(
                std::make_shared<Mul>(Mul(_lhs->differentiate(varName), _rhs)),
                std::make_shared<Mul>(Mul(_lhs, _rhs->differentiate(varName)))
            )
        );
    }

    std::string Mul::toString()
    {
        return std::format("({} * {})", _lhs->toString(), _rhs->toString());
    }

    std::shared_ptr<Expression> Mul::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        const auto lhsEvaluated = _lhs->evaluate(vars);
        const auto rhsEvaluated = _rhs->evaluate(vars);

        const auto maybeLhsConst = constValueOf(lhsEvaluated);
        const auto maybeRhsConst = constValueOf(rhsEvaluated);

        if (maybeLhsConst != nullptr && maybeRhsConst != nullptr)
            return std::make_shared<ComplexConstant>(*maybeLhsConst * *maybeRhsConst);

        return lhsEvaluated * rhsEvaluated;
    }
} // symder