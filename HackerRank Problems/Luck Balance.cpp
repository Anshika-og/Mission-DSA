#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, luck = 0;
    cin >> n >> k;
    vector<pair<int, int>> contests(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> contests[i].first >> contests[i].second;
    }
    
    sort(contests.begin(), contests.end(), [](auto& a, auto& b) {
        return a.second > b.second; // Sort by importance
    });
    
    for (int i = 0; i < n; ++i) {
        if (contests[i].second == 1) {  // Important contest
            if (k > 0) {
                luck += contests[i].first;  // Lose this contest
                k--;
            } else {
                luck -= contests[i].first;  // Win this contest
            }
        } else {
            luck += contests[i].first;  // Lose unimportant contest
        }
    }
    
    cout << luck << endl;
    return 0;
}
