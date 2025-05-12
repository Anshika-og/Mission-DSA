#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        total += arr[i];
    }
    
    if (total % n != 0) {
        cout << "NO" << endl;
    } else {
        int target = total / n, steps = 0;
        for (int i = 0; i < n - 1; ++i) {
            int diff = arr[i] - target;
            arr[i] = target;
            arr[i + 1] += diff;
            steps += abs(diff);
        }
        cout << steps << endl;
    }
    return 0;
}
