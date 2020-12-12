#include <iostream>
#include <climits>
using namespace std;

void optimalParanthesis(int i, int j, int n, int *s, char &mat) {
	if(i == j) {
		cout<<mat++;
		return;
	}

	cout<<"(";
	optimalParanthesis(i, *((s+i*n)+j), n, s, mat);
	optimalParanthesis(*((s+i*n)+j) + 1, j, n, s, mat);
	cout<<")";
};

void MCM(int arr[], int n) {
	int dp[n][n], s[n][n], j;

	for(int i = 0; i < n; i++) {
		dp[0][i] = 0;
		s[0][i] = 0;
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			dp[i][j] = 0;
			s[i][j] = 0;
		}
	}

	for(int l = 2; l < n; l++) {
		for(int i = 1; i < n - l + 1; i++) {
			j = i + l - 1;
			dp[i][j] = INT_MAX;

			for(int k = i; k < j; k++) {
				int mul = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[j] * arr[k];

				if(mul < dp[i][j]) {
					dp[i][j] = mul;
					s[i][j] = k;
				}
			}
		}
	}

	cout<<"\nm matrix is \n";
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	cout<<"\ns matrix is\n";
	for(int i = 1; i < n - 1; i++) {
		for(int j = 2; j < n; j++) cout<<s[i][j]<<" ";
		cout<<endl;
	}

	cout<<"\nMinimum number of multiplications required : "<<dp[1][n - 1];
	
	char mat = 'A';
	cout<<"\nThe optimal paranthesization is ";
	optimalParanthesis(1, n - 1, n, (int *)s, mat);
};

int main() {
	cout<<"\nEnter the number of dimesion : ";
	int n; cin>>n;
	int arr[n];
	cout<<"\nEnter the dimesion sequence : ";
	for(int i = 0; i < n; i++) cin>>arr[i];
	MCM(arr, n);
}
