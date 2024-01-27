#include <iostream>

using namespace std;

struct DNode{
	int data;
	Node* next;
	Node* prev;
};

DNode* createNode(int keyVal){
	DNode* n = new DNode;
	n->key = keyVal;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void addFirst(DNode* &pHead, int val){
	if (pHead == NULL){
		pHead = createNode(val);
	}
	else{
		DNode* newNode = createNode(val);
		newNode->next = pHead;
		pHead->prev = newNode;
		pHead = newNode;
	}
}

void addLast(DNode* &pHead, int val){
	if (pHead == NULL){
		pHead = createNode(val);
	}
	else{
		DNode* curNode = pHead;
		while (curNode->next != NULL)
			curNode = curNode->next;
		
		DNode* newNode = createNode(val);
		curNode->next = newNode;
		newNode->prev = curNode;
	}
}

void removeFirst(DNode*& pHead){
	if (pHead != NULL){
		if (pHead->next == NULL){
			delete pHead;
			pHead = NULL;
		}
		else{
			DNode* nextNode = pHead->next;
			delete pHead;
			pHead = nextNode;
			pHead->prev = NULL; // 
		}
	}
}


void removeLast(DNode*& pHead){
	if (pHead != NULL){
		if (pHead->next == NULL){
			delete pHead;
			pHead = NULL;
		}
		else{
			DNode* curNode = pHead;
			while (curNode->next != NULL)
				curNode = curNode->next;
			curNode = curNode->prev;
			delete curNode->next;
			curNode->next = NULL;	
		}	
	}
}

bool insertPosition(DNode* pHead, int pos, int val){
	if (pos < 0) return false;
	if (pos == 0 || pHead == NULL){
		addFirst(pHead, val);
		return true;
	}
	DNode* curNode = pHead;
	for (int i = 0; i < pos - 1; i++){
		curNode = curNode->next;	
		if (curNode == NULL) return false;
	}
	DNode* newNode = createNode(val);
	newNode->next = curNode->next;
	newNode->prev = curNode;
	curNode->next->prev = newNode;
	curNode->next = newNode;
	return true;
}

int main(){
	
	
}
