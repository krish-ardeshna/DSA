#include <bits/stdc++.h>
using namespace std;

// Problem: Different Ways to Evaluate a Boolean Expression
// Link: https://takeuforward.org/practice/dsa/different-ways-to-evaluate-a-boolean-expression
// Difficulty: Not verified (check the TakeUForward page)
// Pattern: DP on Partitions (Interval DP, Choose the LAST Operator to Evaluate)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int mod = 1e9 + 7;

    // number of ways exp[i..j] evaluates to isTrue (1 = True, 0 = False)
    long long f(int i, int j, int isTrue, string &exp,
                vector<vector<vector<long long>>>& dp) {
        if (i > j) return 0;

        if (i == j) {
            bool truth = (exp[i] == 'T');
            return isTrue ? truth : !truth;
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        long long ways = 0;

        for (int idx = i + 1; idx <= j - 1; idx += 2) {
            long long lT = f(i, idx - 1, 1, exp, dp);
            long long lF = f(i, idx - 1, 0, exp, dp);
            long long rT = f(idx + 1, j, 1, exp, dp);
            long long rF = f(idx + 1, j, 0, exp, dp);

            if (exp[idx] == '&') {
                if (isTrue)
                    ways = (ways + lT * rT) % mod;
                else
                    ways = (ways + lT * rF + lF * rT + lF * rF) % mod;
            }
            else if (exp[idx] == '|') {
                if (isTrue)
                    ways = (ways + lT * rT + lT * rF + lF * rT) % mod;
                else
                    ways = (ways + lF * rF) % mod;
            }
            else if (exp[idx] == '^') {
                if (isTrue)
                    ways = (ways + lT * rF + lF * rT) % mod;
                else
                    ways = (ways + lT * rT + lF * rF) % mod;
            }
        }

        return dp[i][j][isTrue] = ways;
    }

    int countTrue(string expression) {
        int n = expression.size();

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(n, vector<long long>(2, -1))
        );

        return f(0, n - 1, 1, expression, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int mod = 1e9 + 7;

    int countTrue(string expression) {
        int n = expression.size();

        // dp[i][j][1] = ways exp[i..j] is True, dp[i][j][0] = ways it is False
        // only operand positions (even indices) can start or end a range
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(n, vector<long long>(2, 0))
        );

        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 1) continue;

            for (int j = i; j < n; j += 2) {
                if (i == j) {
                    bool truth = (expression[i] == 'T');
                    dp[i][j][1] = truth;
                    dp[i][j][0] = !truth;
                    continue;
                }

                for (int isTrue = 0; isTrue <= 1; isTrue++) {
                    long long ways = 0;

                    for (int idx = i + 1; idx <= j - 1; idx += 2) {
                        long long lT = dp[i][idx - 1][1];
                        long long lF = dp[i][idx - 1][0];
                        long long rT = dp[idx + 1][j][1];
                        long long rF = dp[idx + 1][j][0];

                        if (expression[idx] == '&') {
                            if (isTrue)
                                ways = (ways + lT * rT) % mod;
                            else
                                ways = (ways + lT * rF + lF * rT + lF * rF) % mod;
                        }
                        else if (expression[idx] == '|') {
                            if (isTrue)
                                ways = (ways + lT * rT + lT * rF + lF * rT) % mod;
                            else
                                ways = (ways + lF * rF) % mod;
                        }
                        else if (expression[idx] == '^') {
                            if (isTrue)
                                ways = (ways + lT * rF + lF * rT) % mod;
                            else
                                ways = (ways + lT * rT + lF * rF) % mod;
                        }
                    }

                    dp[i][j][isTrue] = ways;
                }
            }
        }

        return dp[0][n - 1][1];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.countTrue("F|T^F") << " "
         << s1.countTrue("T&F") << " "
         << s1.countTrue("T|T&F^T") << "\n";

    SolutionTabulation s2;
    cout << s2.countTrue("F|T^F") << " "
         << s2.countTrue("T&F") << " "
         << s2.countTrue("T|T&F^T") << "\n";

    return 0;
}