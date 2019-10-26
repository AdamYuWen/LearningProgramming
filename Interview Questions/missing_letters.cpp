// https://www.geeksforgeeks.org/missing-characters-make-string-pangram/
#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

string missingLetters(string input) {
	string res = "";
	set<char> s;
	for (char c = 'a'; c <= 'z'; ++c) {
		s.insert(c);
	}
	for (int i = 0; i < input.size(); ++i) {
		if (s.empty()) break;
		char charInStr = input[i];
		if (isupper(charInStr)) {
			charInStr = tolower(charInStr);
		}
		if (s.find(charInStr) != s.end()) {
			s.erase(charInStr);
		}
	}
	for (auto it = s.begin(); it != s.end(); ++it) {
		res += *it;
	}
	return res;
}

int main() {
	string test1 = "welcome to geeksforgeeks";
	string test2 = "The quick brown fox jumps";

	cout << missingLetters(test1) << endl;
	cout << missingLetters(test2) << endl;

	return 0;
}