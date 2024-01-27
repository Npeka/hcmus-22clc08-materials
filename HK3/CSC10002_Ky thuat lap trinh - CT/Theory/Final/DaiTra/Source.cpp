#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int** createMatrix(int m, int a, int b, int c)
{
	int** matrix = new int* [m];
	int val[3] = { a, b, c };
	for (int i = 0; i < m; i++)
	{
		int n = val[i % 3];
		matrix[i] = new int[n];
		int mul = -1;
		if (i % 2) mul = 1;
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = mul * (n - j);
			mul *= -1;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return matrix;
}
void cau1()
{
	int n = 5;
	createMatrix(7, 3, 1, 4);
}

void printSum(int price[], int n, int v[])
{
	for (int i = 0; i < n; i++)
		if (v[i]) cout << i << " ";
	cout << '\n';
}
int sum(int price[], int n, int v[])
{
	int s = 0;
	for (int i = 0; i < n; i++)
		if (v[i]) s += price[i];
	return s;
}
int len(int v[], int n) 
{
	int l = 0;
	for (int i = 0; i < n; i++)
		if (v[i]) l++;
	return l;
}
void findMaxLength(int price[], int n, int m, int v[], int pos, int& l)
{
	if (pos < 0 || sum(price, n, v) > m) return;
	findMaxLength(price, n, m, v, pos - 1, l); v[pos] = 1;
	if (sum(price, n, v) == m) l = max(l, len(v, n));
	findMaxLength(price, n, m, v, pos - 1, l); v[pos] = 0;
}
void find(int price[], int n, int m, int v[], int pos, int l)
{
	if (pos < 0 || sum(price, n, v) > m) return;
	find(price, n, m, v, pos - 1, l); v[pos] = 1;
	if (sum(price, n, v) == m && len(v, n) == l) printSum(price, n, v);
	find(price, n, m, v, pos - 1, l); v[pos] = 0;
}
void print(int price[], int n, int m)
{
	int* v = new int[n] {0}, l = 0;
	findMaxLength(price, n, m, v, n - 1, l);
	find(price, n, m, v, n - 1, l);
}
void cau4()
{
	int price[] = { 5,7,1,8,1,2, };
	int n = sizeof(price) / sizeof(price[0]);
	int m = 10;
	print(price, n, m);
}
int main()
{
	cau4();
	//cau3();
}

