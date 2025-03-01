#include "Mul.hpp"

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
} // symder