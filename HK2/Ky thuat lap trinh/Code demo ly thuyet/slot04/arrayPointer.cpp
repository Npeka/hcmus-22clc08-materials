#include <iostream>

using namespace std;

int* inputArray(int& n){
	cout << "Input n = ";
	cin >> n;
	int* a;
	a = new int[n];
	for (int i = 0; i < n; i++){
		cout <<"a[" << i <<"]=";
		cin >> a[i];
	}
	return a;
}

int main(){
	int *a; 
	int n;
	a = inputArray(n);
	cout <<"Array: \n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	delete[] a;
	return 0;
}
