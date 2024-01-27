#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int val){
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void addHead(Node*& pHead, int val){
	if (pHead == NULL){
		pHead = createNode(val);
	}
	else{
		Node* newNode = createNode(val);
		newNode->next = pHead;
		pHead = newNode;
	}
}

void addTail(Node*& pHead, int val){
	if (pHead == NULL){
		pHead = createNode(val);
	}
	else{
		Node* cur = pHead;
		while (cur->next != NULL){
			cur = cur->next;
		}
		Node* newNode = createNode(val); 
		cur->next = newNode;
	}
}

void removeHead(Node*& pHead){
	if (pHead != NULL){
		Node* tmp = pHead->next;
		delete pHead;
		pHead = tmp;
	}
}

void removeTail(Node*& pHead){
	if (pHead != NULL){
		
		if (pHead->next == NULL){
			delete pHead; // huy quyen truy cap, ko tu gan pHead= NULL
			pHead = NULL;
		}
		else{
			Node* cur = pHead;
			while (cur->next->next != NULL)
				cur = cur->next;
			
			delete cur->next;
			cur->next = NULL;
		}
	}
}

void clear(Node*& pHead){
	Node* tmp;
	while (pHead != NULL){
		tmp = pHead->next;
		delete pHead;
		pHead = tmp;
	}
}

void printList(Node* pHead){
	Node* cur = pHead;
	while (cur != NULL){
		cout << cur->data << "->";
		cur = cur->next;
	}
	cout << endl;
}

// sau < truoc
// prev < cur => prev >= cur

bool checkAscending(Node* pHead){
	Node* cur = pHead;
	Node* next = pHead->next;
	while (next != NULL){
		if (cur->data >= next->data)
			return false;
		cur = next;
		next = next->next;
	}
	return true;
}


void addPos(Node*& pHead, int val, int pos){
	if (pHead == NULL && pos == 0)
		addHead(pHead, val);
	else{
		Node* cur = pHead;
		while (pos > 1){
			if (cur == NULL) return;
			cur = cur->next;
			pos--;
		}
		if (cur == NULL) return;
		
		Node* newNode = createNode(val);
		Node* tmp = cur->next;
		cur->next = newNode;
		newNode->next = tmp;
	}
}

bool checkSymmetric(Node* pHead){
	Node* pLeft, *pRight;
	pLeft = pHead;
	pRight = pHead;
	while (pRight->next != NULL)
		pRight = pRight->next;
	while (pLeft != NULL && pLeft != pRight && pLeft->next != pRight){
		if (pLeft->data != pRight->data) 
			return false;
		else{
			pLeft = pLeft->next;
			Node* cur = pLeft;
			while (cur->next != pRight){
				cur = cur->next;
			}
			pRight = cur;
		}
	}
	return true;
}



int main(){
	Node* pHead = NULL; 
	addHead(pHead, 1);  
	addHead(pHead, 2);
	addHead(pHead, 3);
	addHead(pHead, 2);
	addHead(pHead, 1);
	
	printList(pHead);
	cout << checkSymmetric(pHead);
	clear(pHead);
	
	return 0;
}


