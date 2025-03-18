cmake_minimum_required(VERSION 3.28)
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

add_executable(symder_test lib/test/test_main.cpp
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

        lib/test/test_utils.hpp
        lib/types/Variable/tests/test_differentiation.hpp
        lib/types/Constant/test/tests.hpp
        lib/types/Ops/Add/test/tests.hpp
        lib/types/Ops/Sub/test/tests.hpp
        lib/types/Ops/Mul/test/tests.hpp
        lib/types/Ops/Div/test/test.hpp
        lib/types/Fns/Cos/test/test.hpp
        lib/types/Fns/Sin/test/test.hpp
        lib/types/Fns/Exp/test/test.hpp
        lib/types/Fns/Ln/test/test.hpp
        lib/parser/test/test.hpp
)

add_custom_target(test
        DEPENDS symder_test
        COMMAND ./symder_test
)
