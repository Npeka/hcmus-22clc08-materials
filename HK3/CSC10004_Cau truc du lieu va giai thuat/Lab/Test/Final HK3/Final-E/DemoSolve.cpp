#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	vector<char> A;
	Node* left;
	Node* right;
};
bool palindrome(vector<char> A)
{
	for (int i = 0; i < A.size() / 2; i++)
		if (A[i] != A[A.size() - i - 1])
			return false;
	return true;
}
int vowel(vector<char> A)
{
	int cnt = 0;
	for (char x : A)
		if (x == 'o' || x == 'e' || x == 'a' || x == 'u' || x == 'i')
			cnt++;
	return cnt;
}
bool operator>(vector<char> A, vector<char> B)
{
	if (palindrome(A) > palindrome(B))
		return true;
	else if (palindrome(A) == palindrome(B)){
		if (vowel(A) > vowel(B))
			return true;
	}
	return false;
}
bool operator<(vector<char> A, vector<char> B)
{
	if (palindrome(A) < palindrome(B))
		return true;
	else if (palindrome(A) == palindrome(B)) {
		if (vowel(A) < vowel(B))
			return true;
	}
	return false;
}
Node* createNode(vector<char> A)
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
void Insert(Node*& root, vector<char> A)
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
		stringstream ss(line); vector <char> A; char c;
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
	for (char x : root->A) cout << x; cout << "\n";
	LNR(root->right);
}
// 2
void Remove(Node*& root, vector<char> A)
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
void removeVowel(Node*& root)
{
	if (root == NULL) return;
	removeVowel(root->left);
	removeVowel(root->right);
	if (!palindrome(root->A) && vowel(root->A) < 3)
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
	removeVowel(root);
	LNR(root);
	deleteTree(root);
}