#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Number of Pushes to Type Word II
// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
// Difficulty: Medium
// Pattern: Greedy, Frequency Counting

// ------------------------------------------------------------
// Approach: Greedy + Frequency Counting
// ------------------------------------------------------------

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        for (int i = 0; i < 26 && freq[i] > 0; i++)
            ans += freq[i] * (i / 8 + 1);

        return ans;
    }
};

int main() {
    Solution obj;

    string word = "abcabc";

    cout << obj.minimumPushes(word);

    return 0;
}