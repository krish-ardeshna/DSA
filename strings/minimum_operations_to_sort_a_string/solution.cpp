#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Operations to Sort a String
// Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Greedy Case Analysis (Answer Is Always 0, 1, 2, 3 or -1)

// ------------------------------------------------------------
// Approach: Check Where the Min and Max Characters Sit
// ------------------------------------------------------------
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        return 3;
    }
};

int main() {
    Solution obj;
    cout << obj.minOperations("ba") << " "
         << obj.minOperations("acb") << " "
         << obj.minOperations("bca") << " "
         << obj.minOperations("cba") << "\n";
    return 0;
}