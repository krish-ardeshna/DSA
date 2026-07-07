#include <bits/stdc++.h>
using namespace std;

// Problem: Concatenate Non-Zero Digits and Multiply by Sum I
// Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
// Difficulty: Easy
// Pattern: Math / Strings

// ------------------------------------------------------------
// Approach: String Traversal
// ------------------------------------------------------------

class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        long long x = 0;
        long long sum = 0;

        for (char ch : s) {
            if (ch != '0') {
                
                int digit = ch - '0';
                x = x * 10 + digit;
                sum += digit;
            }
        }
        return sum * x;
    }
};

int main() {
    int n = 102304;

    Solution s;
    cout << s.sumAndMultiply(n) << "\n";

    return 0;
}