#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Naive Method - O(nlogn) time
bool areAnagram(string s1, string s2) {
    if(s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return (s1 == s2);
}

// Efficient Method
bool areAnagramEff(string s1, string s2) {
    if(s1.length() != s2.length())
        return false;

    int count[256] = {0};

    for(int i = 0; i < s1.length(); i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for(int i = 0; i < 256; i++) {
        if(count[i] != 0) 
            return false;
    }

    return true;
}

// My Method
bool areAnagramMap(string s1, string s2) {
    if(s1.length() != s2.length())
        return false;

    unordered_map <char, int> m1, m2;

    for(int i = 0; i < s1.length(); i++) {
        m1[s1[i]]++;
        m2[s2[i]]++;
    }

    for(int i = 0; i < s1.length(); i++) {
        if(m1[s1[i]] != m2[s1[i]])
            return false;
    }

    return true;
}

int main() {
    string s1 = "aabca", s2 = "acaba";
    cout << areAnagram(s1, s2) << endl;
    cout << areAnagramMap(s1, s2) << endl;
    cout << areAnagramEff(s1, s2);
    return 0;
}