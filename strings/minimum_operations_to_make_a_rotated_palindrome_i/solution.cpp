#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Operations to Make a Rotated Palindrome I
// Link: https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/
// Difficulty: Medium(contest problem)
// Pattern: String - Brute Force Rotation + Palindrome Cost

// ------------------------------------------------------------
// Approach: Try Every Rotation, Compute Min Char-Change Cost
// ------------------------------------------------------------
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int operations = i;

            for (int j = 0; j < n / 2; j++) {
                int left = (i + j) % n;
                int right = (i + n - 1 - j) % n;

                int a = s[left] - 'a';
                int b = s[right] - 'a';

                int cost = min((a - b + 26) % 26, (b - a + 26) % 26);

                operations += cost;
            }
            ans = min(ans, operations);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "abcd";
    cout << obj.minOperations(s);
    return 0;
}