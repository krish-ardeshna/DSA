#include <bits/stdc++.h>
using namespace std;

// Problem: Twisted Mirror Path Count
// Link: https://leetcode.com/problems/twisted-mirror-path-count/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: DP on Grids (State = Cell + Direction We Entered With, Mirrors Force a Turn)

// dir = 0: we entered the cell moving RIGHT (came from the left)
// dir = 1: we entered the cell moving DOWN  (came from above)
// empty cell (0): we may continue right or down
// mirror cell (1): right -> forced down, down -> forced right

const int MOD = 1e9 + 7;

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // number of ways to reach the bottom-right cell after entering (i, j) with direction dir
    int f(int i, int j, int dir, vector<vector<int>>& grid, int m, int n,
          vector<vector<array<int, 2>>>& dp) {
        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j][dir] != -1) return dp[i][j][dir];

        int ways = 0;

        if (grid[i][j] == 0) {
            // empty: go right or down
            ways = (f(i, j + 1, 0, grid, m, n, dp) +
                    f(i + 1, j, 1, grid, m, n, dp)) % MOD;
        }
        else if (dir == 0) {
            // entered moving right: the mirror reflects us down
            ways = f(i + 1, j, 1, grid, m, n, dp);
        }
        else {
            // entered moving down: the mirror reflects us right
            ways = f(i, j + 1, 0, grid, m, n, dp);
        }

        return dp[i][j][dir] = ways;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<array<int, 2>>> dp(
            m, vector<array<int, 2>>(n, {-1, -1})
        );

        // the start cell is entered moving right
        return f(0, 0, 0, grid, m, n, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up, Push Forward)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // dp[i][j][0]: entered from left (moving right)
        // dp[i][j][1]: entered from top (moving down)
        vector<vector<array<int, 2>>> dp(
            m, vector<array<int, 2>>(n, {0, 0})
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int right = dp[i][j][0];
                int down = dp[i][j][1];

                if (grid[i][j] == 0) {
                    int ways = (right + down) % MOD;

                    if (j + 1 < n)
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % MOD;

                    if (i + 1 < m)
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % MOD;
                }
                else {
                    // entering from left: reflect down
                    if (i + 1 < m)
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + right) % MOD;

                    // entering from top: reflect right
                    if (j + 1 < n)
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + down) % MOD;
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // cur = the row being processed, nxt = the row below it
        vector<array<int, 2>> cur(n, {0, 0}), nxt(n, {0, 0});

        cur[0][0] = 1;

        int result = 0;

        for (int i = 0; i < m; i++) {
            fill(nxt.begin(), nxt.end(), array<int, 2>{0, 0});

            for (int j = 0; j < n; j++) {
                int right = cur[j][0];
                int down = cur[j][1];

                if (grid[i][j] == 0) {
                    int ways = (right + down) % MOD;

                    if (j + 1 < n)
                        cur[j + 1][0] = (cur[j + 1][0] + ways) % MOD;

                    if (i + 1 < m)
                        nxt[j][1] = (nxt[j][1] + ways) % MOD;
                }
                else {
                    if (i + 1 < m)
                        nxt[j][1] = (nxt[j][1] + right) % MOD;

                    if (j + 1 < n)
                        cur[j + 1][0] = (cur[j + 1][0] + down) % MOD;
                }
            }

            if (i == m - 1)
                result = (cur[n - 1][0] + cur[n - 1][1]) % MOD;

            swap(cur, nxt);
        }

        return result;
    }
};

int main() {
    vector<vector<int>> g1 = {{0, 0}, {0, 0}};
    vector<vector<int>> g2 = {{0, 1, 1}, {1, 1, 0}};
    vector<vector<int>> g3 = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};

    SolutionMemo s1;
    cout << s1.uniquePaths(g1) << " " << s1.uniquePaths(g2) << " " << s1.uniquePaths(g3) << "\n";

    SolutionTabulation s2;
    cout << s2.uniquePaths(g1) << " " << s2.uniquePaths(g2) << " " << s2.uniquePaths(g3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.uniquePaths(g1) << " " << s3.uniquePaths(g2) << " " << s3.uniquePaths(g3) << "\n";

    return 0;
}