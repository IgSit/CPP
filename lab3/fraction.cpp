#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator can't be 0.");
    numerator_ = numerator;
    denominator_ = denominator;
}

int Fraction::numerator() const {
    return numerator_;
}

int Fraction::denominator() const {
    return denominator_;
}

void Fraction::setNumerator(int numerator) {
    numerator_ = numerator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator can't be 0.");
    denominator_ = denominator;
}

Fraction operator+(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    int numerator = fraction1.numerator() * fraction2.denominator() + fraction2.numerator() * fraction1.denominator();
    int denominator = fraction1.denominator() * fraction2.denominator();

    int gcd = std::gcd(numerator, denominator);

    numerator /= gcd;
    denominator /= gcd;

    result.setNumerator(numerator);
    result.setDenominator(denominator);
    return result;
}

Fraction operator*(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    int numerator = fraction1.numerator() * fraction2.numerator();
    int denominator = fraction1.denominator() * fraction2.denominator();

    int gcd = std::gcd(numerator, denominator);

    numerator /= gcd;
    denominator /= gcd;

    result.setNumerator(numerator);
    result.setDenominator(denominator);
    return result;
}
