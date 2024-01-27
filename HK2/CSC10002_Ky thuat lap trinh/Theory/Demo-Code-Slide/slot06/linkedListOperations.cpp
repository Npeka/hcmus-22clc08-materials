#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* next;
};

Node* createNode(int keyVal){
	Node* n = new Node;
	n->key = keyVal;
	n->next = NULL;
	return n;
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
		Node* tmp = pHead;
		pHead = pHead->next;
		delete tmp;
	}
}

void removeLast(Node*& head)
{	// not consider the failure mode
    if (head == NULL)
        return;
  
    if (head->next == NULL) {
        delete head;
        head = NULL;
    }
    // Find the second last node
    Node* curNode = head;
    while (curNode->next->next != NULL)
        curNode = curNode->next;
  
    // Delete last node
    delete (curNode->next);
  
    // Change next of second last
    curNode->next = NULL;
}

bool addPos(Node* &pHead, int data, int pos){
	if (pos < 1) return false;
	Node* curNode = pHead;
	while (pos > 1){
		if (curNode->next == NULL) return false;
		pos = pos - 1;
		curNode = curNode->next;
	}
	Node* newNode = createNode(data);
	newNode->next = curNode->next;
	curNode->next = newNode;
	return true;
}

void clearLL(Node* &pHead){
	Node* curNode; 
	while (pHead != NULL){
		curNode = pHead->next;
		delete pHead;
		pHead = curNode;
	}
}

void printLL(Node* pHead){
	Node* curNode = pHead;
	while (curNode != NULL){
		cout << curNode->key << "->";
		curNode = curNode->next;
	}
}

int main(){
	int n;
	cin >> n;
	Node* head = NULL;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		addTail(head, tmp);
	}
	printLL(head);
	
	clearLL(head);
	return 0;
	
}
