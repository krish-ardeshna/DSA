#include <bits/stdc++.h>
using namespace std;

// Problem: Subarrays Distinct Element Sum of Squares I
// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Difficulty: Easy
// Pattern: Brute Force + Hash Set (Enumerate All Subarrays)

// ------------------------------------------------------------
// Approach: Fix Start, Extend End, Track Distinct Count With a Set
// ------------------------------------------------------------
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                int distinct = st.size();
                ans += distinct * distinct;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 1};
    cout << obj.sumCounts(nums1) << "\n";

    vector<int> nums2 = {1, 1};
    cout << obj.sumCounts(nums2) << "\n";

    return 0;
}