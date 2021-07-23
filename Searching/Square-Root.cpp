#include <iostream>

using namespace std;

// theta(x ^ 1 / 2)
// Binary search can also be used to solev equations.

int sqRootFloor(int x) {
    int i = 1;
    while(i * i <= x)
        i++;
    return (i - 1);
}

int sqRootEff(int x) {
    int low = 0, high = x, ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int mSq = mid * mid;

        if(mSq == x)
            return mSq;
        else if(mSq > x)
            high = mid - 1;
        else {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;
}

int main() {
    cout << sqRootFloor(8) << endl;
    cout << sqRootEff(15);
    return 0;
}