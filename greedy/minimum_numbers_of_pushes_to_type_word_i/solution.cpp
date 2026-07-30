#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Number of Pushes to Type Word I
// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
// Difficulty: Easy
// Pattern: Greedy

// ------------------------------------------------------------
// Approach: Greedy
// ------------------------------------------------------------

class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;

        for (int i = 0; i < word.size(); i++)
            ans += (i / 8) + 1;

        return ans;
    }
};

int main() {
    Solution obj;

    string word = "abcde";

    cout << obj.minimumPushes(word);

    return 0;
}