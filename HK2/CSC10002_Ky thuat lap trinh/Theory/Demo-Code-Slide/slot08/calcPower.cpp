#include <iostream>

using namespace std;

int calcPower(int x, int n) {
	if (n == 0)
		return 1;
	return calcPower(x, n - 1) * x;
}

int main(){
	int x = 3, y = 2;
	cout << calcPower(x, y);
}
