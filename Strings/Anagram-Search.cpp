#include <iostream>
#include <algorithm>

using namespace std;

bool areAnagram(string pat, string txt, int i) {
    int count[256] = {0};

    for(int j = 0; j < pat.length(); j++) {
        count[pat[j]]++;
        count[txt[i + j]]--;
    }

    for(int j = 0; j < 256; j++) {
        if(count[j] != 0)
            return false;
    }

    return true;
}

// O((n - m + 1) * m) time
bool isPresent(string txt, string pat) {
    int n = txt.length(), m = pat.length();

    for(int i = 0; i <= n - m; i++) {
        if(areAnagram(pat, txt, i))
            return true;
    }

    return false;
}

bool areSame(int CP[], int CT[]) {
    sort(CP, CP + 256);
    sort(CT, CT + 256);

    for(int i = 0; i < 256; i++) {
        if(CT[i] != CP[i])
            return false;
    }

    return true;
}

// O(n * 256) time, theta(256) space
bool isPresentEff(string txt, string pat) {
    int CT[256] = {0}, CP[256] = {0};

    for(int i = 0; i < pat.length(); i++) {
        CP[pat[i]]++;
        CT[txt[i]]++;
    }

    for(int i = pat.length(); i < txt.length(); i++) {
        if(areSame(CP, CT))
            return true;
        CT[txt[i]]++;
        CT[txt[i - pat.length()]]--;
    }

    return false;
}

int main() {
    string txt = "geeksforgeeks", pat = "rseek";
    // gives true for pat = "frog"
    cout << isPresent(txt, pat);
    return 0;
}