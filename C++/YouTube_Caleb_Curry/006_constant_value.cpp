#include <iostream>
using std::cout;
using std::endl;

// It is used in C.
#define X 10 // Usually, upper case

int main() {
    const int k_x = 5; // Add a k at the beginning of the variable

    enum { y = 100 };

    cout << "X = " << X << endl;
    cout << "k_x = " << k_x << endl;
    cout << "y = " << y << endl;

    return 0;
}