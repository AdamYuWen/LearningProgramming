#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Enter the size of array: ";
    int size;
    cin >> size;

    // ! The following line doesn't work for some compilers.
    // ! Please don't use it.
    // int myArray[size];

    int* myArray = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "myArray[" << i << "] = ";
        cin >> myArray[i];
    }
    cout << "The input myArray is" << endl;
    for (int i = 0; i < size; i++) {
        cout << "myArray[" << i << "] = " << myArray[i] << endl;
    }

    delete[] myArray; // deallocate memory by using the pointer
    myArray = NULL;   // assign the pointer to NULL

    return 0;
}