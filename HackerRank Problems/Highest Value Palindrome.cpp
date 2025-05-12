#include <iostream>
#include <string>
using namespace std;

bool makePalindrome(string& s, int n) {
    bool changed = false;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            if (s[i] > s[n - i - 1]) s[n - i - 1] = s[i];
            else s[i] = s[n - i - 1];
            changed = true;
        }
    }
    return changed;
}

bool makeMaxPalindrome(string& s, int n) {
    bool changed = false;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != '9' && s[i] == s[n - i - 1]) {
            s[i] = s[n - i - 1] = '9';
            changed = true;
        }
    }
    return changed;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool changed = makePalindrome(s, n);
    int remaining = k - changed;
    if (remaining > 0) {
        makeMaxPalindrome(s, n);
    }
    cout << s << endl;
    return 0;
}
