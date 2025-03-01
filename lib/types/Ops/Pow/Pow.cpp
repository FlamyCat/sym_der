#include "Pow.hpp"

#include "../../Constant/Constant.hpp"
#include "../../Fns/Exp/Exp.hpp"
#include "../../Fns/Ln/Ln.hpp"
#include "../Add/Add.hpp"
#include "../Div/Div.hpp"
#include "../Mul/Mul.hpp"
#include "../Sub/Sub.hpp"

namespace symder
{
    std::shared_ptr<Expression> Pow::differentiate(const std::string& varName)
    {
        const auto baseDiff = _base->differentiate(varName);
        const auto expDiff = _exp->differentiate(varName);

        return std::make_shared<Exp>(_exp * std::make_shared<Ln>(_base)) *
            (_exp * baseDiff / expDiff + expDiff * std::make_shared<Ln>(_base));
    }

    std::string Pow::toString()
    {
        return std::format("({} ^ {})", _base->toString(), _exp->toString());
    }
} // symder
