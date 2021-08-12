#include <iostream>

using namespace std;

// Naive partition - theta(n) time and space, stable
void partition(int arr[], int l, int h, int p) {
    int tmp[h - l + 1], ind = 0;

    for(int i = l; i <= h; i++) {
        if(arr[i] <= arr[p] && i != p) {
            tmp[ind] = arr[i];
            ind++;
        }
    }

    tmp[ind++] = arr[p];

    for(int i = l; i <= h; i++) {
        if(arr[i] > arr[p]) {
            tmp[ind] = arr[i];
            ind++;
        }
    }

    for(int i = l; i <= h; i++) {
        arr[i] = tmp[i - l];
        cout << arr[i] << " ";
    }
}

// theta(n) time and constant space, unstable
void lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    for(int i = low; i <= high; i++)
        cout << arr[i] << " ";
}

// theta(n) time and constant space. It does not 
// place the pivot at its proper place, unstable
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while(true) {
        do {
            i++;
        } while(arr[i] < pivot);

        do {
            j--;
        } while(arr[j] > pivot);

        if(i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[] = {5, 13, 8, 9, 12, 4, 11};
    partition(arr, 0, 6, 2);
    cout << endl;
    lomutoPartition(arr, 0, 6);
    cout << endl << hoarePartition(arr, 0, 6);
    return 0;
}