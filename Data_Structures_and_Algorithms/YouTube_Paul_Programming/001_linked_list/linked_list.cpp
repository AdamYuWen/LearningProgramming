#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() { head = curr = temp = nullptr; } // C++11 and higher

LinkedList::~LinkedList() {
    curr = head;
    while (curr != nullptr) {
        delete curr;
        curr = curr->next;
    }
}

void LinkedList::AddNode(int value) {
    temp = new node();
    temp->data = value;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
    } else {
        curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void LinkedList::DeleteNode(int value) {
    if (head == nullptr) { // if the list is empty
        return;
    } else {
        curr = head;
        temp = head->next;

        if (head->data == value) { // if remove the first node
            head = head->next;
            delete curr;
            return;
        }
        while (temp != nullptr) {
            if (temp->data == value) { // if remove a node not the first one
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = temp;
            temp = temp->next;
        }
    }
}

void LinkedList::PrintLinkedList() {
    curr = head;
    std::cout << "head";
    while (curr != nullptr) {
        std::cout << " -> " << curr->data;
        curr = curr->next;
    }
    std::cout << " -> NULL" << std::endl;
}