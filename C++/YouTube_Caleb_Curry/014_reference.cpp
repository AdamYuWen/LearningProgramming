#include <iostream>
using std::cout;
using std::endl;

int main() {
    /**
     * Only for myself:
     *  - int* a; // pointer: * closes to the type
     *  - *a;     // dereference: * closes to the variable
     *  - int& b; // reference: & closes to the type
     *  - &b;     // address: & closes to the variable
     */

    int a = 5;
    int& b = a; // pass by reference, alias
    cout << "a is " << b << endl;

    // ! Cannot re-assign the local that the reference refers to
    int c = 100;
    // It does NOT refer b to c. It assign c to b, so the value of b was changed
    // to be the same as c.
    b = c;
    cout << "a is " << a << endl; // returns 100
    cout << "b is " << b << endl; // returns 100
    cout << "c is " << c << endl; // returns 100
    c = 20;
    // a and b are still the same, because b was not re-assigned.
    cout << "a is " << a << endl; // returns 100
    cout << "b is " << b << endl; // returns 100
    cout << "c is " << c << endl; // returns 20

    return 0;
}