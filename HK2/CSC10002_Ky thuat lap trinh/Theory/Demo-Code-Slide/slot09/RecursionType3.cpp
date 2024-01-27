#include <iostream>

using namespace std;

// Tail Recursion
void printNum_tail(int n){
	cout << n << endl;
	if(n > 0)
		printNum_tail(n-1);
}

// Non-tail Recursion
void printNum_nontail(int n){
	if(n > 0){
		printNum_nontail(n-1);
		cout << n << endl;
	}
}

int main(){
	int x = 6;
	cout << "tail = " << endl;
	printNum_tail(x) ;
	cout << endl;
	cout << "nontail = " << endl;
	printNum_nontail(x);
	cout << endl;
}
