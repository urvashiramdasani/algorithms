#include <iostream>
#include <map>
#include <climits>

using namespace std;

// Naive Solution
int leftNonRepChar(string s) {
    for(int i = 0; i < s.length(); i++) {
        bool flag = false;
        for(int j = 0; j < s.length(); j++) {
            if(s[i] == s[j] && i != j) {
                flag = true;
                break;
            }
        }
        if(flag == false)
            return i;
    }

    return -1;
}

// Better Solution
int leftNonRepCharBet(string s) {
    int count[256] = {0};
    for(int i = 0; i < s.length(); i++) 
        count[s[i]]++;

    for(int i = 0; i < s.length(); i++) {
        if(count[s[i]] == 1)
            return i;
    }

    return -1;
}

// My Approach
int leftNonRepCharMap(string s) {
    map < char, int > m;
    for(int i = 0; i < s.length(); i++) 
        m[s[i]]++;
    
    for(int i = 0; i < s.length(); i++) {
        if(m[s[i]] == 1)
            return i;
    }

    return -1;
}

// Efficient Solution
int leftNonRepCharEff(string s) {
    int fi[256];
    fill(fi, fi + 256, -1);
    
    for(int i = 0; i < s.length(); i++) {
        if(fi[s[i]] == -1)
            fi[s[i]] = i;
        else
            fi[s[i]] = -2;
    }

    int res = INT_MAX;
    for(int i = 0; i < 256; i++) {
        if(fi[i] > 0) 
            res = min(res, fi[i]);
    }

    return (res == INT_MAX) ? -1 : res;
}

int main() {
    string s = "geeksforgeeks";
    cout << leftNonRepChar(s) << endl;
    cout << leftNonRepCharBet(s) << endl;
    cout << leftNonRepCharMap(s) << endl;
    cout << leftNonRepCharEff(s);
    return 0;
}