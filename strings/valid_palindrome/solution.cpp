#include <bits/stdc++.h>
using namespace std;

// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/
// Difficulty: Easy
// Pattern: Strings

// ------------------------------------------------------------
// Approach: Build Filtered String and Compare
// ------------------------------------------------------------

class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                newString += tolower(ch);
            }
        }

        string reversed = newString;
        reverse(reversed.begin(), reversed.end());

        return newString == reversed;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution obj;

    cout << boolalpha << obj.isPalindrome(s) << "\n";
    return 0;
}