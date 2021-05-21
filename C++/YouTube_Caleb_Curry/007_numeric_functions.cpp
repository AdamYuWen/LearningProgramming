#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

int main() {
    cout << sqrt(25) << endl;
    cout << endl;

    cout << remainder(10, 3.25) << endl; // remainder works with float.
    cout << 10 % 3 << endl;         // Modulus only works with integer operands.
    cout << fmod(10, 3.25) << endl; // simliar to remainder
    cout << endl;

    cout << fmax(10, 3.25) << endl; // max
    cout << fmin(10, 3.25) << endl; // min
    cout << endl;

    cout << ceil(-1.5) << endl;  // returns -1, always go up
    cout << floor(-1.5) << endl; // returns -2, always go down
    cout << trunc(-1.5) << endl; // returns -1, moves close to 0
    cout << endl;

    cout << round(2.49) << endl;
    cout << endl;

    cout << sqrt(-25) << endl; // return nan
    cout << NAN << endl;
    cout << INFINITY << endl;
    cout << -INFINITY << endl;

    return 0;
}