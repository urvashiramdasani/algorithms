// Used in case of uniform distribution in large ranges and floating point 
// numbers. Best case O(n) when all buckets have one element - perfect 
// uniform distribution. Worst case O(n ^ 2) - all items go in single bucket
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(int arr[], int n, int k) {
    int max_val = arr[0];
    for(int i = 1; i < n; i++)
        max_val = max(max_val, arr[i]);

    max_val++;
    vector <int> bkt[k];

    for(int i = 0; i < n; i++) {
        int bi = (k * arr[i]) / max_val;
        bkt[bi].push_back(arr[i]);
    }

    for(int i = 0; i < k; i++) 
        sort(bkt[i].begin(), bkt[i].end());
    
    int index = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < bkt[i].size(); j++)
            arr[index++] = bkt[i][j];
    }

    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {30, 40, 10, 80, 5, 12, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    bucketSort(arr, n, k);
    return 0;
}