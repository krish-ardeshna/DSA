#include <bits/stdc++.h>
using namespace std;

// Problem: Longest String Chain
// Link: https://leetcode.com/problems/longest-string-chain/
// Difficulty: Medium
// Pattern: DP on Subsequences (LIS Variant, "Is One Letter Longer Subsequence")

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    bool check(const string &s1, const string &s2) {
        if (s1.size() != s2.size() + 1) return false;

        int first = 0;
        int second = 0;

        while (first < s1.size() && second < s2.size()) {
            if (s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        return second == s2.size();
    }

    // longest chain that ENDS at words[i] (words must be sorted by length)
    int f(int i, vector<string>& words, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];

        int best = 1;
        for (int prev = 0; prev < i; prev++) {
            if (check(words[i], words[prev])) {
                best = max(best, 1 + f(prev, words, dp));
            }
        }

        return dp[i] = best;
    }

    static bool cmp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;

        vector<int> dp(n, -1);
        sort(words.begin(), words.end(), cmp);

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, f(i, words, dp));
        }
        return maxi;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    bool check(const string &s1, const string &s2) {
        if (s1.size() != s2.size() + 1) return false;

        int first = 0;
        int second = 0;

        while (first < s1.size() && second < s2.size()) {
            if (s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        return second == s2.size();
    }

    static bool cmp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;

        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), cmp);

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (check(words[i], words[prev]) &&
                    1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main() {
    vector<string> w1 = {"a", "b", "ba", "bca", "bda", "bdca"};
    vector<string> w2 = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    vector<string> w3 = {"abcd", "dbqca"};

    SolutionMemo s1;
    cout << s1.longestStrChain(w1) << " " << s1.longestStrChain(w2) << " " << s1.longestStrChain(w3) << "\n";

    SolutionTabulation s2;
    cout << s2.longestStrChain(w1) << " " << s2.longestStrChain(w2) << " " << s2.longestStrChain(w3) << "\n";

    return 0;
}