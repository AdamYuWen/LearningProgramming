#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

void PrintQueue(queue<int> queue) {
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
}

int main() {
    // First in first out
    // 6 main function: empty, size, push, front, back, pop
    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    cout << "Size is " << my_queue.size() << endl;
    cout << "Front is " << my_queue.front() << endl;
    cout << "Back is " << my_queue.back() << endl;

    cout << "My queue is " << endl;
    PrintQueue(my_queue);

    return 0;
}