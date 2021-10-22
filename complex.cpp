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
    // set_real(real);
    // set_imaginary(imaginary);
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

// (a + bi) + (c + di) = (a + c) + (b + d)i
Complex Complex::operator+(const Complex &complex_num) const
{
    Complex result;
    result.set_real(this->get_real() + complex_num.get_real());
    result.set_imaginary(this->get_imaginary() + complex_num.get_imaginary());
    return result;
}

// (a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(const Complex &complex_num) const
{
    Complex result;
    result.set_real(this->get_real() - complex_num.get_real());
    result.set_imaginary(this->get_imaginary() - complex_num.get_imaginary());
    return result;
}

// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex &complex_num) const
{
    Complex result;
    Complex::NumType a, b, c, d;
    a = this->get_real();
    b = this->get_imaginary();
    c = complex_num.get_real();
    d = complex_num.get_imaginary();

    result.set_real(a * c - b * d);
    result.set_imaginary(a * d + b * c);

    return result;
}

// (a + bi) / (c + di) = (ac + bd)/(c^2 + d^2) + ((bc - ad)/(c^2 + d^2))i
Complex Complex::operator/(const Complex &complex_num) const
{
    Complex result;
    Complex::NumType a, b, c, d;
    a = this->get_real();
    b = this->get_imaginary();
    c = complex_num.get_real();
    d = complex_num.get_imaginary();

    if (IsValidDivisor(complex_num))
    {
        result.set_real((a * c + b * d) / (c * c + d * d));
        result.set_imaginary((b * c - a * d) / (c * c + d * d));
    }
    else
    {
        result.set_real(a);
        result.set_imaginary(b);
        std::cerr << "You cannot divide by zero \n";
    };

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
