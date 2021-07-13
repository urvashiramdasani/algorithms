// Used when mutiple searches are required
// Construct Longest Proper Prefix Suffix Array
// See video for better understanding

#include <iostream>

using namespace std;

// Naive O(n ^ 3)
int longPropPreSuff(string s, int n) {
    for(int len = n - 1; len > 0; len--) {
        bool flag = true;
        
        for(int i = 0; i < len; i++) {
            if(s[i] != s[n - len + 1])
                flag = false;
        }
        
        if(flag)
            return len;
    }

    return 0;
}

void fillLPS(string s, int lps[]) {
    for(int i = 0; i < s.length(); i++) 
        lps[i] = longPropPreSuff(s, i + 1);
}

// Efficient O(n)
void fillLPSEff(string s, int lps[]) {
    int len = 0, i = 1;
    lps[0] = 0;

    while(i < s.length()) {
        if(s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len == 0) {
                lps[i] = 0;
                i++;
            } else 
                len = lps[len - 1];
        }
    }
}

void KMP(string pat, string txt) {
    int n = txt.length(), m = pat.length();
    int lps[m];
    fillLPSEff(pat, lps);
    int i = 0, j = 0;

    while(i < n) {
        if(pat[j] == txt[i]) {
            i++;
            j++;
        }

        if(j == m) {
            cout << i - j << " ";
            j = lps[j - 1];
        } else if(i < n && pat[j] != txt[i]) {
            if(j == 0) 
                i++;
            else 
                j = lps[j - 1];
        }
    }
}

int main() {
    string pat = "ababa", txt = "ababcababaad";
    KMP(pat, txt);
}