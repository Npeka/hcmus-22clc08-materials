#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* next;
};

Node* createNode(int data){
	Node* n = new Node;
	n->key = data;
	n->next = NULL;
	return n;
}

void printList(Node* pHead){
	Node* curNode = pHead;
	while (curNode != NULL){
		cout << curNode->key << "->";
		curNode = curNode->next;
	}
}

void addHead(Node* &pHead, int val){
	// step 1: create new node
	Node* newNode = createNode(val);
	// step 2: add into head
	if (pHead == NULL) pHead = newNode;
	else{
		newNode->next = pHead;
		pHead = newNode;
	}
}

void addTail(Node* &pHead, int val){
	// step 1: create new node
	Node* newNode = createNode(val);
	// step 2: find the node at tail
	if (pHead == NULL) pHead = newNode;
	else{
		Node* curNode = pHead;
		while (curNode->next != NULL){
			curNode = curNode->next;
		}
		// step: add newNode to tail
		curNode->next = newNode;
	}
}


void removeHead(Node* &pHead){
	if (pHead != NULL){
		Node* nextNode = pHead->next;
		delete pHead;
		pHead = nextNode;
	}
}

void removeTail(Node* &pHead){
	if (pHead != NULL){
		if (pHead->next == NULL){
			delete pHead;
			pHead = NULL;
		}
		else{
			Node* curNode = pHead;
			while (curNode->next->next != NULL)
				curNode = curNode->next;
			delete curNode->next;
			curNode->next = NULL; // quan trong
		}
	}
}

void clearLL(Node* &pHead){
	Node* curNode; 
	while (pHead != NULL){
		curNode = pHead->next;
		delete pHead;
		pHead = curNode;
	}
}



int main(){
	Node* pHead = NULL;
	addHead(pHead, 1);
	addHead(pHead, 5);
	addTail(pHead, 2);
	printList(pHead);
	clearLL(pHead);
	
	return 0;
}

