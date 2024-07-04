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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteHeadOf2LL(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    if (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *kNode = head;
    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }
    Node *prev = kNode->back;
    Node *front = kNode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHeadOf2LL(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}

void deleteNode(Node*temp){
    Node*prev  = temp->back;
    Node*front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return; 
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

int main()
{
    vector<int> arr = {9, 4, 6, 7};

    Node *head = converArr2Dll(arr);
    deleteNode(head->next->next);
    print(head);
    return 0;
}