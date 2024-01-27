#include <iostream>

using namespace std;

int isPrime(int n){
	if (n < 2) return 0;
	if (n == 2 || n == 3) return 1;
	for (int i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}

int countPrime(int** a, int row, int col){
	int count = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (isPrime(a[i][j]) == 1)
				count++;
	return count;
}


int main(){
	int** a;
	int col, row;
	
	cin >> row >> col;
	a = new int*[row];
	for (int i = 0; i < row; i++)
		a[i] = new int[col];
		
	for (int i = 0 ; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> a[i][j];	
	cout << "Number of prime: " << countPrime(a, row, col);
	
	for (int i = 0; i < row; i++)
		delete[] a[i];
	delete[] a;	
	
	return 0;
}
