#include <bits/stdc++.h>
using namespace std;

// Problem: Range Sum Query - Immutable
// Link: https://leetcode.com/problems/range-sum-query-immutable/
// Difficulty: Easy
// Pattern: Prefix Sum

// ------------------------------------------------------------
// Approach: Prefix Sum
// ------------------------------------------------------------

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);

    cout << obj.sumRange(0, 2) << "\n";
    cout << obj.sumRange(2, 5) << "\n";
    cout << obj.sumRange(0, 5) << "\n";

    return 0;
}