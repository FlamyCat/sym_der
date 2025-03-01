#include "Add.hpp"
#include "../Sub/Sub.hpp"
#include "../Mul/Mul.hpp"
#include "../Div/Div.hpp"

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
} // symder
