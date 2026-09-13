#include <bits/stdc++.h>
using namespace std;

// Problem: Count Shadow Pairs I
// Link: https://leetcode.com/problems/count-shadow-pairs-i/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Monotonic Stack + Binary Search

// ------------------------------------------------------------
// Approach: Maintain Monotonic Vector, Binary Search for Count
// ------------------------------------------------------------
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> st;
        long long ans = 0;

        for (int x : nums) {
            ans += lower_bound(st.begin(), st.end(), x) - st.begin();

            while (!st.empty() && st.back() > x) {
                st.pop_back();
            }

            st.push_back(x);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << obj.shadowPairs(nums);
    return 0;
}