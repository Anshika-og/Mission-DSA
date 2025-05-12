#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;

        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums1.size() && i < k; ++i) pq.emplace(i, 0);

        while (!pq.empty() && k--) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (++j < nums2.size()) pq.emplace(i, j);
        }

        return res;
    }
};
