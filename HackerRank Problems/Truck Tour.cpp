#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> stations(n);
    for (int i = 0; i < n; ++i) cin >> stations[i].first >> stations[i].second;
    
    int start = 0, fuel = 0, deficit = 0;
    for (int i = 0; i < n; ++i) {
        fuel += stations[i].first - stations[i].second;
        if (fuel < 0) {
            deficit += fuel;
            fuel = 0;
            start = i + 1;
        }
    }
    
    cout << (fuel + deficit >= 0 ? start : -1) << endl;
    return 0;
}
