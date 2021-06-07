#include "double_linked_list.h"
#include <iostream>

int main() {
    DoubleLinkedList dll;
    dll.AddEndNode(1);
    dll.AddEndNode(2);
    dll.AddEndNode(3);
    dll.AddBeginNode(4);
    dll.AddBeginNode(5);
    dll.PrintForward();
    dll.PrintBackward();

    dll.DeleteNode(6);
    dll.PrintForward();
    dll.DeleteNode(3);
    dll.PrintForward();
    dll.DeleteNode(5);
    dll.PrintForward();
    dll.DeleteNode(1);
    dll.DeleteNode(2);
    dll.DeleteNode(4);
    dll.PrintForward();

    return 0;
}