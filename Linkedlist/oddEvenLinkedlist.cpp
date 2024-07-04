#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* converArr2Dll(vector<int> &arr)
{
    if (arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* oddEvenList(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        if (evenHead != nullptr) {
            evenHead->back = odd;
        }
        return head;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = converArr2Dll(arr);

    cout << "Original List: ";
    print(head);

    Solution solution;
    Node* result = solution.oddEvenList(head);

    cout << "Modified List: ";
    print(result);

    // Freeing the allocated memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
