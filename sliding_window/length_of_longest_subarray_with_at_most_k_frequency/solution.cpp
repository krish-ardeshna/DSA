#include <bits/stdc++.h>
using namespace std;

// Problem: Length of Longest Subarray With at Most K Frequency
// Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Difficulty: Medium
// Pattern: Sliding Window + Hashmap

// ------------------------------------------------------------
// Approach: Variable-Size Sliding Window with Frequency Map
// ------------------------------------------------------------
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    cout << obj.maxSubarrayLength(nums, 2);
    return 0;
}