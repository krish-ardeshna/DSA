#include <bits/stdc++.h>
using namespace std;

        // Problem: Maximum Nesting Depth of the Parentheses
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Difficulty: Easy
// Pattern: String - Running Counter (Stack Without the Stack)

// ------------------------------------------------------------
// Approach: Single Pass Depth Counter, Track Max
// ------------------------------------------------------------
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                depth++;
                ans = max(ans, depth);
            }
            else if (c == ')') {
                depth--;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << obj.maxDepth(s);
    return 0;
}