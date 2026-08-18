#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Largest Almost Missing Integer
// Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
// Difficulty: Easy
// Pattern: Array - Sliding Window + Presence Counting

// ------------------------------------------------------------
// Approach: Brute Force Windows + Bounded Value Presence Count
// ------------------------------------------------------------
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);
        for (int i = 0; i <= n - k; i++) {
            vector<bool> present(51, false);
            for (int j = i; j < i + k; j++) {
                present[nums[j]] = true;
            }
            for (int x = 0; x <= 50; x++) {
                if (present[x]) {
                    count[x]++;
                }
            }
        }
        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 3, 2, 1, 3};
    int k = 2;
    cout << obj.largestInteger(nums, k);
    return 0;
}