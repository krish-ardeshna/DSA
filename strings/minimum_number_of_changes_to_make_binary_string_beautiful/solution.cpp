#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Number of Changes to Make Binary String Beautiful
// Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
// Difficulty: Medium
// Pattern: Partition DP (Brute Force) + Greedy on Pairs

// ------------------------------------------------------------
// Approach 1: Partition DP (Try Every Even-Length Block)
// ------------------------------------------------------------
class SolutionDP {
public:
    int minChanges(string s) {
        int n = s.size();

        // ones[i] = number of '1' in the first i characters
        vector<int> ones(n + 1, 0);

        for (int i = 0; i < n; i++)
            ones[i + 1] = ones[i] + (s[i] == '1');

        const int INF = 1e9;

        // dp[i] = minimum changes to make the first i characters beautiful (i is even)
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 2; i <= n; i += 2) {
            for (int j = 0; j < i; j += 2) {
                // the last block is s[j..i-1], make it all 0s or all 1s
                int one = ones[i] - ones[j];
                int zero = (i - j) - one;

                dp[i] = min(dp[i], dp[j] + min(one, zero));
            }
        }

        return dp[n];
    }
};

// ------------------------------------------------------------
// Approach 2: Greedy (Every Pair Must Match)
// ------------------------------------------------------------
class SolutionGreedy {
public:
    int minChanges(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i + 1]) ans++;
        }

        return ans;
    }
};

int main() {
    SolutionDP s1;
    cout << s1.minChanges("1001") << " "
         << s1.minChanges("10") << " "
         << s1.minChanges("0000") << "\n";

    SolutionGreedy s2;
    cout << s2.minChanges("1001") << " "
         << s2.minChanges("10") << " "
         << s2.minChanges("0000") << "\n";

    return 0;
}