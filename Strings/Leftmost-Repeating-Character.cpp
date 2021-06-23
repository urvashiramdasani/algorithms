#include <iostream>
#include <map>
#include <climits>

using namespace std;

// Naive Approach
int leftRepeatChar(string s) {
    for(int i = 0; i < s.length(); i++) {
        for(int j = i + 1; j < s.length(); j++) {
            if(s[i] == s[j])
                return i;
        }
    }

    return -1;
}

// My Approach
int leftRepeatCharMap(string s) {
    map<char, int> m;

    for(int i = 0; i < s.length(); i++) 
        m[s[i]]++;

    for(int i = 0; i < m.size(); i++) {
        if(m[s[i]] > 1)
            return i;
    }

    return -1;
}

// Better Approach
int leftRepeatCharBet(string s) {
    int count[256] = {0};

    for(int i = 0; i < s.length(); i++)
        count[s[i]]++;

    for(int i = 0; i < 256; i++) {
        if(count[s[i]] > 1)
            return i;
    }

    return -1;
}

// Efficient Approach - 1
int leftRepeatCharEff1(string s) {
    int findex[256];
    fill(findex, findex + 256, -1);
    int res = INT_MAX;

    for(int i = 0; i < s.length(); i++) {
        int fi = findex[s[i]];
        if(fi == -1)
            findex[s[i]] = i;
        else
            res = min(res, fi);
    }

    return (res == INT_MAX) ? -1 : res;
}

// Efficient Approach - 2
int leftRepeatCharEff2(string s) {
    bool visited[256];
    fill(visited, visited + 256, false);
    int res = -1;

    for(int i = s.length() - 1; i >= 0; i--) {
        if(visited[s[i]])
            res = i;
        else
            visited[s[i]] = true;
    }
    
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << leftRepeatChar(s) << endl;
    cout << leftRepeatCharMap(s) << endl;
    cout << leftRepeatCharBet(s) << endl;
    cout << leftRepeatCharEff1(s) << endl;
    cout << leftRepeatCharEff2(s);
    return 0;
}