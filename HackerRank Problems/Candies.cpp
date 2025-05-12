#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ratings(n), candies(n, 1);
    for (int i = 0; i < n; ++i) cin >> ratings[i];
    
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    cout << accumulate(candies.begin(), candies.end(), 0) << endl;
    return 0;
}
