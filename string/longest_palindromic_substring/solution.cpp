#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Palindromic Substring
// Link: https://leetcode.com/problems/longest-palindromic-substring/
// Difficulty: Medium
// Pattern: Strings / Expand Around Center

class Solution {
public:
    string expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string res = "";

        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            string odd = expand(s, i, i);

            // Even length palindrome
            string even = expand(s, i, i + 1);

            if (odd.length() > res.length()) res = odd;
            if (even.length() > res.length()) res = even;
        }

        return res;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestPalindrome(s) << "\n";

    return 0;
}