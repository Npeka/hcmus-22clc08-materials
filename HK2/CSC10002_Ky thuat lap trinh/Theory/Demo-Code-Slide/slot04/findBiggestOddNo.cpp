#include <iostream>
#include <limits.h>
using namespace std;

int findBiggestOddNo(int* a, int n){
	//int max = INT_MIN;// so le trong mang, so nho nhat
	int max = 0;
	for (int i = 0; i < n; i++)
		if (a[i]%2 != 0){
			max = a[i];
			break;
		}
	if (max == 0) return 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 != 0)
			if (a[i] > max)
				max = a[i];
	}		
	return max;
}
