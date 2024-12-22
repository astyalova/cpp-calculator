
#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template <class Number>

class Calculator {

public:

    void Set(Number n) {
        result_ = n;
    }

    Number GetNumber() const {
        return result_;
    }

    std::optional<Error> Add(Number n) {
        result_ +=n;
        return std::nullopt;
    }

    std::optional<Error> Sub(Number n) {
        result_ -=n;
        return std::nullopt;
    }

    constexpr std::optional<Error> Div(Number n) {
        if constexpr (std::is_integral_v<Number>) {
            if (n == 0) {
                return "Division by zero";
            }
        } if constexpr (std::is_same_v<Number, Rational>) {
            if (n == 0) {
                return "Division by zero";
            }
        }

        result_ /= n;
        return std::nullopt;
    }


    std::optional<Error> Mul(Number n) {
        result_ *=n;
        return std::nullopt;
    }

    constexpr std::optional<Error> Pow(Number n) {
        if (result_ == 0 && n == 0) {
            return "Zero power to zero";
        }

        if constexpr (std::is_integral_v<Number>) {
            if (n < 0) {
                return "Integer negative power";
            }
            result_ = IntegerPow(result_, n);
            return std::nullopt;

        } else if constexpr (std::is_same_v<Number, Rational>) {
            if (n.GetDenominator() != 1) {
                return "Fractional power is not supported";
            }
            result_ = ::Pow(result_, n);
            return std::nullopt;

        } else if constexpr (std::is_floating_point_v<Number>) {
            result_ = std::pow(result_, n);
            return std::nullopt;
        }
        return std::nullopt;
    }


    void Save() {
        memory_ = result_;
    }

    void Load() {
        if(memory_) {
            result_ = *memory_;
        }
    }

    bool GetHasMem() const {
        return memory_.has_value();
    }



private:

    Number result_ = 0;

    std::optional<Number> memory_;

};



