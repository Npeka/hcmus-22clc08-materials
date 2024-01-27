#include <iostream>

using namespace std;


struct Node{
	int data;
	Node* next;
};

struct List{
	Node* head;
};


Node* createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
}

void addHead(List& ls, int data){
	if (ls.head == NULL){
		ls.head = createNode(data);
	}
	else{
		Node* newNode = createNode(data);
		newNode->next = ls.head;
		ls.head = newNode;
	}
}

void clearList(List& ls){
	Node* curNode; 
	while (ls.head != NULL){
		curNode = ls.head->next;
		delete ls.head;
		ls.head = curNode;
	}
}

int absFunc(int a, int b){
	if (a > b) return a - b;
	else return b - a;
}


int Count(List ls){
	Node* cur = ls.head;
	if (cur->next == NULL || cur->next->next == NULL)
		return 0;
	Node* prev = cur;
	cur = cur->next;
	int count = 0;
	while (cur->next != NULL){
		if (absFunc(prev->data,cur->next->data) == cur->data)
			count += 1;
		prev = cur;
		cur = cur->next;
	}
	return count;
}

int main(){
	List ls;
	ls.head = NULL;
	addHead(ls, 4);
	addHead(ls, 5);
	addHead(ls, 9);
	addHead(ls, 2);
	addHead(ls, 10);
	addHead(ls, 12);
	
	cout << Count(ls);
	clearList(ls);
	return 0;
}
