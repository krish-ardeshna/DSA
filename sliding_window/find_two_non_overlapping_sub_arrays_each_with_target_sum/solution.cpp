#include <bits/stdc++.h>
using namespace std;

// Problem: Find Two Non-overlapping Sub-arrays Each With Target Sum
// Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Difficulty: Medium
// Pattern: Sliding Window + DP (Best Length Ending By Index)

// ------------------------------------------------------------
// Approach: Variable Window + Running Min-Length-So-Far Array
// ------------------------------------------------------------
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> res(n, INF);

        int left = 0;
        long long sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && res[left - 1] != INF) {
                    ans = min(ans, len + res[left - 1]);
                }

                if (right == 0)
                    res[right] = len;
                else
                    res[right] = min(res[right - 1], len);
            } else {
                if (right > 0)
                    res[right] = res[right - 1];
            }
        }

        return ans == INF ? -1 : ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {3, 2, 2, 4, 3};
    int target = 3;
    cout << obj.minSumOfLengths(arr, target);
    return 0;
}