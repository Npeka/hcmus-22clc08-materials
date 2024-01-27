#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* next;
};

struct Stack{
	Node* pHead;
};

Node* createNode(int data);

void initStack(Stack& s){
	s.pHead = NULL;
}

void push(Stack& s, int data){
	Node* newNode = createNode(data);
	newNode->next = s.pHead;
	s.pHead = newNode;
}


Node* createNode(int data){
	Node* newNode = new Node;
	newNode->key = data;
	newNode->next = NULL;
	return newNode;
}



bool isEmpty(Stack s){
	if (s.pHead == NULL) return true;
	else return false;
}

int getSize(Stack s){
	int size = 0;
	Node* cur = s.pHead;
	while (cur != NULL){
		size++;
		cur = cur->next;
	}
	return size;
}

Node* topNode(Stack s){
	return s.pHead;
}

int topData(Stack s){
	if (s.pHead == NULL) return 0;
	else return s.pHead->key;
}

int pop(Stack& s){
	if (s.pHead == NULL){
		return 0;
	} 
	int a = s.pHead->key;
	Node* nextNode = s.pHead->next;
	delete s.pHead;
	s.pHead = nextNode;
	return a;
}


int main(){
	
}
