#include "Ln.hpp"

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
} // symder