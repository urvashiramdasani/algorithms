#include <iostream>

using namespace std;

// Time - O(n) Auxiliary - O(n)

bool isPalindrome(string str, int start, int end) {
    if(start >= end) return true;
    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
};

int main() {
    string str = "abba";
    cout<<"String abba is palindrome : "<<isPalindrome(str, 0, 3);
}
