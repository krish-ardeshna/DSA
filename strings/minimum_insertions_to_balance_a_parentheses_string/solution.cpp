#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Insertions to Balance a Parentheses String
// Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Difficulty: Medium
// Pattern: Greedy (Running Counter of Needed Closers)

// ------------------------------------------------------------
// Approach: Track Pending ')' Needed, Fix Odd Gaps and Unmatched Closers on the Fly
// ------------------------------------------------------------
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }

                need += 2;
            }
            else {
                need--;

                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};

int main() {
    Solution obj;
    cout << obj.minInsertions("(()))") << "\n";
    cout << obj.minInsertions("())") << "\n";
    cout << obj.minInsertions("))())(") << "\n";
    return 0;
}