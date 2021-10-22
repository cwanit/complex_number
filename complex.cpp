#include "complex.h"

// Constructor
/**
 * @brief Construct a new Complex:: Complex object
 *
 * @param real
 * @param imaginary
 */
Complex::Complex(NumType real, NumType imaginary) : real_(real), imaginary_(imaginary)
{
}

// Accessors
Complex::NumType Complex::get_real() const
{
    return this->real_;
}

Complex::NumType Complex::get_imaginary() const
{
    return this->imaginary_;
}

// Mutator
bool Complex::set_real(const NumType real)
{
    this->real_ = real;
    return true;
}

bool Complex::set_imaginary(const NumType imaginary)
{
    this->imaginary_ = imaginary;
    return true;
}

Complex Complex::Conjugate() const
{
    Complex result;
    result.set_real(this->get_real());
    result.set_imaginary(this->get_imaginary() * -1);
    return result;
}

// Arithmatic Operation

Complex Complex::operator+(const Complex &complex_num) const
{
    Complex result = *this; //  make a copy of myself
    result += complex_num;  //  use += to add to the copy
    return result;
}

Complex Complex::operator-(const Complex &complex_num) const
{
    Complex result = *this; //  make a copy of myself
    result -= complex_num;  //  use -= to subtract from the copy
    return result;
}

Complex Complex::operator*(const Complex &complex_num) const
{
    Complex result = *this; //  make a copy of myself
    result *= complex_num;  //  use *= to multiply the copy by
    return result;
}

// (a + bi) / (c + di) = (ac + bd)/(c^2 + d^2) + ((bc - ad)/(c^2 + d^2))i
Complex Complex::operator/(const Complex &complex_num) const
{
    Complex result = *this; // make a copy of myself
    result /= complex_num;  // use /= to divide the copy by
    return result;
}

// Comparison operators
bool Complex::operator==(const Complex &complex_num) const
{
    return this->get_real() == complex_num.get_real() && this->get_imaginary() == complex_num.get_imaginary();
}

bool Complex::operator!=(const Complex &complex_num) const
{
    return !(*this == complex_num);
}

// Compound Assignment Operators
// (a + bi) + (c + di) = (a + c) + (b + d)i
Complex &Complex::operator+=(const Complex &complex_num)
{
    this->set_real(this->get_real() + complex_num.get_real());
    this->set_imaginary(this->get_imaginary() + complex_num.get_imaginary());
    return *this;
}

// (a + bi) - (c + di) = (a - c) + (b - d)i
Complex &Complex::operator-=(const Complex &complex_num)
{
    this->set_real(this->get_real() - complex_num.get_real());
    this->set_imaginary(this->get_imaginary() - complex_num.get_imaginary());
    return *this;
}

// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex &Complex::operator*=(const Complex &complex_num)
{
    Complex::NumType a, b, c, d;
    a = this->get_real();
    b = this->get_imaginary();
    c = complex_num.get_real();
    d = complex_num.get_imaginary();

    this->set_real(a * c - b * d);
    this->set_imaginary(a * d + b * c);

    return *this;
}

// (a + bi) / (c + di) = (ac + bd)/(c^2 + d^2) + ((bc - ad)/(c^2 + d^2))i
Complex &Complex::operator/=(const Complex &complex_num)
{
    Complex::NumType a, b, c, d;
    a = this->get_real();
    b = this->get_imaginary();
    c = complex_num.get_real();
    d = complex_num.get_imaginary();

    if (IsValidDivisor(complex_num))
    {
        this->set_real((a * c + b * d) / (c * c + d * d));
        this->set_imaginary((b * c - a * d) / (c * c + d * d));
    }
    else
    {
        // this->set_real(a);
        // this->set_imaginary(b);
        std::cerr << "You cannot divide by zero \n";
    };
    return *this;
}

// Checking if divisor is valid
bool Complex::IsValidDivisor(const Complex &complex_num) const
{
    return !(complex_num.get_real() == 0 && complex_num.get_imaginary() == 0);
}

// I/Ostream operation
std::ostream &
operator<<(std::ostream &output, const Complex &complex_num)
{

    // 0 +/- 0i => 0
    // 0 +/- i  => +/-i
    // 0 +/- #i => +/-#i

    // # +/- 0i => #
    // # +/- i  => # +/- i
    // # +/- #i => # +/- #i

    if (complex_num.get_real() == 0)
    {
        if (complex_num.get_imaginary() == 0) // if both are zero 0 + 0i then show 0
        {
            std::cout << 0;
        }
        else if (complex_num.get_imaginary() == 1 || complex_num.get_imaginary() == -1) // 0 + i and 0 - i
        {
            std::cout << (complex_num.get_imaginary() == 1 ? "i" : "-i");
        }
        else
        {
            std::cout << complex_num.get_imaginary() << "i"; // 0 + #i print #i
        };
    }
    else
    {
        if (complex_num.get_imaginary() == 0) // # +/- 0i => #
        {
            std::cout << complex_num.get_real();
        }
        else if (complex_num.get_imaginary() == 1 || complex_num.get_imaginary() == -1) // # +/- i  => # +/- i
        {
            std::cout << complex_num.get_real()
                      << (complex_num.get_imaginary() > 0 ? "+" : "")
                      << (complex_num.get_imaginary() == 1 ? "i" : "-i");
        }
        else // # +/- #i => # +/- #i
        {
            std::cout << complex_num.get_real()
                      << (complex_num.get_imaginary() > 0 ? "+" : "")
                      << complex_num.get_imaginary()
                      << "i";
        };
    };

    return output;
}
