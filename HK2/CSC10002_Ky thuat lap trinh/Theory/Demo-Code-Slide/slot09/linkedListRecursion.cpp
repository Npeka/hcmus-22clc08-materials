#include <iostream>

using namespace std;

// Definition of a linked list node
struct Node {
    int data;
    Node* next;
};

Node* createNode(int val){
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
}

// Function to insert a new node at the end of the linked list
void insert(Node*& head, int data) {
    if (head == NULL) {
        head = createNode(data);
    } else {
        insert(head->next, data);
    }
}

// Function to count the number of items in the linked list using recursion
int countItems(Node* head) {
    if (head == NULL) {
        return 0;
    } else {
        return 1 + countItems(head->next);
    }
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
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = NULL;
    for (int i = 1; i <= 5; i++) {
        insert(head, i);
    }

    // Counting the number of items in the linked list
    int count = countItems(head);
    cout << "Number of items in the linked list: " << count << endl;
	
	removeAll(head);
	

    return 0;
}

