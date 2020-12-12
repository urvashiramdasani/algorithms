#include <iostream>

using namespace std;

int coin_change_recursive(int coins[], int n, int sum) {
    if(sum == 0) return 1;
    if(n == 0) return 0;
    int res = coin_change_recursive(coins, n - 1, sum);
    if(coins[n - 1] <= sum) res += coin_change_recursive(coins, n, sum - coins[n - 1]);
    return res;
}

int main() {
    int coins[] = {2, 3, 5, 6};
    int n = 4; int sum = 10;
    cout<<"Number of ways of getting sum = 10 from coins (Recursive) "<<coin_change_recursive(coins, 4, 10);
    
    int dp[sum + 1][n + 1]; // sum+1, n+1
    for(int i=0; i<=n; i++) dp[0][i] = 1;
    for(int i=1; i<=sum; i++) dp[i][0] = 0;
    for(int i=1; i<=sum; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = dp[i][j - 1];
            if(coins[j - 1] <= i) dp[i][j] += dp[i - coins[j - 1]][j];
        }
    }
    cout<<"\nNumber of ways of getting sum = 10 from coins (DP) "<<dp[sum][n];
}

// think for space optimized solution as well. Current auxiliary space = theta(sum*n), optimized auxiliary space = theta(sum)
