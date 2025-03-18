#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <concepts>
#include <complex>
#include <format>

#include "../Expression.hpp"
#include "../Ops/Add/Add.hpp"

namespace symder
{
    template <typename T>
    concept Numeric = std::integral<T> || std::floating_point<T> || std::is_same_v<
        T, std::complex<typename T::value_type>>;

    template <Numeric T>
    class Constant final : public Expression
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

        std::shared_ptr<Expression>
        evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

        [[nodiscard]] T get_value() const { return _value; }
        ~Constant() override = default;
    };

#pragma region Implementation
    template <Numeric T>
    std::shared_ptr<Expression> Constant<T>::differentiate(const std::string& varName)
    {
        return std::make_shared<Constant>(0);
    }

    template <>
    inline std::string Constant<std::complex<long double>>::toString()
    {
        return std::format("{} + {}i", std::real(_value), std::imag(_value));
    }

    template <>
    inline std::string Constant<std::complex<int>>::toString()
    {
        return std::format("{} + {}i", std::real(_value), std::imag(_value));
    }

    template <Numeric T>
    std::string Constant<T>::toString()
    {
        return std::to_string(_value);
    }

    template <Numeric T>
    std::shared_ptr<Expression> Constant<T>::evaluate(
        const std::unordered_map<std::string, std::complex<long double>>& vars)
    {
        return std::make_shared<Constant>(*this);
    }
#pragma endregion Implementation
} // symder

#endif //CONSTANT_HPP
