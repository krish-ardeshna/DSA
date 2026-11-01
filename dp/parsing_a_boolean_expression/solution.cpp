#include <bits/stdc++.h>
using namespace std;

// Problem: Parsing A Boolean Expression
// Link: https://leetcode.com/problems/parsing-a-boolean-expression/
// Difficulty: Hard
// Pattern: Expression Parsing (Recursive Descent with Memoization, Stack)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // evaluates the sub-expression that starts at index `start`
    int f(int start, string& exp, vector<int>& dp, vector<int>& match) {
        if (dp[start] != -1) return dp[start];

        if (exp[start] == 't') return dp[start] = 1;
        if (exp[start] == 'f') return dp[start] = 0;

        char op = exp[start];
        int open = start + 1;
        int close = match[open];

        if (op == '!') {
            return dp[start] = !f(open + 1, exp, dp, match);
        }

        bool result = (op == '&');
        int idx = open + 1;

        while (idx < close) {
            int val = f(idx, exp, dp, match);

            if (op == '&') {
                result = result && val;
            } else {
                result = result || val;
            }

            if (exp[idx] == 't' || exp[idx] == 'f') {
                idx++;
            } else {
                idx = match[idx + 1] + 1;
            }

            if (idx < close && exp[idx] == ',') {
                idx++;
            }
        }

        return dp[start] = result;
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();

        vector<int> match(n, -1);
        vector<int> st;

        for (int i = 0; i < n; i++) {
            if (expression[i] == '(') {
                st.push_back(i);
            } else if (expression[i] == ')') {
                int open = st.back();
                st.pop_back();
                match[open] = i;
            }
        }

        vector<int> dp(n, -1);

        return f(0, expression, dp, match);
    }
};

// ------------------------------------------------------------
// Approach 2: Stack (Iterative, Evaluate on Every ')')
// ------------------------------------------------------------
class SolutionStack {
public:
    bool parseBoolExpr(string expression) {
        vector<char> st;

        for (char c : expression) {
            if (c == ',') continue;

            if (c != ')') {
                st.push_back(c);
                continue;
            }

            // a group just closed: pop its operands back to the '('
            bool hasTrue = false;
            bool hasFalse = false;

            while (st.back() != '(') {
                if (st.back() == 't') hasTrue = true;
                else hasFalse = true;
                st.pop_back();
            }

            st.pop_back();              // remove '('
            char op = st.back();        // the operator before '('
            st.pop_back();

            if (op == '!') {
                st.push_back(hasTrue ? 'f' : 't');
            } else if (op == '&') {
                st.push_back(hasFalse ? 'f' : 't');
            } else {
                st.push_back(hasTrue ? 't' : 'f');
            }
        }

        return st.back() == 't';
    }
};

int main() {
    SolutionMemo s1;
    SolutionStack s2;

    cout << boolalpha;
    cout << s1.parseBoolExpr("&(|(f))") << " "
         << s1.parseBoolExpr("|(f,f,f,t)") << " "
         << s1.parseBoolExpr("!(&(f,t))") << "\n";

    cout << s2.parseBoolExpr("&(|(f))") << " "
         << s2.parseBoolExpr("|(f,f,f,t)") << " "
         << s2.parseBoolExpr("!(&(f,t))") << "\n";

    return 0;
}