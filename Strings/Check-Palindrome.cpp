#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Naive Method - theta(n) time and space
bool isPal(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    return (rev == s);
}

// Efficient Method - theta(n) time, theta(1) space
bool isPalin(string s) {
    int begin = 0, end = s.length() - 1;

    while(begin < end) {
        if(s[begin] != s[end])
            return false;
        
        begin++;
        end--;
    }

    return true;
}

int main() {
    string s = "ABBA";
    cout << isPal(s) << endl;
    cout << isPalin(s);
    return 0;
}