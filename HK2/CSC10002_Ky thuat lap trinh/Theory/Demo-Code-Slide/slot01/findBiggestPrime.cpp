#include <iostream>

using namespace std;

int isPrime(int n){
	if (n < 2) return 0;
	if (n == 2 || n == 3) return 1;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int findBiggestPrime(int a[], int n){
	int max = 0;
	for (int i = 0; i < n; i++)
		if (isPrime(a[i]))
			if (a[i] > max)
				max = a[i];
	return max;
}
