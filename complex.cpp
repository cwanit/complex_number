// ------------------------------------------------ complex.cpp ------------------------------------------------------

// Luke Wanitthananon CSS 501 A

// Creation Date: October 18, 2021

// Date of Last Modification: October 21, 2021

// --------------------------------------------------------------------------------------------------------------------

#include "complex.h"

// ------------------------------------ Complex -----------------------------------------------

// Description

// Complex: a default constructor for Complex with default value of zero
// preconditions: real and imaginary are double
// postconditions: a Complex object is created

// --------------------------------------------------------------------------------------------
Complex::Complex(NumType real, NumType imaginary) : real_(real), imaginary_(imaginary)
{
}

// Accessors

// ------------------------------------ getReal -----------------------------------------------

// Description

// getReal:     An accessor for real part of current Complex.
//              Method returns real part as NumType

// --------------------------------------------------------------------------------------------
Complex::NumType Complex::getReal() const
{
    return this->real_;
}

// ------------------------------------ getImaginary -------------------------------------------

// Description

// getImaginary:    An accessor for imaginary part of current Complex.
//                  Method returns imaginary part as NumType

// --------------------------------------------------------------------------------------------
Complex::NumType Complex::getImaginary() const
{
    return this->imaginary_;
}

// Mutator

// ------------------------------------ setReal ----------------------------------------------

// Description

// setReal: a method to set the real part of current Complex
// preconditions: parameter real is NumType
// postconditions: Complex real field of current object is set to parameter real

// --------------------------------------------------------------------------------------------
bool Complex::setReal(const NumType real)
{
    this->real_ = real;
    return true;
}

// ------------------------------------ setReal ----------------------------------------------

// Description

// setReal: a method to set the imaginary part of current Complex
// preconditions: parameter imaginary is NumType
// postconditions: Complex imaginary field of current object is set to parameter imaginary

// --------------------------------------------------------------------------------------------
bool Complex::setImaginary(const NumType imaginary)
{
    this->imaginary_ = imaginary;
    return true;
}

// ------------------------------------ conjugate ----------------------------------------------

// Description

// conjugate:   a method to return conjugate of current Complex as a new Complex.
//              A conjugate of (a + bi) is (a - bi)

// --------------------------------------------------------------------------------------------
Complex Complex::conjugate() const
{
    Complex result;
    result.setReal(this->getReal());
    result.setImaginary(this->getImaginary() * -1);
    return result;
}

// Arithmatic Operation

// ------------------------------------ operator+ ----------------------------------------------

// Description

// overloaded operator+: Addition of Complex,
//                       current object + parameter.
//                       Method returns new Complex as result of addition

// --------------------------------------------------------------------------------------------
Complex Complex::operator+(const Complex &complex_num) const
{
    Complex result = *this; //  make a copy of myself
    result += complex_num;  //  use += to add to the copy
    return result;
}

// ------------------------------------ operator- ----------------------------------------------

// Description

// overloaded operator-: Subtraction of Complex,
//                       current object - parameter.
//                       Method returns new Complex as result of subtraction

// --------------------------------------------------------------------------------------------
Complex Complex::operator-(const Complex &complex_num) const
{
    Complex result = *this; //  make a copy of myself
    result -= complex_num;  //  use -= to subtract from the copy
    return result;
}

// ------------------------------------ operator* ----------------------------------------------

// Description

// overloaded operator*: Multiplication of Complex,
//                       current object * parameter.
//                       Method returns new Complex as result of multiplication

// --------------------------------------------------------------------------------------------
Complex Complex::operator*(const Complex &complex_num) const
{
    Complex result = *this; //  make a copy of myself
    result *= complex_num;  //  use *= to multiply the copy by
    return result;
}

// ------------------------------------ operator/ ----------------------------------------------

// Description

// overloaded operator/: Division of Complex,
//                       current object / parameter.
//                       Method returns new Complex as result of division

// --------------------------------------------------------------------------------------------
Complex Complex::operator/(const Complex &complex_num) const
{
    Complex result = *this; // make a copy of myself
    result /= complex_num;  // use /= to divide the copy by
    return result;
}

// Comparison operators

// ------------------------------------ operator== --------------------------------------------

// Description

// overloaded operator==: true if current object == parameter, otherwise false.

// --------------------------------------------------------------------------------------------
bool Complex::operator==(const Complex &complex_num) const
{
    return this->getReal() == complex_num.getReal() && this->getImaginary() == complex_num.getImaginary();
}

// ------------------------------------ operator!= --------------------------------------------

// Description

// overloaded operator!=: true if current object != parameter, otherwise false.

// --------------------------------------------------------------------------------------------
bool Complex::operator!=(const Complex &complex_num) const
{
    return !(*this == complex_num);
}

// Compound Assignment Operators

// ------------------------------------ operator+= --------------------------------------------

// Description

// overloaded operator+=: current object = current object + parameter. Addition is defined as
//                        (a + bi) + (c + di) = (a + c) + (b + d)i

// --------------------------------------------------------------------------------------------
Complex &Complex::operator+=(const Complex &complex_num)
{
    this->setReal(this->getReal() + complex_num.getReal());
    this->setImaginary(this->getImaginary() + complex_num.getImaginary());
    return *this;
}

// ------------------------------------ operator-= --------------------------------------------

// Description

// overloaded operator-=: current object = current object - parameter. Subtraction is defined as
//                        (a + bi) - (c + di) = (a - c) + (b - d)i

// --------------------------------------------------------------------------------------------
Complex &Complex::operator-=(const Complex &complex_num)
{
    this->setReal(this->getReal() - complex_num.getReal());
    this->setImaginary(this->getImaginary() - complex_num.getImaginary());
    return *this;
}

// ------------------------------------ operator*= --------------------------------------------

// Description

// overloaded operator*=: current object = current object * parameter. Multiplication is defined as
//                        (a + bi) * (c + di) = (ac - bd) + (ad + bc)i

// --------------------------------------------------------------------------------------------
Complex &Complex::operator*=(const Complex &complex_num)
{
    Complex::NumType a, b, c, d;
    a = this->getReal();
    b = this->getImaginary();
    c = complex_num.getReal();
    d = complex_num.getImaginary();

    this->setReal(a * c - b * d);
    this->setImaginary(a * d + b * c);

    return *this;
}

// ------------------------------------ operator/= --------------------------------------------

// Description

// overloaded operator/=: current object = current object / parameter. Division is defined as
//                        (a + bi) / (c + di) = (ac + bd)/(c^2 + d^2) + ((bc - ad)/(c^2 + d^2))i

// --------------------------------------------------------------------------------------------
Complex &Complex::operator/=(const Complex &complex_num)
{
    Complex::NumType a, b, c, d;
    a = this->getReal();
    b = this->getImaginary();
    c = complex_num.getReal();
    d = complex_num.getImaginary();

    if (IsValidDivisor(complex_num))
    {
        this->setReal((a * c + b * d) / (c * c + d * d));
        this->setImaginary((b * c - a * d) / (c * c + d * d));
    }
    else
    {
        std::cerr << "\nERROR: You cannot divide by zero!\n";
    };
    return *this;
}

// ------------------------------------ IsValidDivisor ----------------------------------------

// Description

// IsValidDivisor:  a function to check if divisor a Complex is valid to be used as disisor
//                  return false Complex is zero

// --------------------------------------------------------------------------------------------
bool Complex::IsValidDivisor(const Complex &complex_num) const
{
    return !(complex_num.getReal() == 0 && complex_num.getImaginary() == 0);
}

// I/Ostream operation

// ------------------------------------ operator<< --------------------------------------------

// Description

// overloaded operator<<: prints using the following rules:
//  -- Condition 1  if complex is   0 +/- 0i    prints  0
//  -- Condition 2  if complex is   0 +/- i     prints  +/-i
//  -- Condition 3  if complex is   0 +/- #i    prints  +/-#i
//  -- Condition 4  if complex is   # +/- 0i    prints  #
//  -- Condition 5  if complex is   # +/- i     prints  # +/- i
//  -- Condition 6  if complex is   # +/- #i    prints  # +/- #i

// --------------------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &output, const Complex &complex_num)
{
    if (complex_num.getReal() == 0)
    {
        if (complex_num.getImaginary() == 0) // condition 1
        {
            std::cout << 0;
        }
        else if (complex_num.getImaginary() == 1 || complex_num.getImaginary() == -1) // condition 2
        {
            std::cout << (complex_num.getImaginary() == 1 ? "i" : "-i");
        }
        else // condition 3
        {
            std::cout << complex_num.getImaginary() << "i";
        };
    }
    else
    {
        if (complex_num.getImaginary() == 0) // condition 4
        {
            std::cout << complex_num.getReal();
        }
        else if (complex_num.getImaginary() == 1 || complex_num.getImaginary() == -1) // condition 5
        {
            std::cout << complex_num.getReal()
                      << (complex_num.getImaginary() > 0 ? "+" : "")
                      << (complex_num.getImaginary() == 1 ? "i" : "-i");
        }
        else // condition 6
        {
            std::cout << complex_num.getReal()
                      << (complex_num.getImaginary() > 0 ? "+" : "")
                      << complex_num.getImaginary()
                      << "i";
        };
    };

    return output;
}

// ------------------------------------ operator>> --------------------------------------------

// Description

// overloaded operator>>:   take 2 NumType as real and imaginary. Check for valid input to only
//                          accepts numbers. Standard casting between numeric types occurs.

// --------------------------------------------------------------------------------------------
std::istream &operator>>(std::istream &input, Complex &complex_num)
{
    Complex::NumType real, imaginary;

    while (!(input >> real)) // check validity of real input
    {
        std::cout << "Your input is invalid.\nPlease enter the real part of your complex number: ";
        input.clear();
        input.ignore(1000, '\n');
    }

    while (!(input >> imaginary)) // check validity of imaginary input
    {
        std::cout << "Your input is invalid.\nPlease enter the imginary part of your complex number without the \"i\": ";
        input.clear();
        input.ignore(1000, '\n');
    }

    complex_num.setReal(real);
    complex_num.setImaginary(imaginary);

    return input;
}