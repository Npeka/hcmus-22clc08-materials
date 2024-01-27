#include <iostream>
#include <string>
using namespace std;

int main(){
	string lastName, firstName, middleName;
	
	cin >> firstName >> middleName >> lastName;
	cout << lastName << ", " 
	     << middleName[0] << ". "
	     << firstName << endl;
	return 0;
	
}
