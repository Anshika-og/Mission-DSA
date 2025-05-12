#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    vector<pair<int, int>> obstacles(k);
    for (int i = 0; i < k; ++i) {
        cin >> obstacles[i].first >> obstacles[i].second;
    }

    int attack = 0;
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (auto& direction : directions) {
        int i = r, j = c;
        while (true) {
            i += direction[0];
            j += direction[1];
            if (i < 1 || i > n || j < 1 || j > n) break;
            bool blocked = false;
            for (auto& obs : obstacles) {
                if (obs.first == i && obs.second == j) {
                    blocked = true;
                    break;
                }
            }
            if (blocked) break;
            attack++;
        }
    }
    cout << attack << endl;
    return 0;
}
