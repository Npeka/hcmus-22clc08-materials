#include <iostream>

using namespace std;

// direct recursion
int fact(int x){
	if (x == 0) 
		return 1;
	else 
		return x*fact(x-1);
}



bool isEven(int x);

// indirect recursion
bool isOdd(int x){
	return !isEven(x);
}

bool isEven(int x){
	if (x == 0) 
		return true;
	else 
		return isOdd(x - 1);
}



int main(){
	int x = 10;
	cout << "Fact = " << fact(x) << endl;
	cout << isEven(x) << endl;
}
