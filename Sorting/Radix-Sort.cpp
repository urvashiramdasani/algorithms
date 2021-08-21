// Supports linear time for larger range (disadvantage of counting sort)
// theta(n + b) space, theta(d * (n + b)), d - number of digits, b - base
#include <iostream>

using namespace std;

void countSort(int arr[], int n, int exp) {
    int count[10], output[n];
    for(int i = 0; i < 10; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++) 
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int mx = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > mx)
            mx = arr[i];
    }

    for(int exp = 1; mx / exp > 0; exp *= 10) 
        countSort(arr, n, exp);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {319, 212, 6, 8, 100, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    return 0;
}