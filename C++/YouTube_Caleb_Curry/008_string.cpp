#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string greeting;
    cin >> greeting; // cin only get the first word.
    cout << greeting << endl;

    // The next word is still in the stream.
    string left_over;
    cin >> left_over;
    cout << left_over << endl;
    // cin.clear() only clear the error flag.
    cin.ignore(); // ignore everything in the stream.

    // ******************
    getline(cin, greeting);
    cout << greeting << endl;
    // cin.getline() tries to get numbers.

    return 0;
}