#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        
        if(n > 0)
            isPrime[0] = false;
        
        if(n > 1)
            isPrime[1] = false;
        
        for(int i = 2; i * i < n; i++) {
            if(!isPrime[i])
                continue;
            
            for(int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
        
        int count = 0;
        
        for(int i = 2; i < n; i++) {
            if(isPrime[i])
                count++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    int n = 10;
    cout << "Number of primes from 1 to " << n << " are: " << solution.countPrimes(n);
    return 0;
}