cmake_minimum_required(VERSION 3.28)
project(sym_der)

set(CMAKE_CXX_STANDARD 20)

add_executable(sym_der main.cpp
        lib/types/Expression.cpp
        lib/types/Variable/Variable.cpp
        lib/types/Variable/Variable.cpp
        lib/types/Ops/Add/Add.cpp
        lib/types/Ops/Sub/Sub.cpp
        lib/types/Ops/Mul/Mul.cpp
        lib/types/Ops/Div/Div.cpp
        lib/types/Fns/Ln/Ln.cpp
        lib/types/Fns/Exp/Exp.cpp
        lib/types/Ops/Pow/Pow.cpp
        lib/types/Fns/Sin/Sin.cpp
        lib/types/Fns/Cos/Cos.cpp
        lib/parser/Parser.cpp
        lib/parser/Lexer.cpp
)

add_executable(symder_test lib/test/test_main.cpp
        lib/types/Expression.cpp
        lib/types/Variable/Variable.cpp
        lib/types/Variable/Variable.cpp
        lib/types/Ops/Add/Add.cpp
        lib/types/Ops/Sub/Sub.cpp
        lib/types/Ops/Mul/Mul.cpp
        lib/types/Ops/Div/Div.cpp
        lib/types/Fns/Ln/Ln.cpp
        lib/types/Fns/Exp/Exp.cpp
        lib/types/Ops/Pow/Pow.cpp
        lib/types/Fns/Sin/Sin.cpp
        lib/types/Fns/Cos/Cos.cpp
        lib/parser/Parser.cpp
        lib/parser/Lexer.cpp
)

add_custom_target(test
        DEPENDS symder_test
        COMMAND ./symder_test
)
