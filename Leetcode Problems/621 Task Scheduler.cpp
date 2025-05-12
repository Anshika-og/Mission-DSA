#include <queue>
#include <unordered_map>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        priority_queue<int> pq;
        for (auto& [_, f] : freq) pq.push(f);

        int time = 0;
        while (!pq.empty()) {
            vector<int> tmp;
            int i = 0;
            for (; i <= n && !pq.empty(); i++) {
                tmp.push_back(pq.top() - 1);
                pq.pop();
            }

            for (int t : tmp)
                if (t > 0) pq.push(t);

            time += pq.empty() ? i : n + 1;
        }
        return time;
    }
};
