#include <bits/stdc++.h>
using namespace std;

// Problem: Stone Game
// Link: https://leetcode.com/problems/stone-game/
// Difficulty: Medium
// Pattern: Dynamic Programming, Minimax, Game Theory

// ------------------------------------------------------------
// Approach 1: Recursion (Minimax)
// Time: O(2^n)
// Space: O(n)
// ------------------------------------------------------------

class SolutionRecursive {
public:
    int solve(vector<int>& piles, int i, int j) {
        if (i == j)
            return piles[i];

        int left = piles[i] - solve(piles, i + 1, j);
        int right = piles[j] - solve(piles, i, j - 1);

        return max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        return solve(piles, 0, piles.size() - 1) > 0;
    }
};

// ------------------------------------------------------------
// Approach 2: Memoization (Top-Down DP)
// Time: O(n²)
// Space: O(n²)
// ------------------------------------------------------------

class SolutionMemoization {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int i, int j) {
        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = piles[i] - solve(piles, i + 1, j);
        int right = piles[j] - solve(piles, i, j - 1);

        return dp[i][j] = max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(piles, 0, n - 1) > 0;
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation (Bottom-Up DP)
// Time: O(n²)
// Space: O(n²)
// ------------------------------------------------------------

class SolutionTabulation {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = max(
                    piles[i] - dp[i + 1][j],
                    piles[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] > 0;
    }
};

// ------------------------------------------------------------
// Approach 4: Mathematical Observation (Game Theory)
// Time: O(1)
// Space: O(1)
// ------------------------------------------------------------

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // The number of piles is always even, and the total number
        // of stones is odd. Player 1 can always choose either the
        // even-indexed or odd-indexed piles, guaranteeing a win.
        return true;
    }
};

int main() {
    Solution obj;

    vector<int> piles = {5, 3, 4, 5};

    cout << boolalpha << obj.stoneGame(piles);

    return 0;
}