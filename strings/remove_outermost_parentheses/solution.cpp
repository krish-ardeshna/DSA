#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Outermost Parentheses
// Link: https://leetcode.com/problems/remove-outermost-parentheses/
// Difficulty: Easy
// Pattern: String - Running Depth Counter

// ------------------------------------------------------------
// Approach: Skip Brackets at Depth 0 Boundary While Scanning
// ------------------------------------------------------------
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0)
                    ans += c;

                depth++;
            }
            else {
                depth--;

                if (depth > 0)
                    ans += c;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "(()())(())";
    cout << obj.removeOuterParentheses(s);
    return 0;
}