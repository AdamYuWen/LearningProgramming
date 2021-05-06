#include <iostream>
using namespace std;

int main() {
    int a = 20, b = 10;
    cout << "a = " << a << " and b = " << b << endl;

    // It is good to remember this method.
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a = " << a << " and b = " << b << endl;

    return 0;
}