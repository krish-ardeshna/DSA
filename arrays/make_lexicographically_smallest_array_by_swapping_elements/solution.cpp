#include <bits/stdc++.h>
using namespace std;

// Problem: Make Lexicographically Smallest Array by Swapping Elements
// Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Difficulty: Medium
// Pattern: Sort + Union-Find Style Grouping (via Sorted Adjacent Check)

// ------------------------------------------------------------
// Approach: Sort by Value, Group Swappable Chains, Reassign Sorted Positions
// ------------------------------------------------------------
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans = nums;

        int start = 0;

        while (start < n) {
            int end = start;

            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            sort(indices.begin(), indices.end());

            for (int i = start; i <= end; i++) {
                ans[indices[i - start]] = arr[i].first;
            }

            start = end + 1;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;
    vector<int> result = obj.lexicographicallySmallestArray(nums, limit);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}