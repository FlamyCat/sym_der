#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include <complex>
#include <memory>
#include <unordered_map>

namespace symder
{
    class Expression
    {
    public:
        virtual ~Expression() = default;

        virtual std::shared_ptr<Expression> differentiate(const std::string& varName) = 0;
        virtual std::string toString() = 0;

        virtual std::shared_ptr<Expression> evaluate(
            const std::unordered_map<std::string, std::complex<long double>>& vars) = 0;
    };

    std::shared_ptr<Expression> operator+(const std::shared_ptr<Expression>& lhs,
                                          const std::shared_ptr<Expression>& rhs);
    std::shared_ptr<Expression> operator-(const std::shared_ptr<Expression>& lhs,
                                          const std::shared_ptr<Expression>& rhs);
    std::shared_ptr<Expression> operator*(const std::shared_ptr<Expression>& lhs,
                                          const std::shared_ptr<Expression>& rhs);
    std::shared_ptr<Expression> operator/(const std::shared_ptr<Expression>& lhs,
                                          const std::shared_ptr<Expression>& rhs);
    std::shared_ptr<Expression> operator^(const std::shared_ptr<Expression>& lhs,
                                          const std::shared_ptr<Expression>& rhs);
} // symder

#endif //EXPRESSION_HPP
