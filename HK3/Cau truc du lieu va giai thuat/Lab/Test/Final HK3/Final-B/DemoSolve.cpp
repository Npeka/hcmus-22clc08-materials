#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	vector<int> A;
	Node* left;
	Node* right;
};
long long hashFunction(vector<int> A)
{
	long long s = 0, pow = 1;
	for (int i = 0; i < A.size(); i++)
	{
		s = (s + (A[i] * pow) % 1123) % 1123;
		pow = pow * 12 % 1123;
	}
	return s;
}
bool operator>(vector<int> A, vector<int> B)
{
	return hashFunction(A) > hashFunction(B);
}
bool operator<(vector<int> A, vector<int> B)
{
	return hashFunction(A) < hashFunction(B);
}
Node* createNode(vector<int> A)
{
	return new Node{ A, NULL, NULL };
}
void leftRotation(Node*& root)
{
	Node* cur = root->right;
	root->right = cur->left;
	cur->left = root;
	root = cur;
}
void rightRotation(Node*& root)
{
	Node* cur = root->left;
	root->left = cur->right;
	cur->right = root;
	root = cur;
}
int Height(Node* root)
{
	if (root == NULL) return 0;
	return 1 + max(Height(root->left), Height(root->right));
}
int getBalance(Node* root)
{
	if (root == NULL) return 0;
	return Height(root->left) - Height(root->right);
}
void Balance(Node*& root)
{
	if (root == NULL) return;
	int balance = getBalance(root);
	if (balance > 1) {
		if (getBalance(root->left) < 0)
			leftRotation(root->left);
		rightRotation(root);
	}
	else if (balance < -1) {
		if (getBalance(root->right) > 0)
			rightRotation(root->right);
		leftRotation(root);
	}
}
void Insert(Node*& root, vector<int> A)
{
	if (root == NULL)
		root = createNode(A);
	else if (root->A > A)
		Insert(root->left, A);
	else if (root->A < A)
		Insert(root->right, A);
	else
		return;
	Balance(root);
}
Node* createAVLTree(string filename)
{
	ifstream filein(filename);
	Node* root = NULL; string line;
	while (getline(filein, line, '\n'))
	{
		stringstream ss(line); vector <int> A; int c;
		while (ss >> c)
			A.push_back(c);
		Insert(root, A);
	}
	filein.close();
	return root;
}
void LNR(Node* root)
{
	if (root == NULL) return;
	LNR(root->left);
	cout << "{ ";
	for (int x : root->A) cout << x << " ";
	cout << "}\n";
	LNR(root->right);
}
// 2
void Remove(Node*& root, vector<int> A)
{
	if (root == NULL)
		return;
	else if (root->A > A)
		Remove(root->left, A);
	else if (root->A < A)
		Remove(root->right, A);
	else {
		if (root->left == NULL) {
			Node* del = root;
			root = root->right;
			delete del;
		}
		else if (root->right == NULL) {
			Node* del = root;
			root = root->left;
			delete del;
		}
		else {
			Node* cur = root->left;
			while (cur->right != NULL)
				cur = cur->right;
			root->A = cur->A;
			Remove(root->left, cur->A);
		}
	}
	if (root != NULL) Balance(root);
}
void removeHash(Node*& root)
{
	if (root == NULL) return;
	removeHash(root->left);
	removeHash(root->right);
	if (hashFunction(root->A) > 1111)
		Remove(root, root->A);
	Balance(root);
}
void deleteTree(Node*& root)
{
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root; root = NULL;
}
int main()
{
	Node* root = createAVLTree("data.txt");
	LNR(root);
	cout << "=============\n";
	removeHash(root);
	LNR(root);
	deleteTree(root);
}