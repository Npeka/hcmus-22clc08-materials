#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* next;
};

struct List{
	Node* pHead;
	Node* pTail;
};

Node* createNode(int keyVal){
	Node* n = new Node;
	n->key = keyVal;
	n->next = NULL;
	return n;
}

List* createList(){
	List* l = new List;
	l->pHead = NULL;
	l->pTail = NULL;
}

void addTail(List* &l, int val){
	// step 1: create new node
	Node* newNode = createNode(val);
	// step 2: find the node at tail
	if (l->pHead == NULL){
		l->pHead = newNode;
		l->pTail = l->pHead;
	}
	else{
		l->pTail->next = newNode;
	}
}


void removeLast(List* &l)
{
    if (l->phead == NULL)
        return;
  
    if (l->pHead->next == NULL) {
        delete l->head;
        l->phead = NULL;
        l->pTail = NULL
    }
    Node* curNode = l->pHead;
    while (curNode->next != l->pTail)
    	curNode = curNode->next;
    delete l->pTail;
    l->pTail = curNode;
}


void clearLL(List* &l){
	Node* curNode; 
	while (l->pHead != NULL){
		curNode = l->pHead->next;
		delete l->pHead;
		l->pHead = curNode;
	}
}

void printLL(List* l){
	Node* curNode = l->pHead;
	while (curNode != NULL){
		cout << curNode->key << "->";
		curNode = curNode->next;
	}
}

int main(){
	int n;
	cin >> n;
	List* l = ;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		addTail(head, tmp);
	}
	printLL()
	return 0;
	
}
