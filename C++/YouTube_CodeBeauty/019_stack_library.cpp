#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

void PrintStack(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
    cout << endl;
}

int main() {
    // Last in first out
    // 5 main functions: empty, size, push, pop, top
    stack<int> numbers_stack;
    numbers_stack.push(1);
    numbers_stack.push(2);
    numbers_stack.push(3);

    PrintStack(numbers_stack);

    numbers_stack.pop();

    PrintStack(numbers_stack);

    return 0;
}