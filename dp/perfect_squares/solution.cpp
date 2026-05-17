#include <bits/stdc++.h>
using namespace std;

// Problem: Perfect Squares
// Link: https://leetcode.com/problems/perfect-squares/
// Difficulty: Medium
// Pattern: Dynamic Programming / Math

// ------------------------------------------------------------
// Approach 1: Dynamic Programming
// ------------------------------------------------------------

class SolutionDP {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// ------------------------------------------------------------
// Approach 2: Mathematical Optimization
// ------------------------------------------------------------

class SolutionOptimal {
public:

    bool isPerfectSquare(int n) {
        int x = sqrt(n);
        return x * x == n;
    }

    int numSquares(int n) {

        // Case 1: perfect square
        if (isPerfectSquare(n)) {
            return 1;
        }

        // Case 2: sum of two perfect squares
        for (int i = 1; i * i <= n; i++) {
            if (isPerfectSquare(n - i * i)) {
                return 2;
            }
        }

        // Reduce factors of 4
        while (n % 4 == 0) {
            n /= 4;
        }

        // Legendre's theorem case
        if (n % 8 == 7) {
            return 4;
        }

        // Otherwise answer is 3
        return 3;
    }
};

int main() {
    int n;
    cin >> n;

    SolutionOptimal s;

    cout << s.numSquares(n) << "\n";

    return 0;
}