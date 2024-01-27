#include <iostream>

using namespace std;

int main() {
    int a[2][3];
    int n = 2, m = 3;
    int* ptr = (int*) a;
    for (int i = 0; i < n*m; i++)
    	cin >> *(ptr + i);
    
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < m; j++)
    		cout << a[i][j] << "\t";
    	cout << endl;
	}
    
    return 0;
}
