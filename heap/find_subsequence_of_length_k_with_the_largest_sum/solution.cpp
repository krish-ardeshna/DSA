#include <bits/stdc++.h>
using namespace std;

// Problem: Find Subsequence of Length K With the Largest Sum
// Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Difficulty: Easy
// Pattern: Heap, Sorting

// ------------------------------------------------------------
// Approach 1: Min Heap
// Time: O(n log k)
// Space: O(k)
// ------------------------------------------------------------

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<pair<int, int>> selected;

        while (!pq.empty()) {
            selected.push_back(pq.top());
            pq.pop();
        }

        sort(selected.begin(), selected.end(),
             [](const auto& a, const auto& b) {
                 return a.second < b.second;
             });

        vector<int> ans;

        for (auto& p : selected)
            ans.push_back(p.first);

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Sorting
// Time: O(n log n)
// Space: O(n)
// ------------------------------------------------------------

class Solution2 {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        v.resize(k);

        sort(v.begin(), v.end(),
             [](const auto& a, const auto& b) {
                 return a.second < b.second;
             });

        vector<int> ans;

        for (auto& p : v)
            ans.push_back(p.first);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 1, 3, 3};
    int k = 2;

    vector<int> ans = obj.maxSubsequence(nums, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}