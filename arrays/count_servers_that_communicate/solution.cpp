#include <bits/stdc++.h>
using namespace std;

// Problem: Count Servers that Communicate
// Link: https://leetcode.com/problems/count-servers-that-communicate/
// Difficulty: Medium
// Pattern: Matrix + Row/Column Counting

// ------------------------------------------------------------
// Approach 1: Brute Force (Scan the Row and Column of Every Server)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                bool communicates = false;

                // another server in the same row
                for (int c = 0; c < n && !communicates; c++) {
                    if (c != j && grid[i][c] == 1)
                        communicates = true;
                }

                // another server in the same column
                for (int r = 0; r < m && !communicates; r++) {
                    if (r != i && grid[r][j] == 1)
                        communicates = true;
                }

                if (communicates)
                    ans++;
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Row Count + Column Count
// ------------------------------------------------------------
class SolutionCounting {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> rows(m, 0), cols(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 &&
                    (rows[i] > 1 || cols[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> g1 = {{1, 0}, {0, 1}};
    vector<vector<int>> g2 = {{1, 0}, {1, 1}};
    vector<vector<int>> g3 = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    SolutionBruteForce s1;
    cout << s1.countServers(g1) << " " << s1.countServers(g2) << " " << s1.countServers(g3) << "\n";

    SolutionCounting s2;
    cout << s2.countServers(g1) << " " << s2.countServers(g2) << " " << s2.countServers(g3) << "\n";

    return 0;
}