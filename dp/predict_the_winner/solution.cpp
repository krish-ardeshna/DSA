#include <bits/stdc++.h>
using namespace std;

// Problem: Predict the Winner
// Link: https://leetcode.com/problems/predict-the-winner/
// Difficulty: Medium
// Pattern: Dynamic Programming, Minimax

// ------------------------------------------------------------
// Approach 1: Recursion (Minimax)
// Time: O(2^n)
// Space: O(n)
// ------------------------------------------------------------

class SolutionRecursive {
public:
    int solve(vector<int>& nums, int i, int j) {
        if (i == j)
            return nums[i];

        int left = nums[i] - solve(nums, i + 1, j);
        int right = nums[j] - solve(nums, i, j - 1);

        return max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};

// ------------------------------------------------------------
// Approach 2: 2D DP (Tabulation)
// Time: O(n²)
// Space: O(n²)
// ------------------------------------------------------------

class SolutionDP2D {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};

// ------------------------------------------------------------
// Approach 3: 1D DP (Space Optimized)
// Time: O(n²)
// Space: O(n)
// ------------------------------------------------------------

class SolutionDP1D {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(nums);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(
                    nums[i] - dp[j],
                    nums[j] - dp[j - 1]
                );
            }
        }

        return dp[n - 1] >= 0;
    }
};

// ------------------------------------------------------------
// Approach 4: Mathematical Observation + 1D DP
// Time: O(n²)
// Space: O(n)
// ------------------------------------------------------------

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // Player 1 can always guarantee a win when n is even.
        if (n % 2 == 0)
            return true;

        vector<int> dp(nums);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(
                    nums[i] - dp[j],
                    nums[j] - dp[j - 1]
                );
            }
        }

        return dp[n - 1] >= 0;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 5, 2};

    cout << boolalpha << obj.predictTheWinner(nums);

    return 0;
}