#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Member function to convert vector to linked list
static Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// insert value to the head of the Linked list
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}
// insert value to the tail of the Linked list
Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}
// Insert element at the position of the linked list
Node *insertPosition(Node *head, int el, int k)
{
    // If the list is empty and k is 1, insert at the head
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            // If k is not 1 and list is empty, insertion is invalid
            return head;
        }
    }

    // If k is 1, insert at the head
    if (k == 1)
    {
        return new Node(el, head);
    }

    // Traverse the list to find the (k-1)th node
    int cnt = 1;
    Node *temp = head;
    while (temp != nullptr && cnt < k - 1)
    {
        cnt++;
        temp = temp->next;
    }

    // If temp is not nullptr, insert the new node
    if (temp != nullptr)
    {
        Node *x = new Node(el, temp->next);
        temp->next = x;
    }

    return head;
}

Node *insertBeforeValue(Node *head, int el, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == val)
    {
        return new Node(el, head);
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next != nullptr)
    {
        Node *x = new Node(el, temp->next);
        temp->next = x;
    }

    return head;
}


int main()
{
    vector<int> arr = {9, 4, 6, 7};
    Node *head = convertArr2LL(arr);
    head = insertBeforeValue(head, 3,9);
    print(head);
    return 0;
}
