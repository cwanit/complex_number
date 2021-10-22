// ------------------------------------------------ complex.h ---------------------------------------------------------

// Luke Wanitthananon CSS 501 A

// Creation Date: October 18, 2021

// Date of Last Modification: October 21, 2021

// --------------------------------------------------------------------------------------------------------------------

// Purpose

// Complex object holds one complex number. Complex is capable of basic arithmetic operations.

// --------------------------------------------------------------------------------------------------------------------

// Implementation and assumptions

//  --  Only rectangular form is implemented. Assume polar and exponential form are not required
//  --  Complexes are stored as NumType real and imaginary
//  --  NumType is defined as double in this implementation
//  --  Divide by zero returns itself

// --------------------------------------------------------------------------------------------------------------------

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
    // overloaded operator<<: prints using the following rules:
    //  -- Condition 1  if complex is   0 +/- 0i    prints  0
    //  -- Condition 2  if complex is   0 +/- i     prints  +/-i
    //  -- Condition 3  if complex is   0 +/- #i    prints  +/-#i
    //  -- Condition 4  if complex is   # +/- 0i    prints  #
    //  -- Condition 5  if complex is   # +/- i     prints  # +/- i
    //  -- Condition 6  if complex is   # +/- #i    prints  # +/- #i
    friend std::ostream &operator<<(std::ostream &output, const Complex &complex_num);

    // overloaded operator>>:   take 2 NumType as real and imaginary. Check for valid input to only
    //                          accepts numbers. Standard casting between numeric types occurs.
    friend std::istream &operator>>(std::istream &input, Complex &complex_num);

public:
    typedef double NumType;
    // Constructors
    Complex(NumType real = 0.0, NumType imaginary = 0.0); // Default constructor

    // Accessors
    NumType getReal() const;
    NumType getImaginary() const;

    // Mutators
    bool setReal(const NumType real);
    bool setImaginary(const NumType imaginary);

    // Arithmetic Operators
    Complex operator+(const Complex &complex_num) const; //  add 2 Complexes
    Complex operator-(const Complex &complex_num) const; //  subtract 2 Complexes
    Complex operator*(const Complex &complex_num) const; //  multiple 2 Complexes
    Complex operator/(const Complex &complex_num) const; //  divide 2 Complexes

    // Conjugate
    Complex conjugate() const; // create a conjugate of current onject

    // Comparison operators
    bool operator==(const Complex &complex_num) const; // is object == parameter?
    bool operator!=(const Complex &complex_num) const; // is object != parameter?

    // Compound Assignment Operators
    Complex &operator+=(const Complex &complex_num); // current object += parameter
    Complex &operator-=(const Complex &complex_num); // current object -= parameter
    Complex &operator*=(const Complex &complex_num); // current object *= parameter
    Complex &operator/=(const Complex &complex_num); // current object /= parameter

private:
    NumType real_;                                         // real part of a complex number
    NumType imaginary_;                                    // imaginary part of a complex number
    bool IsValidDivisor(const Complex &complex_num) const; // function to test for non-zero divisor
};

#endif