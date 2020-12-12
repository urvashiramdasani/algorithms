#include <iostream>
#include <algorithm>

using namespace std;

int eD_recursive(string s1, string s2, int m, int n) {
    if(m == 0) return n;
    if(n == 0) return m;
    if(s1[m - 1] == s2[n - 1]) return eD_recursive(s1, s2, m - 1, n - 1);
    else {
        return 1 + min(eD_recursive(s1, s2, m, n - 1), min(eD_recursive(s1, s2, m - 1, n), eD_recursive(s1, s2, m - 1, n - 1)));
        // Insert Delete Replace Try with Saturday and Sunday
    }
};

int main() {
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    int m = s1.length();
    int n = s2.length();
    cout<<"Number of operations required to convert s1 into s2 (Recursive) "<<eD_recursive(s1, s2, m, n);
    
    int dp[m + 1][n + 1];
    for(int i=0; i<=m; i++) dp[i][0] = i;
    for(int i=0; i<=n; i++) dp[0][i] = i;
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    cout<<"\nNumber of operations required to convert s1 into s2 (DP) "<<dp[m][n]; // theta(mn) time and space
}

// Used in spelling suggestions and bioinformatics
