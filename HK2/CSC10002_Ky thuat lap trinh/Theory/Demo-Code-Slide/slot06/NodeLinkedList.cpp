#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* next;
};

int main(){
	Node n, c;
	c.key = 2;
	n.key = 1;
	n.next = &c;
	cout << n.key << "->" << n.next->key;
	return 0;
}

