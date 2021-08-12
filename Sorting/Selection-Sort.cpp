// Sort STL uses intro sort (hybrid of heap, insertion, quick sort) O(nlogn)
// Stable algorithm = Bubble, insertion, merge
// Unstable algorithm = selection, quick, heap
// Does less memory writes compared to other. Cycle sort is optimal in terms of memory writes.
// Not stable, in place. Basic idea of heap sort. theta(n ^ 2)

#include <iostream>
#include <climits>

using namespace std;

// Naive 
void SelectionSort(int arr[], int n) {
    int tmp[n];

    for(int i = 0; i < n; i++) {
        int min_ind = 0;
        for(int j = 1; j < n; j++) {
            if(arr[j] < arr[min_ind])
                min_ind = j;
        }

        tmp[i] = arr[min_ind];
        arr[min_ind] = INT_MAX;
    }

    for(int i = 0; i < n; i++)
        arr[i] = tmp[i];
    
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

// In place
void selectSort(int arr[], int n) {
    int min_ind = 0;
    for(int i = 0; i < n - 1; i++) {
        min_ind = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_ind])
                min_ind = j;
        }
        swap(arr[min_ind], arr[i]);
    }

    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {9, 0, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    SelectionSort(arr, n);
    selectSort(arr, n);
    return 0;
}