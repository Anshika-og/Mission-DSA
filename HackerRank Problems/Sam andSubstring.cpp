#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    long long total = 0, f = 0;
    for (int i = 0; i < s.size(); ++i) {
        f = (f * 10 + (s[i] - '0') * (i + 1)) % MOD;
        total = (total + f) % MOD;
    }
    cout << total << endl;
    return 0;
}
