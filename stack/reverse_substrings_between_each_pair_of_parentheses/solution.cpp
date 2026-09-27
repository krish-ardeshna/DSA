#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse Substrings Between Each Pair of Parentheses
// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Difficulty: Medium
// Pattern: Stack (String Segment Accumulation)

// ------------------------------------------------------------
// Approach: Stack of Strings, Reverse and Merge on Closing Bracket
// ------------------------------------------------------------
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");

        for (char c : s) {
            if (c == '(') {
                st.push("");
            }
            else if (c == ')') {
                string cur = st.top();
                st.pop();

                reverse(cur.begin(), cur.end());

                st.top() += cur;
            }
            else {
                st.top() += c;
            }
        }

        return st.top();
    }
};

int main() {
    Solution obj;
    string s = "(u(love)i)";
    cout << obj.reverseParentheses(s);
    return 0;
}