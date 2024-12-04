#include "calculator.h"

void Calculator::Set(Number n) {
    result_ = n;
}

Number Calculator::GetNumber() const {
    return result_;
}

void Calculator::Add(Number n) {
    result_ +=n;
}

void Calculator::Sub(Number n) {
    result_ -=n;
}

void Calculator::Div(Number n) {
    result_ /=n;
}

void Calculator::Mul(Number n) {
    result_ *=n;
}

void Calculator::Pow(Number n) {
    result_ = pow(result_, n);
}

void Calculator::Save() {
    remember_number_ = result_;
    is_save_ = true;
}

void Calculator::Load() {
    result_ = remember_number_;
}

bool Calculator::HasMem() const {
    if(is_save_) {
        return true;
    }
    return false;
}
