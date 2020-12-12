#include <iostream>
#include <algorithm>
using namespace std;

// recursive - O(2^n)
int knapSack_recursive(int w, int wt[], int val[], int n) {
	if(w == 0 || n == 0) return 0;

	if(wt[n - 1] > w) return knapSack_recursive(w, wt, val, n - 1);

	else return max(knapSack_recursive(w, wt, val, n - 1), 
		val[n - 1] + knapSack_recursive(w - wt[n - 1], wt, val, n - 1));
};

int main() {
	cout<<"Enter the number of elements : ";
	int n; cin>>n;
	int weight[n], value[n], w = 0;

	cout<<"\nEnter the weights of elements : ";
	for(int i = 0; i < n; i++) cin>>weight[i];

	cout<<"\nEnter the values of elements : ";
	for(int i = 0; i < n; i++) cin>>value[i];

	cout<<"\nEnter the total weight of knapSack : ";
	cin>>w;

	cout<<"\nMaximum value obtained using recursion: "<<knapSack_recursive(w, weight, value, n);

	// Using Dynamic Programming - O(w*n) - pseudo-polynomial
	// Auxiliary Space - O(n*w)
	// Tabulation
	int dp[n + 1][w + 1];

	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	for(int i = 0; i <= w; i++) dp[0][i] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= w; j++) {
			if(weight[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], 
					value[i - 1] + dp[i - 1][j - weight[i - 1]]);
		}
	}

	cout<<"\ndp array is \n";
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	cout<<"\nMaximum value obtained using DP : "<<dp[n][w];
}

// weight 5 4 6 3
// value 10 40 30 50
// w 10
