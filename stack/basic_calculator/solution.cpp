#include <bits/stdc++.h>
using namespace std;

// Problem: Basic Calculator
// Link: https://leetcode.com/problems/basic-calculator/
// Difficulty: Hard
// Pattern: Stack

// ------------------------------------------------------------
// Approach: Stack with Sign and Previous Result
// ------------------------------------------------------------

class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        long long result = 0;
        long long num = 0;

        int sign = 1;

        for (char c : s) {

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * num;

                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;

                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;

                int prevSign = st.top();
                st.pop();

                int prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }
        result += sign * num;

        return result;
    }
};

int main() {

    string s = "(1+(4+5+2)-3)+(6+8)";

    Solution obj;

    cout << obj.calculate(s) << "\n";

    return 0;
}