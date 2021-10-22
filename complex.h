#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
    typedef double NumType;

    friend std::ostream &operator<<(std::ostream &output, const Complex &complex_num);
    friend std::istream &operator>>(std::istream &input, const Complex &complex_num);

public:
    // Constructors
    Complex(NumType real = 0.0, NumType imaginary = 0.0); // Default constructor

    // Accessors
    NumType get_real() const;
    NumType get_imaginary() const;

    // Mutator
    bool set_real(const NumType real);
    bool set_imaginary(const NumType imaginary);

    // Math Operators
    Complex operator+(const Complex &complex_num) const;
    Complex operator-(const Complex &complex_num) const;
    Complex operator*(const Complex &complex_num) const;
    Complex operator/(const Complex &complex_num) const;

    // Conjugate
    Complex Conjugate() const;

    // Comparison
    bool operator==(const Complex &complex_num) const;
    bool operator!=(const Complex &complex_num) const;

    // Compound Assignment Operators
    Complex &operator+=(const Complex &complex_num);
    Complex &operator-=(const Complex &complex_num);
    Complex &operator*=(const Complex &complex_num);
    Complex &operator/=(const Complex &complex_num);

private:
    NumType real_;
    NumType imaginary_;
    bool IsValidDivisor(const Complex &complex_num) const;
};

#endif