#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node{ data, nullptr };
    } else {
        insert(head->next, data);
    }
}

void remove(Node*& head, int data) {
    if (head == nullptr) {
        return;
    } else if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        remove(head->next, data);
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "NULL\n";
    } else {
        std::cout << head->data << "->";
        printList(head->next);
    }
}

int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);

    std::cout << "Initial list: ";
    printList(head);

    remove(head, 2);

    std::cout << "List after removing 2: ";
    printList(head);

    return 0;
}

