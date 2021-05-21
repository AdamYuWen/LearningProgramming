#include <float.h>
#include <iostream>
using std::cout;
using std::endl;

int main() {
    float a;
    double b;
    long double c;

    a = (10.0 / 3) * 1E12; // "1E12" same as 1 * 10^12
    // "std::fixed" to show all digits, not scientific notation.
    cout << std::fixed << a << endl;
    cout << FLT_DIG << endl; // We can only trust 6 digits for float type.

    b = (10.0 / 3) * 1E12;
    cout << std::fixed << b << endl;
    cout << DBL_DIG << endl; // We can only trust 15 digits for double type.

    c = (10.0 / 3) * 1E12;
    cout << std::fixed << c << endl;
    cout << LDBL_DIG
         << endl; // We can only trust 18 digits for long double type.

    return 0;
}