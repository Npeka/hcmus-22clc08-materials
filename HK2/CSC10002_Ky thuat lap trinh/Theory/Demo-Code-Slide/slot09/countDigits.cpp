#include <iostream>
using namespace std;

int countDigits(int n);

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int digitCount = countDigits(num);
    cout << "The number of digits in " << num << " is " << digitCount << endl;
    return 0;
}

int countDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + countDigits(n / 10);
    }
}
