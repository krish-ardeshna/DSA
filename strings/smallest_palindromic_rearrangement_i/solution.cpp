#include <bits/stdc++.h>
using namespace std;

// Problem: Smallest Palindromic Rearrangement I
// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
// Difficulty: Medium
// Pattern: String, Frequency Counting

// ------------------------------------------------------------
// Approach: Frequency Counting
// ------------------------------------------------------------

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, char('a' + i));

            if (freq[i] % 2) {
                middle = char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0') {
            return left + middle + right;
        }

        return left + right;
    }
};

int main() {
    string s = "daccad";

    Solution obj;
    cout << obj.smallestPalindrome(s) << endl;

    return 0;
}