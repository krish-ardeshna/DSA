#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of Sortable Integers
// Link: https://leetcode.com/problems/sum-of-sortable-integers/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Prefix Max + Suffix Min + Divisor Enumeration

// ------------------------------------------------------------
// Approach: For Each Divisor k, Check Every Block Is a Rotated Sorted Run
//           and Blocks Are Already Ordered Against Each Other
// ------------------------------------------------------------
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, INT_MIN);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i]);
        }

        auto check = [&](int k) {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int drops = prefDrop[end] - prefDrop[start];

                if (nums[end] > nums[start])
                    drops++;

                if (drops > 1 || prefMax[start] > suffMin[start])
                    return false;
            }

            return true;
        };

        int ans = 0;

        for (int k = 1; k <= n / k; k++) {
            if (n % k == 0) {
                if (check(k))
                    ans += k;

                int other = n / k;

                if (other != k && check(other))
                    ans += other;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 3};
    cout << obj.sortableIntegers(nums1) << "\n";

    vector<int> nums2 = {3, 1, 2};
    cout << obj.sortableIntegers(nums2) << "\n";

    vector<int> nums3 = {2, 1, 4, 3};
    cout << obj.sortableIntegers(nums3) << "\n";

    return 0;
}