#include<iostream>
#include<vector>
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

Node *converArr2Dll(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

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

int addHelper(Node* temp) {
    if (temp == nullptr)
        return 1;
    int carry = addHelper(temp->next);
    temp->data += carry;
    if (temp->data < 10) 
        return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
    int carry = addHelper(head);
    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head->back = newNode;
        head = newNode;
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {9, 9, 9};
    Node* head = converArr2Dll(arr);
    cout << "Original List: ";
    printList(head);

    head = addOne(head);
    cout << "List after adding one: ";
    printList(head);

    return 0;
}
