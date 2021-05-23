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
    cout << endl;

    // ******************
    getline(cin, greeting);
    cout << greeting << endl;
    // cin.getline() tries to get numbers.
    cout << endl;

    // ******************
    greeting = "hello";
    cout << greeting << endl;
    greeting.insert(3, " "); // insert characters in front of index 3
    cout << greeting << endl;
    greeting.erase(3, 2); // erase 1 character from index 3
    cout << greeting << endl;
    greeting.erase(3); // erase everything from index 3 (include) to the end
    cout << greeting << endl;
    greeting.erase(greeting.length() - 1); // erase the last character
    cout << greeting << endl;
    greeting.pop_back(); // erase the last character
    cout << greeting << endl;
    cout << endl;

    // ******************
    greeting = "What the hell?";
    // find "hell" and return the index
    // from the index, replace the following 4 characters with "****"
    greeting.replace(greeting.find("hell"), 4, "****");
    cout << greeting << endl;

    greeting = "What is up?";
    // from index 5, get substr of 2 characters
    cout << greeting.substr(5, 2) << endl;

    cout << greeting.find_first_of("aeiou") << endl;
    if (greeting.find_first_of("!") == -1) // npos is -1, means not found
        cout << "NOT FOUND!" << endl;

    return 0;
}