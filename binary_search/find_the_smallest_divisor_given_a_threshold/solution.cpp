#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Smallest Divisor Given a Threshold
// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Difficulty: Medium
// Pattern: Binary Search on Answer

// ------------------------------------------------------------
// Approach: Binary Search on Divisor + Ceiling Sum Check
// ------------------------------------------------------------
class Solution {
public:
    int summation(const vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            // sum += ceil((double)num / (double(div)));
            sum += (num + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) return -1;

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low + high) / 2;

            if (summation(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << obj.smallestDivisor(nums, threshold);
    return 0;
}                       