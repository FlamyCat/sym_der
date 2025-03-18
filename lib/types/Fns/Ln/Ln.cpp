#include "Ln.hpp"

#include "../../../utils.hpp"
#include "../../Ops/Div/Div.hpp"

namespace symder
{
    std::shared_ptr<Expression> Ln::differentiate(const std::string& varName)
    {
        const auto argDiff = _arg->differentiate(varName);
        return argDiff / _arg;
    }

    std::string Ln::toString()
    {
        return std::format("ln({})", _arg->toString());
    }

    std::shared_ptr<Expression> Ln::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        auto evaluatedArg = _arg->evaluate(vars);
        const auto maybeArgVal = constValueOf(evaluatedArg);

        if (maybeArgVal != nullptr)
        {
            if (maybeArgVal->real() < 0)
                throw std::invalid_argument("Ln::evaluate() - maybeArgVal < 0");

            return complexConstant(std::log(*maybeArgVal));
        }

        return std::make_shared<Ln>(evaluatedArg);
    }
} // symder
