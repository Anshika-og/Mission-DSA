#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> teams(n);
    for (int i = 0; i < n; ++i) cin >> teams[i];
    
    int maxTopics = 0, count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int topics = 0;
            for (int k = 0; k < m; ++k) {
                if (teams[i][k] == '1' || teams[j][k] == '1') topics++;
            }
            if (topics > maxTopics) {
                maxTopics = topics;
                count = 1;
            } else if (topics == maxTopics) {
                count++;
            }
        }
    }
    cout << maxTopics << endl << count << endl;
    return 0;
}
