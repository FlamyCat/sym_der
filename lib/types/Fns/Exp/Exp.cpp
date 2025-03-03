#include "Exp.hpp"

#include "../../../utils.hpp"
#include "../../Ops/Add/Add.hpp"
#include "../../Ops/Mul/Mul.hpp"
#include "../../Ops/Sub/Sub.hpp"

namespace symder {
    std::shared_ptr<Expression> Exp::differentiate(const std::string& varName)
    {
        auto argDiff = _arg->differentiate(varName);
        auto thisCopy = std::make_shared<Exp>(Exp(*this));

        return std::make_shared<Mul>(thisCopy, argDiff);
    }

    std::string Exp::toString()
    {
        return std::format("exp({})", _arg->toString());
    }

    std::shared_ptr<Expression> Exp::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        auto evaluatedArg = _arg->evaluate(vars);
        const auto maybeArgVal = constValueOf(evaluatedArg);

        if (maybeArgVal != nullptr)
            return std::make_shared<ComplexConstant>(std::exp(*maybeArgVal));

        return std::make_shared<Exp>(evaluatedArg);
    }
} // symder