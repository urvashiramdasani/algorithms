// Demonstrate Memoization and Tabulation using Fibonacci

#include <iostream>

using namespace std;
int memo[100];

int fib(int n) {
    int res;
    if(memo[n] == -1) {
        if(n == 0 || n == 1) res = n;
        else res = fib(n - 1) + fib(n - 2);
        memo[n] = res;
    }
    return memo[n];
};

int main() {
    // Memoization
    for(int i=0; i<100; i++) memo[i] = -1;
    cout<<"\nfib(5) using Memoization : "<<fib(5);
    
    // Tabulation
    int f[100];
    f[0] = 0; f[1] = 1;
    for(int i=2; i<=5; i++) f[i] = f[i - 1] + f[i - 2];
    cout<<"\nfib(5) using Tabulation : "<<f[5];
}
