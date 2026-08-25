#include <bits/stdc++.h>
using namespace std;

// Problem: Smallest Missing Multiple of K
// Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/
// Difficulty: Not verified (contest problem, check LC page)
// Pattern: Hashing + Linear Search

// ------------------------------------------------------------
// Approach: Hash Set Lookup + Incremental Multiple Check
// ------------------------------------------------------------
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        int x = k;

        while (s.count(x)) {
            x += k;
        }

        return x;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 8};
    int k = 4;
    cout << obj.missingMultiple(nums, k);
    return 0;
}