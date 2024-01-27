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

void removeBefore(Node* &pHead, int val){
	if (pHead != NULL && pHead->next != NULL){
		if (pHead->next->next == NULL){
			if (pHead->next->key == val)
				removeHead(pHead);
		}
		else{
			Node* curNode = pHead;
			Node* prevNode = NULL;
			while (curNode->next->next->key != val){
				// chi con 2 nut
				prevNode = curNode;
				curNode = curNode->next;
				if (curNode->next->next == NULL){
					if (curNode->next->key == val){
						prevNode->next = curNode->next;
						delete curNode;
					}
					return;
				}
			}
			Node* nextNode = curNode->next->next;
			delete curNode->next;
			curNode->next = nextNode;
		}
	}
}

bool insertAtPosition(Node* &pHead, int pos, int val){
	if (pos < 0)
		return false;
	else{
		if (pos == 0)
			addHead(pHead, val);
		else{
			Node* curNode = pHead;
			for (int i = 0; i < pos - 1; i++){
				curNode = curNode->next;
				if (curNode == NULL) return false;
			}
			Node* newNode = createNode(val);
			newNode->next = curNode->next;
			curNode->next = newNode;
		}
	}
}

bool isPrime(int n){
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	for (int i = 2; i*i <= n + 1; i++)
		if (n % i == 0) return false;
	return true;
}


int countPrime(Node* pHead){
	if (pHead == NULL){
		return 0;
	}
	else{
		Node* curNode = pHead;
		int count = 0;
		while (curNode != NULL){
			if (isPrime(curNode->key))
				count = count + 1;
			curNode = curNode->next;
		}
		return count;
	}
}

int length(Node* pHead){
	if (pHead != NULL){
		int len = 0;
		Node* curNode = pHead;
		while (curNode != NULL){
			len = len + 1;
			curNode = curNode->next;
		}
		return len;
	}
	else return 0;
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
	addHead(pHead, 4);
	printList(pHead);
	removeBefore(pHead, 2);
	cout << "\nAfter deleting:\n";
	printList(pHead);
	clearLL(pHead);
	
	return 0;
}

