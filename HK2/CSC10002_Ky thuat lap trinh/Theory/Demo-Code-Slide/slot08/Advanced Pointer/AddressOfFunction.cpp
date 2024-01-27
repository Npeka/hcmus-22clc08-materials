#include <iostream>

using namespace std;

void greets(){
	cout << "Hello Everyone";
}

int main(){
	cout << reinterpret_cast<void*>(greets)<<endl;
	cout << reinterpret_cast<void*>(&greets);
	return 0;
}


