#include <iostream>
using std::cout;
using std::endl;

struct Node {
    int value;
    Node* next;
};

// "**" is a pointer to a pointer
void InsertFront(Node** head, int value) {
    Node* new_ptr = new Node;
    new_ptr->value = value;
    new_ptr->next = *head; // "*"" is for dereferencing
    *head = new_ptr;
}

void PrintList(Node* node_ptr) {
    while (node_ptr != NULL) {
        cout << node_ptr->value << " ";
        node_ptr = node_ptr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    // pass by reference, which is passing the address or a pointer
    // pass an address of a pointer
    InsertFront(&head, -1);

    PrintList(head);

    delete head;
    delete second;
    delete third;
    head = NULL;
    second = NULL;
    third = NULL;

    return 0;
}