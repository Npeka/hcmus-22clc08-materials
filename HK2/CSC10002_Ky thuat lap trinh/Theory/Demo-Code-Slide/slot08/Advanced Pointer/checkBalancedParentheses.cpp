#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = NULL;
    }
};

void push(Stack& s, char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = s.top;
    s.top = newNode;
}

void pop(Stack& s) {
    if (s.top == NULL) {
        return;
    }
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
}

char peek(Stack& s) {
    if (s.top == NULL) {
        return '\0';
    }
    return s.top->data;
}

bool isBalanced(string str) {
    Stack s;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(s, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            char topChar = peek(s);
            if ((c == ')' && topChar == '(') || (c == ']' && topChar == '[') || (c == '}' && topChar == '{')) {
                pop(s);
            }
            else {
                return false;
            }
        }
    }
    return (s.top == NULL);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if (isBalanced(str)) {
        cout << "The string is balanced" << endl;
    }
    else {
        cout << "The string is not balanced" << endl;
    }
    return 0;
}

