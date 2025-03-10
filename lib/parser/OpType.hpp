#ifndef OPTYPE_HPP
#define OPTYPE_HPP

namespace symder
{
    enum OpType
    {
        OpAdd, OpSub, OpMul, OpDiv, OpPow,
        FnSin, FnCos, FnExp, FnLn,
        Lparen,
    };
}

#endif //OPTYPE_HPP
