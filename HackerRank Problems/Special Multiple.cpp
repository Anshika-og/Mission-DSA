#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void findSpecialMultiple(int n) {
    queue<string> q;
    q.push("9");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (stoll(s) % n == 0) {
            cout << s << endl;
            return;
        }
        q.push(s + "0");
        q.push(s + "9");
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        findSpecialMultiple(n);
    }
    return 0;
}
