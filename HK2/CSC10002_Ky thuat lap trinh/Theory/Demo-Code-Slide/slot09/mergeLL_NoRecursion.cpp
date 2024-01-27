#include <iostream>

using namespace std;

// Definition of a Node in the linked list
struct Node {
    int data;
    Node* next;
    
};

Node* createNode(int val){
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
}

// Function to insert a Node at the end of a linked list
Node* insertNode(Node* head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to merge two sorted linked lists and return the head of the merged list
Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    Node* mergedHead = NULL;
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    Node* current = mergedHead;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1 != NULL) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    return mergedHead;
}

// Function to print the elements of a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
    // Create two sorted linked lists
    Node* head1 = NULL;
    head1 = insertNode(head1, 1);
    head1 = insertNode(head1, 3);
    head1 = insertNode(head1, 5);

    Node* head2 = NULL;
    head2 = insertNode(head2, 2);
    head2 = insertNode(head2, 4);
    head2 = insertNode(head2, 6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* mergedHead = mergeSortedLists(head1, head2);
    cout << "Merged List: ";
    printList(mergedHead);
	removeAll(mergedHead);
    return 0;
}

