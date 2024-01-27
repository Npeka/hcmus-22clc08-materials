#include <iostream>

using namespace std;


// nested recursion
int func(int n){
	if(n ==0) return 0;
	if(n > 4) return n;
	return 
		func(2+ func(2*n));
}

int main(){
	cout << func(4);
}
