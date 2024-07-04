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

Node *converArr2Dll(vector<int> &arr)
{
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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummyHead = new Node(-1);
    Node *curr = dummyHead;
    Node *temp1 = num1;
    Node *temp2 = num2;
    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if (temp1) sum += temp1->data;
        if (temp2) sum += temp2->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
}

int main()
{
    vector<int> arr1 = {9, 4, 6, 7};
    vector<int> arr2 = {5, 6, 4};

    Node *num1 = converArr2Dll(arr1);
    Node *num2 = converArr2Dll(arr2);

    Node *result = addTwoNumbers(num1, num2);

    print(result);

    return 0;
}
