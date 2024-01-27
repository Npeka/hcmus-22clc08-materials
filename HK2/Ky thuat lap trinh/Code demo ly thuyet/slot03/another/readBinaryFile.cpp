#include <iostream>
#include <fstream>
#include <string>

#define MAX_ELE 100

using namespace std; 

void printArr(int a[], int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void inputArr(int a[], int& n){
	cout << "Input n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void writeArr2FBin(string fPath, int a[], int n){
	fstream outFile;
	outFile.open(fPath.c_str(), ios::out | ios::binary);
	
	outFile.write(reinterpret_cast<char*> (&n), sizeof(n));

	for (int i = 0; i < n; i++)
		outFile.write(reinterpret_cast<char*> (&a[i]), sizeof(a[i]));
		
	outFile.close();
}

void readArrFromFBin(string fPath, int a[], int& n){
	fstream inFile;
	inFile.open(fPath.c_str(), ios_base::in);
	inFile.read(reinterpret_cast<char*> (&n), sizeof(int)); 
	for (int i = 0; i < n; i++)
		inFile.read(reinterpret_cast<char*> (&a[i]), sizeof(int)); 
		
	inFile.close();
}

int main(){
	
	int a[MAX_ELE];
	int n;
	string outPath = "binaryArr.bin";
	inputArr(a, n);
	writeArr2FBin(outPath, a, n);
	
	int b[MAX_ELE];
	int m;
	readArrFromFBin(outPath, b, m);
	printArr(b, m);
	

	
	return 0;
}
