// This program counts the frequency of characters in a string and displays results in
// alphabetical order

#include <iostream>

using namespace std;

void CountFreq(string s) {
    int count[26] = {0};

    for(int i = 0; i < s.size(); i++) 
        count[s[i] - 'a']++;

    for(int i = 0; i < 26; i++) {
        if(count[i] > 0) 
            cout << (char) (i + 'a') << " " << count[i] << endl;
    }
}

int main() {
    string s = "geeksforgeeks";
    CountFreq(s);
    return 0;
}