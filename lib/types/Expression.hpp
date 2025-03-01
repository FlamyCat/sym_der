#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include <memory>

namespace symder
{
    class Expression
    {
        public:
        virtual ~Expression() = default;
        virtual std::shared_ptr<Expression> differentiate(const std::string& varName) = 0;

        virtual std::string toString() = 0;
    };

    std::shared_ptr<Expression> operator+(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
    std::shared_ptr<Expression> operator-(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
    std::shared_ptr<Expression> operator*(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
    std::shared_ptr<Expression> operator/(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
} // symder

#endif //EXPRESSION_HPP
