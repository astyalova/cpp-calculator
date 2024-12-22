#pragma once
#include <istream>
#include <cstdint>
#include <numeric>

class Rational {
public:
    Rational() {}
    Rational(int numerator) : numerator_(numerator) {
        Reduction();
    }
    Rational(int numerator, int denominator) :numerator_(numerator), denominator_(denominator) {
        Reduction();
    }
    Rational(const Rational& other) : numerator_(other.numerator_), denominator_(other.denominator_) {
        Reduction();
    }

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

    Rational Inv() const {
        return Rational(denominator_, numerator_);
    }

    Rational operator +(const Rational& r) const {
        int n = numerator_* r.denominator_ + r.numerator_*denominator_;
        int d = denominator_ * r.denominator_;
        return Rational(n, d);
    }

    Rational operator -(const Rational& r) const {
        Rational res;
        int n  = numerator_* r.denominator_ - r.numerator_*denominator_;
        int d = denominator_ * r.denominator_;
        return Rational(n, d);
    }

    Rational operator *(const Rational& r) const {
        int n  = numerator_ * r.numerator_;
        int d = denominator_ * r.denominator_;
        return Rational(n, d);
    }

    Rational operator /(const Rational& r)  const {
        int n  = numerator_ * r.denominator_;
        int d = denominator_ * r.numerator_;
        return Rational(n, d);
    }

    Rational& operator +=(const Rational& r) {
        numerator_ = numerator_* r.denominator_ + r.numerator_*denominator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator -=(const Rational& r) {
        numerator_ = numerator_* r.denominator_ - r.numerator_*denominator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator *=(const Rational& r) {
        numerator_ = numerator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator /=(const Rational& r) {
        numerator_ = numerator_ * r.denominator_;
        denominator_ = denominator_ * r.numerator_;
        Reduction();
        return *this;
    }

    Rational& operator=(const Rational& other) {
        if (this != &other) {
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;
        }
        return *this;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        return Rational(-numerator_, denominator_);
    }

    friend std::istream& operator >>(std::istream& is, Rational& r);
    friend std::ostream& operator <<(std::ostream& os, const Rational& r);

private:
    int numerator_ = 0;
    int denominator_ = 1;

    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }
};

inline std::istream& operator >>(std::istream& is, Rational& r) {
    int a, b = 1;
    char ch;
    is >> a;

    if(!(is >> ch)) {
        r.numerator_ = a;
        r.denominator_ = b;
        return is;
    }
    if(ch != '/') {
        is.unget();
        r.numerator_ = a;
        r.denominator_ = b;
        return is;
    }

    if((!(is >> b)) || b == 0) {
        is.setstate(std::ios::failbit);
        return is;
    }

    r.numerator_ = a;
    r.denominator_ = b;
    return is;
}

inline std::ostream& operator <<(std::ostream& os, const Rational& r) {
    if(r.denominator_ == 1) {
        os << r.numerator_;
    } else {
        os << r.numerator_ << " " << "/" << " " << r.denominator_;
    }
    return os;
}

inline auto operator <=>(Rational rhs, Rational lhs) {
    std::int64_t a = static_cast <std::int64_t>(rhs.GetNumerator())*lhs.GetDenominator();
    std::int64_t b = static_cast <int64_t>(lhs.GetNumerator())*rhs.GetDenominator();
    return a <=> b;
}

inline auto operator ==(Rational rhs, Rational lhs) {
    std::int64_t a = static_cast <std::int64_t>(rhs.GetNumerator())*lhs.GetDenominator();
    std::int64_t b = static_cast <int64_t>(lhs.GetNumerator())*rhs.GetDenominator();
    return a==b;
}
