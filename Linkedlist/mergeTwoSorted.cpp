#include <iostream>
using namespace std;

// Definition for singly-linked list.
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T x) : data(x), next(nullptr) {}
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* t1 = first;
    Node<int>* t2 = second;
    Node<int>* dummyNode = new Node<int>(-1); // Dummy node to start the merged list
    Node<int>* temp = dummyNode;

    // Traverse both lists and attach the smaller node to the merged list
    while (t1 != nullptr && t2 != nullptr) {
        if (t1->data < t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    // Attach the remaining nodes from either list
    if (t1 != nullptr) temp->next = t1;
    else temp->next = t2;

    // Return the merged list, skipping the dummy node
    Node<int>* mergedHead = dummyNode->next;
    delete dummyNode; // Free the dummy node to avoid memory leak
    return mergedHead;
}

// Function to print the linked list
void printList(Node<int>* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two sorted linked lists for testing
    Node<int>* list1 = new Node<int>(1);
    list1->next = new Node<int>(3);
    list1->next->next = new Node<int>(5);

    Node<int>* list2 = new Node<int>(2);
    list2->next = new Node<int>(4);
    list2->next->next = new Node<int>(6);

    // Merge the two sorted lists
    Node<int>* mergedList = sortTwoLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Free the allocated memory for the merged list
    while (mergedList != nullptr) {
        Node<int>* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
