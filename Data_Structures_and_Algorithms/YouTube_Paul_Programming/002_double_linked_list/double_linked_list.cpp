#include "double_linked_list.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() { head = tail = nullptr; }

DoubleLinkedList::DoubleLinkedList(int value) {
    node* curr = new node();
    curr->data = value;
    head = tail = curr;
    curr = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {
    node* curr = head;
    while (curr != nullptr) {
        head = curr->next;
        delete curr;
        curr = curr->next;
    }
    head = tail = curr = nullptr;
}

void DoubleLinkedList::AddBeginNode(int value) {
    node* curr = new node();
    curr->data = value;
    if (tail == nullptr) {
        head = tail = curr;
    } else {
        head->prev = curr;
        curr->next = head;
        head = curr;
    }
    curr = nullptr;
}

void DoubleLinkedList::AddEndNode(int value) {
    node* curr = new node();
    curr->data = value;
    if (head == nullptr) {
        head = tail = curr;
    } else {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    curr = nullptr;
}

// Delete the first match value from head
void DoubleLinkedList::DeleteNode(int value) {
    if (head->next == nullptr && head->data == value) {
        // If there is only one node and it is the target
        delete head;
        head = tail = nullptr;
    } else {
        node* prev = head;
        node* curr = head->next;
        if (prev->data == value) {
            // If at the beginning
            delete prev;
            head = curr;
            curr->prev = nullptr;
            prev = curr = nullptr;
            return;
        } else if (tail->data == value) {
            node* temp = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete temp;
            temp = nullptr;
            return;
        }
        // If in the middle
        while (curr->next != nullptr) {
            if (curr->data == value) {
                prev->next = curr->next;
                curr->next->prev = prev;
                delete curr;
                prev = curr = nullptr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
}

void DoubleLinkedList::PrintHeadTail() {
    if (head != nullptr) {
        std::cout << "head is " << head->data << std::endl;
        std::cout << "tail is " << tail->data << std::endl;
    } else {
        std::cout << "head is NULL" << std::endl;
        std::cout << "tail is NULL" << std::endl;
    }
}

void DoubleLinkedList::PrintForward() {
    std::cout << "PrintForward: \n";
    node* curr = head;
    std::cout << "HEAD";
    while (curr != nullptr) {
        std::cout << " -> " << curr->data;
        curr = curr->next;
    }
    std::cout << " -> NULL" << std::endl;

    PrintHeadTail();
}

void DoubleLinkedList::PrintBackward() {
    std::cout << "PrintBackward: \n";
    node* curr = tail;
    std::cout << "TAIL";
    while (curr != nullptr) {
        std::cout << " -> " << curr->data;
        curr = curr->prev;
    }
    std::cout << " -> NULL" << std::endl;

    PrintHeadTail();
}