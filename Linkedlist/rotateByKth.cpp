#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* findNthNode(Node* head, int k) {
    Node* temp = head;
    int cnt = 1;
    while (temp != NULL) {
        if (cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return NULL;
}

Node* rotate(Node* head, int k) {
    if (head == NULL || k == 0) return head;

    Node* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        length += 1;
    }

    if (k % length == 0) return head;

    k = k % length;

    tail->next = head;

    Node* newLastNode = findNthNode(head, length - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = rotate(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}
