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


int stoi(string s){
	int result = 0;
	int pow10 = 1;
	int lenS = s.length();
	for (int i = lenS - 1; i >= 0; i--){
		result += (s[i] - 48)*pow10;
		pow10 *= 10;
	}
	return result;
}

void convertDOB2Int(string dob, int& d, int& m, int& y){
	
	// For C++ 11.1 above
	d = stoi(dob.substr(0,2));
	m = stoi(dob.substr(3,2));
	y = stoi(dob.substr(6,4));	
}


void printStudentList(Student t[], int n){
	for (int i = 0; i < n; i++)
		cout<< t[i].studentID << " "
			<< t[i].name << " "
			<< t[i].dob << " "
			<< t[i].score << endl;
}

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
		inFile.ignore();
	}
	inFile.close();
}


int findStudentMaxScore(Student t[], int n){
	int maxIdx = 0;
	
	for (int i = 1; i < n; i++)
		if (t[i].score > t[maxIdx].score){
			maxIdx = i;
		}
	return maxIdx;
}

void printStudentToFile(Student t, string outPath){
	fstream outFile;
	outFile.open(outPath.c_str(), ios::out);
	outFile << t.studentID << " " << t.name;
	outFile.close();
}

int main(){
	Student t[100];
	int n;          
	readStudentFromFile(t, n, "../slot02_ex03.txt");
	cout << "No of student: "<< n << endl;
	printStudentList(t, n);
	printStudentToFile(t[findStudentMaxScore(t, n)], "output.txt");
	return 0;
}
