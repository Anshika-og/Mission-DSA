#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    
    sort(prices.rbegin(), prices.rend());
    
    int total_cost = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += prices[i] * (count / k + 1);
        count++;
    }
    
    cout << total_cost << endl;
    return 0;
}
