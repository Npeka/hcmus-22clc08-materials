#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream bFile;
	bFile.open("binaryArr.bin", ios::in | ios::binary);
	
	int n;
	bFile.read(reinterpret_cast<char *> (&n), sizeof(n));
	cout << n << endl;
	int a[100];
	
	for (int i = 0; i < n; i++)
		bFile.read(reinterpret_cast<char *> (&a[i]), sizeof(a[i]));
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	bFile.close();
	return 0;
}
