#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Product of Two Elements in an Array
// Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Difficulty: Easy
// Pattern: Array, Sorting

// ------------------------------------------------------------
// Approach 1: Sorting
// ------------------------------------------------------------

class SolutionSorting {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        return max(
            (nums[n - 1] - 1) * (nums[n - 2] - 1),
            (nums[0] - 1) * (nums[1] - 1)
        );
    }
};

// ------------------------------------------------------------
// Approach 2: One Pass (Optimal)
// ------------------------------------------------------------

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int num : nums) {
            if (num >= largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest) {
                secondLargest = num;
            }
        }
        
        return (largest - 1) * (secondLargest - 1);
    }
};

int main() {
    vector<int> nums = {3,4,5,2};

    Solution s;
    cout << s.maxProduct(nums) << endl;

    return 0;
}