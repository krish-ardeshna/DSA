#include <bits/stdc++.h>
using namespace std;

// Problem: Palindrome Partitioning II
// Link: https://leetcode.com/problems/palindrome-partitioning-ii/
// Difficulty: Hard
// Pattern: DP on Partitions (Front Partition, 1D DP), Expand Around Center

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // min number of palindromic pieces for str[i..n - 1]
    int f(int i, int n, string &str, vector<int>& dp) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + f(j + 1, n, str, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, n, s, dp) - 1;   // pieces - 1 = cuts
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;

            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};

// ------------------------------------------------------------
// Approach 3: Expand Around Center (Prefix DP, O(n^2) Time, O(n) Space)
// ------------------------------------------------------------
class SolutionExpandAroundCenter {
public:
    int minCut(string s) {
        int n = s.size();

        // cuts[i] = min cuts for the prefix s[0..i - 1]
        // worst case: cut between every pair of characters, so i - 1 cuts
        vector<int> cuts(n + 1);
        for (int i = 0; i <= n; i++) cuts[i] = i - 1;

        for (int center = 0; center < n; center++) {
            // odd length palindromes s[center - k .. center + k]
            for (int k = 0; center - k >= 0 && center + k < n
                            && s[center - k] == s[center + k]; k++) {
                cuts[center + k + 1] = min(cuts[center + k + 1], cuts[center - k] + 1);
            }

            // even length palindromes s[center - k + 1 .. center + k]
            for (int k = 1; center - k + 1 >= 0 && center + k < n
                            && s[center - k + 1] == s[center + k]; k++) {
                cuts[center + k + 1] = min(cuts[center + k + 1], cuts[center - k + 1] + 1);
            }
        }

        return cuts[n];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.minCut("aab") << " " << s1.minCut("a") << " " << s1.minCut("ab") << "\n";

    SolutionTabulation s2;
    cout << s2.minCut("aab") << " " << s2.minCut("a") << " " << s2.minCut("ab") << "\n";

    SolutionExpandAroundCenter s3;
    cout << s3.minCut("aab") << " " << s3.minCut("a") << " " << s3.minCut("ab") << "\n";

    return 0;
}