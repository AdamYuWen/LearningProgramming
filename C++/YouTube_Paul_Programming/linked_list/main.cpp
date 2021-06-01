#include "linked_list.h"
#include <iostream>

int main() {
    LinkedList ll;
    ll.AddNode(1);
    ll.AddNode(2);
    ll.AddNode(3);
    ll.AddNode(3);
    ll.AddNode(4);
    ll.AddNode(5);
    ll.PrintLinkedList();
    ll.DeleteNode(1);
    ll.PrintLinkedList();
    ll.DeleteNode(3);
    ll.PrintLinkedList();
    ll.DeleteNode(5);
    ll.PrintLinkedList();
    ll.DeleteNode(2);
    ll.DeleteNode(3);
    ll.DeleteNode(4);
    ll.PrintLinkedList();

    return 0;
}