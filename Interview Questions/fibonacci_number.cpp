/**
 * C++ Interview Question Preparation
 * Fibonacci Numbers
 * Description: There are 4 implementations for calculating Fibonacci numbers.
 * Time Complexity: T(n + 1) / T(n) =~ (sqrt(5) + 1) / 2
 * Author: Adam Yu Wen
 * Date: October 15, 2019
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Interation and stores all values.
// Time Complexity: O(n)
// Space Complexity: O(n)
long fib_interation_all_memory(int n) {
	vector<long> res;
	for (unsigned int i = 0; i < n + 1; ++i) {
		if (i == 0) {
			res.push_back(0);
		}
		else if (i == 1) {
			res.push_back(1);
		}
		else {
			res.push_back(res[i - 1] + res[i - 2]);
		}
	}
	return res[n];
}

// Interation and only save three values.
// Time Complexity: O(n)
// Space Complexity: O(1)
long fib_interation_two_memory(int n) {
	long first = 0, second = 1;
	if (n == 0)
		return first;
	for (unsigned int i = 2; i < n + 1; ++i) {
		long next = first + second;
		first = second;
		second = next;
	}
	return second;
}

// Recursion
// Time comlexity: O(2^n)
// Space Complexity: O(n)
long fib_recursion(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fib_recursion(n - 1) + fib_recursion(n - 2);
	}
}

// Recursion and stores all values.
// Time Complexity: O(n)
// Space Complexity: O(n)
long fib_recursion_memorization(int n) {
	static map<int, long> allFib;
	allFib[0] = 0;
	allFib[1] = 1;
	auto found = allFib.find(n);
	if (found != allFib.end()) {
		return found->second;
	}
	else {
		long res = fib_recursion_memorization(n - 1) + fib_recursion_memorization(n - 2);
		allFib[n] = res;
		return res;
	}
}

int main() {
	cout << fib_interation_all_memory(40) << endl;
	cout << fib_interation_two_memory(40) << endl;
	cout << fib_recursion(40) << endl;
	cout << fib_recursion_memorization(40) << endl;

	return 0;
}