#include <iomanip> // for iomanip setw function
#include <iostream>
using namespace std;

int main() {
    int height, width;
    char symbol;
    cout << "Enter the height: ";
    cin >> height;
    cout << "Enter the width: ";
    cin >> width;
    cout << "Enter the symbol: ";
    cin >> symbol;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << setw(3) << symbol;
        }
        cout << endl;
    }

    return 0;
}