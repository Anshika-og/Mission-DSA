#include <queue>
#include <algorithm>
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& interval : intervals) {
            if (!minHeap.empty() && interval[0] >= minHeap.top())
                minHeap.pop();
            minHeap.push(interval[1]);
        }

        return minHeap.size();
    }
};
