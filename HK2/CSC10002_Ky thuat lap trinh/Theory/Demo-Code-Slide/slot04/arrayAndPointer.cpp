#include <iostream>
using namespace std;

int main(){
	int a[5] = {1,2,3,4,5};
	
	cout << a[3] << endl;
	cout << *(a + 3) <<endl ;
	cout << *(&a[0] + 3);
	return 0;
}


