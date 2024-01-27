#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    int len = str.length();
    if (len <= 1) {
        return true;
    } else if (str[0] != str[len - 1]) {
        return false;
    } else {
				// Eliminate the first and last character in str
        return isPalindrome(str.substr(1, len - 2));
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }
    return 0;
}
