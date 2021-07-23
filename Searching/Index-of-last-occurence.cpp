#include <iostream>

using namespace std;

int lastOcc(int arr[], int low, int high, int x, int n) {
    if(low > high)
        return -1;
    int mid = (low + high) / 2;

    if(x < arr[mid])
        return lastOcc(arr, low, mid - 1, x, n);
    else if(x > arr[mid])
        return lastOcc(arr, mid + 1, high, x, n);
    else {
        if(mid == n - 1 || arr[mid] != arr[mid + 1])
            return mid;
        else
            return lastOcc(arr, mid + 1, high, x, n);
    }
}

int lastOccItr(int arr[], int x, int n) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(x < arr[mid]) 
            high = mid - 1;
        else if(x > arr[mid])
            low = mid + 1;
        else {
            if(mid == n - 1 || arr[mid] != arr[mid + 1])
                return mid;
            else
                low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {5, 10, 10, 10, 10, 20, 20};
    cout << lastOcc(arr, 0, 6, 10, 7) << endl;
    cout << lastOccItr(arr, 10, 7);
    return 0;
}