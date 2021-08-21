// Not a comparison based sorting algorithm
// theta(n + k) time and space
// Useful when k is linearly proportional to n
// Stable, used as subroutine in radix sort

#include <iostream>

using namespace std;

// Naive implementation - Cannot be used as a general purpose algorithm
// for sorting objects with multiple members
void countSort(int arr[], int n, int k) {
    int count[k];

    for(int i = 0; i < k; i++)
        count[i] = 0;

    for(int i = 0; i < k; i++)
        count[arr[i]]++;

    int index = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[index] = i;
            index++;
        }
    }
}

// General Purpose Implementation
void countSortGen(int arr[], int n, int k) {
    int count[k];
    for(int i = 0; i < k; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    for(int i = 1; i < k; i++)
        count[i] += count[i - 1];

    int output[n];
    // Traversing from right to left to preserve stability
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {1, 4, 4, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n, 5);

    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    countSortGen(arr, n, 5);
    return 0;
}