cmake_minimum_required(VERSION 3.30)
project(sym_der)

set(CMAKE_CXX_STANDARD 23)

add_executable(sym_der main.cpp
        lib/types/Expression.hpp
        lib/types/Expression.cpp
        lib/types/Constant/Constant.hpp
        lib/types/Variable/Variable.hpp
        lib/types/Variable/Variable.cpp
        lib/types/Variable/Variable.cpp
        lib/types/Ops/Add/Add.cpp
        lib/types/Ops/Add/Add.hpp
        lib/types/Ops/Sub/Sub.cpp
        lib/types/Ops/Sub/Sub.hpp
        lib/types/Ops/Mul/Mul.cpp
        lib/types/Ops/Mul/Mul.hpp
        lib/types/Ops/Div/Div.cpp
        lib/types/Ops/Div/Div.hpp
        lib/types/Fns/Ln/Ln.cpp
        lib/types/Fns/Ln/Ln.hpp
        lib/types/Fns/Exp/Exp.cpp
        lib/types/Fns/Exp/Exp.hpp
        lib/types/Ops/Pow/Pow.cpp
        lib/types/Ops/Pow/Pow.hpp
        lib/types/Fns/Sin/Sin.cpp
        lib/types/Fns/Sin/Sin.hpp
        lib/types/Fns/Cos/Cos.cpp
        lib/types/Fns/Cos/Cos.hpp
        lib/utils.hpp
        lib/parser/Parser.cpp
        lib/parser/Parser.hpp
        lib/parser/TokenType.hpp
        lib/parser/OpType.hpp
        lib/parser/Lexer.cpp
        lib/parser/Lexer.hpp
        lib/parser/Token.hpp
)
