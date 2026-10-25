#include <bits/stdc++.h>
using namespace std;

// Problem: Word Break
// Link: https://leetcode.com/problems/word-break/
// Difficulty: Medium
// Pattern: DP on Strings (Prefix Segmentation)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    bool f(int i, const string& s, const unordered_set<string>& dict,
           vector<int>& dp) {
        if (i == 0) return true;

        if (dp[i] != -1) return dp[i];

        for (int j = 0; j < i; j++) {
            if (dict.count(s.substr(j, i - j)) && f(j, s, dict, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<int> dp(n + 1, -1);
        return f(n, s, dict, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up, Single 1D Array)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    vector<string> d1 = {"leet", "code"};
    vector<string> d2 = {"apple", "pen"};
    vector<string> d3 = {"cats", "dog", "sand", "and", "cat"};

    SolutionMemo s1;
    cout << s1.wordBreak("leetcode", d1) << " "
         << s1.wordBreak("applepenapple", d2) << " "
         << s1.wordBreak("catsandog", d3) << "\n";

    SolutionTabulation s2;
    cout << s2.wordBreak("leetcode", d1) << " "
         << s2.wordBreak("applepenapple", d2) << " "
         << s2.wordBreak("catsandog", d3) << "\n";

    return 0;
}