#include <iostream>

using namespace std;

int watch(int n) {
	if (n > 0)
		return n;
	cout << n <<endl;
	return watch((n+2)*2);
}

int main(){
	cout << watch(-7);
	
}

