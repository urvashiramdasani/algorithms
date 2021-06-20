#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Naive Method
bool isPal(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    return (rev == s);
}

int main() {
    string s = "ABBA";
    cout << isPal(s);
    return 0;
}