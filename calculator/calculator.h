#pragma once

#include <string>
#include <cmath>

using Number = double;

class Calculator {
public:
    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);

private:
    Number result_ = 0.0;
};

enum class operations {
    NO_OPERATION,
    MULTIPLICATION,
    DIVISION,
    SUBTRACTION,
    ADDITION,
    POWER,
};

