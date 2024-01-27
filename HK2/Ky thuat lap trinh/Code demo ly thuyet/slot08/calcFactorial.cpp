#include <iostream>

using namespace std;

int calcFactorial(int n){
	if (n == 0) return 1;
	else return n*calcFactorial(n - 1);
}

int main(){
	int n;
	cin >> n;
	cout << calcFactorial(n);
}
