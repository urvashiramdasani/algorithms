/*

m = pattern length, n = txt length, 1 <=m <= n

Naive - O((n - m + 1) * m), when all characters of pattern are distinct = O(n)
--> No preprocessing

Rabin Karp - O((n - m + 1) * m), but better performance in average case
--> Preprocess pattern

KMP - O(n)
--> Preprocess pattern

Suffix Tree - O(m) (Datastructure)
--> Preprocess Text

*/

#include <iostream>

using namespace std;

// Naive
void PatSearching(string pat, string txt) {
    int n = txt.length(), m = pat.length();

    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(pat[j] != txt[i + j])
                break;
        }

        if(j == m)
            cout << i << " ";
    }
}

// Improved Naive -- When pattern has all distinct characters
// theta(n) time
void PatSearchingDist(string pat, string txt) {
    int n = txt.length(), m = pat.length();

    for(int i = 0; i <= n - m; ) {
        int j;
        for(j = 0; j < m; j++) {
            if(pat[j] != txt[i + j])
                break;
        }

        if(j == m)
            cout << i << " ";

        if(j == 0)
            i++;
        else
            i = i + j;
    }
}

int main() {
    string txt = "ABCABCD";
    string pat = "ABCD";
    PatSearching(pat, txt);
    cout << endl;
    PatSearchingDist(pat, txt);
    return 0;
}