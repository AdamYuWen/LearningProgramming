#include <iostream>
using namespace std;

int main() {
    float a, b;
    char operation;

    cout << "**Self Calculator**" << endl;
    cout << "Please type your equation:" << endl;
    cin >> a >> operation >> b;

    switch (operation) {
    case '+':
        cout << "a " << operation << " b = " << a + b << endl;
        break; // If here has no "break", it goes to the "-" as well.
    case '-':
        cout << "a " << operation << " b = " << a - b << endl;
        break;
    case '*':
        cout << "a " << operation << " b = " << a * b << endl;
        break;
    case '/':
        cout << "a " << operation << " b = " << a / b << endl;
        break;
    case '%':
        cout << "a " << operation << " b = " << (int)a % (int)b << endl;
        break;
    default:
        cout << "Not valid input" << endl;
        break;
    }

    return 0;
}