#include <iostream>
#include "complex.h"

using namespace std;
int main()
{

    Complex c1, c2(1.2, 4.9), c3(2.2, 1.0), c4(-7.0, 9.6), c5(8.1, -4.3), c6(0.0, -7.1), c7(6.4), c8(0.0, 1.0), c9(0.0, 4.1), c10(0.0, -1.0), c11;

    // cout << "type two doubles for c11: ";
    // cin >> c11;

    cout << "Testing Ostream" << endl;
    cout << "===================================" << endl;
    cout << "c1 = " << c1 << endl;   //  expect 0
    cout << "c2 = " << c2 << endl;   //  expect 1.2 + 4.9i
    cout << "c3 = " << c3 << endl;   //  expect 2.2 + i
    cout << "c4 = " << c4 << endl;   //  expect -7 + 9.6i
    cout << "c5 = " << c5 << endl;   //  expect 8.1 - 4.3i
    cout << "c6 = " << c6 << endl;   //  expect -7.1i
    cout << "c7 = " << c7 << endl;   //  expect 6.4
    cout << "c8 = " << c8 << endl;   //  expect i
    cout << "c9 = " << c9 << endl;   //  expect 4.1i
    cout << "c10 = " << c10 << endl; //  expect -i
    cout << "c11 = " << c11 << endl; //  expect 0 or whatever user input
    cout << endl;

    cout << "Testing arithmatic operators" << endl;
    cout << "===================================" << endl;
    cout << "c1 + c2 + c3 = " << c1 + c2 + c3 << endl; //  expect 3.4 + 5.9i
    cout << "c2 + 1 = " << c2 + 1 << endl;             //  expect 2.2 + 4.9i
    cout << "c7 - c8 - c9 = " << c7 - c8 - c9 << endl; //  expect 6.4 - 5.1i
    cout << "c2 * 22 = " << c2 * 22 << endl;           //  expect 26.4 + 107.8i
    cout << "c2 * c3 = " << c2 * c3 << endl;           //  expect -2.26 + 11.98i
    cout << "c2 / c3 = " << c2 / c3 << endl;           //  expect 1.291 + 1.640i
    cout << "c2 / c1 = " << c2 / c1 << endl;           //  expect divide by zero error and return 1.2 + 4.9i
    cout << " c2 / c5 = " << c2 / c5 << endl;          //  expect -0.135 + 0.533i
    cout << endl;

    cout << "Testing comparison operators" << endl;
    cout << "===================================" << endl;
    cout << "c4 == c4 is " << ((c4 == c4) ? "true" : "false") << endl; //  expect true
    cout << "c4 != c4 is " << ((c4 != c4) ? "true" : "false") << endl; //  expect false
    cout << endl;

    cout << "Testing member functions" << endl;
    cout << "===================================" << endl;
    cout << "Conjugate of " << c5 << " is " << c5.Conjugate() << endl;     //  expect 8.1 + 4.3i
    cout << "Real of " << c3 << " is " << c3.get_real() << endl;           //  expect 2.2
    cout << "Imaginary of " << c4 << " is " << c4.get_imaginary() << endl; // expect 9.6
    cout << endl;

    cout << "Testing compound assignment operators" << endl;
    cout << "===================================" << endl;
    cout << "(c5 += c2) += c3 is " << ((c5 += c2) += c3) << endl; //  expect c5 = 11.5 + 1.6i
    cout << "(c5 -= c1) -= c2 is " << ((c5 -= c1) -= c2) << endl; //  expect c5 = 10.3 - 3.3i
    cout << "(c5 *= 22) *= 13 is " << ((c5 *= 22) *= 13) << endl; //  expect c5 = 2945.8 - 943.8i
    cout << "(c5 *= c4) *= c4 is " << ((c5 *= c4) *= c4) << endl; //  expect c5 = -253987.448 - 355181.112i
    cout << "(c3 /= 2) / c3 is " << ((c3 /= 2) / c3) << endl;     //    expect 1
    cout << "c4 is " << c4 << endl;                               //    expect -7 + 9.6i
    cout << "(c4 /= c1) / c1 is " << ((c4 /= c1) / c1) << endl;   //    expect divide by zero error and return -7 + 9.6i
    cout << "c4 is " << c4 << endl;                               //    expect -7 + 9.6i
    cout << endl;
}
