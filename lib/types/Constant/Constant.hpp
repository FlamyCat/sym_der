#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <concepts>
#include <complex>

#include "../Expression.hpp"
#include "../Ops/Add/Add.hpp"

namespace symder
{
    template <typename T>
    concept Numeric = std::integral<T> || std::floating_point<T> ||
        requires(T x)
        {
            requires std::is_same_v<T, std::complex<typename T::value_type>>;
        };

    template <Numeric T>
    class Constant : public Expression
    {
        T _value;

    public:
        Constant(const Constant& other) = default;
        Constant(Constant&& other) noexcept = default;

        Constant& operator=(const Constant& other) = default;
        Constant& operator=(Constant&& other) noexcept = default;

        explicit Constant(T value)
            : _value(value) {}

        std::shared_ptr<Expression> differentiate(const std::string& varName) override;
        std::string toString() override;

        ~Constant() override = default;
    };

#pragma region Implementation
    template <Numeric T>
    std::shared_ptr<Expression> Constant<T>::differentiate(const std::string& varName)
    {
        return std::make_shared<Constant>(0);
    }

    template <Numeric T>
    std::string Constant<T>::toString()
    {
        return std::to_string(_value);
    }
#pragma endregion Implementation
} // symder

#endif //CONSTANT_HPP
