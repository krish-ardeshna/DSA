#include <bits/stdc++.h>
using namespace std;

// Problem: Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/
// Difficulty: Easy
// Pattern: Hashing

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int x : nums) {

            // Duplicate found
            if (seen.count(x)) {
                return true;
            }

            // Store element
            seen.insert(x);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    Solution s;

    cout << s.containsDuplicate(nums) << "\n";

    return 0;
}