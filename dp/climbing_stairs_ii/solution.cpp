#include <bits/stdc++.h>
using namespace std;

// Problem: Climbing Stairs II
// Link: https://leetcode.com/problems/climbing-stairs-ii/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: 1D DP (Last Jump of Size 1, 2 or 3)

const long long INF = LLONG_MAX / 4;

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // minimum cost to reach step i
    long long f(int i, vector<int>& costs, vector<long long>& dp) {
        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        long long best = INF;

        // the last jump comes from step i - j, with j = 1, 2 or 3
        for (int j = 1; j <= 3 && j <= i; j++) {
            best = min(best,
                f(i - j, costs, dp) + costs[i - 1] + 1LL * j * j);
        }

        return dp[i] = best;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, -1);

        return f(n, costs, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[i] = minimum cost to reach step i
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3 && j <= i; j++) {
                dp[i] = min(dp[i],
                    dp[i - j] + costs[i - 1] + 1LL * j * j);
            }
        }

        return dp[n];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Last 3 Values)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int climbStairs(int n, vector<int>& costs) {
        // p1 = dp[i - 1], p2 = dp[i - 2], p3 = dp[i - 3]
        // steps below 0 do not exist, so they stay INF
        long long p1 = 0, p2 = INF, p3 = INF;

        for (int i = 1; i <= n; i++) {
            long long cur = min({
                p1 + 1,
                p2 + 4,
                p3 + 9
            }) + costs[i - 1];

            p3 = p2;
            p2 = p1;
            p1 = cur;
        }

        return p1;
    }
};

int main() {
    vector<int> c1 = {1, 2, 3, 4};
    vector<int> c2 = {5, 1, 6, 2};
    vector<int> c3 = {9, 8, 3};

    SolutionMemo s1;
    cout << s1.climbStairs(4, c1) << " "
         << s1.climbStairs(4, c2) << " "
         << s1.climbStairs(3, c3) << "\n";

    SolutionTabulation s2;
    cout << s2.climbStairs(4, c1) << " "
         << s2.climbStairs(4, c2) << " "
         << s2.climbStairs(3, c3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.climbStairs(4, c1) << " "
         << s3.climbStairs(4, c2) << " "
         << s3.climbStairs(3, c3) << "\n";

    return 0;
}