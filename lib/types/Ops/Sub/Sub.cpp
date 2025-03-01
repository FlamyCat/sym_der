#include "Sub.hpp"

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
} // symder
