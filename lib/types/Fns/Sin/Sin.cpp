#include "Sin.hpp"

#include "../../../utils.hpp"
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

    std::shared_ptr<Expression> Sin::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        auto evaluatedArg = _arg->evaluate(vars);
        const auto maybeArgVal = constValueOf(evaluatedArg);

        if (maybeArgVal != nullptr)
            return complexConstant(std::sin(*maybeArgVal));

        return std::make_shared<Sin>(evaluatedArg);
    }
} // symder
