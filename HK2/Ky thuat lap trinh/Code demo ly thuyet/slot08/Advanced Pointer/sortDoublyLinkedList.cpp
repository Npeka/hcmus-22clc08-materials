#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insert(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortList(Node* &head, bool (*compare)(int, int)) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* curr = head;
    while (curr != nullptr) {
        Node* minNode = curr;
        Node* innerCurr = curr->next;
        while (innerCurr != nullptr) {
            if (compare(innerCurr->data, minNode->data)) {
                minNode = innerCurr;
            }
            innerCurr = innerCurr->next;
        }
        if (minNode != curr) {
            swap(&(curr->data), &(minNode->data));
        }
        curr = curr->next;
    }
}

void clear(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}

int main() {
    Node* head = nullptr;
    insert(head, 10);
    insert(head, 5);
    insert(head, 20);
    insert(head, 3);
    insert(head, 15);
    cout << "Original list: ";
    printList(head);
    sortList(head, ascending);
    cout << "List in ascending order: ";
    printList(head);
    sortList(head, descending);
    cout << "List in descending order: ";
    printList(head);
    clear(head);
    return 0;
}

