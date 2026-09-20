#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse Degree of a String
// Link: https://leetcode.com/problems/reverse-degree-of-a-string/
// Difficulty: Easy
// Pattern: String - Weighted Character Value Sum

// ------------------------------------------------------------
// Approach: Single Pass, Reverse-Alphabet Value Weighted by Position
// ------------------------------------------------------------
class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 1; i <= s.size(); i++) {
            int tmp = 'z' - s[i - 1] + 1;
            sum += tmp * i;
        }

        return sum;
    }
};

int main() {
    Solution obj;
    string s = "abcde";
    cout << obj.reverseDegree(s);
    return 0;
}