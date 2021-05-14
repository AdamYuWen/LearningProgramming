#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class MyIntStack {
  public:
    bool empty() {
        if (stack_.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    int size() { return stack_.size(); }

    void push(int value) { stack_.push_back(value); }

    void pop() { stack_.pop_back(); }

    int top() { return stack_.at(stack_.size() - 1); }

    void PrintStack(MyIntStack stack) {
        while (!stack.empty()) {
            cout << stack.top() << endl;
            stack.pop();
        }
        cout << endl;
    }

  private:
    vector<int> stack_;
};

int main() {
    MyIntStack numbers_stack;
    numbers_stack.push(1);
    numbers_stack.push(2);
    numbers_stack.push(3);

    numbers_stack.PrintStack(numbers_stack);

    numbers_stack.pop();

    numbers_stack.PrintStack(numbers_stack);

    return 0;
}