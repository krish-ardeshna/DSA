#include <bits/stdc++.h>
using namespace std;

// Problem: Next Greater Element II
// Link: https://leetcode.com/problems/next-greater-element-ii/
// Difficulty: Medium
// Pattern: Monotonic Stack (Circular Array via Double Pass)

// ------------------------------------------------------------
// Approach: Monotonic Decreasing Stack, Double-Length Traversal
// ------------------------------------------------------------
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        vector<int> ans(n);

        for (int i = 2 * n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[i % n]);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 1};
    vector<int> result = obj.nextGreaterElements(nums);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}