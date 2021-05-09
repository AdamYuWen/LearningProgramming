#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;

int main() {
    fstream myFile;
    // out: write
    myFile.open("saldina.txt", ios::out);
    if (myFile.is_open()) {
        myFile << "First line.\n";
        myFile << "Second line.\n";
        myFile.close();
    }

    // app: append
    myFile.open("saldina.txt", ios::app);
    if (myFile.is_open()) {
        myFile << "Third line.\n";
        myFile.close();
    }

    // in: read
    myFile.open("saldina.txt", ios::in);
    if (myFile.is_open()) {
        string line;
        // getline is in the string libary.
        while (getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    }

    return 0;
}