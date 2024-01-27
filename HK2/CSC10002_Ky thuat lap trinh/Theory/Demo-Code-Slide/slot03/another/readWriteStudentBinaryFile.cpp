#include <iostream> // getline(stream, string)
#include <fstream> // cin.getline(char c[])
#include <string.h>
#include <string>
using namespace std;

struct Student{
	string studentID;
	string name;
	string dob;
	float score;
};

void readStudentFromFile(Student t[], int& n, string inPath){
	fstream inFile;
	inFile.open(inPath.c_str(), ios::in);
	n = -1;
	string tmp;
	char cTmp[100];
	while (!inFile.eof()){
		n = n + 1;		
		//inFile.getline(cTmp, 100);
		getline(inFile, tmp);
		t[n].studentID = tmp;
		
		inFile.getline(cTmp, 100);
		t[n].name = cTmp;
		
		inFile.getline(cTmp, 100);
		t[n].dob = cTmp;
		
		inFile >> t[n].score; 
		inFile.ignore(); // 
	}
	inFile.close();
}


void printStudentList(Student t[], int n){
	for (int i = 0; i < n; i++)
		cout<< t[i].studentID << " "
			<< t[i].name << " "
			<< t[i].dob << " "
			<< t[i].score << endl;
}

void writeStudentList2BFile(string outPath, Student t[], int n){
	fstream outFile;
	outFile.open(outPath.c_str(), ios::out | ios::binary);
	
	outFile.write(reinterpret_cast<char*> (&n), sizeof(n));
	
	for (int i = 0; i < n; i++){
		// write student ID
		outFile.write(reinterpret_cast<char*> (&(t[i].studentID)), sizeof(t[i].studentID));
		// write name
		int sizeofName = sizeof(t[i].name);
		outFile.write(reinterpret_cast<char*> (&sizeofName), sizeof(int));
		outFile.write(reinterpret_cast<char*> (&(t[i].name)), sizeofName);
		
		// write dob
		outFile.write(reinterpret_cast<char*> (&(t[i].dob)), sizeof(t[i].dob));
		
		// write score
		outFile.write(reinterpret_cast<char*> (&(t[i].score)), sizeof(float));
	}	
	outFile.close();
}


void readStudentListFromBFile(string inPath, Student t[], int& n){
	fstream inFile;
	inFile.open(inPath.c_str(), ios::in | ios::binary);
	inFile.read(reinterpret_cast<char *> (&n), sizeof(n));
	for (int i = 0; i < n; i++){
		// read student ID
		inFile.read(reinterpret_cast<char *> (&(t[i].studentID)), 8);
		int sizeofName;
		inFile.read(reinterpret_cast<char *> (&sizeofName), sizeof(sizeofName));
		inFile.read(reinterpret_cast<char *> (&(t[i].name)), sizeofName);
		inFile.read(reinterpret_cast<char *> (&(t[i].dob)), sizeof(t[i].dob));
		
		inFile.read(reinterpret_cast<char *> (&(t[i].score)), sizeof(float));
		// printStudentList(t, n);
	}
		
	
}

int main(){
	Student t[100];
	Student newT[100];
	int lenOfNewT;
	int n;
	readStudentFromFile(t, n, "../slot02_ex03.txt");
	writeStudentList2BFile("student.bin", t, n);
	readStudentListFromBFile("student.bin", newT, lenOfNewT);
	cout << "newlen = " << lenOfNewT;
	printStudentList(newT, lenOfNewT);
	return 0;	
}
