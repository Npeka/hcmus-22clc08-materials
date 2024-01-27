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

int main(){
	Node* n = createNode(3);
	cout << n->key;
	delete n;
}
