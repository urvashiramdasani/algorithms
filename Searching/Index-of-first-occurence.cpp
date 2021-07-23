#include <iostream>

using namespace std;

int firstOccNaive(int arr[], int n, int ele) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == ele)
            return i;
    }
    return -1;
}

int firstOccRec(int arr[], int low, int high, int x) {
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(x > arr[mid]) 
        return firstOccRec(arr, mid + 1, high, x);
    else if(x < arr[mid])
        return firstOccRec(arr, low, mid - 1, x);
    else {
        if(mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return firstOccRec(arr, low, mid - 1, x);
    }
}

int firstOccItr(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(x > arr[mid])
            low = mid + 1;
        else if(x < arr[mid])
            high = mid - 1;
        else {
            if(mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 10, 15, 20, 20, 20};
    cout << firstOccNaive(arr, 7, 20) << endl;
    cout << firstOccRec(arr, 0, 6, 20) << endl;
    cout << firstOccItr(arr, 7, 20); 
    return 0;
}