#include <iostream>
#include <algorithm>

using namespace std;

// Time - O(n), space - O(1)
void repeating_missing_neg(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int tmp = arr[abs(arr[i]) - 1];
        if(tmp < 0) {
            cout << "Repeating : " << arr[i] << endl;
        } else
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            cout << "Missing : " << (i + 1) << endl;
        }
    }
}

// Time - O(nlogn) space - O(1)
void repeating_missing_naive(int arr[], int n) {
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++) {
        if(arr[i + 1] - arr[i] == 0)
            cout << "Repeating : " << arr[i] << endl;
        if(arr[i + 1] - arr[i] > 1)
            cout << "Missing : " << i + 1 << endl;
    }
}

// Time - O(n), space - O(n)
void repeating_missing_map(int arr[], int n) {
    int m[n + 1] = {0};
    for(int i = 0; i < n; i++) 
        m[arr[i]]++;
    
    for(int i = 1; i <= n; i++) {
        if(m[i] == 0)
            cout << "Missing : " << i << endl;
        if(m[i] > 1)
            cout << "Repeating : " << arr[i] << endl;
    }
}

int main() {
    int arr[] = {7, 6, 1, 2, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    repeating_missing_naive(arr, n);
    repeating_missing_map(arr, n);
    repeating_missing_neg(arr, n);
}