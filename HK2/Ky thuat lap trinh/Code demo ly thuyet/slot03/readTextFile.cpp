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

void writeArr2FText(string fPath, int a[], int n){
	fstream outFile;
	outFile.open(fPath.c_str(), ios::out);
	outFile << n << endl;
	for (int i = 0; i < n; i++)
		outFile << a[i] << " ";
	outFile.close();
}

void readArrFromTFile(string fPath, int a[], int& n){
	fstream inFile;
	inFile.open(fPath.c_str(), ios_base::in);
	inFile >> n;
	for (int i = 0; i < n; i++)
		inFile >> a[i];
		
	inFile.close();
}

int main(){
	
	int a[MAX_ELE];
	int n;
	string inPath = "arr.txt";
	
	readArrFromTFile(inPath, a, n);
	printArr(a, n);
	
	int b[MAX_ELE];
	int m;
	string outPath = "written_arr.txt";
	inputArr(b, m);
	writeArr2FText(outPath, b, m);
	
	return 0;
}
