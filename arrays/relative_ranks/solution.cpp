#include <bits/stdc++.h>
using namespace std;

// Problem: Relative Ranks
// Link: https://leetcode.com/problems/relative-ranks/
// Difficulty: Easy
// Pattern: Sorting

// ------------------------------------------------------------
// Approach: Sorting
// ------------------------------------------------------------

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<pair<int, int>> athletes;
        for (int i = 0; i < n; i++)
            athletes.push_back({score[i], i});

        sort(athletes.begin(), athletes.end(), greater<pair<int, int>>());

        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            int idx = athletes[i].second;

            if (i == 0)
                ans[idx] = "Gold Medal";
            else if (i == 1)
                ans[idx] = "Silver Medal";
            else if (i == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(i + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> score = {5, 4, 3, 2, 1};

    vector<string> ans = obj.findRelativeRanks(score);

    for (string rank : ans)
        cout << rank << " ";

    return 0;
}