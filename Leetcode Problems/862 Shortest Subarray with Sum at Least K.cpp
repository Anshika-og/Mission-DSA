#include <deque>
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];

        int res = n + 1;
        deque<int> dq;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
                res = min(res, i - dq.front()), dq.pop_front();

            while (!dq.empty() && prefix[i] <= prefix[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }
        return res <= n ? res : -1;
    }
};
