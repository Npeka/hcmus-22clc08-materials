#include <iostream>

using namespace std;
void printArray(int* a, int n);
void inputArray(int*& a, int& n){
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
int* inputArray(int& n){
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	return a;
}


int main(){
	
	int n 
	
	int n;
	int* a = inputArray(n);
	printArray(a, n);
	delete[] a;
	return 0;
}

void printArray(int* a, int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

