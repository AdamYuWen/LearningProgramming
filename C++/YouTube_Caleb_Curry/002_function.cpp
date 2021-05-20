#include <iostream>
using std::cout;
using std::endl;

// functions => parameters
void print(int a, int b) { // a and b are parameters
    cout << a << ", " << b << endl;
}

int main() {
    // call the function, arguments
    print(3, 4); // 3 and 4 are arguments

    return 0;
}