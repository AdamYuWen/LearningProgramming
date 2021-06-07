#ifndef DOUBLE_LINKED_LIST_
#define DOUBLE_LINKED_LIST_

struct node {
    int data;
    node* next;
    node* prev;
};

class DoubleLinkedList {
  public:
    DoubleLinkedList();
    DoubleLinkedList(int value);
    ~DoubleLinkedList();
    void AddBeginNode(int value);
    void AddEndNode(int value);
    void DeleteNode(int value);
    void PrintHeadTail();
    void PrintForward();
    void PrintBackward();

  private:
    node* head;
    node* tail;
};

#endif // DOUBLE_LINKED_LIST_