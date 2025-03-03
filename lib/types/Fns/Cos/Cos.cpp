#include "Cos.hpp"

#include "../../../utils.hpp"
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

    std::shared_ptr<Expression> Cos::evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        auto evaluatedArg = _arg->evaluate(vars);
        const auto maybeArgVal = constValueOf(evaluatedArg);

        if (maybeArgVal != nullptr)
            return std::make_shared<ComplexConstant>(std::cos(*maybeArgVal));

        return std::make_shared<Cos>(evaluatedArg);
    }
} // symder
