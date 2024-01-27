#include <iostream>

using namespace std;

void convertInt2Freq(int n, int digits[]){
	while (n != 0){
		int d = n % 10;
		digits[d] += 1;
		n = n / 10;
	}	
}

void createBiggestNoFromFreq(int digits[]){
	//int result = 0;
	for (int i = 9; i >=0; i--){
		while (digits[i] != 0){
			//result = result*10 + i;
			cout << i;
			digits[i] -= 1;
		}
	}
}

int main(){
	int n;
	cin >> n;
	int digits[10] = {0};
	convertInt2Freq(n, digits);
	createBiggestNoFromFreq(digits);
	return 0;
}
