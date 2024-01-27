#include <stdio.h>

using namespace std;

int countAppearance(int a[], int n, int val){
	count = 0;
	for (int i = 0; i <= n; i++)
		if (a[i] == val)
			count += 1;
	return count;
}

int findMajorityElement(int a[], int n){
	for (int i = 0; i<= n; i++)
		if (countAppearance(a, n, a[i]) > n / 2)
			return a[i];
	return -1;
}

int main(){
	
}
