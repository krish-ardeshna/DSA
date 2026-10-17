#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Swaps to Sort by Digit Sum
// Link: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/
// Difficulty: Medium
// Pattern: Sorting + Permutation Cycle Detection

// ------------------------------------------------------------
// Approach: Sort With Original Indices, Count Swaps as (Cycle Size - 1) Per Cycle
// ------------------------------------------------------------
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || get<2>(arr[i]) == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(arr[j]);
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }

        return swaps;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {37, 100};
    cout << obj.minSwaps(nums1) << "\n";

    vector<int> nums2 = {22, 14, 33, 7};
    cout << obj.minSwaps(nums2) << "\n";

    vector<int> nums3 = {18, 43, 34, 16};
    cout << obj.minSwaps(nums3) << "\n";

    return 0;
}