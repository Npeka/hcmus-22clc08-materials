#include <iostream>

using namespace std;

int** generateMatrix2(int* a, int* b, int na, int nb){
	int** matrix;
	matrix = new int*[na];
	for (int i = 0; i < na; i++)
		matrix[i] = new int[nb];
	
	for (int i = 0 ; i < na; i++)
		for (int j = 0; j < nb; j++)
			matrix[i][j] = a[i] + b[j];	
		
	return matrix;
}

void inputArray(int*& a, int& n){
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
}


int main(){
	
	int *a, *b;
	int na, nb;
	inputArray(a, na);
	inputArray(b, nb);
	
	int** matrix = generateMatrix2(a, b, na, nb);
		
	for (int i = 0 ; i < na; i++){
		for (int j = 0; j < nb; j++)
			cout << matrix[i][j] << " "; 
		cout << endl;
	}
			
	delete[] a;
	delete[] b;
	
	for (int i = 0; i < na; i++)
		delete[] matrix[i];
	delete[] matrix;	
	
	
	return 0;
}
