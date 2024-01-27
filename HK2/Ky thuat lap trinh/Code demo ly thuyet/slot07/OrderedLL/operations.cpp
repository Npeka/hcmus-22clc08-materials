#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node in the correct position in the list
void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node; // Allocate memory for new node
    new_node->data = new_data; // Set data for new node
    new_node->next = NULL; // Set next pointer to null

    // If the list is empty or the new node data is less than the head node data, insert the new node at the head
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        // Find the correct position to insert the new node
        Node* current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        // Insert the new node in the correct position
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to delete a node with a given data value from the list
void remove(Node** head_ref, int key) {
    // If the head node itself holds the key to be deleted
    if (*head_ref != NULL && (*head_ref)->data == key) {
        Node* temp = *head_ref;
        *head_ref = (*head_ref)->next; // Change head
        delete temp; // Free memory
    } else {
        // Find the node with the key value and remove it from the list
        Node* current = *head_ref;
        Node* prev = NULL;
        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }
        if (current != NULL) {
            prev->next = current->next;
            delete current; // Free memory
        }
    }
}

Node* mergeLists(Node* head1, Node* head2) {
    Node* merged_head = NULL;
    Node** current_node_ptr = &merged_head;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            *current_node_ptr = head1;
            head1 = head1->next;
        } else {
            *current_node_ptr = head2;
            head2 = head2->next;
        }
        current_node_ptr = &((*current_node_ptr)->next);
    }

    if (head1 == NULL) {
        *current_node_ptr = head2;
    } else {
        *current_node_ptr = head1;
    }

    return merged_head;
}


// Function to print the contents of the list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function to test the list operations
int main() {
    Node* head = NULL; // Initialize empty list

    // Insert nodes in order
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 5);

    cout << "Original List: ";
    printList(head);

    // Remove nodes with given values
    remove(&head, 20);
    remove(&head, 5);

    
}
