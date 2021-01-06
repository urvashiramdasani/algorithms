// This is not the only way to solve the problem. Return -1 when the rope cannot be divided.
// Time Complexity = O(3 ^ n)
#include <iostream>
#include <algorithm>

using namespace std;

int maxCuts(int n, int a, int b, int c) {
    if(n == 0) return 0;
    if(n < 0) return -1;
    int res = max(max(maxCuts(n - a, a, b, c), maxCuts(n - b, a, b, c)), maxCuts(n - c, a, b, c));
    if(res == -1) return -1;
    return res + 1;
}

int main() {
    int n = 23, a = 12, b = 9, c = 11;
    cout<<maxCuts(n, a, b, c)<<endl;
    n = 5, a = 2, b = 4, c = 6;
    cout<<maxCuts(n, a, b, c);
}