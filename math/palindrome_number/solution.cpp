#include <bits/stdc++.h>
using namespace std;

// Problem: Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number/
// Difficulty: Easy
// Pattern: Math

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers cannot be palindrome
        // Numbers ending with 0 also fail (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int rev = 0;

        // Reverse only half of the number
        while (x > rev) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        // Even length:
        // x == rev

        // Odd length:
        // x == rev / 10
        return (x == rev || x == rev / 10);
    }
};

int main() {
    int x;
    cin >> x;

    Solution s;

    cout << s.isPalindrome(x) << "\n";

    return 0;
}