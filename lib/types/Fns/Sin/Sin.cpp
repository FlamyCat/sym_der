#include "Sin.hpp"

#include "../Cos/Cos.hpp"

namespace symder
{
    std::shared_ptr<Expression> Sin::differentiate(const std::string& varName)
    {
        return std::make_shared<Cos>(_arg) * _arg->differentiate(varName);
    }

    std::string Sin::toString()
    {
        return std::format("sin({})", _arg->toString());
    }
} // symder
