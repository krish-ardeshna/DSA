#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Cost to Cut a Stick
// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Difficulty: Hard
// Pattern: DP on Partitions (Interval DP, Choose the FIRST Cut in a Segment)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // min cost to make all cuts i..j (cuts is sorted, with 0 and n added at the ends)
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int idx = i; idx <= j; idx++) {
            int cost = cuts[j + 1] - cuts[i - 1]
                     + f(i, idx - 1, cuts, dp)
                     + f(idx + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size() - 2;

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

        return f(1, c, cuts, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size() - 2;

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j) continue;

                int mini = INT_MAX;

                for (int idx = i; idx <= j; idx++) {
                    int cost = cuts[j + 1] - cuts[i - 1]
                             + dp[i][idx - 1]
                             + dp[idx + 1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};

int main() {
    vector<int> c1 = {1, 3, 4, 5};
    vector<int> c2 = {5, 6, 1, 4, 2};

    // minCost changes cuts, so pass a fresh copy each time
    SolutionMemo s1;
    vector<int> t1 = c1, t2 = c2;
    cout << s1.minCost(7, t1) << " " << s1.minCost(9, t2) << "\n";

    SolutionTabulation s2;
    vector<int> t3 = c1, t4 = c2;
    cout << s2.minCost(7, t3) << " " << s2.minCost(9, t4) << "\n";

    return 0;
}