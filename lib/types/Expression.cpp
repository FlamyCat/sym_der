#include "Expression.hpp"

#include "Ops/Add/Add.hpp"
#include "Ops/Div/Div.hpp"
#include "Ops/Mul/Mul.hpp"
#include "Ops/Pow/Pow.hpp"
#include "Ops/Sub/Sub.hpp"

namespace symder
{
    std::shared_ptr<Expression> operator+(const std::shared_ptr<Expression>& lhs,
                                          const std::shared_ptr<Expression>& rhs)
    {
        return std::make_shared<Add>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator-(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
    {
        return std::make_shared<Sub>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator*(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
    {
        return std::make_shared<Mul>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator/(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
    {
        return std::make_shared<Div>(lhs, rhs);
    }

    std::shared_ptr<Expression> operator^(const std::shared_ptr<Expression>& lhs, const std::shared_ptr<Expression>& rhs)
    {
        return std::make_shared<Pow>(lhs, rhs);
    }
}
