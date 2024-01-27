#include <iostream>

using namespace std;

int checkAscending(int a[], int n, int left, int right){
	
	for (int i = left; i <= right; i++)
		if (a[i] >= a[i+1])
			return 0;
	return 1;
}



int checkAttribute(int a[], int n, int left, int right){
	for (int i = 0; i <= (right-left)/2 ; i++)
		if (a[left + i] != a[right - i])
			return 0;
	return 1;
}


int findLongestSymArr(int a[], int n){
	int max = 1;
	for (int left = 0; left < n; left++)
		for (int right = left + 1; right < n; right++)
			if (checkAttribute(a, n, left, right)){
				int len = right - left + 1;
				if (len > max)
					max = len;
			}
	
}
