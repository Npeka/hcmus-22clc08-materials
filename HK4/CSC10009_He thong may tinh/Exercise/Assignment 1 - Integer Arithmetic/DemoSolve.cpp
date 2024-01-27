#include <iostream>
#include <string>

#define MAX_SIZE 8

using namespace std;

char* getBinary(char n);
void printBinary(char* a);
void printDecimal(char* a);
void resetArray(char* a);
void copyArray(char* dest, char* src, int n);
void shiftLeft(char* a);
void shiftRight(char* a);
void reverseSign(char* a);
void Add(char* a, char* b, char* res);
void Subtract(char* a, char* b, char* res);
void Multiply(char* a, char* b, char* res);
void Divide(char* a, char* b, char* res, char* mod);
void Input(char& a, char& b);
void Output(char a, char b);

char* getBinary(char n) {
	char* c = new char[MAX_SIZE] {0};
	for (int i = 0; i < MAX_SIZE; i++)
		c[MAX_SIZE - i - 1] = (n >> i & 1);
	return c;
}
void printBinary(char* a) {
	for (int i = 0; i < MAX_SIZE; i++)
		cout << (char) (a[i] + '0');
	cout << '\n';
}
void printDecimal(char* a) {
	char num = 0;
	for (int i = 0; i < MAX_SIZE; i++)
		num = (num << 1) | a[i];
	cout << (int) num << '\n';
}
void resetArray(char* a) {
	for (int i = 0; i < MAX_SIZE; i++)
		a[i] = 0;
}
void copyArray(char* dest, char* src, int n = MAX_SIZE) {
	for (int i = 0; i < n; ++i)
		dest[i] = src[i];
}
void shiftLeft(char* a) {
	for (int i = 0; i < MAX_SIZE - 1; i++)
		a[i] = a[i + 1];
	a[MAX_SIZE - 1] = 0;
}
void shiftRight(char* a) {
	for (int i = MAX_SIZE - 1; i > 0; --i)
		a[i] = a[i - 1];
}
void reverseSign(char* a) {
	for (int i = 0; i < MAX_SIZE; i++)
		(a[i] == 0) ? a[i] = 1 : a[i] = 0;
	char* one = getBinary(1);
	Add(a, one, a);
}
void Add(char* a, char* b, char* res) {
	char carry = 0;
	for (int i = MAX_SIZE - 1; i >= 0; i--) {
		char k = a[i] + b[i] + carry;
		if (k >= 2) {
			k -= 2;
			carry = 1;
		}
		else carry = 0;
		res[i] = k;
	}
}
void Subtract(char* a, char* b ,char* res) {
	int carry = 0;
	for (int i = MAX_SIZE - 1; i >= 0; i--) {
		int k = a[i] - b[i] - carry;
		if (k < 0) {
			k += 2;
			carry = 1;
		}
		else carry = 0;
		res[i] = k;
	}
}
void Multiply(char* a, char* b, char* res) { // m*q a q q-1 | m
	char last = 0;
	char* c = new char[MAX_SIZE] {0};
	for (int i = MAX_SIZE - 1; i >= 0; i--) {
		if (b[i] == 1 && last == 0)
			Subtract(c, a, c);
		else if (b[i] == 0 && last == 1)
			Add(c, a, c);
		last = b[i];
		res[i] = c[MAX_SIZE - 1];
		shiftRight(c);
	}
	delete[] c;
}
void Divide(char* a, char* b, char* res, char* mod) { // q/m a q | m
	char* tmpA = new char[MAX_SIZE] {0};
	char* tmpRes = new char[MAX_SIZE] {0};
	bool negative = false;
	bool negativeA = false;
	if (a[0]) negativeA = true;
	if (a[0] != b[0]) {
		if (a[0]) reverseSign(a);
		if (b[0]) reverseSign(b);
		negative = true;
	}
	else if (a[0] == 1 && b[0] == 1) {
		reverseSign(a);
		reverseSign(b);
	}
	copyArray(tmpA, a);

	int k = MAX_SIZE;
	while (k-- > 0) {
		shiftLeft(res);
		res[MAX_SIZE - 1] = a[0];
		shiftLeft(a);
		copyArray(tmpRes, res);
		Subtract(tmpRes, b, res);
		if (res[0] == 1) {
			copyArray(tmpRes, res);
			Add(tmpRes, b, res);
		}
		else if (res[0] == 0){
			a[MAX_SIZE - 1] = 1;
		}
	}
	copyArray(mod, res);
	copyArray(res, a);
	copyArray(a, tmpA);
	if (negative) reverseSign(res);
	if (negativeA && !mod[0]) reverseSign(mod);
	delete[] tmpA;
	delete[] tmpRes;
}
bool checkInput(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 && s[i] == '-') continue;
		if (!isdigit(s[i]))
			return false;
	}
	double a = stod(s);
	return (-128 <= a && a <= 127 && a - (int)a == 0);
}
void Input(char& a, char& b) {	
	string s1, s2;
	s1 = s2 = "";
	cout << "Input 2 signed integers 8-bit A and B (-128 <= A,B <= 127)\n";
	cout << "Input A (Decimal): ";
	getline(cin, s1);
	cout << "Input B (Decimal): ";
	getline(cin, s2);
	while (!(checkInput(s1) && checkInput(s2))){
		cout << "Your input is wrong. Please re-enter: \n";
		cout << "Input A (Decimal): ";
		getline(cin, s1);
		cout << "Input B (Decimal): ";
		getline(cin, s2);
	} 
	a = (char) stod(s1);
	b = (char) stod(s2);
}
void Output(char a, char b) {
	char* chrA = getBinary(a);
	char* chrB = getBinary(b);
	char* res = new char[MAX_SIZE] {0};
	char* mod = new char[MAX_SIZE] {0};
	cout << '\n';

	cout << "A (Binary): ";
	printBinary(chrA);
	cout << "B (Binary): ";
	printBinary(chrB);
	cout << '\n';

	resetArray(res);
	Add(chrA, chrB, res);
	cout << "A + B (Binary) : "; printBinary(res);
	cout << "A + B (Decimal): "; printDecimal(res);
	cout << '\n';

	resetArray(res);
	Subtract(chrA, chrB, res);
	cout << "A - B (Binary) : "; printBinary(res);
	cout << "A - B (Decimal): "; printDecimal(res);
	cout << '\n';

	resetArray(res);
	Multiply(chrA, chrB, res);
	cout << "A * B (Binary) : "; printBinary(res);
	cout << "A * B (Decimal): "; printDecimal(res);
	cout << '\n';

	if (b) {
		resetArray(res);
		Divide(chrA, chrB, res, mod);
		cout << "A / B (Binary) : "; printBinary(res);
		cout << "A / B (Decimal): "; printDecimal(res);
		cout << '\n';

		cout << "A % B (Binary) : "; printBinary(mod);
		cout << "A % B (Decimal): "; printDecimal(mod);
	}
	else {
		cout << "A / B and A % B are invalid!\n";
		cout << "Cannot divide by 0!\n";
	}

	delete[] chrA;
	delete[] chrB;
	delete[] res;
	delete[] mod;
}

int main()
{
	char a, b;
	Input(a, b);
	Output(a, b);
	system("pause");
	return 0;
}