#ifndef LINKED_LIST_
#define LINKED_LIST_

/**
 * The final code combined the struct definition and pointer.
 * struct node {
 *     int data;
 *     node* next;
 * };
 * typedef struct node* node_ptr;
 */
typedef struct node {
    int data;
    node* next;
} * node_ptr;

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    node_ptr get_head() { return head; }
    void AddNode(int value);
    void DeleteNode(int value);
    void SearchRecursive(node_ptr ptr, int value);
    void PrintLinkedList();

  private:
    node_ptr head;
    node_ptr curr;
    node_ptr temp;
};

#endif // LINKED_LIST_