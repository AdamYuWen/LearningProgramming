#include <climits> // for MIN and MAX
#include <iostream>
using std::cout;
using std::endl;

int main() {
    /**
     * short
     * int
     * long
     * long long
     * unsigned short
     * unsigned int
     * unsigned long
     * unsigned long long
     */

    // sizeof is actually an operator, not a function
    cout << sizeof(short) << endl;     // 2
    cout << sizeof(int) << endl;       // 4
    cout << sizeof(long) << endl;      // 8
    cout << sizeof(long long) << endl; // 8

    cout << SHRT_MIN << endl;
    cout << SHRT_MAX << endl;
    cout << USHRT_MAX << endl;

    cout << INT_MIN << endl;
    cout << INT_MAX << endl;
    cout << UINT_MAX << endl;

    cout << LONG_MIN << endl;
    cout << LONG_MAX << endl;
    cout << ULONG_MAX << endl;

    cout << LLONG_MIN << endl;
    cout << LLONG_MAX << endl;
    cout << ULLONG_MAX << endl;

    return 0;
}