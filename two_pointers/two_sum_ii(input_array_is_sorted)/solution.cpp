#include <bits/stdc++.h>
using namespace std;

// Problem: Two Sum II - Input Array Is Sorted
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Difficulty: Medium
// Pattern: Two Pointers

// ------------------------------------------------------------
// Approach: Two Pointers
// ------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {
            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};

int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 9;

    Solution s;
    vector<int> ans = s.twoSum(numbers, target);

    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}