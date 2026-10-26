#include <bits/stdc++.h>
using namespace std;

// Problem: Count Islands With Total Value Divisible by K
// Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
// Difficulty: Medium
// Pattern: Graph - Grid DFS (Iterative, Sum Per Island)

// ------------------------------------------------------------
// Approach: Explore Each Island With a Stack, Add Up Its Values, Check Divisibility
// ------------------------------------------------------------
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                long long sum = 0;
                stack<pair<int, int>> st;

                st.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;

                while (!st.empty()) {
                    auto [r, c] = st.top();
                    st.pop();

                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if (nr >= 0 && nr < m &&
                            nc >= 0 && nc < n &&
                            grid[nr][nc] > 0) {

                            sum += grid[nr][nc];
                            grid[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }

                if (sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> g1 = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };
    cout << obj.countIslands(g1, 5) << "\n";

    vector<vector<int>> g2 = {
        {3, 0, 3, 0},
        {0, 3, 0, 3},
        {3, 0, 3, 0}
    };
    cout << obj.countIslands(g2, 3) << "\n";

    return 0;
}