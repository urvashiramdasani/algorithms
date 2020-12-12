#include <iostream>

// int get_fibonacci_last_digit_naive(int n) {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;

//     for (int i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % 10;
// }

int get_fibonacci_last_digit_fast(long long n) {
    // write your code here
    unsigned long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(long long i=2; i<=n; i++) fib[i] = (fib[i-1] + fib[i-2]) % 10; 
    return fib[n] % 10;
}

int main() {
    long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
// There is so much more in fibonacci numbers. Pisano period, sum of fibonacci series etc. There also an even better way to compute fibonacci numbers.
