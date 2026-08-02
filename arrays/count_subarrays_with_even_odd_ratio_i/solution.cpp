#include <bits/stdc++.h>
using namespace std;

// Problem: Count Subarrays With Even Odd Ratio I
// Link: https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/
// Difficulty: Medium
// Pattern: Brute Force, Counting

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int even = 0;
            int odd = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    even++;
                else
                    odd++;

                if (odd > 0 && 1LL * even * b <= 1LL * odd * a)
                    ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4};
    int a = 1;
    int b = 1;

    cout << obj.countRatioSubarrays(nums, a, b);

    return 0;
}