#include "Expression.hpp"

#include "Ops/Add/Add.hpp"
#include "Ops/Div/Div.hpp"
#include "Ops/Mul/Mul.hpp"
#include "Ops/Sub/Sub.hpp"

namespace symder
{
    std::shared_ptr<Expression> operator+(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs)
    {
        return std::make_shared<Add>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator-(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs)
    {
        return std::make_shared<Sub>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator*(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs)
    {
        return std::make_shared<Mul>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator/(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs)
    {
        return std::make_shared<Div>(lhs, rhs);
    }
}
