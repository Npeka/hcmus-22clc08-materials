#include <iostream>

using namespace std;

void swapValue(int &value1, int &value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

int main()
{
	void (*pSwap)(int &, int &) = swapValue;
	
	int a = 1, b = 5;
	cout << "Before: " << a << " " << b << endl;
	(*pSwap)(a, b);
	cout << "After:  " << a << " " << b << endl;

	return 0;
}
