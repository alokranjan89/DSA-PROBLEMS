#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *converArr2Dll(vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* removeKthNode(Node* head, int K) {
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < K; i++) {
        if (fast == nullptr) return head;
        fast = fast->next;
    }
    if (fast == nullptr) {
        Node *newHead = head->next;
        if (newHead != nullptr) newHead->back = nullptr;
        delete head;
        return newHead;
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;
    if (slow->next != nullptr) {
        slow->next->back = slow;
    }
    delete delNode;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = converArr2Dll(arr);
    head = removeKthNode(head, 3);
    print(head);
    return 0;
}
