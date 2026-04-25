# sym_der

sym_der is a C++ library for symbolic expression differentiation and evaluation, including partial evaluation. It also provides a CMake executable for evaluating symbolic expressions and computing their derivatives from the command line.

## Features

- Symbolic differentiation of expressions
- Expression evaluation with variable substitution (complex values are
  supported!)
- Partial evaluation (substitute some variables while keeping others)
- Support for basic operations: addition, subtraction, multiplication, division,
  powers
- Support for functions: sin, cos, exp, ln
- Command-line interface for quick evaluation and differentiation

## Building

```bash
# Perform configuration
cmake -S . -B build -G Ninja    # Or specify your preferred build system instead of "Ninja"

# Then build the project
cmake --build build
```

This produces two executables inside the `build` directory:
- `sym_der` - the main CLI tool
- `symder_test` - the test runner

## Usage

The following examples assume you're inside the `build` directory that was created during configuration (see part called `Building`).

### Differentiation

```bash
./sym_der --diff "x * sin(x)" --var x
```
Output:
```
((1 * sin(x)) + (x * (cos(x) * 1)))
```

### Evaluation

```bash
./sym_der --eval "x^2 + y" x=2i y=3
```
Output:
```
-1 + -2.0066230450673328094e-19i
```

### Partial Evaluation

```bash
./sym_der --eval "x^2 + y" x=2
```
Output:
```
(4 + 0i + y)
```

The output of the above commands might be a little verbose (this is a tradeoff I
accepted to simplify the implementation), but it is (apart from rounding errors
caused by floating point numbers representation limitations) mathematically
correct.

## Error handling

The solution also handles input errors, providing informative messages on what
has gone wrong. For instance:

```bash
./sym_der --eval "x^2 + y" x2   # Oops, forgot the '=' sign, intended to write "x=2"
```

Output:
```
Error: Declaration "x2" does not contain the '=' sign
```

## Architecture

The project uses OOP principles, specifically inheritance, to represent different types of mathematical expressions.

### Base Class

The `Expression` class (`lib/types/Expression.hpp`) serves as the abstract base class with three pure virtual methods:
- `differentiate(varName)` - computes the derivative with respect to a variable
- `toString()` - converts the expression to a string representation
- `evaluate(vars)` - evaluates the expression with given variable values

### Derived Classes

All mathematical types inherit from `Expression`:

**Constants:**
- `Constant` - numeric constants. Again, these can have complex values.

**Variables:**
- `Variable` - symbolic variables

**Operations:**
- `Add` - addition
- `Sub` - subtraction
- `Mul` - multiplication
- `Div` - division
- `Pow` - exponentiation

**Functions:**
- `Sin` - sine
- `Cos` - cosine
- `Exp` - exponential
- `Ln` - natural logarithm

Differentiation of complex functions requires to differentiate "subfunctions"
(the arguments of the outer function: `f'(g(x)) = f'(x) * g'(x)`). The situation
is similar for evaluation: to evaluate a function, one must evaluate its
arguments. This is where having methods like `differentiate` and `evaluate`
defined in a base class and overriden in subclasses becomes quite useful.

## Testing

If you have not done the configuration yet, run this line in the root of the
project:

```bash
cmake -S . -B build -G Ninja
```

Build and run the test suite:

```bash
cmake --build build --target test
```

The project uses a custom testing solution. See `lib/test/test_utils.hpp` for
details of its implementation and `lib/types/Ops/Add/test/tests.hpp` for example
usage.

## Tech Stack

- C++20
- CMake
