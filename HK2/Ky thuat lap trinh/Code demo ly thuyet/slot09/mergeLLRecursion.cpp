#include <iostream>

using namespace std;
// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    
};

Node* createNode(int val){
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
}

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    Node* merged;
    if (head1->data < head2->data) {
        merged = head1;
        merged->next = mergeTwoLists(head1->next, head2);
    } else {
        merged = head2;
        merged->next = mergeTwoLists(head1, head2->next);
    }
    return merged;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to remove all nodes in the linked list using recursion
void removeAll(Node*& head) {
    if (head == NULL) {
        return;
    }
    Node* nextNode = head->next;
    delete head;
    head = NULL;
    removeAll(nextNode);
}

int main() {
    // Sample input linked lists
    Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    cout << "Input Linked List 1: ";
    printList(head1);

    cout << "Input Linked List 2: ";
    printList(head2);

    // Merge the two linked lists
    Node* merged = mergeTwoLists(head1, head2);

    cout << "Merged Linked List: ";
    printList(merged);
	removeAll(merged);
    return 0;
}

