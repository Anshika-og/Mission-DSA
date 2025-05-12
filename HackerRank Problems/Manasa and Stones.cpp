#include <iostream>
#include <set>
using namespace std;

int main() {
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        set<int> results;
        for (int i = 0; i <= n - 1; ++i) {
            results.insert(a * i + b * (n - 1 - i));
        }
        for (auto res : results) {
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}
