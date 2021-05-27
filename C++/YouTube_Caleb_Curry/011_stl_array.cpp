#include <array> // STL array
#include <iostream>
using std::array;
using std::cout;
using std::endl;

/**
 * array ------------------- std::array ---------- std::vector
 * static size ------------- static size --------- dynamic size
 * not remember length ----- remember length ----- remember length
 * pass by pointer --------- pass by value ------- pass by value
 */

int main() {
    // C style array
    int normal_array[5] = {0, 1, 2, 3, 4};
    cout << normal_array[0] << endl;

    array<int, 5> std_array = {0, 1, 2, 3, 4};
    cout << std_array.size() << endl;

    // range based for loop
    for (int i : std_array) {
        cout << i << "  ";
    }
    cout << endl;

    return 0;
}