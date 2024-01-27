#include <iostream>

using namespace std;

// Declare Node
struct Node {
    int data;
    Node* next;
};

// Declare Queue
struct Queue {
    Node *front, *rear;
};

// Initialize an empty Queue
void initQueue(Queue &q) {
    q.front = q.rear = NULL;
}

// Check if Queue is empty
bool isEmpty(Queue q) {
    return (q.front == NULL);
}

// Add an element to the rear of the Queue
void enqueue(Queue &q, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (q.rear == NULL) {
        q.front = q.rear = temp;
        return;
    }
    q.rear->next = temp;
    q.rear = temp;
}

// Remove an element from the front of the Queue
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == NULL) {
        q.rear = NULL;
    }
    delete temp;
}

// Return the element at the front of the Queue
int peek(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        return q.front->data;
    }
}

// Print the Queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = q.front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// delete all elements in Queue
void clear(Queue &q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}
