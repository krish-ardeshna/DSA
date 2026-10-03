#include <bits/stdc++.h>
using namespace std;

// Problem: Climbing Stairs
// Link: https://leetcode.com/problems/climbing-stairs/
// Difficulty: Easy
// Pattern: DP (Fibonacci-Style Recurrence)

// ------------------------------------------------------------
// Approach 1: Space-Optimized Iterative (O(1) Space)
// ------------------------------------------------------------
class SolutionOptimized {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int ways;
        int prev1 = 2;
        int prev2 = 1;

        for (int i = 3; i <= n; i++) {
            ways = prev1 + prev2;
            prev2 = prev1;
            prev1 = ways;
        }

        return prev1;
    }
};

// ------------------------------------------------------------
// Approach 2: DP Array (O(n) Space)
// ------------------------------------------------------------
class SolutionDPArray {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> dp(n + 1, -1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// ------------------------------------------------------------
// Approach 3: Recursion + Memoization (Top-Down DP)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int recur(int n, vector<int>& memo) {
        if (n <= 1) return 1;

        if (memo[n] != -1) return memo[n];

        int left = recur(n - 1, memo);
        int right = recur(n - 2, memo);

        return memo[n] = left + right;
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return recur(n, memo);
    }
};

int main() {
    int n = 5;

    SolutionOptimized s1;
    cout << s1.climbStairs(n) << "\n";

    SolutionDPArray s2;
    cout << s2.climbStairs(n) << "\n";

    SolutionMemo s3;
    cout << s3.climbStairs(n) << "\n";

    return 0;
}