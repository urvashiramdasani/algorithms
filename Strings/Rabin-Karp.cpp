// Slide the pattern one by one
// Compare hash values of pattern and current text window. If hash values
// match then only compare individual characters
// p = hash value of pattern, t = hash value of current window of text
// values of characters -> a = 1, b = 2, c = 3 and so on...
// Spurious hit = hash value matches but characters do not match
// Rolling hash: t(i + 1) = t(i) + txt[i + m] - txt[i] -- m = pattern length
// This is a simple hash
// Improved hash: t(i + 1) = d(t(i) - txt[i]*d^(m - 1)) + txt[i + m]
// We use mod here in case string length is large
// See the video again for better understanding

#include <iostream>

using namespace std;

void RBSearch(string pat, string txt) {
    int n = txt.length(), m = pat.length();
    int h = 1, d = 5, q = 7;

    // Compute d^(m - 1)
    for(int i = 1; i <= m - 1; i++) 
        h = (h * d) % q;

    int p = 0, t = 0;

    // Compute p and t(0)
    for(int i = 0; i < m; i++) {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for(int i = 0; i <= n - m; i++) {
        // Check for spurious hit
        if(p == t) {
            bool flag = true;
            for(int j = 0; j < m; j++) 
                if(txt[i + j] != pat[j]) {
                    flag = false;
                    break;
                }
            
            if(flag)
                cout << i << " ";
        }

        // Compute t(i + 1) using t(i)
        if(i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if(t < 0) t = t + q;
        }
    }
}

int main() {
    string txt = "abcdefgabcde", pat = "abc";
    RBSearch(pat, txt);
    return 0;
}