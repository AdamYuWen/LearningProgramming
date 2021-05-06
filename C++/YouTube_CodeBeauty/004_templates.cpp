#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5, b = 7;
    Swap(a, b);  // Swap<int>(a, b) also works.
    // 1st: The program tells the type based on inputs.
    // 2nd: The user let the program know the type.
    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;
}