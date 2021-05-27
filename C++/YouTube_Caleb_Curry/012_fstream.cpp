#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::ofstream write_file;
    write_file.open("hello.txt");
    vector<string> write_names;
    write_names.push_back("Caleb");
    write_names.push_back("Amy");
    write_names.push_back("Susan");

    for (string name : write_names) {
        write_file << name << endl;
    }

    write_file.close();

    std::ifstream read_file("hello.txt");
    vector<string> read_names;
    string input; // read each word
    // char temp = read_file.get(); // read each character
    // getline(read_file, line);    // read each line
    while (read_file >> input) {
        read_names.push_back(input);
    }

    for (string name : read_names) {
        cout << name << endl;
    }

    read_file.close();

    return 0;
}