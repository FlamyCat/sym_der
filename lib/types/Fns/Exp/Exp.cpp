#include "Exp.hpp"

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
} // symder