#include <bits/stdc++.h>
using namespace std;

// Problem: Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/
// Difficulty: Easy
// Pattern: Monotonic Stack

// ------------------------------------------------------------
// Approach: Monotonic Decreasing Stack (Right to Left) + Hashmap
// ------------------------------------------------------------
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> res;

        for (int x : nums1) {
            res.push_back(mp[x]);
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = obj.nextGreaterElement(nums1, nums2);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}