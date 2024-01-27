#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}


void inputArray(int a[], int n){
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void printArray(int a[], int n){
	for (int i = 0; i < n; i++)	
		cout << a[i] << " ";
	cout << endl;
}

bool isPrime(int n){
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void sortArray(int a[], int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n ; j++)
			if ((isPrime(a[j]) || isPrime(a[j+1]))
				&& a[j] > a[j+1]) {
					swap(a[j], a[j+1]);
				
			}
}


void sortWithSelection(int a[], int n){
	for (int i = 0; i < n; i++){
		// tim prime, swap(a[i], a[pos]
		int pos = -1;
		for (int j = i; j < n; j++)
			if (isPrime(a[j])){
				pos = j;
				break;
			}
		
		if (pos != -1){
			swap(a[i], a[pos]);
		}
		
	}
}



int main(){
	int a[1000], n;
	cin >> n;
	inputArray(a, n);
	printArray(a, n);
	cout << "After sorting" << endl;
	sortArray(a, n);
	printArray(a, n);
	return 0;
}
