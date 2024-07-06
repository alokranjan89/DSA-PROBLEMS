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

Node *convertArr2Dll(vector<int> &arr)
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

Node *findIntersection(Node *firstHead, Node *secondHead) {
  // Write your code here
    if(firstHead == NULL || secondHead == NULL)  return NULL;
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2  = temp2->next;

        if(temp1 == temp2) return temp1;
        if(temp1 == NULL) temp1 = secondHead;
        if(temp2 == NULL)  temp2 = firstHead;
    } 
    return temp1;
}


int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3,4,6, 7, 8};

    Node *head1 = convertArr2Dll(arr1);
    Node *head2 = convertArr2Dll(arr2);

    // Print both lists
    cout << "First List: ";
    print(head1);
    cout << "Second List: ";
    print(head2);

    // Find intersection
    Node* intersection = findIntersection(head1, head2);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    return 0;
}