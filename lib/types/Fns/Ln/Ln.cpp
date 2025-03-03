#include "Ln.hpp"

#include "../../../utils.hpp"
#include "../../Ops/Add/Add.hpp"
#include "../../Ops/Div/Div.hpp"
#include "../../Ops/Mul/Mul.hpp"
#include "../../Ops/Sub/Sub.hpp"

namespace symder {
    std::shared_ptr<Expression> Ln::differentiate(const std::string& varName)
    {
        auto argDiff = _arg->differentiate(varName);
        auto frac = std::make_shared<Mul>(argDiff, _arg);

        return std::make_shared<Ln>(frac);
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
            return complexConstant(std::log(*maybeArgVal));

        return std::make_shared<Ln>(evaluatedArg);
    }
} // symder