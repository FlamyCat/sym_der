#ifndef LN_HPP
#define LN_HPP
#include <memory>

#include "../../Expression.hpp"

namespace symder {

class Ln final : public Expression {
    std::shared_ptr<Expression> _arg;

    public:
    explicit Ln(const std::shared_ptr<Expression>& arg)
        : _arg(arg) {}

    Ln(const Ln& other) = default;
    Ln(Ln&& other) noexcept = default;
    Ln& operator=(const Ln& other) = default;
    Ln& operator=(Ln&& other) noexcept = default;

    std::shared_ptr<Expression> differentiate(const std::string& varName) override;
    std::string toString() override;

    std::shared_ptr<Expression>
    evaluate(const std::unordered_map<std::string, std::complex<long double>>& vars) override;

    ~Ln() override = default;
};

} // symder

#endif //LN_HPP
