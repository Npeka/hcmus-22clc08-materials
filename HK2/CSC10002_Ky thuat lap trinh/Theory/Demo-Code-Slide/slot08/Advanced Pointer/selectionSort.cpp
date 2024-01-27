#include <iostream>

using namespace std;


bool ascending(int left, int right){
	return left > right;
}

bool descending(int left, int right){
	return left < right;
}

void selectionSort(int *arr, int length, bool (*comparisonFunc)(int, int)){
	for (int i_start = 0; i_start < length; i_start++){
		int minIndex = i_start;
		for (int i_current = i_start + 1; i_current < length; i_current++){
			// use function pointer as ascending or descending function
			if (comparisonFunc(arr[minIndex], arr[i_current])) {
				minIndex = i_current;
			}
		}

		swap(arr[i_start], arr[minIndex]); 
	}
}

void printArray(int arr[], int length){
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[] = { 1, 4, 2, 3, 6, 5, 8, 9, 7 };
	int length = sizeof(arr) / sizeof(int);

	cout << "Before sorted: ";
	printArray(arr, length);

	selectionSort(arr, length, descending);

	cout << "After sorted:  ";
	printArray(arr, length);

	return 0;
}
