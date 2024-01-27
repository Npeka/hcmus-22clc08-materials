#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inch;
};

int main() {
    Distance *ptr;
	int n = 2;
    ptr = new Distance[5];
    
    for (int i = 0; i < n; i++){
    	cout << "Enter feet: ";
    	cin >> ptr[i].feet;
    	cout << "Enter inch: ";
    	cin >> ptr[i].inch;
	}
    cout << "Displaying information:" << endl;
 	for (int i = 0; i < n; i++)
    	cout << "Distance = " 
			 << ptr[i].feet << " feet " 
			 << ptr[i].inch << " inches" << endl;
	
	delete[] ptr;
    return 0;
}
