#include <iostream>
#include <fstream>


using namespace std;

int main(){
	
	fstream outFile;
	outFile.open("demo.bin", ios::out | ios::binary);
	
	string s = "22127000";
	cout<<s.length();
	cout << sizeof(s) << endl;	
	outFile.write(reinterpret_cast<char* >(&s) , sizeof(s));
	outFile.close();
	
	fstream inFile;
	inFile.open("demo.bin", ios::in | ios::binary);
	string t;
	inFile.read(reinterpret_cast<char* >(&t) , 8);
	cout << "t = "<< t;
	
	return 0;
}
