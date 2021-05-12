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

    void InsertFront(int value) {
        Node* new_ptr = new Node;
        new_ptr->value_ = value;
        new_ptr->next_ = head_;
        head_ = new_ptr;
    }

    // If the target doesn't exist, insert to the end.
    void InsertAfter(int value, int target) {
        Node* curr = head_;
        if (curr != NULL) { // if the list is not empty
            while (curr != NULL) {
                if (curr->value_ == target) { // find the target
                    Node* new_ptr = new Node;
                    new_ptr->value_ = value;
                    new_ptr->next_ = curr->next_;
                    curr->next_ = new_ptr;
                    return;
                }
                curr = curr->next_;
            }
            // Didn't find the target.
            InsertEnd(value);
        } else { // if the list is empty
            InsertFront(value);
        }
    }

    void InsertEnd(int value) {
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

    ll.InsertEnd(1);
    ll.InsertEnd(2);
    ll.InsertEnd(3);
    ll.InsertEnd(4);
    ll.InsertFront(5);
    ll.InsertAfter(6, 5);

    ll.Display();

    return 0;
}