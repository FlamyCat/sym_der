#include "Cos.hpp"

#include "../../Constant/Constant.hpp"
#include "../Sin/Sin.hpp"

namespace symder
{
    std::shared_ptr<Expression> Cos::differentiate(const std::string& varName)
    {
        return std::make_shared<Constant<int>>(0) - std::make_shared<Sin>(_arg) * _arg->differentiate(varName);
    }

    std::string Cos::toString()
    {
        return std::format("cos({})", _arg->toString());
    }
} // symder
