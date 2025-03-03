#ifndef VARIABLE_HPP
#define VARIABLE_HPP
#include <utility>

#include "../Expression.hpp"

namespace symder
{
    class Variable final : public Expression
    {
        std::string _name;

    public:
        explicit Variable(std::string name)
            : _name(std::move(name)) {}

        Variable(const Variable& other) = default;
        Variable(Variable&& other) noexcept = default;
        Variable& operator=(const Variable& other) = default;
        Variable& operator=(Variable&& other) noexcept = default;

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        ~Variable() override = default;
    };
} // symder

#endif //VARIABLE_HPP
