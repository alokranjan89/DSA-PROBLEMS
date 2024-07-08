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
bool detectCycle(Node *head)
{
	//	Write your code here
    Node *slow  =head;
    Node *fast =  head;
    while(fast != NULL && fast-> next != NULL){
        slow  = slow ->next;
        fast  = fast->next->next;

        if(slow == fast)  return true;
    }
    return false;
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArr2Dll(arr);
    print(head);

    bool hasCycle = detectCycle(head);
    cout << "Cycle detected: " << (hasCycle ? "Yes" : "No") << endl;

    return 0;


    return 0;
}