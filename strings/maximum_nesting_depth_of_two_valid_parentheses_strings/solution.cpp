#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Nesting Depth of Two Valid Parentheses Strings
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Difficulty: Medium
// Pattern: String - Depth Parity Split

// ------------------------------------------------------------
// Approach: Alternate Groups by Depth Parity
// ------------------------------------------------------------
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;
                ans.push_back(depth % 2);
            } else {
                ans.push_back(depth % 2);
                depth--;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    string seq = "(()())";
    vector<int> result = obj.maxDepthAfterSplit(seq);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}