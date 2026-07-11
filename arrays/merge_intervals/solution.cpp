#include <bits/stdc++.h>
using namespace std;

// Problem: Merge Intervals
// Link: https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium
// Pattern: Intervals

// ------------------------------------------------------------
// Approach: Sorting + Merge
// ------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            auto& lastMerged = merged.back();

            if (intervals[i][0] <= lastMerged[1]) {
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            }
            else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    Solution s;
    vector<vector<int>> ans = s.merge(intervals);

    for (auto& interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << "\n";
    return 0;
}