#include <iostream>

using namespace std;

// Iterative
bool isSubsequence(string s1, string s2) {
    if(s1.length() < s2.length())
        return false;

    int j = 0;
    for(int i = 0; i < s1.length() && j < s2.length(); i++) {
        if(s1[i] == s2[j])
            j++;
    }

    return (j == s2.length());
}

// Recursive
bool isSubSeqRec(string s1, string s2, int n, int m) {
    if(m == 0)
        return true;
    
    if(n == 0)
        return false;

    if(s1[n - 1] == s2[m - 1])
        return isSubSeqRec(s1, s2, n - 1, m - 1);
    else
        return isSubSeqRec(s1, s2, n - 1, m);
}

int main() {
    string s1 = "ABCDEF", s2 = "ADE";
    cout << isSubsequence(s1, s2) << endl;
    cout << isSubSeqRec(s1, s2, s1.length(), s2.length());
    return 0;
}