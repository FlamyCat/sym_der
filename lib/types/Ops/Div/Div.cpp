#include "Div.hpp"

#include "../Add/Add.hpp"
#include "../Sub/Sub.hpp"
#include "../Mul/Mul.hpp"

namespace symder {
    std::shared_ptr<Expression> Div::differentiate(const std::string& varName)
    {
        auto lhsDiff = _lhs->differentiate(varName);
        auto rhsDiff = _rhs->differentiate(varName);

        auto mulLhs = std::make_shared<Mul>(lhsDiff, _rhs);
        auto mulRhs = std::make_shared<Mul>(_lhs, rhsDiff);

        auto numerator = std::make_shared<Mul>(mulLhs, mulRhs);
        auto denominator = std::make_shared<Mul>(_rhs, _rhs);

        return std::make_shared<Div>(numerator, denominator);
    }

    std::string Div::toString()
    {
        return std::format("({} / {})", _lhs->toString(), _rhs->toString());
    }
} // symder