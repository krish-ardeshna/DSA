#include <bits/stdc++.h>
using namespace std;

// Problem: Insert Interval
// Link: https://leetcode.com/problems/insert-interval/
// Difficulty: Medium
// Pattern: Intervals

// ------------------------------------------------------------
// Approach: Single Pass Interval Merge
// ------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        for (auto& interval : intervals) {
            
            if (interval[1] < newInterval[0]) {
                ans.push_back(interval);
            }
            else if (interval[0] > newInterval[1]) {
                ans.push_back(newInterval);
                newInterval = interval;
            }
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        ans.push_back(newInterval);

        return ans;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    vector<int> newInterval = {2, 5};
    Solution s;
    vector<vector<int>> ans = s.insert(intervals, newInterval);

    for (auto& interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << "\n";
    return 0;
}