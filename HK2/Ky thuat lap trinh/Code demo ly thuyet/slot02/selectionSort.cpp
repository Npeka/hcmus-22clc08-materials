#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

int selectionSort(int a[], int n){
	// tang dan 
	for (int i = 0; i < n; i++){
		// xet vi tri a[i] 
		// a[i] -> nho nhat
		// tim min tu a[i] - a[n-1]
		int min = a[i], minPos = i;
		for (int j = i; j < n; j++)
			if (min > a[j]){
				min = a[j];
				minPos = j;
			}
		
		// doi cho a[minPos] vs a[i]
		swap(a[i], a[minPos]);
	}
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
		for (int j = i; j < n; j++)
			if (isPrime(a[j])){
				swap(a[i], a[j]);
				break;
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
