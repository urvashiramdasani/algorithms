#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int getMinDiff(int arr[], int n) {
    int res = INT_MAX;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++)
            res = min(res, abs(arr[j] - arr[i]));
    }

    return res;
}

int getMinDiffEff(int arr[], int n) {
    sort(arr, arr + n);
    int res = INT_MAX;

    for(int i = 1; i < n; i++) 
        res = min(res, arr[i] - arr[i - 1]);

    return res;
}

int main() {
    int arr[] = {5, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << getMinDiff(arr, n);
    cout << endl << getMinDiffEff(arr, n);
    return 0;
}