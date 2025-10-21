// C++ Program for converting singly linked list
// into circular linked list.
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function that convert singly linked list
// into circular linked list.
void circular(Node *curr, Node *head) {

    // if last node, then point next ptr
    // to head Node
    if (curr->next == nullptr) {
        curr->next = head;
        return;
    }

    // otherwise traverse to the
    // next node
    circular(curr->next, head);
}

void printList(Node *head) {
    Node *curr = head;

    do {
        cout << curr->data << " ";
        curr = curr->next;

    } while (curr != head);
    cout << endl;
}

int main() {

    // create a hard coded list
    // 10->12->14->16
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(14);
    head->next->next->next = new Node(16);

    circular(head, head);

    printList(head);

    return 0;
}
