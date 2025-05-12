#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, x, result = 0;
    cin >> n;
    unordered_map<int, int> freq;
    while (n--) {
        cin >> x;
        freq[x]++;
    }
    for (auto& [key, val] : freq) {
        result = max(result, val + freq[key + 1]);
    }
    cout << result << endl;
    return 0;
}
