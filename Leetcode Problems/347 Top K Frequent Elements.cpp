#include <unordered_map>
#include <queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        priority_queue<pair<int, int>> pq;
        for (auto& [num, f] : freq) pq.push({f, num});

        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
