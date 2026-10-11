#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of Squares of Special Elements
// Link: https://leetcode.com/problems/sum-of-squares-of-special-elements/
// Difficulty: Easy
// Pattern: Math - Divisor Check (1-Indexed Positions)

// ------------------------------------------------------------
// Approach: Linear Scan, Square Elements at Positions Dividing n
// ------------------------------------------------------------
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        return sum;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};
    cout << obj.sumOfSquares(nums);
    return 0;
}