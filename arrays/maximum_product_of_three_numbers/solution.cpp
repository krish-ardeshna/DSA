#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Product of Three Numbers
// Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Difficulty: Easy
// Pattern: Sorting, Array

// ------------------------------------------------------------
// Approach 1: Sorting
// ------------------------------------------------------------

class SolutionSorting {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return max(
            nums[n - 1] * nums[n - 2] * nums[n - 3],
            nums[0] * nums[1] * nums[n - 1]
        );
    }
};

// ------------------------------------------------------------
// Approach 2: One Pass (Optimal)
// ------------------------------------------------------------

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        int thirdLargest = INT_MIN;

        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for (int num : nums) {

            if (num >= largest) {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = num;
            }
            else if (num >= secondLargest) {
                thirdLargest = secondLargest;
                secondLargest = num;
            }
            else if (num >= thirdLargest) {
                thirdLargest = num;
            }

            if (num <= smallest) {
                secondSmallest = smallest;
                smallest = num;
            }
            else if (num <= secondSmallest) {
                secondSmallest = num;
            }
        }

        return max(
            largest * secondLargest * thirdLargest,
            largest * smallest * secondSmallest
        );
    }
};

int main() {
    vector<int> nums = {-10, -10, 5, 2};

    Solution s;
    cout << s.maximumProduct(nums) << endl;

    return 0;
}