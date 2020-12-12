// To check for the correctness of two algorithms. 
// One algorithm is the efficient solution and other is alternative solution.
// Used when you optimize your code and want to check whether it is correct like the previous (unoptimized) code you wrote.

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    while(true) {
        int n = rand() % 100 + 2;
        cout<<n<<endl;
        vector <int> a;
        for(int i=0; i<n; i++) a.push_back(rand() % 100000);
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<endl;
        // int res1 = function_call1(); // 1st algorithm
        // int res2 = function_call2(); // 2nd algorithm
        // if(res1 != res2) {
        //     cout<<"Wrong Answer! "<<res1<<" "<<res2<<endl;
        //     break;
        // } else cout<<"OK\n";
    }
}
