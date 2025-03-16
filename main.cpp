#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

#include "lib/utils.hpp"
#include "lib/parser/Parser.hpp"
#include "lib/types/Variable/Variable.hpp"

void handleDifferentiation(char** argv)
{
    const std::string rawExpr = argv[2];

    auto expressionParser = symder::Parser(rawExpr);
    auto expr = expressionParser.parse();

    const std::string variable = argv[4];
    expr = expr->differentiate(variable);

    std::cout << expr->toString() << std::endl;
}

enum VarDeclErrorKind
{
    NoEqualsSign
};

struct VarDeclError final : std::exception
{
    VarDeclErrorKind kind;

    explicit VarDeclError(const VarDeclErrorKind kind)
        : kind(kind) {}
};

struct VarDecl
{
    std::string varName;
    std::complex<long double> value;
};

VarDecl parseVariableDeclaration(std::string declaration)
{
    const auto delimiterPosition = declaration.find('=');
    if (delimiterPosition == std::string::npos)
    {
        auto quotedDecl = std::quoted(declaration);
        std::cout << "Declaration " << quotedDecl << " does not contain the '=' sign" << std::endl;
        throw VarDeclError{NoEqualsSign};
    }

    auto variable = declaration.substr(0, delimiterPosition);

    const auto expr = declaration.substr(delimiterPosition + 1, declaration.size() - delimiterPosition - 1);
    auto parser = symder::Parser{expr};
    const auto value = constValueOf(parser.parse());

    VarDecl decl = {variable, *value};

    return decl;
}

void handleEvaluation(const int argc, char** argv)
{
    const std::string rawExpr = argv[2];
    auto expressionParser = symder::Parser(rawExpr);
    const auto expr = expressionParser.parse();

    std::unordered_map<std::string, std::complex<long double>> vars;

    for (int i = 3; i < argc; ++i)
    {
        auto [varName, value] = parseVariableDeclaration(argv[i]);

        vars[varName] = value;
    }

    const auto result = expr->evaluate(vars);

    std::cout << result->toString() << std::endl;
}

int main(const int argc, char** argv)
{
    if (constexpr auto expectedNumberOfArgs = 3; argc < 4)
    {
        std::cout << std::format("There must be at least {} args (the command, the expression and the variable(s))",
                                 expectedNumberOfArgs);

        return 1;
    }

    if (strcmp(argv[1], "--diff") == 0)
    {
        handleDifferentiation(argv);
        return 0;
    }

    if (strcmp(argv[1], "--eval") == 0)
    {
        handleEvaluation(argc, argv);
        return 0;
    }

    std::cout << "Invalid command: " << std::quoted(argv[1]) << std::endl;

    return 0;
}
