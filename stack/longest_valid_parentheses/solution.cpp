#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Valid Parentheses
// Link: https://leetcode.com/problems/longest-valid-parentheses/
// Difficulty: Hard
// Pattern: Stack

// ------------------------------------------------------------
// Approach 1: Stack + Valid Array
// ------------------------------------------------------------

class SolutionBrute {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> valid(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (!st.empty()) {
                    valid[i] = 1;
                    valid[st.top()] = 1;
                    st.pop();
                }
            }
        }

        int maxLen = 0;
        int currLen = 0;

        for (int x : valid) {
            if (x == 1) {
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};

// ------------------------------------------------------------
// Approach 2: Stack of Indices
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    string s = ")()())";
    SolutionOptimal obj;

    cout << obj.longestValidParentheses(s) << "\n";

    return 0;
}