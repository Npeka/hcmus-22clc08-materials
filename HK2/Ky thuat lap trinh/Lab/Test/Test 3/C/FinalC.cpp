#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
struct Monomial {
	int cof; // coefficient
	int exp; // exponents
};
struct Node {
	Monomial base;
	Node* next;
};
struct List {
	Node* head;
	Node* tail;
};

Node* createNode(int cof, int exp)
{
	Node* newNode = new Node;
	newNode->base.cof = cof;
	newNode->base.exp = exp;
	newNode->next = NULL;
	return newNode;
}
void addTail(List& picture, int cof, int exp)
{
	Node* newNode = createNode(cof, exp);
	if (picture.head == NULL || picture.tail == NULL)
		picture.head = picture.tail = newNode;
	else
	{
		picture.tail->next = newNode;
		picture.tail = newNode;
	}
}
void printList(List picture)
{
	Node* cur = picture.head;
	while (cur != NULL)
	{
		cout << cur->base.cof << " " << cur->base.exp << endl;
		cur = cur->next;
	}
}
void printList2(List picture)
{
	Node* cur = picture.head;
	while (cur != NULL)
	{
		if (cur->base.exp == 5)
			cout << cur->base.cof << " " << cur->base.exp << endl;
		cur = cur->next;
	}
}
void readfile(string filename, int& number, int**& matrixA, int& m, int& n, int**& matrixB, int& p, int& q, List& polynomial)
{
	ifstream infile(filename);
	infile >> number;

	infile >> m >> n;
	matrixA = new int* [m];
	for (int i = 0; i < m; i++)
	{
		matrixA[i] = new int[n];
		for (int j = 0; j < n; j++)
			infile >> matrixA[i][j];
	}

	infile >> p >> q;
	matrixB = new int* [p];
	for (int i = 0; i < p; i++)
	{
		matrixB[i] = new int[q];
		for (int j = 0; j < q; j++)
			infile >> matrixB[i][j];
	}

	polynomial.head = polynomial.tail = NULL;
	while (!infile.eof())
	{
		int cof, exp;
		infile >> cof >> exp;
		if (!infile.eof())
			addTail(polynomial, cof, exp);
	}
	infile.close();
}
// ex1
void solution_ex1(int number)
{
	cout << number << " ";
	if (number == 1)
		return;

	if (number % 2 == 0)
		solution_ex1(number / 2);
	else
		solution_ex1(3 * number + 1);
}
// ex2
bool checkmulti(int** matrixA, int m, int n, int** matrixB, int p, int q, int i, int j)
{
	int s = 0;
	for (int k = 0; k < q; k++)
		for (int l = 0; l < p; l++)
			for (int o = 0; o < p; o++)
				s += matrixA[i + k][j + o] * matrixB[o][l];
	return s % 2 == 0;
}
int*** solution_ex2(int** matrixA, int m, int n, int** matrixB, int p, int q, int& d1, int& d2, int& d3)
{
	d1 = 0, d2 = q, d3 = p;
	for (int i = 0; i < m - q + 1; i++)
		for (int j = 0; j < n - p + 1; j++)
			if (checkmulti(matrixA, m, n, matrixB, p, q, i, j))
				d1++;


	int*** matrixC = new int** [d1];
	for (int i = 0; i < d1; i++)
	{
		matrixC[i] = new int* [d2];
		for (int j = 0; j < d2; j++)
			matrixC[i][j] = new int[d3];

	}

	d1 = 0;
	for (int i = 0; i < m - q + 1; i++)
		for (int j = 0; j < n - p + 1; j++)
			if (checkmulti(matrixA, m, n, matrixB, p, q, i, j))
			{
				for (int k = 0; k < d2; k++)
					for (int l = 0; l < d3; l++)
						matrixC[d1][k][l] = matrixA[i + k][j + l];
				d1++;
			}
	return matrixC;
}
void printMatrix3D(int*** a, int d1, int d2, int d3)
{
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)
		{
			for (int k = 0; k < d3; k++)
			{
				cout << a[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
// ex3
void solution_ex3(List& polynomial)
{
	Node* cur = polynomial.head;
	while (cur != NULL && cur->next != NULL)
	{
		Node* pre = cur;
		Node* tmp = cur->next;
		while (tmp != NULL)
		{
			if (tmp->base.exp == cur->base.exp)
			{
				cur->base.cof += tmp->base.cof;

				if (polynomial.tail == tmp)
					polynomial.tail = pre;
				pre->next = tmp->next;
				delete tmp;
				tmp = pre->next;
			}
			else
			{
				pre = tmp;
				tmp = tmp->next;
			}
		}
		cur = cur->next;
	}

	// xoa he so bang 0 ?
	while (polynomial.head != NULL && polynomial.head->base.cof == 0)
	{
		Node* pre = polynomial.head;
		polynomial.head = polynomial.head->next;
		delete pre;
	}

	if (polynomial.head == NULL)
	{
		polynomial.tail = NULL;
		return;
	}

	Node* pre = polynomial.head;
	cur = pre->next;
	while (cur != NULL)
	{
		if (cur->base.cof == 0)
		{
			if (polynomial.tail == cur)
				polynomial.tail = pre;
			cur = cur->next;
			delete pre->next;
			pre->next = cur;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}

int main()
{
	int number;
	int** matrixA, m, n;
	int** matrixB, p, q;
	List polynomial;
	readfile("dataC.txt", number, matrixA, m, n, matrixB, p, q, polynomial);
	// ex1
	//solution_ex1(number);

	// ex2
	/*int*** matrixC, d1, d2, d3;
	matrixC = solution_ex2(matrixA, m, n, matrixB, p, q, d1, d2, d3);
	printMatrix3D(matrixC, d1, d2, d3);*/

	// ex3
	printList(polynomial);
	solution_ex3(polynomial);
	cout << endl;
	printList(polynomial);
}