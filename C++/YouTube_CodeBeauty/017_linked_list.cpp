#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Node {
    int value_;
    Node* next_;
};

class LinkedList {
  public:
    LinkedList() {
        // cout << "default constructor" << endl;
        head_ = NULL;
    }

    ~LinkedList() {
        // cout << "deconstructor" << endl;
        while (head_ != NULL) {
            Node* curr = head_;
            head_ = head_->next_;
            delete curr;
            curr = NULL;
        }
    }

    void Insert(int value) {
        // Create a new Node
        Node* new_ptr = new Node;
        new_ptr->value_ = value;
        new_ptr->next_ = NULL;

        // If the list is empty, set the Node to head.
        // If the list is not empty, add the Node to the end.
        if (head_ == NULL) {
            head_ = new_ptr;
        } else {
            Node* curr = head_;
            // It is curr->next_, which make sure the pointer points to a value.
            while (curr->next_ != NULL) {
                curr = curr->next_;
            }
            curr->next_ = new_ptr;
        }
    }

    void Display() {
        cout << "The LinkedList is " << endl;
        Node* curr = head_;
        // It is curr, which we cannot return a value.
        while (curr != NULL) {
            cout << curr->value_ << "->";
            curr = curr->next_;
        }
        cout << "NULL" << endl;
    }

  private:
    Node* head_;
};

int main() {
    LinkedList ll;

    cout << "Please enter a value: ";
    int val;
    while (cin >> val) {
        ll.Insert(val);
        cout << "Please enter a value: ";
    }
    ll.Display();

    return 0;
}