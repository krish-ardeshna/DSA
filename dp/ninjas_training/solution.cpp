#include <bits/stdc++.h>
using namespace std;

// Problem: Ninja's Training
// Link: https://takeuforward.org/practice/dsa/ninja's-training
// Difficulty: Medium
// Pattern: DP on Grid-like States (Day, Last Task)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1) {
            return dp[day][last];
        }

        int maxi = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = points[day][task] + f(day - 1, task, points, dp);
                maxi = max(maxi, point);
            }
        }

        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1, 3, matrix, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++) {

            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;

                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = matrix[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(4, 0);

        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0);

            for (int last = 0; last < 4; last++) {
                temp[last] = 0;

                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        temp[last] = max(temp[last], matrix[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};

int main() {
    vector<vector<int>> matrix = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    SolutionMemo s1;
    cout << s1.ninjaTraining(matrix) << "\n";

    SolutionTabulation s2;
    cout << s2.ninjaTraining(matrix) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.ninjaTraining(matrix) << "\n";

    return 0;
}