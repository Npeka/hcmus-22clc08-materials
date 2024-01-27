#include <iostream>

using namespace std;

// linear recursion
int fact(int x){
	if (x == 0) 
		return 1;
	else 
		return x*fact(x-1);
}

// binary recursion
int fibo(int x){
	if (x < 2) 
		return x;
	else
		return fibo(x - 1) + fibo(x - 2);
}


int main(){
	int x = 6;
	cout << "Fact = " << fact(x) << endl;
	cout << "Fibo = " << fibo(x) << endl;
}
