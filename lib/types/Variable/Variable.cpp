#include "Variable.hpp"

#include "../Constant/Constant.hpp"
#include "../Ops/Add/Add.hpp"
#include "../Ops/Div/Div.hpp"
#include "../Ops/Mul/Mul.hpp"
#include "../Ops/Sub/Sub.hpp"

namespace symder {
    std::shared_ptr<Expression> Variable::differentiate(const std::string& varName)
    {
        return std::make_shared<Constant<int>>(varName == _name ? 1 : 0);
    }

    std::string Variable::toString()
    {
        return _name;
    }

    std::shared_ptr<Expression> Variable::evaluate(
        const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        if (vars.contains(_name))
            return std::make_shared<Constant<std::complex<long double>>>(vars.at(_name));

        return std::make_shared<Variable>(*this);
    }
} // symder