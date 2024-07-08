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

Node *convertArr2Dll(vector<int> &arr) {
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

int findLength(Node *slow) {
    int count = 1;
    Node *current = slow;
    while (current->next != slow) {
        count++;
        current = current->next;
    }
    return count;
}

int detectCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return findLength(slow);
        }
    }
    return 0; // No cycle
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArr2Dll(arr);

    // Manually create a cycle for testing
    Node *temp = head;
    Node *cycleNode = nullptr;
    int pos = 2; 

    for (int i = 0; i < pos; ++i) {
        temp = temp->next;
    }
    cycleNode = temp;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = cycleNode; // Creating the cycle

    int cycleLength = detectCycle(head);
    if (cycleLength > 0) {
        cout << "Cycle length: " << cycleLength << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
