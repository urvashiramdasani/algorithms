// Lexicographic rank (s) = number of strings lexicographically smaller than s + 1

#include <iostream>

using namespace std;

int fact(int n) {
    return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

// O(n)
int lexRank(string s) {
    int res = 1, n = s.length(), mul = fact(n), count[256] = {0};
    
    for(int i = 0; i < n; i++)
        count[s[i]]++;
    for(int i = 1; i < 256; i++)
        count[i] += count[i - 1];

    for(int i = 0; i < n - 1; i++) {
        mul /= (n - i);
        res += count[s[i] - 1] * mul;

        for(int j = s[i]; j < 256; j++)
            count[j]--;
    }

    return res;
}

int main() {
    string s = "STRING";
    cout << lexRank(s);
    return 0;
}