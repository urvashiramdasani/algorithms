#include <iostream>
#include <algorithm>

using namespace std;
int memo[100][100];

int lcs_recursive(string s1, string s2, int m, int n) {
    if(m == 0 || n == 0) return 0;
    if(s1[m-1] == s2[n-1]) return 1 + lcs_recursive(s1, s2, m-1, n-1);
    else {
        return max(lcs_recursive(s1, s2, m-1, n), lcs_recursive(s1, s2, m, n-1));
    }
};

int lcs_dp(string s1, string s2, int m, int n) {
    if(memo[m][n] != -1) return memo[m][n];
    if(m == 0 || n == 0) memo[m][n] = 0;
    else {
        if(s1[m - 1] == s2[n - 1]) memo[m][n] = 1 + lcs_dp(s1, s2, m - 1, n - 1);
        else memo[m][n] = max(lcs_dp(s1, s2, m - 1, n), lcs_dp(s1, s2, m, n - 1));
    }
    return memo[m][n];
};

int main() {
    string s1 = "AXYZ";
    string s2 = "BAZ";
    cout<<"Length of Longest Common Subsequence (Recursive) is "<<lcs_recursive(s1, s2, 4, 3); // theta(2^n)
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) memo[i][j] = -1;
    }
    cout<<"\nLength of Longest Common Subsequence (DP) is "<<lcs_dp(s1, s2, 4, 3); // theta(mn)
    
    int m = s1.length(); int n = s2.length();
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++) dp[i][0] = 0;
    for(int j=0; j<=n; j++) dp[0][j] = 0;
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout<<"\nLength of Longest Common Subsequnce (Tabulation) is "<<dp[m][n]; // theta(mn)
}
