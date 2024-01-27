#include <iostream>

void sortArrayBySelection(int a[], int n){
	// sort even
	for (int i = 0; i < n; i++){
		//  even, min
		int minEvenIdx = -1;
		for (int j = i; j < n; j++)
			if (a[j] % 2 == 0){
				minEvenIdx = j;
				break;
			}
		if (minEvenIdx == -1)
			break;
		else{
			for (int j = i; j < n; j++)
				if (a[j] % 2 == 0)
					if (a[j] < a[minEvenIdx])
						minEvenIdx = j;
			swap(a[i], a[minEvenIdx]);
		}
	}
	
	// sort odd
	for (int i = n-1; i >= 0; i--){
		// odd, min
		int minOddIdx = -1;
		for (int j = i; j >=0 ; j--)
			if (a[j] % 2 != 0){
				minOddIdx = j;
				break;
			}
		if (minOddIdx == -1)
			break;
		else{
			for (int j = i; j >=0; j--)
				if (a[j] % 2 == 0)
					if (a[j] < a[minOddIdx])
						minOddIdx = j;
			swap(a[i], a[minOddIdx]);
		}
	}
	
}





void sortArray(int a[], int n){
	int evenNo[n], oddNo[n];
	int nEven = 0, nOdd = 0;
	// split a into evenNo array and oddNo array
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0){
			evenNo[nEven] = a[i];
			nEven = nEven + 1;
		}
		else{
			oddNo[nOdd] = a[i];
			nOdd = nOdd + 1;
		}
	// sort ascending for evenNo[]
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (evenNo[j] > evenNo[j+1])
				swap(evenNo[j], evenNo[j+1])
	// sort descending for oddNo[]
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (oddNo[j] < oddNo[j+1])
				swap(oddNo[j], oddNo[j+1])
	// concat evenNo[] + oddNo[]
	for (int i = 0; i < nEven; i++)
		a[i] = evenNo[i];
	for (int i = 0; i < nOdd; i++)
		a[nEven + i] = oddNo[i];
}


int main(){
	return 0;
}
