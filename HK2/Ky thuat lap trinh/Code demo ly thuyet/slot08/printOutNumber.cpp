#include <iostream>

using namespace std;

void printNum(int n){
	if (n == 0){
		cout << endl;
		return;
	}
	cout << n << " ";
	printNum(n - 1);
}

int main(){
	printNum(5);	
}

