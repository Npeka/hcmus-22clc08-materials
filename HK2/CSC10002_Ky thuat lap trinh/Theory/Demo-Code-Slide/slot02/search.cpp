#include <iostream>

using namespace std;

int findXByLinearSearch(int a[], int n, int X){
	// linear search
	for (int i = 0; i < n; i++)
		if (a[i] == X)
			return i;
	return -1;
}

int findByBinarSearch(int a[], int n, int X, int left, int right){
	while (left != right){
		int mid = (left + right) / 2;
		if (a[mid] == X)
			return mid;
		else{
			if (a[mid] > X) // X nam ben trai
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
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

int main(){
	int a[1000], n;
	cin >> n;
	inputArray(a, n);
	printArray(a, n);
	int x; 
	cout << "input x = ";
	cin >> x;
	cout << findByBinarSearch(a, n, x, 0, n);
	return 0;
}
