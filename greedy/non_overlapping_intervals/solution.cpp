#include <bits/stdc++.h>
using namespace std;

// Problem: Non-overlapping Intervals
// Link: https://leetcode.com/problems/non-overlapping-intervals/
// Difficulty: Medium
// Pattern: Greedy / Intervals

// ------------------------------------------------------------
// Approach: Greedy
// ------------------------------------------------------------

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            }
            else {
                removed++;
            }
        }
        return removed;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1,2},
        {2,3},
        {3,4},
        {1,3}
    };

    Solution s;

    cout << s.eraseOverlapIntervals(intervals) << "\n";
    return 0;
}