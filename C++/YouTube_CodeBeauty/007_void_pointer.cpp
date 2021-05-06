#include <iostream>
using std::cout;
using std::endl;

void PrintInter(int* numberPtr) { cout << *numberPtr << endl; }

void PrintChars(char* charPtr) { cout << *charPtr << endl; }

// void pointer
// It is not recommended, because it is hard for compilers to find the error.
// Advantage: Don't need to have multiple pointer functions.
// Disadvantage: Cannot dereference directly. Have to pass a type parameter.
void Print(void* ptr, char type) {
    switch (type) {
    case 'i':
        cout << *((int*)ptr) << endl;
        break;
    case 'c':
        cout << *((char*)ptr) << endl;
        break;
    }
}

int main() {
    int number = 4;
    char character = 'a';

    // PrintInter(&number);
    // PrintChars(&character);
    Print(&number, 'i');
    Print(&character, 'c');

    return 0;
}