#include "../parser/test/test.hpp"
#include "../types/Constant/test/tests.hpp"
#include "../types/Fns/Cos/test/test.hpp"
#include "../types/Fns/Exp/test/test.hpp"
#include "../types/Fns/Ln/test/test.hpp"
#include "../types/Fns/Sin/test/test.hpp"
#include "../types/Ops/Add/test/tests.hpp"
#include "../types/Ops/Div/test/test.hpp"
#include "../types/Ops/Mul/test/tests.hpp"
#include "../types/Ops/Sub/test/tests.hpp"
#include "../types/Variable/tests/test_differentiation.hpp"

int main()
{
    variable::testDifferentiation();

    constant::testDifferentiation();
    constant::testToString();

    addition::testDifferentiation();
    addition::testToString();
    addition::testSubstitution();

    subtraction::testDifferentiation();
    subtraction::testToString();
    subtraction::testSubstitution();

    multiplication::testDifferentiation();
    multiplication::testToString();
    multiplication::testSubstitution();

    division::testDifferentiation();
    division::testToString();
    division::testSubstitution();

    cosine::testDifferentiation();
    cosine::testToString();

    sine::testDifferentiation();
    sine::testToString();

    exponent::testDifferentiation();
    exponent::testToString();

    logarithm::testDifferentiation();
    logarithm::testToString();

    parser::additionTest();
    parser::fnTest();
    parser::parenTest();
    parser::priorityTest();
}
