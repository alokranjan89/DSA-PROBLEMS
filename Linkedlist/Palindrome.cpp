#include<iostream>
#include<vector>
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
Node *reverseLinkedList(Node *head) {
    if (head == NULL || head->next == NULL) return head;
    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node *head) {
    if (head == NULL || head->next == NULL) return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseLinkedList(slow->next);
    Node *first = head;
    Node *second = newHead;

    while (second != NULL) {
        if (first->data != second->data) {
            reverseLinkedList(newHead);  // Restore the original list
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLinkedList(newHead);  // Restore the original list
    return true;
}

int main(){
    vector<int> arr = {1, 2,1, 1, 2,1};
    Node *head = convertArr2LL(arr);
    bool result = isPalindrome(head);
    cout << (result ? "The linked list is a palindrome." : "The linked list is not a palindrome.") << endl;
    print(head); 
    return 0;
}