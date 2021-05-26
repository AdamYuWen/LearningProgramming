#include <iostream>
using std::cout;
using std::endl;

void Print_Wrongly(int array[]) {
    // It returns the size of the pointer, which is 8 bytes.
    cout << sizeof(array) << endl; // returns 8
}

void Print(int array[], int size) { cout << size << endl; }

int main() {
    int guesses[] = {2, 43, 23, 43, 23};

    // ! array doesn't know the size, not like vector
    // cout << guesses.size() << endl; // NOT work

    // ! Doesn't work with functions
    // When we pass an array to a function, it passes a pointer not array.
    int size = sizeof(guesses) / sizeof(guesses[0]);
    cout << size << endl;

    Print_Wrongly(guesses);
    Print(guesses, 5);

    return 0;
}