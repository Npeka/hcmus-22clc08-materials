#include <iostream>
using namespace std;

void decimalToBinary(int decimal);

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "The binary representation of " << num << " is ";
    decimalToBinary(num);
    cout << endl;
    return 0;
}

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        return;
    } else {
        decimalToBinary(decimal / 2);
        cout << decimal % 2;
    }
}
