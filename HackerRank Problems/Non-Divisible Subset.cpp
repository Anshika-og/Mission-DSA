#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k;
    vector<int> freq(k, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        freq[x % k]++;
    }
    int count = min(freq[0], 1);
    for (int i = 1; i <= k / 2; ++i) {
        if (i != k - i) {
            count += max(freq[i], freq[k - i]);
        }
    }
    if (k % 2 == 0) count++;
    cout << count << endl;
    return 0;
}
