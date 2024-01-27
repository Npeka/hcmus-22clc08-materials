#include <iostream>

using namespace std; 
// Function to calculate Fibonacci number without using external space
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, sum = 0;
    for (int i = 2; i <= n; ++i) {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << std::endl;
    return 0;
}

